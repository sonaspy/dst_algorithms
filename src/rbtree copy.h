// author - sonaspy@outlook.com
// coding - utf_8

#ifndef __RB_TREE__
#define __RB_TREE__

#include "avltree.h"
namespace dsa
{

template <typename T>
class rbtree : public avltree<T>
{
    // in rbtree the memver 'height' is BLK height
protected:
#define _blk(opnv) ((!(opnv) || (opnv)->color == BLK))
#define _red(opnv) (!_blk(opnv))
#define __setblk(opnv) (((opnv) ? (opnv->color = BLK) : 0))
#define __setred(opnv) (((opnv) ? (opnv->color = RED) : 0))
#define rb_color(opnv) (((opnv) ? (opnv->color) : BLK))
#define _downblk(opnv) (((opnv) ? (opnv->downblk) : 0))

    inline void __rotate_l(binode_ptr<T> x)
    {
        binode_ptr<T> y = x->rc;
        x->rc = y->lc;
        if (!y)
            return;
        if (y->lc)
            y->lc->parent = x;
        y->parent = x->parent;
        x->isroot() ? (this->_root = y) : from_parent2(x) = y;
        y->lc = x;
        x->parent = y;
    }
    inline void __rotate_r(binode_ptr<T> x)
    {
        binode_ptr<T> y = x->lc;
        x->lc = y->rc;
        if (!y)
            return;
        if (y->rc)
            y->rc->parent = x;
        y->parent = x->parent;
        x->isroot() ? (this->_root = y) : from_parent2(x) = y;
        y->rc = x;
        x->parent = y;
    }
    binode_ptr<T> l_rotate(binode_ptr<T> p)
    {
        auto lr = p->rc;
        p->rc = lr->lc;
        if (lr->lc)
            lr->lc->parent = p;
        lr->parent = p->parent;
        if (nullptr == p->parent)
            this->_root = lr;
        else if (p->parent->lc == p)
            p->parent->lc = lr;
        else
            p->parent->rc = lr;
        lr->lc = p;
        p->parent = lr;
        return lr;
    }
    binode_ptr<T> r_rotate(binode_ptr<T> p)
    {
        auto lc = p->lc;
        p->lc = lc->rc;
        if (lc->rc)
            lc->rc->parent = p;
        lc->parent = p->parent;
        if (nullptr == p->parent)
            this->_root = lc;
        else if (p->parent->lc == p)
            p->parent->lc = lc;
        else
            p->parent->rc = lc;
        lc->rc = p;
        p->parent = lc;
        return lc;
    }
    void __double_red_solution(binode_ptr<T> opnv)
    {
        binode_ptr<T> p, g, u;
        while ((p = opnv->parent) && _red(p))
        {
            g = p->parent;
            u = opnv->uncle();
            if (u && _red(u))
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
    void __double_blk_solution(binode_ptr<T> pp, binode_ptr<T> p)
    {
    }
    void __isrbtree(binode_ptr<T> opnv)
    {
        if (!opnv)
            return;
        __isrbtree(opnv->lc);
        __isrbtree(opnv->rc);
        if (opnv->color == RED && (rb_color(opnv->lc) == RED || rb_color(opnv->rc) == RED))
            this->_isRBtree = 0;
        if (_downblk(opnv->lc) != _downblk(opnv->rc))
            this->_isRBtree = 0;
        else
            opnv->downblk = opnv->color == BLK ? _downblk(opnv->lc) : _downblk(opnv->lc);
    }

public:
    rbtree()
    {
        this->_isRBtree = 1;
    }
    bool insert(const T &x)
    {
        binode_ptr<T> &w = this->search(x);
        if (w)
            return false;
        w = new binode<T>(x, this->_last, nullptr, nullptr, RED);
        this->_size++;
        __double_red_solution(w);
        return true;
    }
    bool erase(const T &val)
    {
        binode_ptr<T> &w = bstree<T>::search(val);
        if (!w)
            return 0;
        binode_ptr<T> p = w, pp = p->parent, fake_null = nullptr;
        RBcolor delcolor = p->color;
        int pp_child_tag = (!pp || pp->lc == p) ? 1 : 2;
        binode_ptr<T> &ref_p = (pp ? (pp_child_tat == 1 ? pp->lc : pp->rc) : this->_root);
        if (p->lc && p->rc)
        {
            auto prev = p->lc, curr = prev;
            for (; curr && curr->rc; prev = curr, curr = curr->rc)
                ;
            delcolor = curr->color;
            p->val = curr->val;
            if (curr == prev)
            {
                p->lc = curr->lc;
                if (curr->lc)
                    curr->lc->parent = p;
                pp = p, p = p->lc;
                pp_child_tag = 1;
                delete curr;
            }
            else
            {
                pp = prev;
                pp_child_tag = 2;
                p = prev->rc = curr->lc;
                if (curr->lc)
                    curr->lc->parent = prev;
                delete curr;
            }
        }
        else if (p->lc)
        {
            ref_p = p->lc;
            p->lc->parent = pp;
            delete p;
            p = ref_p;
        }
        else if (p->rc)
        {
            ref_p = p->rc;
            p->rc->parent = pp;
            delete p;
            p = ref_p;
        }
        else
            p = ref_p = nullptr;
        if (BLK == delcolor && pp)
        {
            if (nullptr == p)
            {
                fake_null = p = new binode<T>();
                p->parent = pp;
                1 == pp_child_tag ? pp->lc = p : pp->rc = p;
            }
            __double_blk_solution(pp, p);
            if (fake_null)
            {
                fake_null->is_l() ? fake_null->parent->lc = nullptr : fake_null->parent->rc = nullptr;
                delete fake_null;
            }
        }
        return 1;
    }
    bool isrbtree()
    {
        this->_isRBtree = 1;
        __isrbtree(this->_root);
        return this->_isRBtree && this->_root->color == BLK;
    }
    void build(vector<T> &a)
    {
        for (auto &x : a)
            insert(x);
        bintree<T>::__update_status();
    }
};
} // namespace dsa
#endif