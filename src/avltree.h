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
        if (bstree<T>::search(x) == nullptr)
            return;
        __erase(this->_root, x);
        this->_size--;
    }
    void insert(const T &x)
    {
        if (bstree<T>::search(x) != nullptr)
            return;
        __insert(this->_root, x);
    }
    inline void clear() { bstree<T>::clear(); }
    ~avltree()
    {
        this->clear();
    }

protected:
    inline void _zig(binode_ptr<T> &v)
    {
        binode_ptr<T> y = v->lc;
        v->lc = y->rc;
        y->rc = v;
        bintree<T>::__updateheight(v);
        bintree<T>::__updateheight(y);
        v = y;
    }
    inline void _zag(binode_ptr<T> &v)
    {
        binode_ptr<T> y = v->rc;
        v->rc = y->lc;
        y->lc = v;
        bintree<T>::__updateheight(v);
        bintree<T>::__updateheight(y);
        v = y;
    }
    inline void _zigzag(binode_ptr<T> &v)
    {
        _zag(v->lc);
        _zig(v);
    }
    inline void _zagzig(binode_ptr<T> &v)
    {
        _zig(v->rc);
        _zag(v);
    }
    void __insert(binode_ptr<T> &v, const T &x)
    {
        if (!v)
        {
            v = this->__newbinode(x);
            this->_size++;
            return;
        }
        else if (x < v->val)
        {
            __insert(v->lc, x);
            if (_factor(v) == 2)
                x < v->lc->val ? _zig(v) : _zigzag(v);
        }
        else if (x > v->val)
        {
            __insert(v->rc, x);
            if (_factor(v) == -2)
                x > v->rc->val ? _zag(v) : _zagzig(v);
        }
        bintree<T>::__updateheight(v);
    }

    void __erase(binode_ptr<T> &v, const T x)
    {
        if (x == v->val)
        {
            if (v->lc && v->rc)
            {
                if (_factor(v) >= 0)
                {
                    v->val = v->precessor()->val;
                    __erase(v->lc, v->val);
                }
                else
                {
                    v->val = v->successor()->val;
                    __erase(v->rc, v->val);
                }
            }
            else
            {
                binode_ptr<T> tmp = v;
                v = v->lc ? v->lc : v->rc;
                this->__release(tmp);
            }
        }
        else if (x < v->val)
        {
            __erase(v->lc, x);
            if (_factor(v) == -2)
                _factor(v->rc) <= 0 ? _zag(v) : _zagzig(v);
        }
        else if (v->val < x)
        {
            __erase(v->rc, x);
            if (_factor(v) == 2)
                _factor(v->lc) >= 0 ? _zig(v) : _zigzag(v);
        }
        if (v)
            bintree<T>::__updateheight(v);
    }
};

} // namespace dsa
#endif