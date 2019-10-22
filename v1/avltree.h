// author - sonaspy@outlook.com
// coding - utf_8

#ifndef __AVLTREE__
#define __AVLTREE__

__DST_BEGIN_NAMESPACE

template <typename _Tp>
class avltree : public bstree<_Tp>
{
public:
    void build(vector<_Tp> &a)
    {
        for (auto i : a)
            insert(i);
        __update_status();
    }
    bool erase(const _Tp &x)
    {
        if (bstree<_Tp>::search(x) == nullptr)
            return false;
        __erase(_root, x);
        return true;
    }
    bool insert(const _Tp &x)
    {
        if (bstree<_Tp>::search(x) != nullptr)
            return false;
        __insert(_root, x);
        return true;
    }
    inline void clear() { bstree<_Tp>::clear(); }
    ~avltree()
    {
        clear();
    }

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

    inline void _zig(binode_ptr<_Tp> &v)
    {
        binode_ptr<_Tp> y = v->lc;
        v->lc = y->rc;
        y->rc = v;
        __updateheight(v);
        __updateheight(y);
        v = y;
    }
    inline void _zag(binode_ptr<_Tp> &v)
    {
        binode_ptr<_Tp> y = v->rc;
        v->rc = y->lc;
        y->lc = v;
        __updateheight(v);
        __updateheight(y);
        v = y;
    }
    inline void _zigzag(binode_ptr<_Tp> &v)
    {
        _zag(v->lc);
        _zig(v);
    }
    inline void _zagzig(binode_ptr<_Tp> &v)
    {
        _zig(v->rc);
        _zag(v);
    }
    void __insert(binode_ptr<_Tp> &v, const _Tp &x)
    {
        if (!v)
        {
            v = __newbinode(x);
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
        __updateheight(v);
    }

    void __erase(binode_ptr<_Tp> &v, const _Tp x)
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
                binode_ptr<_Tp> tmp = v;
                v = v->lc ? v->lc : v->rc;
                __release(tmp);
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
            __updateheight(v);
    }
};

__DST_END_NAMESPACE
#endif