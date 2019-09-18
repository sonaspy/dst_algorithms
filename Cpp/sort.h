// author -sonaspy@outlook.com
// coding - utf_8

#ifndef __NEW_SORT__
#define __NEW_SORT__
#include "functions.h"
using namespace std;
namespace dsa
{
template <typename RandAccessor>
static void HeapSort(RandAccessor lo, RandAccessor hi)
{
    make_heap(lo, hi);
    for (int i = hi - lo; i > 1; --i)
        pop_heap(lo, lo + i);
}

template <typename RandAccessor>
static void bubbleSort(RandAccessor lo, RandAccessor hi)
{ // Bubble largest element in a[0:n-1] to hi.
    RandAccessor i, k;
    for (k = hi - 1; k > lo; k--)
    {
        bool swapped = 0;
        for (i = lo; i < k; i++)
            if (*i > *(i + 1))
            {
                iter_swap(i, (i + 1));
                swapped = 1;
            }
        if (!swapped)
            break;
    }
}

template <typename RandAccessor>
static void double_bubbleSort(RandAccessor lo, RandAccessor hi)
{ // Bubble largest element in a[0:n-1] to hi.
    bool flag = true;
    hi--;
    RandAccessor i;
    while (lo < hi && flag)
    {
        flag = false;
        for (i = lo; i < hi; ++i)
            if (*i > *(i + 1))
                iter_swap(i, (i + 1)), flag = true;
        hi--;
        for (i = hi; i > lo; --i)
            if (*i < *(i - 1))
                iter_swap(i, (i - 1)), flag = true;
        lo++;
    }
}

template <typename RandAccessor>
static void selectionSort(RandAccessor lo, RandAccessor hi)
{ // Sort the n elements a[0:n-1].

    RandAccessor i;
    for (i = hi; i > lo + 1; i--)
        iter_swap(max_element(lo, i), (i - 1));
}

template <typename RandAccessor>
static void insertionSort(RandAccessor lo, RandAccessor hi)
{ // [lo, hi)
    if (lo != hi)
        for (RandAccessor i = lo + 1; i != hi; ++i)
            linear_insert(lo, i, *i);
}

const int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};
template <typename RandAccessor, typename T>
static void __shellsort(RandAccessor lo, RandAccessor hi, const T &val)
{
    int c, increment, n = hi - lo;
    RandAccessor i, j;
    for (c = 0; n <= Sedgewick[c]; ++c)
        ;
    for (increment = Sedgewick[c]; increment > 0; increment = Sedgewick[++c])
        for (i = lo + increment; i < hi; ++i)
        {
            T tmp = *i;
            for (j = i; lo + increment <= j && *(j - increment) > tmp; j -= increment)
                *j = *(j - increment);
            *j = tmp;
        }
}

template <typename RandAccessor>
static void shellsort(RandAccessor lo, RandAccessor hi)
{
    __shellsort(lo, hi, *lo);
}
template <typename RandAccessor, typename T>
static inline void __merge(RandAccessor lo, RandAccessor mid, RandAccessor hi, const T &val)
{
    // a temporary array to store merged result
    T merged[hi - lo + 1];
    RandAccessor i = lo, j = mid + 1;
    int cur = 0;
    while (i <= mid && j <= hi)
        merged[cur++] = (*i < *j ? *(i++) : *(j++));
    while (i <= mid)
        merged[cur++] = *(i++);
    while (j <= hi)
        merged[cur++] = *(j++);
    copy(merged, merged + cur, lo);
}

template <typename RandAccessor, typename T>
static void __merge_sort(RandAccessor lo, RandAccessor hi, const T &val)
{
    if (lo < hi)
    {
        RandAccessor mid = lo + (hi - lo) / 2;
        __merge_sort(lo, mid, val);
        __merge_sort(mid + 1, hi, val);
        __merge(lo, mid, hi, val);
    }
}
template <typename RandAccessor, typename T>
static void __merge_sort0(RandAccessor lo, RandAccessor hi, const T &val)
{
    int len = 1, n = hi - lo;
    while (len <= n)
    {
        for (RandAccessor i = lo; i + len <= hi; i += len * 2)
        {
            RandAccessor mid = i + len - 1, right = i + 2 * len - 1;
            right = right > hi - 1 ? hi - 1 : right;
            __merge(i, mid, right, *lo);
        }
        len <<= 1;
    }
}

