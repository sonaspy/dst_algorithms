#ifndef __BTREE__
#define __BTREE__
#include <iostream>

__DST_BEGIN_NAMESPACE

template <class _Tp>
struct __bnode {
    typedef __bnode *__bnode_ptr;
    size_t sizeOfkey;
    bool isleaf;
    _Tp *keys;
    __bnode_ptr *children;
    __bnode() {
        sizeOfkey = 0;
        isleaf = true;
    }
    __bnode(size_t KMAX) {
        sizeOfkey = 0;
        isleaf = true;
        keys = new _Tp[KMAX];
        children = new __bnode *[KMAX + 1];
        fill(children, children + KMAX + 1, nullptr);
    }
    ~__bnode() {
        delete[] keys;
        delete[] children;
    }
    _Tp predecessor() {
        __bnode *x = this;
        off_t i = x->sizeOfkey;
        for (; !x->isleaf; x = x->children[i], i = x->sizeOfkey)
            ;
        return x->keys[i - 1];
    }
    _Tp successor() {
        __bnode *x = this;
        for (; !x->isleaf; x = x->children[0])
            ;
        return x->keys[0];
    }
};

template <class _Tp>
class btree {
  protected:
    typedef __bnode<_Tp> __base_node;
    typedef __base_node *__node_Ptr;

  public:
    btree();
    btree(size_t h_order);
    __node_Ptr search(__node_Ptr node, _Tp &val);

    bool insert(_Tp &val);
    bool erase(_Tp &val);

    void printPart(__node_Ptr node, size_t num);
    void printAll();

  protected:
    // insert function
    void __insert_general(__node_Ptr node, _Tp &val);
    void __split_children(__node_Ptr parentNode, off_t _offset);

    // erase function
    void __erase_general(__node_Ptr node, _Tp &val);
    void __mergechildren(__node_Ptr node, off_t i);
    void shift2rc(__node_Ptr x, off_t i, __node_Ptr y, __node_Ptr z);
    void shift2lc(__node_Ptr x, off_t i, __node_Ptr y, __node_Ptr z);

    // Common members
    __node_Ptr _root;
    size_t _half_order;
    size_t max_size_k;
    size_t min_size_k;
    size_t max_size_c;
    size_t min_size_c;
};

template <class _Tp>
btree<_Tp>::btree(size_t half_order) {
    _half_order = half_order;
    max_size_k = 2 * _half_order - 1;
    min_size_k = _half_order - 1;
    max_size_c = max_size_k + 1;
    min_size_c = min_size_k + 1;
    _root = nullptr;
}

template <class _Tp>
typename btree<_Tp>::__node_Ptr btree<_Tp>::search(__node_Ptr node, _Tp &val) {
    off_t i;
    for (; node != nullptr; node = node->children[i]) {
        for (i = 0; i < node->sizeOfkey && val > node->keys[i]; ++i)
            ;
        if (i < node->sizeOfkey && val == node->keys[i])
            return node;
        if (node->isleaf)
            return nullptr;
    }
    return nullptr;
}

template <class _Tp>
void btree<_Tp>::__split_children(__node_Ptr parentNode, off_t _offset) {
    __node_Ptr _right_c = new __bnode<_Tp>(max_size_k);
    __node_Ptr node2split = parentNode->children[_offset];

    _right_c->isleaf = node2split->isleaf;
    _right_c->sizeOfkey = min_size_k;

    copy(node2split->keys + min_size_k + 1, node2split->keys + max_size_k,
         _right_c->keys);

    if (!node2split->isleaf)
        copy(node2split->children + min_size_c,
             node2split->children + max_size_c, _right_c->children);

    node2split->sizeOfkey = min_size_k;

    copy_backward(parentNode->children + _offset + 1,
                  parentNode->children + parentNode->sizeOfkey + 1,
                  parentNode->children + parentNode->sizeOfkey + 2);

    parentNode->children[_offset + 1] = _right_c;

    copy_backward(parentNode->keys + _offset,
                  parentNode->keys + parentNode->sizeOfkey,
                  parentNode->keys + parentNode->sizeOfkey + 1);

    parentNode->keys[_offset] = node2split->keys[min_size_k];

    parentNode->sizeOfkey++;
}

template <class _Tp>
bool btree<_Tp>::insert(_Tp &val) {
    if (search(_root, val))
        return false;
    if (_root == nullptr)
        _root = new __bnode<_Tp>(max_size_k);
    if (_root->sizeOfkey == max_size_k) {
        __node_Ptr s = new __bnode<_Tp>(max_size_k);
        s->isleaf = false;
        s->children[0] = _root;
        __split_children(s, 0);
        _root = s;
    }
    __insert_general(_root, val);
    return true;
}

template <class _Tp>
void btree<_Tp>::__insert_general(__node_Ptr node, _Tp &val) {
    int i;
    for (; !node->isleaf; node = node->children[i]) {
        for (i = node->sizeOfkey - 1; - 1 < i && val < node->keys[i]; --i)
            ;
        i++;
        if (node->children[i]->sizeOfkey == max_size_k) {
            __split_children(node, i);
            if (val > node->keys[i])
                ++i;
        }
    }
    for (i = node->sizeOfkey - 1; - 1 < i && val < node->keys[i]; --i)
        node->keys[i + 1] = node->keys[i];
    node->keys[i + 1] = val;
    node->sizeOfkey++;
}

