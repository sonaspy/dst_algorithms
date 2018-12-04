#pragma once

template <typename T>
Posi(T) ListNode<T>::insertAsPred(T const &e)
{
    Posi(T) x = new ListNode(e, pred, this);
    pred->succ = x;
    pred = x;
    return x;
}