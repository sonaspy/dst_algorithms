#pragma once

template <typename T>
void Vector<T>::quickSort(Rank lo, Rank hi)
{
    /*DSA*/ printf("\tQUICKsort [%3d, %3d)\n", lo, hi);
    if (hi - lo < 2)
        return;
    Rank mi = partition(lo, hi - 1);
    quickSort(lo, mi);
    quickSort(mi + 1, hi);
}