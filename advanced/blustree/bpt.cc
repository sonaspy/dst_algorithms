#include "bpt.h"

#include <stdlib.h>

#include <list>
#include <algorithm>
using std::binary_search;
using std::lower_bound;
using std::swap;
using std::upper_bound;

__BEGIN_NAMESPACE_BPT

/* custom compare operator for STL algorithms */
OPERATOR_KEYCMP(__index_t)
OPERATOR_KEYCMP(__record_t)

/* helper iterating function */
template <class _Tp>
inline typename _Tp::__child_t begin(_Tp &node) {
    return node.children;
}
template <class _Tp>
inline typename _Tp::__child_t end(_Tp &node) {
    return node.children + node.n;
}

/* helper searching function */
inline __index_t *find(__internal_bnode_t &node, const key_type &key) {
    if (key) {
        return upper_bound(begin(node), end(node) - 1, key);
    }
    // because the end of the index range is an empty string, so if we search
    // the empty key(when merge internal nodes), we need to return the second
    // last one
    if (node.n > 1) {
        return node.children + node.n - 2;
    }
    return begin(node);
}
inline __record_t *find(__leaf_node_t &node, const key_type &key) {
    return lower_bound(begin(node), end(node), key);
}

bptree::bptree(const char *p, bool force_empty) : _file_ptr(nullptr), fp_level(0) {
    bzero(path, sizeof(path));
    strcpy(path, p);

    if (!force_empty)
        // read tree from file
        if (__map(&OFFSET_META) != 0)
            force_empty = true;

    if (force_empty) {
        __open_file("w+"); // truncate file

        // create empty tree if file doesn't exist
        __init_from_empty();
        __close_file();
    }
}

int bptree::search(const key_type &key, value_type *value) const {
    __leaf_node_t leaf;
    __map(&leaf, __search_leaf(key));

    // finding the record
    __record_t *record = find(leaf, key);
    if (record != leaf.children + leaf.n) {
        // always return the lower bound
        *value = record->value;

        return __key_compare(record->key, key);
    } else {
        return -1;
    }
}

int bptree::search_range(key_type *left, const key_type &right,
                         value_type *values, size_t max, bool *next) const {
    if (left == nullptr || __key_compare(*left, right) > 0)
        return -1;

    off_t off_left = __search_leaf(*left);
    off_t off_right = __search_leaf(right);
    off_t off = off_left;
    size_t i = 0;
    __record_t *b, *e;

    __leaf_node_t leaf;
    while (off != off_right && off != 0 && i < max) {
        __map(&leaf, off);

        // start point
        if (off_left == off)
            b = find(leaf, *left);
        else
            b = begin(leaf);

        // copy
        e = leaf.children + leaf.n;
        for (; b != e && i < max; ++b, ++i)
            values[i] = b->value;

        off = leaf.next;
    }

    // the last leaf
    if (i < max) {
        __map(&leaf, off_right);

        b = find(leaf, *left);
        e = upper_bound(begin(leaf), end(leaf), right);
        for (; b != e && i < max; ++b, ++i)
            values[i] = b->value;
    }

    // mark for next iteration
    if (next != nullptr) {
        if (i == max && b != e) {
            *next = true;
            *left = b->key;
        } else {
            *next = false;
        }
    }

    return i;
}

int bptree::remove(const key_type &key) {
    __internal_bnode_t parent;
    __leaf_node_t leaf;

    // find parent node
    off_t parent_off = __search_index(key);
    __map(&parent, parent_off);

    // find current node
    __index_t *where = find(parent, key);
    off_t offset = where->child;
    __map(&leaf, offset);

    // verify
    if (!binary_search(begin(leaf), end(leaf), key))
        return -1;

    size_t min_n = _leaf_cnt == 1 ? 0 : _order / 2;
    assert(leaf.n >= min_n && leaf.n <= _order);

    // delete the key
    __record_t *to_delete = find(leaf, key);
    std::copy(to_delete + 1, end(leaf), to_delete);
    leaf.n--;

    // merge or borrow
    if (leaf.n < min_n) {
        // first borrow from left
        bool borrowed = false;
        if (leaf.prev != 0)
            borrowed = __borrow_key(false, leaf);

        // then borrow from right
        if (!borrowed && leaf.next != 0)
            borrowed = __borrow_key(true, leaf);

        // finally we merge
        if (!borrowed) {
            assert(leaf.next != 0 || leaf.prev != 0);

            key_type index_key;

            if (where == end(parent) - 1) {
                // if leaf is last element then merge | prev | leaf |
                assert(leaf.prev != 0);
                __leaf_node_t prev;
                __map(&prev, leaf.prev);
                index_key = begin(prev)->key;

                __merge_leaves(&prev, &leaf);
                __node_erase(&prev, &leaf);
                __unmap(&prev, leaf.prev);
            } else {
                // else merge | leaf | next |
                assert(leaf.next != 0);
                __leaf_node_t next;
                __map(&next, leaf.next);
                index_key = begin(leaf)->key;

                __merge_leaves(&leaf, &next);
                __node_erase(&leaf, &next);
                __unmap(&leaf, offset);
            }

            // remove parent's key
            __erase_from_index(parent_off, parent, index_key);
        } else {
            __unmap(&leaf, offset);
        }
    } else {
        __unmap(&leaf, offset);
    }

    return 0;
}

