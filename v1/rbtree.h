// author - sonaspy@outlook.com
// coding - utf_8

#ifndef __RB_TREE__
#define __RB_TREE__

__DST_BEGIN_NAMESPACE

template <typename _Tp>
class rbtree : public bstree<_Tp> {
   protected:
#define is_blk(opnv) ((!(opnv) || (opnv)->color == BLK))
#define is_red(opnv) (!is_blk(opnv))
#define __setblk(opnv) (((opnv) ? (opnv->color = BLK) : 0))
#define __setred(opnv) (((opnv) ? (opnv->color = RED) : 0))
#define __rbcolor(opnv) (((opnv) ? (opnv->color) : BLK))
#define __downblk(opnv) (((opnv) ? (opnv->downblk) : 0))

    typedef bintree<_Tp> __base;
    using __base::__newbinode;
    using __base::__release;
    using __base::__update_status;
    using __base::__updateheight;
    using __base::__updateheightabove;
    using __base::_isRBtree;
    using __base::_root;
    using __base::_size;
    using __base::clear;

    using bstree<_Tp>::search;
    using bstree<_Tp>::_last;

    inline void __rotate_l(binode_ptr<_Tp> x) {
        binode_ptr<_Tp> y = x->rc;
        x->rc = y->lc;
        if (y->lc) y->lc->parent = x;
        y->parent = x->parent;
        x->isroot() ? _root = y : fromParent2(x) = y;
        y->lc = x;
        x->parent = y;
        __updateheight(x);
        __updateheight(y);
    }
    inline void __rotate_r(binode_ptr<_Tp> x) {
        binode_ptr<_Tp> y = x->lc;
        x->lc = y->rc;
        if (y->rc) y->rc->parent = x;
        y->parent = x->parent;
        x->isroot() ? _root = y : fromParent2(x) = y;
        y->rc = x;
        x->parent = y;
        __updateheight(x);
        __updateheight(y);
    }
    void __double_red_solution(binode_ptr<_Tp> opnv) {
        binode_ptr<_Tp> p, g, u;
        while ((p = opnv->parent) && is_red(p)) {
            g = p->parent;
            u = opnv->uncle();
            if (u && is_red(u)) {
                __setblk(u);
                __setblk(p);
                __setred(g);
                opnv = g;
                continue;
            }
            if (p->is_l() && opnv->is_r()) {
                __rotate_l(p);
                swap(opnv, p);
            } else if (p->is_r() && opnv->is_l()) {
                __rotate_r(p);
                swap(opnv, p);
            }
            __setblk(p);
            __setred(g);
            p->is_l() ? __rotate_r(g) : __rotate_l(g);
        }
        __setblk(_root);
    }
    void __double_blk_solution(binode_ptr<_Tp> pp, binode_ptr<_Tp> p) {
        while ((nullptr == p || BLK == p->color) && p != _root) {
            if (pp->lc == p) {
                auto s = pp->rc;
                if (s && RED == s->color) {
                    s->color = BLK;
                    pp->color = RED;
                    __rotate_l(pp);
                    s = pp->rc;
                }
                if ((nullptr == s->lc || BLK == s->lc->color) &&
                    (nullptr == s->rc || BLK == s->rc->color)) {
                    s->color = RED;
                    p = pp;
                    pp = p->parent;
                } else {
                    if (nullptr == s->rc || BLK == s->rc->color) {
                        s->lc ? s->lc->color = BLK : 0;
                        s->color = RED;
                        __rotate_r(s);
                        s = pp->rc;
                    }

                    s->color = pp->color;
                    pp->color = BLK;
                    s->rc->color = BLK;
                    __rotate_l(pp);
                    p = _root;
                }
            } else {
                auto s = pp->lc;
                if (s && RED == s->color) {
                    s->color = BLK;
                    pp->color = RED;
                    __rotate_r(pp);
                    s = pp->lc;
                }
                if ((nullptr == s->lc || BLK == s->lc->color) &&
                    (nullptr == s->rc || BLK == s->rc->color)) {
                    s->color = RED;
                    p = pp;
                    pp = p->parent;
                } else {
                    if (nullptr == s->lc || BLK == s->lc->color) {
                        s->rc ? s->rc->color = BLK : 0;
                        s->color = RED;
                        __rotate_l(s);
                        s = pp->lc;
                    }

                    s->color = pp->color;
                    pp->color = BLK;
                    s->lc->color = BLK;
                    __rotate_r(pp);
                    p = _root;
                }
            }
        }
        p->color = BLK;
    }
    void __isrbtree(binode_ptr<_Tp> opnv) {
        if (!opnv) return;
        __isrbtree(opnv->lc);
        __isrbtree(opnv->rc);
        if (opnv->color == RED &&
            (__rbcolor(opnv->lc) == RED || __rbcolor(opnv->rc) == RED))
            _isRBtree = 0;
        if (__downblk(opnv->lc) != __downblk(opnv->rc))
            _isRBtree = 0;
        else
            opnv->downblk =
                opnv->color == BLK ? __downblk(opnv->lc) : __downblk(opnv->lc);
    }

   public:
    rbtree() { _isRBtree = 1; }
    bool insert(const _Tp &x) {
        binode_ptr<_Tp> &w = search(x);
        if (w) return false;
        w = __newbinode(x, _last, nullptr, nullptr, RED);
        __double_red_solution(w);
        return true;
    }
    bool erase(const _Tp &val) {
        int thesize = _size - 1;
        binode_ptr<_Tp> &w = bstree<_Tp>::search(val);
        if (!w) return 0;
        binode_ptr<_Tp> p = w, pp = p->parent, _nil = nullptr;
        RBColor _del_color = p->color;
        int pp_child_tag = (!pp || pp->lc == p) ? 1 : 2;
        binode_ptr<_Tp> &ref_p =
            (pp ? (pp_child_tag == 1 ? pp->lc : pp->rc) : _root);
        if (p->lc && p->rc) {
            auto prev = p->lc, curr = prev;
            for (; curr && curr->rc; prev = curr, curr = curr->rc)
                ;
            _del_color = curr->color;
            p->val = curr->val;
            if (curr == prev) {
                p->lc = curr->lc;
                if (curr->lc) curr->lc->parent = p;
                pp = p, p = p->lc;
                pp_child_tag = 1;
                __release(curr);
            } else {
                pp = prev;
                pp_child_tag = 2;
                p = prev->rc = curr->lc;
                if (curr->lc) curr->lc->parent = prev;
                __release(curr);
            }
        } else if (p->lc) {
            ref_p = p->lc;
            p->lc->parent = pp;
            __release(p);
            p = ref_p;
        } else if (p->rc) {
            ref_p = p->rc;
            p->rc->parent = pp;
            __release(p);
            p = ref_p;
        } else
            p = ref_p = nullptr;
        if (BLK == _del_color && pp) {
            if (nullptr == p) {
                _nil = p = __newbinode();
                p->parent = pp;
                1 == pp_child_tag ? pp->lc = p : pp->rc = p;
            }
            __double_blk_solution(pp, p);
            if (_nil) {
                _nil->is_l() ? _nil->parent->lc = nullptr
                             : _nil->parent->rc = nullptr;
                __release(_nil);
            }
        }
        _size = thesize;
        return 1;
    }
    bool isrbtree() {
        _isRBtree = 1;
        __isrbtree(_root);
        return _isRBtree && _root->color == BLK;
    }
    void build(vector<_Tp> &a) {
        for (auto &x : a) insert(x);
        __update_status();
    }
};

__DST_END_NAMESPACE

#endif