#pragma once

template <typename T>
void Vector<T>::selectionSort(Rank lo, Rank hi)
{
    /*DSA*/ printf("\tSELECTIONsort [%3d, %3d)\n", lo, hi);
    while (lo < --hi)
        swap(_elem[max(lo, hi)], _elem[hi]);
}

template <typename T>
Rank Vector<T>::max(Rank lo, Rank hi)
{
    Rank mx = hi;
    while (lo < hi--)
        if (_elem[hi] > _elem[mx])
            mx = hi;
    return mx;
}