int bptree::insert(const key_type &key, value_type value) {
    off_t parent = __search_index(key);
    off_t offset = __search_leaf(parent, key);
    __leaf_node_t leaf;
    __map(&leaf, offset);

    // check if we have the same key
    if (binary_search(begin(leaf), end(leaf), key))
        return 1;

    if (leaf.n == _order) {
        // split when full

        // new sibling leaf
        __leaf_node_t new_leaf;
        __node_new(offset, &leaf, &new_leaf);

        // find even split point
        size_t point = leaf.n / 2;
        bool place_right = __key_compare(key, leaf.children[point].key) > 0;
        if (place_right)
            ++point;

        // split
        std::copy(leaf.children + point, leaf.children + leaf.n,
                  new_leaf.children);
        new_leaf.n = leaf.n - point;
        leaf.n = point;

        // which part do we put the key
        if (place_right)
            __insert_record_nonsplit(&new_leaf, key, value);
        else
            __insert_record_nonsplit(&leaf, key, value);

        // save leafs
        __unmap(&leaf, offset);
        __unmap(&new_leaf, leaf.next);

        // insert new index key
        __insert_key(parent, new_leaf.children[0].key, offset, leaf.next);
    } else {
        __insert_record_nonsplit(&leaf, key, value);
        __unmap(&leaf, offset);
    }

    return 0;
}

int bptree::update(const key_type &key, value_type value) {
    off_t offset = __search_leaf(key);
    __leaf_node_t leaf;
    __map(&leaf, offset);

    __record_t *record = find(leaf, key);
    if (record != leaf.children + leaf.n)
        if (__key_compare(key, record->key) == 0) {
            record->value = value;
            __unmap(&leaf, offset);

            return 0;
        } else {
            return 1;
        }
    else
        return -1;
}

void bptree::__erase_from_index(off_t offset, __internal_bnode_t &node,
                                const key_type &key) {
    size_t min_n = _root_offset == offset ? 1 : _order / 2;
    assert(node.n >= min_n && node.n <= _order);

    // remove key
    key_type index_key = begin(node)->key;
    __index_t *to_delete = find(node, key);
    if (to_delete != end(node)) {
        (to_delete + 1)->child = to_delete->child;
        std::copy(to_delete + 1, end(node), to_delete);
    }
    node.n--;

    // remove to only one key
    if (node.n == 1 && _root_offset == offset && _internal_cnt != 1) {
        __unalloc(&node, _root_offset);
        _height--;
        _root_offset = node.children[0].child;
        __unmap(&OFFSET_META);
        return;
    }

    // merge or borrow
    if (node.n < min_n) {
        __internal_bnode_t parent;
        __map(&parent, node.parent);

        // first borrow from left
        bool borrowed = false;
        if (offset != begin(parent)->child)
            borrowed = __borrow_key(false, node, offset);

        // then borrow from right
        if (!borrowed && offset != (end(parent) - 1)->child)
            borrowed = __borrow_key(true, node, offset);

        // finally we merge
        if (!borrowed) {
            assert(node.next != 0 || node.prev != 0);

            if (offset == (end(parent) - 1)->child) {
                // if leaf is last element then merge | prev | leaf |
                assert(node.prev != 0);
                __internal_bnode_t prev;
                __map(&prev, node.prev);

                // merge
                __index_t *where = find(parent, begin(prev)->key);
                __reset_index_cp(begin(node), end(node), node.prev);
                __merge_keys(where, prev, node, true);
                __unmap(&prev, node.prev);
            } else {
                // else merge | leaf | next |
                assert(node.next != 0);
                __internal_bnode_t next;
                __map(&next, node.next);

                // merge
                __index_t *where = find(parent, index_key);
                __reset_index_cp(begin(next), end(next), offset);
                __merge_keys(where, node, next);
                __unmap(&node, offset);
            }

            // remove parent's key
            __erase_from_index(node.parent, parent, index_key);
        } else {
            __unmap(&node, offset);
        }
    } else {
        __unmap(&node, offset);
    }
}

