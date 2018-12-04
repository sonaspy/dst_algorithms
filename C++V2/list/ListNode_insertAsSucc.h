
#pragma once

template <typename T>
Posi(T) ListNode<T>::insertAsSucc(T const &e)
{
    Posi(T) x = new ListNode(e, this, succ);
    succ->pred = x;
    succ = x;
    return x;
}