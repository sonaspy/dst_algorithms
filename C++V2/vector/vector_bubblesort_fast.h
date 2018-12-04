#pragma once

template <typename T>
Rank Vector<T>::bubble(Rank lo, Rank hi)
{
    Rank last_swap_p = lo;
    while (++lo < hi)
        if (_elem[lo - 1] > _elem[lo])
        {
            last_swap_p = lo;
            swap(_elem[lo - 1], _elem[lo]);
        }
    return last_swap_p;
}

template <typename T>
void Vector<T>::bubbleSort(Rank lo, Rank hi)
{
    while (lo < (hi = bubble(lo, hi)))
        ;
}