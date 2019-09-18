// author - sonaspy@outlook.com  
// coding - utf_8 

#ifndef __HUFFMAN__
#define __HUFFMAN__
#include "bintree.h"
namespace dsa
{


template <typename T>
class huffman : public bintree<T>
{
protected:
    int _wpl;
    struct __cmp
    {
        bool operator()(const binode<T> *a, const binode<T> *b) const { return a->val > b->val; }
    };
    void __build_hfm(vector<int> &data)
    {
        priority_queue<binode<T> *, vector<binode<T> *>, __cmp> pq;
        binode<T> *opnv, *w, *root;
        for (auto i : data)
        {
            binode<T> *opnv = new binode<T>(i);
            pq.push_back(opnv);
        }
        while (pq.size() > 1)
        {
            opnv = pq.top(), pq.pop_front();
            w = pq.top(), pq.pop_front();
            root = new binode<T>(opnv->val + w->val);
            root->lc = opnv, root->rc = w;
            pq.push_back(root);
        }
        this->__update_root(root);
    }
    void __wpl(binode<T> *opnv)
    {
        if (!opnv)
            return;
        if (opnv->lc)
            _wpl += opnv->val;
        __wpl(opnv->lc);
        __wpl(opnv->rc);
    };

public:
    huffman()
    {
        _wpl = -1;
    }
    void build(vector<int> &a)
    {
        if (a.empty())
            return;
        __build_hfm(a);
    }
    inline void clear()
    {
        bintree<T>::clear();
        _wpl = 0;
    }
    int wpl()
    {
        if (_wpl == -1)
            __wpl(this->_root);
        return _wpl;
    }
    ~huffman() { this->clear(); }
};
} // namespace dsa
#endif