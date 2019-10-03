// author -sonaspy@outlook.com
// coding - utf_8

#ifndef __NEW_SORT__
#define __NEW_SORT__
#include "algorithms.h"
using namespace std;
namespace dsa
{

//[)
template <typename _RandomAccessIterator>
static void heapSort(_RandomAccessIterator _first, _RandomAccessIterator _last)
{
    makeheap(_first, _last);
    for (_RandomAccessIterator walk = _last; walk > _first + 1; --walk)
        popheap(_first, walk);
}

//[)
template <typename _RandomAccessIterator>
static void bubblesort(_RandomAccessIterator _first, _RandomAccessIterator _last)
{ // Bubble largest element in a[0:_size-1] to _last.
    _RandomAccessIterator i, k;
    bool swapped = 1;
    for (k = _last - 1; swapped && k > _first; k--)
    {
        swapped = 0;
        for (i = _first; i < k; i++)
        {
            if (*i > *(i + 1))
            {
                iter_swap(i, (i + 1));
                swapped = 1;
            }
        }
    }
}
//[)
template <typename _RandomAccessIterator>
static void doublebubblesort(_RandomAccessIterator _first, _RandomAccessIterator _last)
{ // Bubble largest element in a[0:_size-1] to _last.
    bool swapped = true;
    _RandomAccessIterator i;
    for (; _first < --_last && swapped; ++_first)
    {
        swapped = false;
        for (i = _first; i < _last; ++i)
            if (*i > *(i + 1))
                iter_swap(i, i + 1), swapped = true;
        for (i = _last; i > _first; --i)
            if (*(i - 1) > *i)
                iter_swap(i, i - 1), swapped = true;
    }
}
//[)
template <typename _RandomAccessIterator>
static void selectsort(_RandomAccessIterator _first, _RandomAccessIterator _last)
{

    _RandomAccessIterator i;
    for (i = _last; i > _first + 1; i--)
        iter_swap(max_element(_first, i), (i - 1));
}

//[)
template <typename _RandomAccessIterator>
static void doubleselectsort(_RandomAccessIterator _first, _RandomAccessIterator _last)
{
    _RandomAccessIterator _walk, _min_pos, _max_pos;
    for (; _first < --_last; ++_first)
    {
        _min_pos = _max_pos = _first;
        for (_walk = _first + 1; _walk < _last + 1; ++_walk)
        {
            _min_pos = *_walk < *_min_pos ? _walk : _min_pos;
            _max_pos = *_walk > *_max_pos ? _walk : _max_pos;
        }
        iter_swap(_min_pos, _first);
        iter_swap(_max_pos != _first ? _max_pos : _min_pos, _last);
    }
}

//[)
template <typename _RandomAccessIterator>
static void inline insertsort_bin(_RandomAccessIterator _first, _RandomAccessIterator _last)
{ // [_first, _last)
    if (_first < _last)
        for (_RandomAccessIterator i = _first + 1; i < _last; ++i)
            __linear_insert(_first, i, *i);
}

//[)
template <typename _RandomAccessIterator, typename _Tp = typename iterator_traits<_RandomAccessIterator>::value_type>
static void inline insertsort(_RandomAccessIterator _first, _RandomAccessIterator _last)
{ // [_first, _last)
    if (_first < _last)
    {
        _RandomAccessIterator i, j;
        for (i = _first + 1; i < _last; ++i)
        {
            _Tp _val = *i;
            if (_val < *_first)
            {
                copy_backward(_first, i, i + 1);
                *_first = _val;
                continue;
            }
            for (j = i; j > _first && *(j - 1) > _val; --j)
                *j = *(j - 1);
            *j = _val;
        }
    }
}

const int __Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};
template <typename _RandomAccessIterator, typename _Tp = typename iterator_traits<_RandomAccessIterator>::value_type>
static void shellsort(_RandomAccessIterator _first, _RandomAccessIterator _last, const _Tp &_val)
{
    int c, increment, _size = _last - _first;
    _RandomAccessIterator i, j;
    for (c = 0; _size <= __Sedgewick[c]; ++c)
        ;
    for (increment = __Sedgewick[c]; increment > 0; increment = __Sedgewick[++c])
        for (i = _first + increment; i < _last; ++i)
        {
            _Tp tmp = *i;
            for (j = i; _first + increment <= j && *(j - increment) > tmp; j -= increment)
                *j = *(j - increment);
            *j = tmp;
        }
}

//[]
template <typename _RandomAccessIterator, typename _Tp = typename iterator_traits<_RandomAccessIterator>::value_type>
static inline void __merge(_RandomAccessIterator _first, _RandomAccessIterator _mid, _RandomAccessIterator _last)
{
    // a temporary array to store merged result
    _Tp merged[_last - _first + 1];
    _RandomAccessIterator i = _first, j = _mid + 1;
    int _size = 0;
    while (i <= _mid && j <= _last)
        merged[_size++] = (*i < *j ? *(i++) : *(j++));
    while (i <= _mid)
        merged[_size++] = *(i++);
    while (j <= _last)
        merged[_size++] = *(j++);
    copy(merged, merged + _size, _first);
}

//[]
template <typename _RandomAccessIterator>
static void __mergesort(_RandomAccessIterator _first, _RandomAccessIterator _last)
{
    if (_first < _last)
    {
        _RandomAccessIterator _mid = _first + (_last - _first) / 2;
        __mergesort(_first, _mid);
        __mergesort(_mid + 1, _last);
        __merge(_first, _mid, _last);
    }
}

