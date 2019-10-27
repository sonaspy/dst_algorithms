#ifndef BPT_H
#define BPT_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#ifndef UNIT_TEST
#include "predefined.h"
#else
#include "util/unit_test_predefined.h"
#endif

__BEGIN_NAMESPACE_BPT

/* offsets */
#define OFFSET_META 0
#define OFFSET_BLOCK OFFSET_META + sizeof(meta_t)
#define SIZE_NO_CHILDREN sizeof(__leaf_node_t) - BP_ORDER * sizeof(__record_t)

/* internal nodes' index segment */
struct __index_t {
    key_type key;
    off_t child; /* child's offset */
};

struct __internal_bnode_t {
    typedef __index_t *__child_t;

    off_t parent; /* parent node offset */
    off_t next;
    off_t prev;
    size_t n; /* how many children */
    __index_t children[BP_ORDER];
};

/* the final record of value */
struct __record_t {
    key_type key;
    value_type value;
};

/* leaf node block */
struct __leaf_node_t {
    typedef __record_t *__child_t;

    off_t parent; /* parent node offset */
    off_t next;
    off_t prev;
    size_t n;
    __record_t children[BP_ORDER];
};

/* the encapulated B+ tree */
class bptree {
  public:
    bptree(const char *path, bool force_empty = false);

    /* abstract operations */
    int search(const key_type &key, value_type *value) const;
    int search_range(key_type *left, const key_type &right, value_type *values,
                     size_t max, bool *next = nullptr) const;
    int remove(const key_type &key);
    int insert(const key_type &key, value_type value);
    int update(const key_type &key, value_type value);

#ifndef UNIT_TEST
  protected:
#else
  public:
#endif
    char path[512];
    size_t _order;        /* `_order` of B+ tree */
    size_t _value_size;   /* size of value */
    size_t _key_size;     /* size of key */
    size_t _internal_cnt; /* how many internal nodes */
    size_t _leaf_cnt;     /* how many leafs */
    size_t _height;       /* _height of tree (exclude leafs) */
    off_t _slot;          /* where to store new block */
    off_t _root_offset;   /* where is the root of internal nodes */
    off_t _leaf_offset;   /* where is the first leaf */

    /* init empty tree */
    void __init_from_empty();

    /* find index */
    off_t __search_index(const key_type &key) const;

    /* find leaf */
    off_t __search_leaf(off_t index, const key_type &key) const;
    off_t __search_leaf(const key_type &key) const {
        return __search_leaf(__search_index(key), key);
    }

    /* remove internal node */
    void __erase_from_index(off_t offset, __internal_bnode_t &node,
                            const key_type &key);

    /* borrow one key from other internal node */
    bool __borrow_key(bool from_right, __internal_bnode_t &borrower,
                      off_t offset);

    /* borrow one record from other leaf */
    bool __borrow_key(bool from_right, __leaf_node_t &borrower);

    /* change one's parent key to another key */
    void __alter_parent_child(off_t parent, const key_type &o,
                              const key_type &n);

    /* merge right leaf to left leaf */
    void __merge_leaves(__leaf_node_t *left, __leaf_node_t *right);

    void __merge_keys(__index_t *where, __internal_bnode_t &left,
                      __internal_bnode_t &right, bool change_where_key = false);

    /* insert into leaf without split */
    void __insert_record_nonsplit(__leaf_node_t *leaf, const key_type &key,
                                  const value_type &value);

    /* add key to the internal node */
    void __insert_key(off_t offset, const key_type &key, off_t value,
                      off_t after);
    void __insert_key_nonsplit(__internal_bnode_t &node, const key_type &key,
                               off_t value);

    /* change children's parent */
    void __reset_index_cp(__index_t *begin, __index_t *end, off_t parent);

    template <class _Tp>
    void __node_new(off_t offset, _Tp *node, _Tp *next);

    template <class _Tp>
    void __node_erase(_Tp *prev, _Tp *node);

    /* multi-level file open/close */
    mutable FILE *_file_ptr;
    mutable int fp_level;
    void __open_file(const char *mode = "rb+") const {
        // `rb+` will make sure we can write everywhere without truncating file
        if (fp_level == 0)
            _file_ptr = fopen(path, mode);

        ++fp_level;
    }

    void __close_file() const {
        if (fp_level == 1)
            fclose(_file_ptr);

        --fp_level;
    }

    /* __alloc from disk */
    off_t __alloc(size_t size) {
        off_t slot = _slot;
        slot += size;
        return slot;
    }

    off_t __alloc(__leaf_node_t *leaf) {
        leaf->n = 0;
        _leaf_cnt++;
        return __alloc(sizeof(__leaf_node_t));
    }

    off_t __alloc(__internal_bnode_t *node) {
        node->n = 1;
        _internal_cnt++;
        return __alloc(sizeof(__internal_bnode_t));
    }

    void __unalloc(__leaf_node_t *leaf, off_t offset) { --_leaf_cnt; }

    void __unalloc(__internal_bnode_t *node, off_t offset) { --_internal_cnt; }

    /* read block from disk */
    int __map(void *block, off_t offset, size_t size) const {
        __open_file();
        fseek(_file_ptr, offset, SEEK_SET);
        size_t rd = fread(block, size, 1, _file_ptr);
        __close_file();

        return rd - 1;
    }

    template <class _Tp>
    int __map(_Tp *block, off_t offset) const {
        return __map(block, offset, sizeof(_Tp));
    }

    /* write block to disk */
    int __unmap(void *block, off_t offset, size_t size) const {
        __open_file();
        fseek(_file_ptr, offset, SEEK_SET);
        size_t wd = fwrite(block, size, 1, _file_ptr);
        __close_file();

        return wd - 1;
    }

    template <class _Tp>
    int __unmap(_Tp *block, off_t offset) const {
        return __unmap(block, offset, sizeof(_Tp));
    }
};

__END_NAMESPACE_BPT

#endif /* end of BPT_H */
