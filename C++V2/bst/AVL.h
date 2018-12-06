#include"../bintree/BinNode.h"
#include"./BST.h"

 #define tallerChild(x) ( \
    stature( (x)->lc ) > stature( (x)->rc ) ? (x)->lc : (  \
    stature( (x)->lc ) < stature( (x)->rc ) ? (x)->rc : (  \
    IsLChild( * (x) ) ? (x)->lc : (x)->rc \
    ) \
    ) \
 )

#define Balanced(x) ( stature( (x).lc ) == stature( (x).rc ) )
#define BalFac(x) (stature((x).lc) - stature((x).rc))
#define AvlBalanced(x) ((-2 < BalFac(x)) && (BalFac(x) < 2))  

template <typename T>
class AVL: public BST<T>
    {
      public:
        BinNodePosi(T) insert(const T &e);
        bool remove(const T &e);
};

template <typename T>
BinNodePosi(T) AVL<T>::insert(const T &e){
    BinNodePosi(T) &x = search(e);
    if (x)
        return x;
    BinNodePosi(T) xx = x = new BinNode<T>(e, _hot);
    _size++;

    for (BinNodePosi(T) g = _hot; g; g = g->parent){
        if (!AvlBalanced(*g)){
            FromParentTo(*g) = rotateAt(tallerChild(tallerChild(g)));
            break;
        }else
            updateHeight(g);
    }
    return xx;
}

template <typename T>
bool AVL<T>::remove(const T &e){
    BinNodePosi(T) &x = search(e);
    if (!x)
        return false;
    __removeAt(x, _hot);
    _size--;
    for (BinNodePosi(T) g = _hot; g; g = g->parent){
        if (!AvlBalanced(*g))
            g = FromParentTo(*g) = rotateAt(tallerChild(tallerChild(g)));
        updateHeight(g);
    }
    return true;
}

template <typename T>
BinNodePosi(T) BST<T>::connect34(BinNodePosi(T) a, BinNodePosi(T) b,
                                 BinNodePosi(T) c, BinNodePosi(T) T0,
                                 BinNodePosi(T) T1, BinNodePosi(T) T2,
                                 BinNodePosi(T) T3)
{
    a->lc = T0;
    if (T0)
        T0->parent = a;
    a->rc = T1;
    if (T1)
        T1->parent = a;
    updateHeight(a);
    c->lc = T2;
    if (T2)
        T2->parent = c;
    c->rc = T3;
    if (T3)
        T3->parent = c;
    updateHeight(c);
    b->lc = a;
    a->parent = b;
    b->rc = c;
    c->parent = b;
    updateHeight(b);
    return b;
}

template <typename T>
BinNodePosi(T) BST<T>::rotateAt(BinNodePosi(T) v)
{
    BinNodePosi(T) p = v->parent;
    BinNodePosi(T) g = p->parent;
    if (IsLChild(*p)) /* zig */
        if (IsLChild(*v))
        { /* zig-zig */
            p->parent = g->parent;
            return connect34(v, p, g, v->lc, v->rc, p->rc, g->rc);
        }
        else
        { /* zig-zag */
            v->parent = g->parent;
            return connect34(p, v, g, p->lc, v->lc, v->rc, g->rc);
        }
    else /* zag */
        if (IsRChild(*v))
    { /* zag-zag */
        p->parent = g->parent;
        return connect34(g, p, v, g->lc, p->lc, v->lc, v->rc);
    }
    else
    { /* zag-zig */
        v->parent = g->parent;
        return connect34(g, v, p, g->lc, v->lc, v->rc, p->rc);
    }
}