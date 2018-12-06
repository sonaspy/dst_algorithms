#include"../bintree/BinNode.h"

#ifndef rbTree_
#define rbTree_

template <typename T>
class RedBlack : public BST<T>
{
  protected:
    void solveDoubleRed(BinNodePosi(T) x);
    void solveDoubleBlack(BinNodePosi(T) x);
    int updateHeight(BinNodePosi(T) x);

  public:
    BinNodePosi(T) insert(const T &e);
    bool remove(const T &e);
};

template <typename T>
BinNodePosi(T) RedBlack<T>::insert(const T &e)
{
    BinNodePosi(T) &x = search(e);
    if (x)
        return x;
    x = new BinNode<T>(e, _hot, NULL, NULL, -1);
    _size++;
    solveDoubleRed(x);
    return x ? x : _hot->parent;
}

template <typename T>
int RedBlack<T>::updateHeight(BinNodePosi(T) x)
{
    x->height = max(stature(x->lc), stature(x->rc));

    return IsBlack(x) ? x->height++ : x->height;
}

template <typename T>
void RedBlack<T>::solveDoubleRed(BinNodePosi(T) x)
{
    if (IsRoot(*x))
    {
        _root->color = RB_BLACK;
        _root->height++;
        return;
    }
    BinNodePosi(T) p = x->parent;
    if (IsBlack(p))
        return;
    BinNodePosi(T) g = p->parent;
    BinNodePosi(T) u = uncle(x);
    if (IsBlack(u))
    {
        if (IsLChild(*x) == IsLChild(*p))
            p->color = RB_BLACK;
        else
            x->color = RB_BLACK;
        g->color = RB_RED;

        BinNodePosi(T) gg = g->parent;
        BinNodePosi(T) r = FromParentTo(*g) = rotateAt(x);
        r->parent = gg;
    }
    else
    {
        p->color = RB_BLACK;
        p->height++;
        u->color = RB_BLACK;
        u->height++;
        if (!IsRoot(*g))
            g->color = RB_RED;
        solveDoubleRed(g);
    }
}

template <typename T>
void RedBlack<T>::solveDoubleBlack(BinNodePosi(T) r)
{
    BinNodePosi(T) p = r ? r->parent : _hot;
    if (!p)
        return;
    BinNodePosi(T) s = (r == p->lc) ? p->rc : p->lc;
    if (IsBlack(s))
    {
        BinNodePosi(T) t = NULL;
        if (IsRed(s->rc))
            t = s->rc;
        if (IsRed(s->lc))
            t = s->lc;
        if (t)
        {
            RBColor oldColor = p->color;

            BinNodePosi(T) b = FromParentTo(*p) = rotateAt(t);
            if (HasLChild(*b))
            {
                b->lc->color = RB_BLACK;
                updateHeight(b->lc);
            }
            if (HasRChild(*b))
            {
                b->rc->color = RB_BLACK;
                updateHeight(b->rc);
            }
            b->color = oldColor;
            updateHeight(b);
        }
        else
        {
            s->color = RB_RED;
            s->height--;
            if (IsRed(p))
            {
                p->color = RB_BLACK;
            }
            else
            {
                p->height--;
                solveDoubleBlack(p);
            }
        }
    }
    else
    {
        s->color = RB_BLACK;
        p->color = RB_RED;
        BinNodePosi(T) t = IsLChild(*s) ? s->lc : s->rc;
        _hot = p;
        FromParentTo(*p) = rotateAt(t);
        solveDoubleBlack(r);
    }
}

template <typename T>
bool RedBlack<T>::remove(const T &e)
{
    BinNodePosi(T) &x = search(e);
    if (!x)
        return false;
    BinNodePosi(T) r = removeAt(x, _hot);
    if (!(--_size))
        return true;

    if (!_hot)
    {
        _root->color = RB_BLACK;
        updateHeight(_root);
        return true;
    }

    if (BlackHeightUpdated(*_hot))
        return true;
    if (IsRed(r))
    {
        r->color = RB_BLACK;
        r->height++;
        return true;
    }

    solveDoubleBlack(r);
    return true;
}

#endif
