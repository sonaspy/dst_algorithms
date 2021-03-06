// author - sonaspy@outlook.com
// coding - utf_8

#ifndef __BSTREE__
#define __BSTREE__

__DST_BEGIN_NAMESPACE

template <typename _Tp>
class bstree : public bintree<_Tp> {
   protected:
    typedef bintree<_Tp> __base;
    using __base::__newbinode;
    using __base::__release;
    using __base::__update_status;
    using __base::__updateheight;
    using __base::__updateheightabove;
    using __base::_root;
    using __base::_size;
    using __base::clear;

    binode_ptr<_Tp> _last;

    inline void __attAsL(binode_ptr<_Tp> &p, binode_ptr<_Tp> &lc) {
        p->lc = lc;
        if (lc) lc->parent = p;
    }
    inline void __attAsR(binode_ptr<_Tp> &p, binode_ptr<_Tp> &rc) {
        p->rc = rc;
        if (rc) rc->parent = p;
    }
    bool __judge_avl(binode_ptr<_Tp> opnv, binode_ptr<_Tp> p) {
        if (!opnv) return true;
        bool f = __judge_avl(opnv->lc, p) && avlnodebalanced(opnv) &&
                 (!p || p->val < opnv->val);
        p = opnv;
        return f && __judge_avl(opnv->rc, p);
    }
    binode_ptr<_Tp> &__search(binode_ptr<_Tp> &opnv, const _Tp &x) {
        if (!opnv || x == opnv->val) return opnv;
        _last = opnv;
        return __search(x < opnv->val ? opnv->lc : opnv->rc, x);
    }

    binode_ptr<_Tp> __erase(binode_ptr<_Tp> &opnv, const _Tp &x) {
        if (!opnv) return nullptr;
        if (x < opnv->val)
            opnv->lc = __erase(opnv->lc, x);
        else if (opnv->val < x)
            opnv->rc = __erase(opnv->rc, x);
        else {
            binode_ptr<_Tp> tmp;
            if (opnv->lc && opnv->rc) {
                tmp = opnv->successor();
                opnv->val = tmp->val;
                opnv->rc = __erase(opnv->rc, tmp->val);
            } else {
                tmp = opnv;
                opnv = opnv->lc ? opnv->lc : opnv->rc;
                __release(tmp);
            }
        }
        return opnv;
    }

   public:
    ~bstree() { clear(); }
    void build(vector<_Tp> &a) {
        for (auto &i : a) insert(i);
        __update_status();
    }
    bool avlbalanced() {
        binode_ptr<_Tp> p = nullptr;
        return __judge_avl(_root, p);
    }
    bool erase(const _Tp &x) {
        if (__erase(_root, x)) {
            _size--;
            return true;
        }
        return false;
    }
    bool insert(const _Tp &x) {
        binode_ptr<_Tp> &w = search(x);
        if (w) return false;
        _size++;
        w = __newbinode(x, _last);
        __updateheightabove(w);
        return true;
    }
    binode_ptr<_Tp> &search(const _Tp &x) {
        _last = nullptr;
        return __search(_root, x);
    }
    bool count(const _Tp &x) { return search(x) != nullptr; }
    inline void clear() {
        bintree<_Tp>::clear();
        _last = nullptr;
    }
    binode_ptr<_Tp> get_lca(const _Tp &v1, const _Tp &v2) {
        binode_ptr<_Tp> _walk = _root;
        while (_walk) {
            if (v1 < _walk->val && v2 < _walk->val)
                _walk = _walk->lc;
            else if (_walk->val < v1 && _walk->val < v2)
                _walk = _walk->rc;
            else
                break;
        }
        return _walk;
    }

    // class iterator
    class iterator {
       public:
        // typedefs required by C++ for a forward iterator
        typedef _Tp value_type;
        typedef _Tp *pointer;
        typedef _Tp &reference;
        // constructor
        iterator(binode_ptr<_Tp> theNode = nullptr) { _node = theNode; }
        // dereferencing operators
        _Tp &operator*() const { return *_node; }
        binode_ptr<_Tp> operator->() const { return _node; }
        // pre increment
        iterator &operator++() {
            binode_ptr<_Tp> p = _node->successor();
            if (p)
                _node = p;
            else {
                p = _node->parent;
                while (p && p->val < _node->val) p = p->parent;
                _node = p;
            }
            return *this;
        }
        // post increment
        iterator operator++(int) {
            iterator _old = *this;
            ++(*this);
            return _old;
        }
        // pre subtract
        iterator &operator--() {
            binode_ptr<_Tp> p = _node->precessor();
            if (p)
                _node = p;
            else {
                p = _node->parent;
                while (p && p->val > _node->val) p = p->parent;
                _node = p;
            }
            return *this;
        }
        // post subtract
        iterator operator--(int) {
            iterator _old = *this;
            --(*this);
            return _old;
        }

        // equality testing
        bool operator!=(const iterator &_right) const {
            return _node != _right._node;
        }
        bool operator==(const iterator &_right) const {
            return _node == _right._node;
        }

       protected:
        binode_ptr<_Tp> _node;
    };
    // end of iterator class

    iterator begin() {
        binode_ptr<_Tp> p = _root->leftest();
        iterator it(p);
        return it;
    }
    iterator end() {
        binode_ptr<_Tp> p = _root->rightest();
        iterator it(p);
        return it;
    }
};

__DST_END_NAMESPACE

#endif