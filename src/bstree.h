// author - sonaspy@outlook.com
// coding - utf_8

#ifndef __BSTREE__
#define __BSTREE__

namespace dsa
{
template <typename _Tp>
class bstree : public bintree<_Tp>
{
protected:
    binode_ptr<_Tp> _last;
    inline void __attAsL(binode_ptr<_Tp> &p, binode_ptr<_Tp> &lc)
    {
        p->lc = lc;
        if (lc)
            lc->parent = p;
    }
    inline void __attAsR(binode_ptr<_Tp> &p, binode_ptr<_Tp> &rc)
    {
        p->rc = rc;
        if (rc)
            rc->parent = p;
    }
    bool __judge_avl(binode_ptr<_Tp> opnv, binode_ptr<_Tp> &p)
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
    binode_ptr<_Tp> &__search(binode_ptr<_Tp> &opnv, const _Tp &x)
    {
        if (!opnv || x == opnv->val)
            return opnv;
        _last = opnv;
        return __search(x < opnv->val ? opnv->lc : opnv->rc, x);
    }

    binode_ptr<_Tp> __erase(binode_ptr<_Tp> &opnv, const _Tp &x)
    {
        if (!opnv)
            return nullptr;
        if (x < opnv->val)
            opnv->lc = __erase(opnv->lc, x);
        else if (opnv->val < x)
            opnv->rc = __erase(opnv->rc, x);
        else
        {
            binode_ptr<_Tp> tmp;
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
                this->__release(tmp);
            }
        }
        return opnv;
    }

public:
    ~bstree() { this->clear(); }
    void build(vector<_Tp> &a)
    {
        for (auto &i : a)
            insert(i);
        this->__update_status();
    }
    bool avlbalanced()
    {
        binode_ptr<_Tp> p = nullptr;
        return __judge_avl(this->_root, p);
    }
    bool erase(const _Tp &x)
    {
        if (__erase(this->_root, x))
        {
            this->_size--;
            return true;
        };
        return false;
    }
    bool insert(const _Tp &x)
    {
        binode_ptr<_Tp> &w = search(x);
        if (w)
            return false;
        w = this->__newbinode(x, _last);
        this->_size++;
        this->__updateheightabove(w);
        return true;
    }
    binode_ptr<_Tp> &search(const _Tp &x)
    {
        _last = nullptr;
        return __search(this->_root, x);
    }
    inline void clear()
    {
        bintree<_Tp>::clear();
        _last = nullptr;
    }
    binode_ptr<_Tp> get_lca(const _Tp &v1, const _Tp &v2)
    {
        binode_ptr<_Tp> _walk = this->_root;
        while (_walk)
        {
            if (v1 < _walk->val && v2 < _walk->val)
                _walk = _walk->lc;
            else if (_walk->val < v1 && _walk->val < v2)
                _walk = _walk->rc;
            else
                break;
        }
        return _walk;
    }
};
} // namespace dsa
#endif