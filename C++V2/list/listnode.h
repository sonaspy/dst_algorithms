
#ifndef ListNode_
#define ListNode_

typedef int Rank;
#define Posi(T) ListNode<T>*

template <typename T>
struct ListNode
{

    T data;
    Posi(T) pred;
    Posi(T) succ;

    ListNode() {}
    ListNode(T e, Posi(T) p = NULL, Posi(T) s = NULL)
        : data(e), pred(p), succ(s) {}

    Posi(T) insertAsPred(T const &e);
    Posi(T) insertAsSucc(T const &e);
};


#endif



template <typename T>
Posi(T) ListNode<T>::insertAsPred(T const &e)
{
    Posi(T) x = new ListNode(e, pred, this);
    pred->succ = x;
    pred = x;
    return x;
}


template <typename T>
Posi(T) ListNode<T>::insertAsSucc(T const &e)
{
    Posi(T) x = new ListNode(e, this, succ);
    succ->pred = x;
    succ = x;
    return x;
}