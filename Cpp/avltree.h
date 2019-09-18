// author - sonaspy@outlook.com
// coding - utf_8

#ifndef __AVLTREE__
#define __AVLTREE__

#include "bstree.h"
namespace dsa
{

template <typename T>
class avltree : public bstree<T>
{
public:
    void build(vector<T> &a)
    {
        for (auto i : a)
            insert(i);
        bintree<T>::__update_status();
    }
    void erase(const T &x)
    {
        __erase(this->_root, x);
        bintree<T>::__update_status();
        this->_size--;
    }
    void insert(const T &x)
    {
        // binode<T> *&w = this->search(x);
        // if (w)
        //     return false;
        // w = new binode<T>(x, this->_last);
        // this->_size++;
        // binode<T> *g = this->_last;
        // for (; g; g = g->parent)
        // {
        //     this->__updateheight(g);
        //     if (!nodeBalanced(g))
        //     {
        //         __rotate_zz(this->_root, g);
        //         break;
        //     }
        //     this->__updateheight(g);
        // }
        // this->__updateheightabove(g);
        // return true;
        __insert(this->_root, x, nullptr);
    }
    inline void clear() { bstree<T>::clear(); }
    ~avltree()
    {
        this->clear();
    }

protected:
    inline void _zig(binode<T> *&v)
    {
        binode<T> *y = v->lc;
        v->lc = y->rc;
        if (y->rc)
            y->rc->parent = v;
        y->rc = v;
        y->parent = v->parent;
        v->parent = y;
        bintree<T>::__updateheight(v);
        bintree<T>::__updateheight(y);
        v = y;
    }
    inline void _zag(binode<T> *&v)
    {
        binode<T> *y = v->rc;
        v->rc = y->lc;
        if (y->lc)
            y->lc->parent = v;
        y->lc = v;
        y->parent = v->parent;
        v->parent = y;
        bintree<T>::__updateheight(v);
        bintree<T>::__updateheight(y);
        v = y;
    }
    inline void _zigzag(binode<T> *&v)
    {
        _zag(v->lc);
        _zig(v);
    }
    inline void _zagzig(binode<T> *&v)
    {
        _zig(v->rc);
        _zag(v);
    }
    void __insert(binode<T> *&v, const T &x, binode<T> *p)
    {
        if (!v)
        {
            v = new binode<T>(x);
            v->parent = p;
            this->_size++;
            return;
        }
        else if (x < v->val)
        {
            __insert(v->lc, x, v);
            bintree<T>::__updateheight(v);
            if (_factor(v) == 2)
                _factor(v->lc) == 1 ? _zig(v) : _zigzag(v);
        }
        else if (x > v->val)
        {
            __insert(v->rc, x, v);
            bintree<T>::__updateheight(v);
            if (_factor(v) == -2)
                _factor(v->rc) == -1 ? _zag(v) : _zagzig(v);
        }
    }

    binode<T> *__erase(binode<T> *&v, const T &x)
    {
        if (!v)
            return nullptr;
        if (x < v->val)
        {
            v->lc = __erase(v->lc, x);
            bintree<T>::__updateheight(v);
            if (_factor(v) == -2)
                _factor(v->rc) == -1 ? _zag(v) : _zagzig(v);
        }
        else if (v->val < x)
        {
            v->rc = __erase(v->rc, x);
            bintree<T>::__updateheight(v);
            if (_factor(v) == 2)
                (_factor(v->lc) == 1) ? _zig(v) : _zigzag(v);
        }
        else // find it
        {
            binode<T> *tmp;
            if (v->rc && v->lc)
            {
                if (_factor(v) > 0)
                {
                    tmp = v->precessor();
                    v->val = tmp->val;
                    v->lc = __erase(v->lc, tmp->val);
                }
                else
                {
                    tmp = v->successor();
                    v->val = tmp->val;
                    v->rc = __erase(v->rc, tmp->val);
                }
            }
            else
            {
                tmp = v;
                v = v->lc ? v->lc : v->rc;
                __release(tmp);
            }
        }
        return v;
    }
};

} // namespace dsa
#endif