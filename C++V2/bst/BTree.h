#include "BTNode.h"

#ifndef BTree_
#define BTree_

template <class T>
class BTree
{
  protected:
    int _size;
    int _order;
    BTNodePosi(T) _root;
    BTNodePosi(T) _hot; // the last non-null position vistied by search()
    void solveOverflow(BTNodePosi(T));
    void solveUnderflow(BTNodePosi(T));

  public:
    BTree(int order = 3) : _order(order), _size(0)
    {
        _root = new BTNode<T>();
    }
    ~BTree()
    {
        if (_root)
            release(_root);
    }
    int const order() { return _order; }
    int const size() { return _size; }
    BTNodePosi(T) & root() { return _root; }
    bool empty() const { return !_root; }
    BTNodePosi(T) search(const T &e);
    bool insert(const T &e);
    bool remove(const T &e);
};

template <class T>
bool BTree<T>::insert(const T &e)
{
    BTNodePosi(T) v = search(e);
    if (v)
        return false;
    Rank r = _hot->key.search(e);
    _hot->key.insert(++r, e);
    _hot->child.insert(++r, NULL);
    _size++;
    solveOverflow(_hot);
    return true;
}

template <class T>
bool BTree<T>::remove(const T &e)
{
    BTNodePosi(T) v = search(e);
    if (!v)
        return false;
    Rank r = v->key.search(e);
    if (v->child[0])
    {
        BTNodePosi(T) u = v->child[r + 1];
        while (u->child[0])
            u = u->child[0];
        v->key[r] = u->key[0];
        v = u;
        r = 0;
    }
    v->key.remove(r);
    v->child.remove(++r);
    _size--;
    solveUnderflow(v);
    return true;
}

template <class T>
BTNodePosi(T) BTree<T>::search(const T &e)
{
    BTNodePosi(T) v = _root;
    _hot = NULL;
    while (v)
    {
        Rank r = v->key.search(e);
        if ((0 <= r) && (e == v->key[r]))
            return v;
        _hot = v;
        v = v->child[r + 1];
    }
    return _hot;
}

template <class T>
void BTree<T>::solveOverflow(BTNodePosi(T) v)
{
    if (_order >= v->child.size())
        return;
    Rank s = _order 2;
    BTNodePosi(T) u = new BTNode<T>();
    for (Rank j = 0; j < _order - s - 1; j++)
    {
        u->child.insert(j, v->child.remove(s + 1));
        u->key.insert(j, v->key.remove(s + 1));
    }
    u->child[_order - s - 1] = v->child.remove(s + 1);
    if (u->child[0])
        for (Rank j = 0; j < _order - s; j++)
            u->child[j]->parent = u;
    BTNodePosi(T) p = v->parent;
    if (!p)
    {
        _root = p = new BTNode<T>();
        p->child[0] = v;
        v->parent = p;
    }
    Rank r = 1 + p->key.search(v->key[0]);
    p->key.insert(r, v->key.remove(s));
    p->child.insert(r + 1, u);
    u->parent = p;
    solveOverflow(p);
}


template <class T>
void BTree<T>::solveUnderflow(BTNodePosi(T) v)
{
    if ((_order + 1)2 <= v->child.size())
        return;
    BTNodePosi(T) p = v->parent;
    if (!p)
    {
        if (!v->key.size() && v->child[0])
        {

            _root = v->child[0];
            _root->parent = NULL;
            v->child[0] = NULL;
            release(v);
        }
        return;
    }
    Rank r = 0;
    while (p->child[r] != v)
        r++;

    if (0 < r)
    {
        BTNodePosi(T) ls = p->child[r - 1];
        if ((_order + 1)2 < ls->child.size())
        {

            v->key.insert(0, p->key[r - 1]);
            p->key[r - 1] = ls->key.remove(ls->key.size() - 1);
            v->child.insert(0, ls->child.remove(ls->child.size() - 1));

            if (v->child[0])
                v->child[0]->parent = v;
            return;
        }
    }

    if (p->child.size() - 1 > r)
    {
        BTNodePosi(T) rs = p->child[r + 1];
        if ((_order + 1)2 < rs->child.size())
        {

            v->key.insert(v->key.size(), p->key[r]);
            p->key[r] = rs->key.remove(0);
            v->child.insert(v->child.size(), rs->child.remove(0));

            if (v->child[v->child.size() - 1])
                v->child[v->child.size() - 1]->parent = v;
            return;
        }
    }

    if (0 < r)
    {

        BTNodePosi(T) ls = p->child[r - 1];
        ls->key.insert(ls->key.size(), p->key.remove(r - 1));
        p->child.remove(r);

        ls->child.insert(ls->child.size(), v->child.remove(0));
        if (ls->child[ls->child.size() - 1])
            ls->child[ls->child.size() - 1]->parent = ls;
        while (!v->key.empty())
        {
            ls->key.insert(ls->key.size(), v->key.remove(0));
            ls->child.insert(ls->child.size(), v->child.remove(0));
            if (ls->child[ls->child.size() - 1])
                ls->child[ls->child.size() - 1]->parent = ls;
        }
        release(v);
    }
    else
    {

        BTNodePosi(T) rs = p->child[r + 1];
        rs->key.insert(0, p->key.remove(r));
        p->child.remove(r);

        rs->child.insert(0, v->child.remove(v->child.size() - 1));
        if (rs->child[0])
            rs->child[0]->parent = rs;
        while (!v->key.empty())
        {
            rs->key.insert(0, v->key.remove(v->key.size() - 1));
            rs->child.insert(0, v->child.remove(v->child.size() - 1));
            if (rs->child[0])
                rs->child[0]->parent = rs;
        }
        release(v);
    }
    solveUnderflow(p);
    return;
}

#endif
