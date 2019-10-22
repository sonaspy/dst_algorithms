// author - sonaspy@outlook.com
// coding - utf_8

#ifndef __RB_TREE__
#define __RB_TREE__

__DST_BEGIN_NAMESPACE

template <typename _Tp>
class rbtree : public avltree<_Tp>
{
protected:
#define is_blk(opnv) ((!(opnv) || (opnv)->color == BLK))
#define is_red(opnv) (!is_blk(opnv))
#define __setblk(opnv) (((opnv) ? (opnv->color = BLK) : 0))
#define __setred(opnv) (((opnv) ? (opnv->color = RED) : 0))
#define __rbcolor(opnv) (((opnv) ? (opnv->color) : BLK))
#define __downblk(opnv) (((opnv) ? (opnv->downblk) : 0))

    inline void __rotate_l(binode_ptr<_Tp> x)
    {
        binode_ptr<_Tp> y = x->rc;
        x->rc = y->lc;
        if (y->lc)
            y->lc->parent = x;
        y->parent = x->parent;
        x->isroot() ? this->_root = y : fromParent2(x) = y;
        y->lc = x;
        x->parent = y;
        this->__updateheight(x);
        this->__updateheight(y);
    }
    inline void __rotate_r(binode_ptr<_Tp> x)
    {
        binode_ptr<_Tp> y = x->lc;
        x->lc = y->rc;
        if (y->rc)
            y->rc->parent = x;
        y->parent = x->parent;
        x->isroot() ? this->_root = y : fromParent2(x) = y;
        y->rc = x;
        x->parent = y;
        this->__updateheight(x);
        this->__updateheight(y);
    }
    void __double_red_solution(binode_ptr<_Tp> opnv)
    {
        binode_ptr<_Tp> p, g, u;
        while ((p = opnv->parent) && is_red(p))
        {
            g = p->parent;
            u = opnv->uncle();
            if (u && is_red(u))
            {
                __setblk(u);
                __setblk(p);
                __setred(g);
                opnv = g;
                continue;
            }
            if (p->is_l() && opnv->is_r())
            {
                this->__rotate_l(p);
                swap(opnv, p);
            }
            else if (p->is_r() && opnv->is_l())
            {
                this->__rotate_r(p);
                swap(opnv, p);
            }
            __setblk(p);
            __setred(g);
            p->is_l() ? this->__rotate_r(g) : this->__rotate_l(g);
        }
        __setblk(this->_root);
    }
    void __double_blk_solution(binode_ptr<_Tp> pp, binode_ptr<_Tp> p)
    {
        while ((nullptr == p || BLK == p->color) && p != this->_root)
        {
            if (pp->lc == p)
            {
                auto s = pp->rc;
                if (s && RED == s->color)
                {
                    s->color = BLK;
                    pp->color = RED;
                    this->__rotate_l(pp);
                    s = pp->rc;
                }
                if ((nullptr == s->lc || BLK == s->lc->color) && (nullptr == s->rc || BLK == s->rc->color))
                {
                    s->color = RED;
                    p = pp;
                    pp = p->parent;
                }
                else
                {
                    if (nullptr == s->rc || BLK == s->rc->color)
                    {
                        s->lc ? s->lc->color = BLK : 0;
                        s->color = RED;
                        this->__rotate_r(s);
                        s = pp->rc;
                    }

                    s->color = pp->color;
                    pp->color = BLK;
                    s->rc->color = BLK;
                    this->__rotate_l(pp);
                    p = this->_root;
                }
            }
            else
            {
                auto s = pp->lc;
                if (s && RED == s->color)
                {
                    s->color = BLK;
                    pp->color = RED;
                    this->__rotate_r(pp);
                    s = pp->lc;
                }
                if ((nullptr == s->lc || BLK == s->lc->color) && (nullptr == s->rc || BLK == s->rc->color))
                {
                    s->color = RED;
                    p = pp;
                    pp = p->parent;
                }
                else
                {
                    if (nullptr == s->lc || BLK == s->lc->color)
                    {
                        s->rc ? s->rc->color = BLK : 0;
                        s->color = RED;
                        this->__rotate_l(s);
                        s = pp->lc;
                    }

                    s->color = pp->color;
                    pp->color = BLK;
                    s->lc->color = BLK;
                    this->__rotate_r(pp);
                    p = this->_root;
                }
            }
        }
        p->color = BLK;
    }
    void __isrbtree(binode_ptr<_Tp> opnv)
    {
        if (!opnv)
            return;
        __isrbtree(opnv->lc);
        __isrbtree(opnv->rc);
        if (opnv->color == RED && (__rbcolor(opnv->lc) == RED || __rbcolor(opnv->rc) == RED))
            this->_isRBtree = 0;
        if (__downblk(opnv->lc) != __downblk(opnv->rc))
            this->_isRBtree = 0;
        else
            opnv->downblk = opnv->color == BLK ? __downblk(opnv->lc) : __downblk(opnv->lc);
    }

public:
    rbtree()
    {
        this->_isRBtree = 1;
    }
    bool insert(const _Tp &x)
    {
        binode_ptr<_Tp> &w = this->search(x);
        if (w)
            return false;
        w = this->__newbinode(x, this->_last, nullptr, nullptr, RED);
        __double_red_solution(w);
        return true;
    }
    bool erase(const _Tp &val)
    {
        int thesize = this->_size - 1;
        binode_ptr<_Tp> &w = bstree<_Tp>::search(val);
        if (!w)
            return 0;
        binode_ptr<_Tp> p = w, pp = p->parent, _nil = nullptr;
        RBColor _del_color = p->color;
        int pp_child_tag = (!pp || pp->lc == p) ? 1 : 2;
        binode_ptr<_Tp> &ref_p = (pp ? (pp_child_tag == 1 ? pp->lc : pp->rc) : this->_root);
        if (p->lc && p->rc)
        {
            auto prev = p->lc, curr = prev;
            for (; curr && curr->rc; prev = curr, curr = curr->rc)
                ;
            _del_color = curr->color;
            p->val = curr->val;
            if (curr == prev)
            {
                p->lc = curr->lc;
                if (curr->lc)
                    curr->lc->parent = p;
                pp = p, p = p->lc;
                pp_child_tag = 1;
                this->__release(curr);
            }
            else
            {
                pp = prev;
                pp_child_tag = 2;
                p = prev->rc = curr->lc;
                if (curr->lc)
                    curr->lc->parent = prev;
                this->__release(curr);
            }
        }
        else if (p->lc)
        {
            ref_p = p->lc;
            p->lc->parent = pp;
            this->__release(p);
            p = ref_p;
        }
        else if (p->rc)
        {
            ref_p = p->rc;
            p->rc->parent = pp;
            this->__release(p);
            p = ref_p;
        }
        else
            p = ref_p = nullptr;
        if (BLK == _del_color && pp)
        {
            if (nullptr == p)
            {
                _nil = p = this->__newbinode();
                p->parent = pp;
                1 == pp_child_tag ? pp->lc = p : pp->rc = p;
            }
            __double_blk_solution(pp, p);
            if (_nil)
            {
                _nil->is_l() ? _nil->parent->lc = nullptr : _nil->parent->rc = nullptr;
                this->__release(_nil);
            }
        }
        this->_size = thesize;
        return 1;
    }
    bool isrbtree()
    {
        this->_isRBtree = 1;
        __isrbtree(this->_root);
        return this->_isRBtree && this->_root->color == BLK;
    }
    void build(vector<_Tp> &a)
    {
        for (auto &x : a)
            insert(x);
        bintree<_Tp>::__update_status();
    }
};


__DST_END_NAMESPACE


#endif