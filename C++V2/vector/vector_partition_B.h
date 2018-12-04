#pragma once

template <typename T>
Rank Vector<T>::partition(Rank lo, Rank hi)
{
    swap(_elem[lo], _elem[lo + rand() % (hi - lo + 1)]);
    T pivot = _elem[lo];
    while (lo < hi)
    {
        while (lo < hi)
            if (pivot < _elem[hi])
                hi--;
            else
            {
                _elem[lo++] = _elem[hi];
                break;
            }
        while (lo < hi)
            if (_elem[lo] < pivot)
                lo++;
            else
            {
                _elem[hi--] = _elem[lo];
                break;
            }
    }
    _elem[lo] = pivot;
    return lo;
}