
#pragma once

template <typename T>
Rank Vector<T>::find(T const &e, Rank lo, Rank hi) const
{
    while ((hi-- > lo) && (e != _elem[hi]))
        ;
    return hi;
}   