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
    binode<T> *_last;
    inline void __attAsL(binode<T> *&p, binode<T> *&lc)
    {
        p->lc = lc;
        if (lc)
            lc->parent = p;
    }
    inline void __attAsR(binode<T> *&p, binode<T> *&rc)
    {
        p->rc = rc;
        if (rc)
            rc->parent = p;
    }
    bool __judge_avl(binode<T> *opnv, binode<T> *&p)
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
    binode<T> *&__search(binode<T> *&opnv, const T &x)
    {
        if (!opnv || x == opnv->val)
            return opnv;
        _last = opnv;
        return __search(x < opnv->val ? opnv->lc : opnv->rc, x);
    }

    binode<T> *__erase(binode<T> *&opnv, const T &x)
    {
        if (!opnv)
            return nullptr;
        if (x < opnv->val)
            opnv->lc = __erase(opnv->lc, x);
        else if (opnv->val < x)
            opnv->rc = __erase(opnv->rc, x);
        else
        {
            binode<T> *tmp;
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
    //return is delnode's succ ，last is delnode's parent
    static binode<T> *__erase_at(binode<T> *&opnv, binode<T> *&last)
    {
        binode<T> *w = opnv, *succ = nullptr;
        if (!opnv->has_l())
        {
            opnv = opnv->rc;
            succ = opnv;
        }
        else if (!opnv->has_r())
        {
            opnv = opnv->lc;
            succ = opnv;
        }
        else
        {
            w = w->successor();
            swap(opnv->val, w->val);
            binode<T> *u = w->parent;
            succ = w->rc;
            u == opnv ? u->rc = succ : u->lc = succ;
        }
        last = w->parent;
        __release(w);
        return succ;
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
        binode<T> *p = nullptr;
        return __judge_avl(this->_root, p);
    }
    bool erase(const T &x)
    {
        binode<T> *&w = search(x);
        if (!w)
            return false;
        __erase_at(w, _last);
        this->__updateheightabove(_last);
        this->_size--;
        return true;
    }
    bool insert(const T &x)
    {
        binode<T> *&w = search(x);
        if (w)
            return false;
        w = new binode<T>(x, _last);
        this->_size++;
        this->__updateheightabove(w);
        return true;
    }
    binode<T> *&search(const T &x)
    {
        _last = nullptr;
        return __search(this->_root, x);
    }
    inline void clear()
    {
        bintree<T>::clear();
        _last = nullptr;
    }
    binode<T> *findLCA(const T &v1, const T &v2)
    {
        binode<T> *walk = this->_root;
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