template <typename RandAccessor>
static void inline mergesort__(RandAccessor lo, RandAccessor hi)
{
    // __merge_sort(lo, hi, *lo);   // recursive
    __merge_sort0(lo, hi, *lo);
}

#define CUTOFF 50
template <typename RandAccessor>
static inline void __median3(RandAccessor lo, RandAccessor hi)
{
    RandAccessor mid = lo + (hi - lo) / 2;
    if (*lo > *mid)
        iter_swap(lo, mid);
    if (*lo > *hi)
        iter_swap(lo, hi);
    if (*mid > *hi)
        iter_swap(mid, hi);
    iter_swap(hi, mid);
}
//Partition routine for quicksort
template <typename RandAccessor, typename T>
static RandAccessor __partition(RandAccessor lo, RandAccessor hi, const T &val)
{
    __median3(lo, hi);
    T pivot = *hi;
    RandAccessor i = lo - 1, j = lo;
    for (; j < hi; j++)
        if (*j < pivot)
        {
            i++;
            iter_swap(i, j);
        }
    iter_swap(i + 1, hi);
    return i + 1;
}
template <typename RandAccessor>
static void __quicksort(RandAccessor lo, RandAccessor hi)
{
    if (lo < hi)
    {
        RandAccessor p = __partition(lo, hi, *lo);
        __quicksort(lo, p - 1);
        __quicksort(p + 1, hi);
    }
}
template <typename RandAccessor>
static void inline quicksort(RandAccessor lo, RandAccessor hi)
{
    hi--;
    __quicksort(lo, hi);
}

template <typename RandAccessor>
void quickSort(RandAccessor lo, RandAccessor hi)
{
    if (lo >= hi)
        return;
    RandAccessor mid = lo;
    mid = partition(lo + 1, hi, bind2nd(less<int>(), *mid));
    iter_swap(mid - 1, lo);
    quickSort(lo, mid - 1);
    quickSort(mid, hi);
}

template <typename RandAccessor>
static RandAccessor __kth_element(RandAccessor lo, RandAccessor hi, int k)
{
    RandAccessor p = __partition(lo, hi, *lo);
    int r = p - lo;
    if (r == k)
        return p;
    else if (k < r)
        return __kth_element(lo, p - 1, k);
    else
        return __kth_element(p + 1, hi, k - (r + 1));
}
template <typename RandAccessor>
static RandAccessor inline kth_element(RandAccessor lo, RandAccessor hi, int k)
{
    hi--;
    return __kth_element(lo, hi, k);
}

template <typename T>
static void __partial_k_sort(T *lo, T *hi, int k)
{
    // k < size / 2  sort k max elem to bottom;
    T *walk = hi;
    if (k > hi - lo)
        return;
    make_heap(lo, hi);
    for (; hi - walk < k; walk--)
        pop_heap(lo, walk);
}

template <typename T>
static void __partial_k_sort2(T *lo, T *hi, int k)
{
    // k > size / 2  sort k max elem to neck;
    T *walk = lo + k;
    if (k > hi - lo)
        return;
    make_heap(lo, lo + k, greater<int>());
    for (; walk < hi; ++walk)
    {
        if (*walk > *lo)
        {
            //swap(*walk, *lo);
            pop_heap(lo, lo + k, greater<int>());
            swap(*walk, *(lo + k - 1));
            push_heap(lo, lo + k, greater<int>());
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

template <typename T>
static void tableSort(T *a, T *b)
{
    int n = b - a;
    vector<int> table(n);
    for (int i = 0; i < n; i++)
        table[i] = i;
    for (int i = 1; i < n; i++)
    {
        int tmp = table[i];
        int j;
        for (j = i; 1 <= j && a[tmp] < a[table[j - 1]]; j -= 1)
            table[j] = table[j - 1];
        table[j] = tmp;
    }
    for (int i = 0; i < n; i++)
    {
        T val = a[i];
        int j = i, last = i, next;
        for (; table[j] != j; j = next)
        {
            last = j;
            next = table[j];
            a[j] = a[table[j]];
            table[j] = j;
        }
        a[last] = val;
    }
}

}; // namespace dsa

// namespace dsa

#endif