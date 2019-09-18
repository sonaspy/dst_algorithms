// author - sonaspy@outlook.com
// coding - utf_8

#ifndef __RED_BLK___
#define __RED_BLK___

#include "avltree.h"
namespace dsa
{

template <typename T>
class rbtree : public avltree<T>
{
    // in rbtree the memver 'height' is blk height
protected:
#define _blk(opnv) ((!(opnv) || (opnv)->color == blk))
#define _red(opnv) (!_blk(opnv))
    inline void __rotate_l(binode<T> *&root, binode<T> *x)
    {
        binode<T> *y = x->rc;
        x->rc = y->lc;
        if (y->lc)
            y->lc->parent = x;
        y->parent = x->parent;
        x->isroot() ? (root = y) : from_parent2(x) = y;
        y->lc = x;
        x->parent = y;
    }
    inline void __rotate_r(binode<T> *&root, binode<T> *x)
    {
        binode<T> *y = x->lc;
        x->lc = y->rc;
        if (y->rc)
            y->rc->parent = x;
        y->parent = x->parent;
        x->isroot() ? (root = y) : from_parent2(x) = y;
        y->rc = x;
        x->parent = y;
    }
    static inline void __alterheight(binode<T> *&opnv)
    {
        opnv->height = max(_height(opnv->lc), _height(opnv->rc));
        opnv->height += _blk(opnv) ? 1 : 0;
    }
    static inline bool _blk_altered(binode<T> *&opnv)
    {
        return _height(opnv->lc) == _height(opnv->rc) &&
                       opnv->height == _red(opnv)
                   ? _height(opnv->lc)
                   : _height(opnv->lc) + 1;
    }
    void __double_red_solution(binode<T> *x)
    {
        if (x->isroot())
        {
            this->_root->color = blk;
            this->_root->height++;
            return;
        }
        binode<T> *p = x->parent, *g, *u, *gg, *r;
        if (_blk(p))
            return;
        g = p->parent;
        u = x->uncle();
        if (_blk(u))
        {
            if (x->is_l() && p->is_l())
                p->color = blk;
            else
                x->color = blk;
            g->color = red;
            gg = g->parent;
            r = (from_parent2(g) = this->__rotate_at(x));
            r->parent = gg;
        }
        else
        {
            p->color = blk, p->height++;
            u->color = blk, u->height++;
            if (!g->isroot())
                g->color = red;
            __double_red_solution(g);
        }
    }
    void __double_blk_solution(binode<T> *x)
    {
    }

public:
    bool insert(const T &x)
    {
        binode<T> *&w = this->search(x);
        if (w)
            return false;
        w = new binode<T>(x, this->_last);
        this->_size++;
        //__double_red_solution(w);
        return true;
    }
    bool erase(const T &x)
    {
        binode<T> *&opnv = search(x);
        if (!opnv)
            return false;
        binode<T> *r = this->__erase_at(opnv, this->_last);
        if (--this->_size == 0)
            return true;
        if (!this->_last)
        {
            this->_root->color = blk;
            __alterheight(this->_root);
            return true;
        }
        if (_blk_altered(this->_last))
            return true;
        if (_red(r))
        {
            r->color = blk;
            r->height++;
            return true;
        }
        solveDoubleBlack(r);
        return true;
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