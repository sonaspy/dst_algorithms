#include "../stack/stack_vector.h"
#include "../queue/queue.h"

#ifndef BinNode_
#define BinNode_

#define BinNodePosi(T) BinNode<T> *
#define stature(p) ((p) ? (p)->height : -1)
#define IsRoot(x) (!((x).parent))
#define IsLChild(x) (!IsRoot(x) && (&(x) == (x).parent->lc))
#define IsRChild(x) (!IsRoot(x) && (&(x) == (x).parent->rc))
#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lc)
#define HasRChild(x) ((x).rc)
#define HasChild(x) (HasLChild(x) || HasRChild(x))
#define HasBothChild(x) (HasLChild(x) && HasRChild(x))
#define IsLeaf(x) (!HasChild(x))

#define sibling(p) /*bro*/ \
    (IsLChild(*(p)) ? (p)->parent->rc : (p)->parent->lc)

#define uncle(x) /*uncle*/ \
    (IsLChild(*((x)->parent)) ? (x)->parent->parent->rc : (x)->parent->parent->lc)

#define FromParentTo(x) \
    (IsRoot(x) ? _root : (IsLChild(x) ? (x).parent->lc : (x).parent->rc))

typedef enum
{
    RB_RED,
    RB_BLACK
} RBColor;

template <class T>
struct BinNode
{

    T data;
    BinNodePosi(T) parent,
        lc,
        rc;
    int height;
    int npl;
    RBColor color;

    BinNode() : parent(NULL), lc(NULL), rc(NULL), height(0), npl(1), color(RB_RED) {}
    BinNode(T e,
            BinNodePosi(T) p = NULL,
            BinNodePosi(T) lc = NULL,
            BinNodePosi(T) rc = NULL,
            int h = 0,
            int l = 1,
            RBColor c = RB_RED) : data(e), parent(p), lc(lc), rc(rc), height(h), npl(l), color(c) {}

    int size();
    BinNodePosi(T) insertAsLC(T const &);
    BinNodePosi(T) insertAsRC(T const &);
    BinNodePosi(T) succ();
    template <class VST>
    void travLevel(VST &);
    template <class VST>
    void travPre(VST &);
    template <class VST>
    void travIn(VST &);
    template <class VST>
    void travPost(VST &);

    bool operator<(BinNode const &bn) { return data < bn.data; }
    bool operator==(BinNode const &bn) { return data == bn.data; }
};

template <class T>
BinNodePosi(T) BinNode<T>::insertAsLC(T const &e)
{
    return lc = new BinNode(e, this);
}

template <class T>
BinNodePosi(T) BinNode<T>::insertAsRC(T const &e)
{
    return rc = new BinNode(e, this);
}

template <class T>
int BinNode<T>::size()
{
    int s = 1;
    if (lc)
        s += lc->size();
    if (rc)
        s += rc->size();
    return s;
}

template <class T, class VST>
void travPre_R(BinNodePosi(T) x, VST &visit)
{
    if (!x)
        return;
    visit(x->data);
    travPre_R(x->lc, visit);
    travPre_R(x->lr, visit);
}

template <class T, class VST>
void travPre_I1(BinNodePosi(T) x, VST &visit)
{
    Stack<BinNodePosi(T)> S;
    if (x)
        S.push(x);
    while (!S.empty())
    {
        x = S.pop();
        visit(x->data);
        if (x->rc)
            S.push(x->rc);
        if (x->lc)
            S.push(x->lc);
    }
}

template <class T, class VST>
static void visitAlongVine_pre(BinNodePosi(T) x, VST &visit, Stack<BinNodePosi(T)> &S)
{
    while (x)
    {
        visit(x->data);
        S.push(x->rc);
        x = x->lc;
    }
}
template <class T, class VST>
void travPre_I2(BinNodePosi(T) x, VST &visit)
{
    Stack<BinNodePosi(T)> S;
    while (true)
    {
        visitAlongVine_pre(x, visit, S);
        if (S.empty())
            break;
        x = S.pop();
    }
}

template <class T, class VST>
void travIn_R(BinNodePosi(T) x, VST &visit)
{
    if (!x)
        return;
    travIn_R(x->lc, visit);
    visit(x->data);
    travIn_R(x->rc, visit);
}

template <class T, class VST>
static void visitAlongVine_in(BinNodePosi(T) x, Stack<BinNodePosi(T)> &S)
{
    while (x)
    {
        S.push(x);
        x = x->lc;
    }
}

template <class T, class VST>
void travIn_I1(BinNodePosi(T) x, VST &visit)
{
    Stack<BinNodePosi(T)> S;
    while (true)
    {
        visitAlongVine_in(x, S);
        if (S.empty())
            break;
        x = S.pop();
        visit(x->data);
        x = x->rc;
    }
}
template <class T, class VST>
void travIn_I4(BinNodePosi(T) x, VST &visit)
{
    while (true)
        if (x->lc)
            x = x->lc;
        else
        {
            visit(x->data);
            while (x->rc)
                if (!(x = x->succ()))
                    return;
                else
                    visit(x->data);
            x = x->rc;
        }
}

template <class T, class VST>
void BinNode<T>::travLevel(VST &visit)
{
    Queue<BinNodePosi(T)> Q;
    Q.enqueue(this);
    while (!Q.empty())
    {
        BinNodePosi(T) x = Q.dequeue();
        visit(x->data);
        if (x->lc)
            Q.enqueue(x->lc);
        if (x->rc)
            Q.enqueue(x->rc);
    }
}

template <class T>
BinNodePosi(T) BinNode<T>::succ()
{
    BinNodePosi(T) s = this;
    if (rc)
    {
        s = rc;
        while (HasLChild(*s))
            s = s->lc;
    }
    else
    {
        while (IsRChild(*s))
            s = s->parent;
        s = s->parent;
    }
    return s;
}

template <class T, class VST> 
void travPost_R ( BinNodePosi(T) x, VST& visit ){
     if ( !x ) return;
     travPost_R ( x->lc, visit );
     travPost_R ( x->rc, visit );
     visit ( x->data );
}

template <class T>
static void gotoHLVFL ( Stack<BinNodePosi(T)>& S ){
    while ( BinNodePosi(T) x = S.top() ) 
          if ( HasLChild ( *x ) ){
              if ( HasRChild ( *x ) ) S.push ( x->rc ); 
               S.push ( x->lc );
          }else
            S.push ( x->rc ); 
        S.pop();
}
template <class T, class VST>
void travPost_I ( BinNodePosi(T) x, VST& visit ) {
    Stack<BinNodePosi(T)> S; 
     if ( x ) S.push ( x );
     while ( !S.empty() ){
         if ( S.top() != x->parent )
            gotoHLVFL ( S ); 
        x = S.pop(); visit ( x->data );
     }
}



#endif