#pragma once

#include "../bintree/BinTree.h"
#include "../priority_queue/PQ.h"

#ifndef LeftHeap_
#define LeftHeap_

template <class T>
class PQ_LeftHeap : public PQ<T>, public BinTree<T>
{
public:
    PQ_LeftHeap() {}
    PQ_LeftHeap(T *E, int n)
    {
        for (int i = 0; i < n; i++)
            insert(E[i]);
    }
    void insert(T);
    T getMax();
    T delMax();
};

template <class T>
T PQ_LeftHeap<T>::delMax()
{
    BinNodePosi(T) lHeap = _root->lc;
    BinNodePosi(T) rHeap = _root->rc;
    T e = _root->data;
    delete _root;
    _size--;
    _root = merge(lHeap, rHeap);
    return e;
}

template <class T>
T PQ_LeftHeap<T>::getMax()
{
    return _root->data;
}

template <class T>
void PQ_LeftHeap<T>::insert(T e)
{
    BinNodePosi(T) v = new BinNode<T>(e);
    _root = merge(_root, v);
    _size++;
}

template <class T>
static BinNodePosi(T) merge(BinNodePosi(T) a, BinNodePosi(T) b)
{
    if (!a)
        return b;
    if (!b)
        return a;
    if (lt(a->data, b->data))
        swap(a, b);
    a->rc = merge(a->rc, b);
    a->rc->parent = a;
    if (!a->lc || a->lc->npl < a->rc->npl)
        swap(a->lc, a->rc);
    a->npl = a->rc ? a->rc->npl + 1 : 1;
    return a;
}

#endif