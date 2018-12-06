#include"../vector/vector.h"

#define BTNodePosi(T) BTNode<T>*

template <typename T>
struct BTNode
{

    BTNodePosi(T) parent;
    Vector<T> key;
    Vector<BTNodePosi(T)> child;

    BTNode()
    {
        parent = NULL;
        child.insert(0, NULL);
    }
    BTNode(T e, BTNodePosi(T) lc = NULL, BTNodePosi(T) rc = NULL)
    {
        parent = NULL;
        key.insert(0, e);
        child.insert(0, lc);
        child.insert(1, rc);
        if (lc)
            lc->parent = this;
        if (rc)
            rc->parent = this;
    }
};

template <typename T>
BinNodePosi(T) BinNode<T>::zig()
{
    BinNodePosi(T) lChild = lc;
    lChild->parent = this->parent;
    if (lChild->parent)
        ((this == lChild->parent->rc) ? lChild->parent->rc : lChild->parent->lc) = lChild;
    lc = lChild->rc;
    if (lc)
        lc->parent = this;
    lChild->rc = this;
    this->parent = lChild;
    return lChild;
}

template <typename T>
BinNodePosi(T) BinNode<T>::zag()
{
    BinNodePosi(T) rChild = rc;
    rChild->parent = this->parent;
    if (rChild->parent)
        ((this == rChild->parent->lc) ? rChild->parent->lc : rChild->parent->rc) = rChild;
    rc = rChild->lc;
    if (rc)
        rc->parent = this;
    rChild->lc = this;
    this->parent = rChild;
    return rChild;
}
