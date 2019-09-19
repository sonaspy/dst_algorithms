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
#define set_blk(opnv) (((opnv) ? (opnv->color = BLK) : 0))
#define set_red(opnv) (((opnv) ? (opnv->color = RED) : 0))
#define rb_color(opnv) (((opnv) ? (opnv->color) : BLK))
#define _downblk(opnv) (((opnv) ? (opnv->downblk) : 0))

    inline void __rotate_l(binode<T> *x)
    {
        binode<T> *y = x->rc;
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
    inline void __rotate_r(binode<T> *x)
    {
        binode<T> *y = x->lc;
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
    void __double_red_solution(binode<T> *opnv)
    {
        binode<T> *p, *g, *u;
        while ((p = opnv->parent) && _red(p))
        {
            g = p->parent;
            u = opnv->uncle();
            if (u && _red(u))
            {
                set_blk(u);
                set_blk(p);
                set_red(g);
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
            set_blk(p);
            set_red(g);
            p->is_l() ? this->__rotate_r(g) : this->__rotate_l(g);
        }
        set_blk(this->_root);
    }
    // _root  _last
    void __double_blk_solution(binode<T> *opnv, binode<T> *p)
    {
        binode<T> *oths;
    }
    void __isrbtree(binode<T> *opnv)
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
        binode<T> *&w = this->search(x);
        if (w)
            return false;
        w = new binode<T>(x, this->_last, nullptr, nullptr, RED);
        this->_size++;
        __double_red_solution(w);
        return true;
    }
    bool erase(const T &x)
    {
        bstree<T>::__erase(this->_root, x);
        return true;
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