template <class _Tp>
void btree<_Tp>::printPart(__node_Ptr node, size_t num) {
    if (node != nullptr) {
        for (off_t i = 0; i < node->sizeOfkey; i++) {
            if (!node->isleaf)
                printPart(node->children[i], num + 5);

            for (off_t j = 0; j < num; j++)
                std::cout << "-";
            std::cout << node->keys[i] << endl;
        }
        if (!node->isleaf)
            printPart(node->children[node->sizeOfkey], num + 5);
    }
}

template <class _Tp>
void btree<_Tp>::printAll() {
    printPart(_root, 2);
}

template <class _Tp>
bool btree<_Tp>::erase(_Tp &val) {
    if (!search(_root, val))
        return false;
    if (_root->sizeOfkey == 1) {
        if (_root->isleaf) {
            delete _root;
            _root = nullptr;
            return true;
        } else {
            __node_Ptr lc = _root->children[0];
            __node_Ptr rc = _root->children[1];
            if (lc->sizeOfkey == min_size_k && rc->sizeOfkey == min_size_k) {
                __mergechildren(_root, 0);
                delete _root;
                _root = lc;
            }
        }
    }
    __erase_general(_root, val);
    return true;
}

template <class _Tp>
void btree<_Tp>::__erase_general(__node_Ptr node, _Tp &val) {
    off_t i = 0;
    if (node->isleaf) {
        for (; i < node->sizeOfkey && val > node->keys[i]; ++i)
            ;
        if (node->keys[i] == val) {
            for (off_t j = i; j < node->sizeOfkey - 1; j++)
                node->keys[j] = node->keys[j + 1];
            node->sizeOfkey--;
        }
    } else {
        __node_Ptr rc = nullptr;
        __node_Ptr p = nullptr;

        for (; i < node->sizeOfkey && val > node->keys[i]; ++i)
            ;
        __node_Ptr lc = node->children[i];

        if (i < node->sizeOfkey)
            rc = node->children[i + 1];

        if (node->keys[i] == val) {
            if (lc->sizeOfkey > min_size_k) {
                _Tp k1 = lc->predecessor();
                __erase_general(lc, k1);
                node->keys[i] = k1;
            } else if (rc->sizeOfkey > min_size_k) {
                _Tp k1 = rc->successor();
                __erase_general(rc, k1);
                node->keys[i] = k1;
            } else {
                __mergechildren(node, i);
                __erase_general(lc, val);
            }
        } else {
            if (i > 0)
                p = node->children[i - 1];
            if (lc->sizeOfkey == min_size_k) {
                if (i > 0 && p->sizeOfkey > min_size_k) {
                    shift2rc(node, i - 1, p, lc);
                } else if (i < node->sizeOfkey && rc->sizeOfkey > min_size_k) {
                    shift2lc(node, i, lc, rc);
                } else if (i > 0) {
                    __mergechildren(node, i - 1);
                    lc = p;
                } else {
                    __mergechildren(node, i);
                }
            }
            __erase_general(lc, val);
        }
    }
}

template <class _Tp>
void btree<_Tp>::__mergechildren(__node_Ptr node, off_t i) {
    __node_Ptr lc = node->children[i];
    __node_Ptr rc = node->children[i + 1];
    lc->sizeOfkey = max_size_k;
    lc->keys[min_size_k] = node->keys[i];
    for (off_t j = min_size_k + 1; j < max_size_k; j++)
        lc->keys[j] = rc->keys[j - (min_size_k + 1)];

    if (!lc->isleaf) {
        for (off_t j = min_size_c; j < max_size_c; j++)
            lc->children[j] = rc->children[j - min_size_c];
    }
    for (off_t j = i + 1; j < node->sizeOfkey; j++) {
        node->keys[j - 1] = node->keys[j];
        node->children[j] = node->children[j + 1];
    }
    node->sizeOfkey--;
}

template <class _Tp>
void btree<_Tp>::shift2rc(__node_Ptr x, off_t i, __node_Ptr y, __node_Ptr z) {
    z->sizeOfkey++;
    int j;
    for (j = z->sizeOfkey - 1; j > 0; --j)
        z->keys[j] = z->keys[j - 1];

    z->keys[0] = x->keys[i];
    x->keys[i] = y->keys[y->sizeOfkey - 1];
    if (!z->isleaf) {
        for (j = z->sizeOfkey - 1; j > -1; --j)
            z->children[j + 1] = z->children[j];
        z->children[0] = y->children[y->sizeOfkey];
    }
    y->sizeOfkey--;
}

template <class _Tp>
void btree<_Tp>::shift2lc(__node_Ptr x, off_t i, __node_Ptr y, __node_Ptr z) {
    y->sizeOfkey++;
    y->keys[y->sizeOfkey - 1] = x->keys[i];
    x->keys[i] = z->keys[0];
    z->sizeOfkey--;

    off_t j;
    for (j = 0; j < z->sizeOfkey; ++j)
        z->keys[j] = z->keys[j + 1];

    if (!z->isleaf) {
        y->children[y->sizeOfkey] = z->children[0];
        for (j = 0; j <= z->sizeOfkey; ++j)
            z->children[j] = z->children[j + 1];
    }
}

__DST_END_NAMESPACE

#endif