template <typename _RandomAccessIterator>
static void __mergesort_non_recur(_RandomAccessIterator _first, _RandomAccessIterator _last)
{
    int len = 1, _size = _last - _first;
    for (; len < _size; len <<= 1)
        for (_RandomAccessIterator lo = _first; lo + len < _last; lo += (len << 1))
        {
            _RandomAccessIterator _mid = lo + len - 1, hi = lo + (len << 1) - 1;
            hi = _last - 1 < hi ? _last - 1 : hi;
            __merge(lo, _mid, hi);
        }
}

//[)
template <typename _RandomAccessIterator>
static void inline mergeSort(_RandomAccessIterator _first, _RandomAccessIterator _last)
{

    //__mergesort(_first, --_last);
    __mergesort_non_recur(_first, _last);
}

template <typename _RandomAccessIterator>
static inline void __median3(_RandomAccessIterator _first, _RandomAccessIterator _last)
{
    _RandomAccessIterator _mid = _first + (_last - _first) / 2;
    if (*_first > *_mid)
        iter_swap(_first, _mid);
    if (*_first > *_last)
        iter_swap(_first, _last);
    if (*_mid > *_last)
        iter_swap(_mid, _last);
    iter_swap(_last, _mid);
}

//Partition routine for quicksort []
template <typename _RandomAccessIterator, typename _Tp = typename iterator_traits<_RandomAccessIterator>::value_type>
static _RandomAccessIterator __partition(_RandomAccessIterator _first, _RandomAccessIterator _last)
{
    __median3(_first, _last);
    _Tp pivot = *_last;
    _RandomAccessIterator i = _first - 1, j = _first;
    for (; j < _last; ++j)
        if (*j < pivot)
            iter_swap(++i, j);
    iter_swap(i + 1, _last);
    return i + 1;
}
//[]
#define CUTOFF 10
template <typename _RandomAccessIterator>
static void __quicksort(_RandomAccessIterator _first, _RandomAccessIterator _last)
{
    if (_first < _last)
    {
        if (_last - _first < CUTOFF)
        {
            insertsort(_first, _last + 1);
            return;
        }
        _RandomAccessIterator p = __partition(_first, _last);
        __quicksort(_first, p - 1);
        __quicksort(p + 1, _last);
    }
}
//[)
template <typename _RandomAccessIterator>
static void inline quicksort(_RandomAccessIterator _first, _RandomAccessIterator _last)
{
    __quicksort(_first, --_last);
}

//[)
template <typename _RandomAccessIterator>
void qksort(_RandomAccessIterator _first, _RandomAccessIterator _last)
{
    if (_first >= _last)
        return;
    _RandomAccessIterator _mid = _first;
    _mid = partition(_first + 1, _last, bind2nd(less<int>(), *_mid));
    iter_swap(_mid - 1, _first);
    qksort(_first, _mid - 1);
    qksort(_mid, _last);
}

//[]
template <typename _RandomAccessIterator>
static _RandomAccessIterator __kth_element(_RandomAccessIterator _first, _RandomAccessIterator _last, int k)
{
    _RandomAccessIterator p = __partition(_first, _last, *_first);
    int r = p - _first;
    if (r == k)
        return p;
    else if (k < r)
        return __kth_element(_first, p - 1, k);
    else
        return __kth_element(p + 1, _last, k - (r + 1));
}
//[)
template <typename _RandomAccessIterator>
static inline _RandomAccessIterator kth_element(_RandomAccessIterator _first, _RandomAccessIterator _last, int k)
{
    return __kth_element(_first, --_last, k);
}

template <typename _Tp>
static void __partial_k_sort(_Tp *_first, _Tp *_last, int k)
{
    // k < size / 2  sort k max elem to bottom;
    _Tp *walk = _last;
    if (k > _last - _first)
        return;
    makeheap(_first, _last);
    for (; _last - walk < k; walk--)
        popheap(_first, walk);
}

template <typename _Tp>
static void __partial_k_sort2(_Tp *_first, _Tp *_last, int k)
{
    // k > size / 2  sort k max elem to neck;
    _Tp *walk = _first + k;
    if (k > _last - _first)
        return;
    makeheap(_first, _first + k, greater<int>());
    for (; walk < _last; ++walk)
    {
        if (*walk > *_first)
        {
            //swap(*walk, *_first);
            popheap(_first, _first + k, greater<int>());
            swap(*walk, *(_first + k - 1));
            pushheap(_first, _first + k, greater<int>());
        }
    }
}

/*

1:Build max heap , then call DeletMax for k times.  
O(N + KlogN)
2:Keep a min heap of k elements. Compare a new element with the root and, DeletMin and Insert the
new element (if the new one is larger.)
O(K + NlogK)
3:partition Average = O(N). Worst=O(N2).

*/

template <typename _Tp>
static void tableSort(_Tp *a, _Tp *b)
{
    int _size = b - a;
    vector<int> table(_size);
    iota(table.begin(), table.end(), 0);
    for (int i = 1; i < _size; i++)
    {
        int tmp = table[i];
        int j;
        for (j = i; 1 <= j && a[tmp] < a[table[j - 1]]; j -= 1)
            table[j] = table[j - 1];
        table[j] = tmp;
    }
    for (int i = 0; i < _size; i++)
    {
        if (table[i] != i)
        {
            _Tp _val = a[i];
            int j = i, last = i, next;
            for (; table[j] != j; j = next)
            {
                last = j;
                next = table[j];
                a[j] = a[table[j]];
                table[j] = j;
            }
            a[last] = _val;
        }
    }
}
/*
for (int i = 0; i < SIZE; i++)
    {
        if (a[i] != i)
        {
            int start = i, j = a[i], tmp;
            for (; j != start; j = tmp)
            {
                tmp = a[j];
                a[j] = j;
            }
            a[i] = i;
        }
    }
*/

}; // namespace dsa

// namespace dsa

#endif