bool bptree::__borrow_key(bool from_right, __internal_bnode_t &borrower,
                          off_t offset) {
    typedef typename __internal_bnode_t::__child_t __child_t;

    off_t lender_off = from_right ? borrower.next : borrower.prev;
    __internal_bnode_t lender;
    __map(&lender, lender_off);

    assert(lender.n >= _order / 2);
    if (lender.n != _order / 2) {
        __child_t where_to_lend, where_to_put;

        __internal_bnode_t parent;

        // swap keys, draw on paper to see why
        if (from_right) {
            where_to_lend = begin(lender);
            where_to_put = end(borrower);

            __map(&parent, borrower.parent);
            __child_t where = lower_bound(begin(parent), end(parent) - 1,
                                          (end(borrower) - 1)->key);
            where->key = where_to_lend->key;
            __unmap(&parent, borrower.parent);
        } else {
            where_to_lend = end(lender) - 1;
            where_to_put = begin(borrower);

            __map(&parent, lender.parent);
            __child_t where = find(parent, begin(lender)->key);
            // where_to_put->key = where->key;  // We shouldn't change
            // where_to_put->key, because it just records the largest info but
            // we only changes a new one which have been the smallest one
            where->key = (where_to_lend - 1)->key;
            __unmap(&parent, lender.parent);
        }

        // store
        std::copy_backward(where_to_put, end(borrower), end(borrower) + 1);
        *where_to_put = *where_to_lend;
        borrower.n++;

        // erase
        __reset_index_cp(where_to_lend, where_to_lend + 1, offset);
        std::copy(where_to_lend + 1, end(lender), where_to_lend);
        lender.n--;
        __unmap(&lender, lender_off);
        return true;
    }

    return false;
}

bool bptree::__borrow_key(bool from_right, __leaf_node_t &borrower) {
    off_t lender_off = from_right ? borrower.next : borrower.prev;
    __leaf_node_t lender;
    __map(&lender, lender_off);

    assert(lender.n >= _order / 2);
    if (lender.n != _order / 2) {
        typename __leaf_node_t::__child_t where_to_lend, where_to_put;

        // decide offset and update parent's index key
        if (from_right) {
            where_to_lend = begin(lender);
            where_to_put = end(borrower);
            __alter_parent_child(borrower.parent, begin(borrower)->key,
                                 lender.children[1].key);
        } else {
            where_to_lend = end(lender) - 1;
            where_to_put = begin(borrower);
            __alter_parent_child(lender.parent, begin(lender)->key,
                                 where_to_lend->key);
        }

        // store
        std::copy_backward(where_to_put, end(borrower), end(borrower) + 1);
        *where_to_put = *where_to_lend;
        borrower.n++;

        // erase
        std::copy(where_to_lend + 1, end(lender), where_to_lend);
        lender.n--;
        __unmap(&lender, lender_off);
        return true;
    }

    return false;
}

void bptree::__alter_parent_child(off_t parent, const key_type &o,
                                  const key_type &n) {
    __internal_bnode_t node;
    __map(&node, parent);

    __index_t *w = find(node, o);
    assert(w != node.children + node.n);

    w->key = n;
    __unmap(&node, parent);
    if (w == node.children + node.n - 1) {
        __alter_parent_child(node.parent, o, n);
    }
}

void bptree::__merge_leaves(__leaf_node_t *left, __leaf_node_t *right) {
    std::copy(begin(*right), end(*right), end(*left));
    left->n += right->n;
}

void bptree::__merge_keys(__index_t *where, __internal_bnode_t &node,
                          __internal_bnode_t &next, bool change_where_key) {
    //(end(node) - 1)->key = where->key;
    if (change_where_key) {
        where->key = (end(next) - 1)->key;
    }
    std::copy(begin(next), end(next), end(node));
    node.n += next.n;
    __node_erase(&node, &next);
}

void bptree::__insert_record_nonsplit(__leaf_node_t *leaf, const key_type &key,
                                      const value_type &value) {
    __record_t *where = upper_bound(begin(*leaf), end(*leaf), key);
    std::copy_backward(where, end(*leaf), end(*leaf) + 1);

    where->key = key;
    where->value = value;
    leaf->n++;
}

