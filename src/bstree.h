// author - sonaspy@outlook.com
// coding - utf_8

#ifndef __BSTREE__
#define __BSTREE__

#include "bintree.h"
namespace dsa
{
template <typename T>
class bstree : public bintree<T>
{
protected:
    binode_ptr<T> _last;
    inline void __attAsL(binode_ptr<T> &p, binode_ptr<T> &lc)
    {
        p->lc = lc;
        if (lc)
            lc->parent = p;
    }
    inline void __attAsR(binode_ptr<T> &p, binode_ptr<T> &rc)
    {
        p->rc = rc;
        if (rc)
            rc->parent = p;
    }
    bool __judge_avl(binode_ptr<T> opnv, binode_ptr<T> &p)
    {
        if (!opnv)
            return true;
        bool f1, f2, f;
        f1 = __judge_avl(opnv->lc, p);
        f = nodeBalanced(opnv) && (p == nullptr || p->val < opnv->val);
        p = opnv;
        f2 = __judge_avl(opnv->rc, p);
        return f1 && f2 & f;
    }
    binode_ptr<T> &__search(binode_ptr<T> &opnv, const T &x)
    {
        if (!opnv || x == opnv->val)
            return opnv;
        _last = opnv;
        return __search(x < opnv->val ? opnv->lc : opnv->rc, x);
    }

    binode_ptr<T> __erase(binode_ptr<T> &opnv, const T &x)
    {
        if (!opnv)
            return nullptr;
        if (x < opnv->val)
            opnv->lc = __erase(opnv->lc, x);
        else if (opnv->val < x)
            opnv->rc = __erase(opnv->rc, x);
        else
        {
            binode_ptr<T> tmp;
            if (opnv->lc && opnv->rc)
            {
                tmp = opnv->successor();
                opnv->val = tmp->val;
                opnv->rc = __erase(opnv->rc, tmp->val);
            }
            else
            {
                tmp = opnv;
                opnv = opnv->lc ? opnv->lc : opnv->rc;
                __release(tmp);
            }
        }
        return opnv;
    }

public:
    ~bstree() { this->clear(); }
    void build(vector<T> &a)
    {
        for (auto &i : a)
            insert(i);
        this->__update_status();
    }
    bool balanced()
    {
        binode_ptr<T> p = nullptr;
        return __judge_avl(this->_root, p);
    }
    bool erase(const T &x)
    {
        if (__erase(this->_root, x))
        {
            this->__update_status();
            this->_size--;
            return true;
        };
        return false;
    }
    bool insert(const T &x)
    {
        binode_ptr<T> &w = search(x);
        if (w)
            return false;
        w = new binode<T>(x, _last);
        this->_size++;
        this->__updateheightabove(w);
        return true;
    }
    binode_ptr<T> &search(const T &x)
    {
        _last = nullptr;
        return __search(this->_root, x);
    }
    inline void clear()
    {
        bintree<T>::clear();
        _last = nullptr;
    }
    binode_ptr<T> findLCA(const T &v1, const T &v2)
    {
        binode_ptr<T> walk = this->_root;
        while (walk)
        {
            if (v1 < walk->val && v2 < walk->val)
                walk = walk->lc;
            else if (walk->val < v1 && walk->val < v2)
                walk = walk->rc;
            else
                break;
        }
        return walk;
    }
};
} // namespace dsa
#endif