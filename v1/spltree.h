// author - sonaspy@outlook.com
// coding - utf_8
#ifndef __SPLAYTREE___
#define __SPLAYTREE___
__DST_BEGIN_NAMESPACE
template <class _Tp>
class spltree : public bstree<_Tp> {
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

    using bstree<_Tp>::__attAsL;
    using bstree<_Tp>::__attAsR;
    using bstree<_Tp>::__search;
    using bstree<_Tp>::_last;

    binode_ptr<_Tp> __splay(binode_ptr<_Tp> opnv) {
        if (!opnv) return nullptr;
        binode_ptr<_Tp> p, g, gg;
        while (1) {
            if (!opnv->parent) break;
            p = opnv->parent;
            if (!p->parent) break;
            g = p->parent;
            gg = g->parent;
            if (opnv->is_l()) {
                if (p->is_l())
                    __attAsL(g, p->rc), __attAsL(p, opnv->rc), __attAsR(p, g),
                        __attAsR(opnv, p);
                else
                    __attAsL(p, opnv->rc), __attAsR(g, opnv->lc),
                        __attAsL(opnv, g), __attAsR(opnv, p);
            } else if (p->is_r())
                __attAsR(g, p->lc), __attAsR(p, opnv->lc), __attAsL(p, g),
                    __attAsL(opnv, p);
            else
                __attAsR(p, opnv->lc), __attAsL(g, opnv->rc), __attAsR(opnv, g),
                    __attAsL(opnv, p);
            if (!gg)
                opnv->parent = nullptr;
            else
                g == gg->lc ? __attAsL(gg, opnv) : __attAsR(gg, opnv);
            bintree<_Tp>::__updateheight(g), bintree<_Tp>::__updateheight(p),
                bintree<_Tp>::__updateheight(opnv);
        }
        p = opnv->parent;
        if (p) {
            if (opnv->is_l())
                __attAsL(p, opnv->rc), __attAsR(opnv, p);
            else
                __attAsR(p, opnv->lc), __attAsL(opnv, p);
            bintree<_Tp>::__updateheight(p), bintree<_Tp>::__updateheight(opnv);
        }
        opnv->parent = nullptr;
        return opnv;
    }

   public:
    void build(vector<_Tp> &a) {
        for (auto data : a) insert(data);
        __update_status();
    }
    binode_ptr<_Tp> search(const _Tp &e) {
        _last = nullptr;
        binode_ptr<_Tp> p = __search(_root, e);
        _root = __splay(p ? p : _last);
        return _root;
    }
    bool insert(const _Tp &x) {
        if (!_root) {
            _root = __newbinode(x);
            return true;
        }
        binode_ptr<_Tp> w = search(x), t;
        if (w->val == x) return false;
        t = _root;
        if (_root->val < x) {
            t->parent = (_root = __newbinode(x, nullptr, t, t->rc));
            if (t->has_r()) {
                t->rc->parent = _root;
                t->rc = nullptr;
            }
        } else {
            t->parent = (_root = __newbinode(x, nullptr, t->lc, t));
            if (t->has_l()) {
                t->lc->parent = _root;
                t->lc = nullptr;
            }
        }
        __updateheightabove(t);
        return true;
    }

    bool erase(const _Tp &x) {
        if (!_root || (x != search(x)->val)) return 0;
        binode_ptr<_Tp> w = _root, t, lt;
        if (!(_root->has_l())) {
            _root = _root->rc;
            if (_root) _root->parent = nullptr;
        } else if (!(_root->has_r())) {
            _root = _root->lc;
            if (_root) _root->parent = nullptr;
        } else {
            lt = _root->lc;
            lt->parent = nullptr;
            _root->lc = nullptr;
            _root = _root->rc;
            _root->parent = nullptr;

            search(w->val);
            _root->lc = lt;
            lt->parent = _root;
        }
        __release(w);
        if (_root) bintree<_Tp>::__updateheight(_root);
        return true;
    }
};

__DST_END_NAMESPACE

#endif