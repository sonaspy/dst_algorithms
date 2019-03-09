
#include "../bintree/BinTree.h"

#ifndef BST_
#define BST_

template <class T>
class BST : public BinTree<T>
{
protected:
    BinNodePosi(T) _hot;
    BinNodePosi(T) connect34(
        BinNodePosi(T), BinNodePosi(T), BinNodePosi(T),
        BinNodePosi(T), BinNodePosi(T), BinNodePosi(T), BinNodePosi(T));
    BinNodePosi(T) rotateAt(BinNodePosi(T) x);

public:
    virtual BinNodePosi(T) & search(const T &e);
    virtual BinNodePosi(T) insert(const T &e);
    virtual bool remove(const T &e);
};

template <class T>
BinNodePosi(T) & BST<T>::search(const T &e)
{
    return __seachIn(_root, e, _hot = NULL);
}

#define EQUAL(e, v) (!(v) || (e) == (v)->data)
template <class T>
static BinNodePosi(T) & __seachIn(BinNodePosi(T) & v, const T &e, BinNodePosi(T) & hot)
{
    if (EQUAL(e, v))
        return v;
    hot = v;
    while (true)
        {
            BinNodePosi(T) &c = (e < hot->data) ? hot->lc : hot->rc;
            if (EQUAL(e, c))
                return c;
            hot = c;
        }
}

template <class T>
static BinNodePosi(T) & __seachIn_r(BinNodePosi(T) & v, const T &e, BinNodePosi(T) & hot)
{
    if (!v || (e == v->data))
        return v;
    hot = v;
    return __seachIn_r(((e < v->data) ? v->lc : v->rc), e, hot);
}

template <class T>
BinNodePosi(T) BST<T>::insert(const T &e)
{
    BinNodePosi(T) &x = search(e);
    if (!x)
        {
            x = new BinNode<T>(e, _hot);
            _size++;
            updateHeightAbove(x);
        }
    return x;
}

template <class T>
bool BST<T>::remove(const T &e)
{
    BinNodePosi(T) &x = search(e);
    if (!x)
        return false;
    __removeAt(x, _hot);
    _size--;
    updateHeightAbove(_hot);
    return true;
}

template <class T>
static BinNodePosi(T) __removeAt(BinNodePosi(T) & x, BinNodePosi(T) & hot)
{
    BinNodePosi(T) w = x;
    BinNodePosi(T) replacer = NULL;
    if (!HasLChild(*x))
        replacer = (x = x->rc);
    else if (!HasRChild(*x))
        replacer = (x = x->lc);
    else
        {
            w = w->succ();
            swap(x->data, w->data);
            BinNodePosi(T) u = w->parent;
            ((u == x) ? u->rc : u->lc) = replacer = w->rc;
        }
    hot = w->parent;
    if (replacer)
        replacer->parent = hot;
    release(w->data);
    release(w);
    return replacer;
}

#endif
