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
    // in rbtree the memver 'height' is blk height
protected:
#define _blk(opnv) ((!(opnv) || (opnv)->color == blk))
#define _red(opnv) (!_blk(opnv))
#define set_blk(opnv) (((opnv) ? (opnv->color = blk) : 0))
#define set_red(opnv) (((opnv) ? (opnv->color = red) : 0))
#define rb_color(opnv) (((opnv) ? (opnv->color) : blk))
#define _downblk(opnv) (((opnv) ? (opnv->downblk) : 0))
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
                this->__rotate_right(p);
                swap(opnv, p);
            }
            else if (p->is_r() && opnv->is_l())
            {
                this->__rotate_left(p);
                swap(opnv, p);
            }
            set_blk(p);
            set_red(g);
            p->is_l() ? this->__rotate_left(g) : this->__rotate_right(g);
        }
        set_blk(this->_root);
    }
    // _root  _last
    void __double_blk_solution(binode<T> *opnv, binode<T> *p)
    {
        binode<T> *oths;

        while ((!opnv || _blk(opnv)) && opnv != this->_root)
        {
            if (p->lc == opnv)
            {
                oths = p->rc;
                if (_red(oths))
                {
                    set_blk(oths);
                    set_red(p);
                    this->__rotate_right(p);
                    oths = p->rc;
                }
                if ((!oths->lc || _blk(oths->lc)) &&
                    (!oths->rc || _blk(oths->rc)))
                {
                    set_red(oths);
                    opnv = p;
                    p = opnv->parent;
                }
                else
                {
                    if (!oths->rc || _blk(oths->rc))
                    {
                        set_blk(oths->lc);
                        set_red(oths);
                        this->__rotate_left(oths);
                        oths = p->rc;
                    }
                    oths->color = rb_color(p);
                    set_blk(p);
                    set_blk(oths->rc);
                    this->__rotate_right(p);
                    opnv = this->_root;
                    break;
                }
            }
            else
            {
                oths = p->lc;
                if (_red(oths))
                {
                    set_blk(oths);
                    set_red(p);
                    this->__rotate_left(p);
                    oths = p->lc;
                }
                if ((!oths->lc || _blk(oths->lc)) &&
                    (!oths->rc || _blk(oths->rc)))
                {
                    set_red(oths);
                    opnv = p;
                    p = opnv->parent;
                }
                else
                {
                    if (!oths->lc || _blk(oths->lc))
                    {
                        set_blk(oths->rc);
                        set_red(oths);
                        this->__rotate_right(oths);
                        oths = p->lc;
                    }
                    oths->color = rb_color(p);
                    set_blk(p);
                    set_blk(oths->lc);
                    this->__rotate_left(p);
                    opnv = this->_root;
                    break;
                }
            }
        }
        if (opnv)
            set_blk(opnv);
    }
    void __isrbtree(binode<T> *opnv)
    {
        if (!opnv)
            return;
        __isrbtree(opnv->lc);
        __isrbtree(opnv->rc);
        if (opnv->color == red && (rb_color(opnv->lc) == red || rb_color(opnv->rc) == red))
            this->_isRBtree = 0;
        if (_downblk(opnv->lc) != _downblk(opnv->rc))
            this->_isRBtree = 0;
        else
            opnv->downblk = opnv->color == blk ? _downblk(opnv->lc) : _downblk(opnv->lc);
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
        w = new binode<T>(x, this->_last, nullptr, nullptr, red);
        this->_size++;
        __double_red_solution(w);
        return true;
    }
    bool erase(const T &x)
    {
        binode<T> *&opnv = this->search(x);
        if (!opnv)
            return false;
        binode<T> *s = opnv->successor();
        RBColor col = s ? s->color : blk;
        binode<T> *r = this->__erase_at(opnv, this->_last);
        if (col == blk)
            __double_blk_solution(r, this->_last);
        return true;
    }
    bool isrbtree()
    {
        this->_isRBtree = 1;
        __isrbtree(this->_root);
        return this->_isRBtree && this->_root->color == blk;
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