void bptree::__insert_key(off_t offset, const key_type &key, off_t old,
                          off_t after) {
    if (offset == 0) {
        // create new root node
        __internal_bnode_t root;
        root.next = root.prev = root.parent = 0;
        _root_offset = __alloc(&root);
        _height++;

        // insert `old` and `after`
        root.n = 2;
        root.children[0].key = key;
        root.children[0].child = old;
        root.children[1].child = after;

        __unmap(&OFFSET_META);
        __unmap(&root, _root_offset);

        // update children's parent
        __reset_index_cp(begin(root), end(root), _root_offset);
        return;
    }

    __internal_bnode_t node;
    __map(&node, offset);
    assert(node.n <= _order);

    if (node.n == _order) {
        // split when full

        __internal_bnode_t new_node;
        __node_new(offset, &node, &new_node);

        // find even split point
        size_t point = (node.n - 1) / 2;
        bool place_right = __key_compare(key, node.children[point].key) > 0;
        if (place_right)
            ++point;

        // prevent the `key` being the right `middle_key`
        // example: insert 48 into |42|45| 6|  |
        if (place_right && __key_compare(key, node.children[point].key) < 0)
            point--;

        key_type middle_key = node.children[point].key;

        // split
        std::copy(begin(node) + point + 1, end(node), begin(new_node));
        new_node.n = node.n - point - 1;
        node.n = point + 1;

        // put the new key
        if (place_right)
            __insert_key_nonsplit(new_node, key, after);
        else
            __insert_key_nonsplit(node, key, after);

        __unmap(&node, offset);
        __unmap(&new_node, node.next);

        // update children's parent
        __reset_index_cp(begin(new_node), end(new_node), node.next);

        // give the middle key to the parent
        // note: middle key's child is reserved
        __insert_key(node.parent, middle_key, offset, node.next);
    } else {
        __insert_key_nonsplit(node, key, after);
        __unmap(&node, offset);
    }
}

void bptree::__insert_key_nonsplit(__internal_bnode_t &node,
                                   const key_type &key, off_t value) {
    __index_t *where = upper_bound(begin(node), end(node) - 1, key);

    // move later index forward
    std::copy_backward(where, end(node), end(node) + 1);

    // insert this key
    where->key = key;
    where->child = (where + 1)->child;
    (where + 1)->child = value;

    node.n++;
}

void bptree::__reset_index_cp(__index_t *begin, __index_t *end, off_t parent) {
    // this function can change both __internal_bnode_t and __leaf_node_t's
    // parent field, but we should ensure that:
    // 1. sizeof(__internal_bnode_t) <= sizeof(__leaf_node_t)
    // 2. parent field is placed in the beginning and have same size
    __internal_bnode_t node;
    while (begin != end) {
        __map(&node, begin->child);
        node.parent = parent;
        __unmap(&node, begin->child, SIZE_NO_CHILDREN);
        ++begin;
    }
}

off_t bptree::__search_index(const key_type &key) const {
    off_t org = _root_offset;
    int _height = _height;
    while (_height > 1) {
        __internal_bnode_t node;
        __map(&node, org);

        __index_t *i = upper_bound(begin(node), end(node) - 1, key);
        org = i->child;
        --_height;
    }

    return org;
}

off_t bptree::__search_leaf(off_t index, const key_type &key) const {
    __internal_bnode_t node;
    __map(&node, index);

    __index_t *i = upper_bound(begin(node), end(node) - 1, key);
    return i->child;
}

template <class _Tp>
void bptree::__node_new(off_t offset, _Tp *node, _Tp *next) {
    // new sibling node
    next->parent = node->parent;
    next->next = node->next;
    next->prev = offset;
    node->next = __alloc(next);
    // update next node's prev
    if (next->next != 0) {
        _Tp old_next;
        __map(&old_next, next->next, SIZE_NO_CHILDREN);
        old_next.prev = node->next;
        __unmap(&old_next, next->next, SIZE_NO_CHILDREN);
    }
    __unmap(&OFFSET_META);
}

template <class _Tp>
void bptree::__node_erase(_Tp *prev, _Tp *node) {
    __unalloc(node, prev->next);
    prev->next = node->next;
    if (node->next != 0) {
        _Tp next;
        __map(&next, node->next, SIZE_NO_CHILDREN);
        next.prev = node->prev;
        __unmap(&next, node->next, SIZE_NO_CHILDREN);
    }
    __unmap(&OFFSET_META);
}

void bptree::__init_from_empty() {
    // init default meta
    bzero(&sizeof(t));
    _order = BP_ORDER;
    _value_size = sizeof(value_type);
    _key_size = sizeof(key_type);
    _height = 1;
    _slot = OFFSET_BLOCK;

    // init root node
    __internal_bnode_t root;
    root.next = root.prev = root.parent = 0;
    _root_offset = __alloc(&root);

    // init empty leaf
    __leaf_node_t leaf;
    leaf.next = leaf.prev = 0;
    leaf.parent = _root_offset;
    _leaf_offset = root.children[0].child = __alloc(&leaf);

    // save
    __unmap(&OFFSET_META);
    __unmap(&root, _root_offset);
    __unmap(&leaf, root.children[0].child);
}

__END_NAMESPACE_BPT
