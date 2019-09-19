// author - sonaspy@outlook.com
// coding - utf_8

#ifndef __FUNCTIONS__
#define __FUNCTIONS__
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
namespace dsa
{

template <typename T>
void output_vec(vector<T> &a)
{
    cout << a[0];
    for (int i = 1; i < a.size(); i++)
        cout << " -> " << a[i];
    cout << endl;
}

template <class RandomIterator>
void __reverse(RandomIterator lo, RandomIterator hi)
{
    if (lo < hi)
        for (; lo < --hi; ++lo)
            iter_swap(lo, hi);
}
// find median in 2 array
template <class T>
T M_search(T *lo1, T *hi1, T *lo2, T *hi2)
{
    T *m1, *m2;
    while (lo1 < hi1 || lo2 < hi2)
    {
        m1 = lo1 + (hi1 - lo1) / 2;
        m2 = lo2 + (hi2 - lo2) / 2;
        if (*m1 == *m2)
            return *m1;
        if (*m1 < *m2)
        {
            lo1 = (hi1 - lo1) % 2 ? m1 + 1 : m1;
            hi2 = m2;
        }
        else
        {
            lo2 = (hi2 - lo2) % 2 ? m2 + 1 : m2;
            hi1 = m1;
        }
    }
    return min(*lo1, *lo2);
}
inline int __gcd(int a, int b)
{
    while (b)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}
template <class RandomIterator>
bool isparlindrome(RandomIterator lo, RandomIterator hi)
{
    if (lo < hi)
        for (; lo < --hi; ++lo)
            if (*lo != *hi)
                return false;
    return true;
}
double __polynomial(int n, double a[], double x)
{
    int i;
    double p = a[n];
    for (i = n; i; --i)
        p = a[i - 1] + x * p;
    return p;
}

void towersOfHanoi(int n, char x, char y, char z)
{ // Move the top n disks from tower x to tower y.
    // Use tower z for intermediate storage.
    if (n > 0)
    {
        towersOfHanoi(n - 1, x, z, y);
        std::cout << "Move top disk from tower " << x
                  << " to top of tower " << y << std::endl;
        towersOfHanoi(n - 1, z, y, x);
    }
}
double __newpow(double x, int n)
{
    long long N = n;
    if (N < 0)
    {
        x = 1 / x;
        N = -N;
    }
    double ans = 1;
    double cur = x;
    for (long long i = N; i; i /= 2)
    {
        if ((i % 2) == 1)
            ans *= cur;
        cur *= cur;
    }
    return ans;
}

template <typename RandAccessor>
static inline void __siftdown(RandAccessor base, int pos, int border)
{
    int up = pos, down = pos * 2 + 1;
    for (; down < border; up = down, down = down * 2 + 1)
    {
        if (down + 1 < border && *(base + down) < *(base + down + 1))
            down++;
        if (*(base + down) > *(base + up))
            iter_swap(base + down, base + up);
        else
            break;
    }
}
//[lo,hi)
template <typename RandAccessor>
static inline void __makeheap(RandAccessor lo, RandAccessor hi)
{
    int pos = (hi - lo) / 2 - 1, border = hi - lo;
    for (; 0 <= pos; --pos)
    {
        __siftdown(lo, pos, border);
    }
}
//[lo,hi)
template <typename RandAccessor>
static inline void __pushheap(RandAccessor lo, RandAccessor hi)
{
    int pos = hi - lo - 1, _up = (pos - 1) / 2;
    for (; 1; pos = _up, _up = (_up - 1) / 2)
    {
        if (*(lo + pos) > *(lo + _up))
            iter_swap(lo + pos, lo + _up);
        else
            break;
        if (!_up)
            break;
    }
}
//[lo,hi)
template <typename RandAccessor>
static inline void __popheap(RandAccessor lo, RandAccessor hi)
{
    iter_swap(lo, hi - 1);
    __siftdown(lo, 0, hi - 1 - lo);
}
template <typename RandAccessor>
static inline bool __isheap(RandAccessor lo, RandAccessor hi)
{
    int pos = (hi - lo) / 2 - 1, border = hi - lo;
    if (!border)
        return 0;
    if (border % 2 == 0)
    {
        if (*(lo + pos) < *(lo + pos * 2 + 1))
            return 0;
        --pos;
    }
    for (; 0 <= pos; --pos)
        if (*(lo + pos) < *(lo + pos * 2 + 1) || *(lo + pos) < *(lo + pos * 2 + 2))
            return 0;
    return 1;
}

template <typename T, typename RandAccessor>
RandAccessor __lower_bound(RandAccessor lo, RandAccessor hi, const T &val)
{ // binary search
    int _length = hi - lo, _half_len;
    RandAccessor mid;
    while (_length > 0)
    {
        _half_len = _length >> 1;
        mid = lo + _half_len;
        if (*mid < val)
        {
            lo = mid + 1;
            _length -= _half_len + 1;
        }
        else
            _length = _half_len;
    }
    return lo;
}

template <typename T, typename RandAccessor>
RandAccessor __upper_bound(RandAccessor lo, RandAccessor hi, const T &val)
{ // binary search
    int _length = hi - lo, _half_len;
    RandAccessor mid;
    while (_length > 0)
    {
        _half_len = _length >> 1;
        mid = lo + _half_len;
        if (*mid <= val)
        {
            lo = mid + 1;
            _length -= _half_len + 1;
        }
        else
            _length = _half_len;
    }
    return lo;
}
template <typename RandAccessor, typename T>
static inline void linear_insert(RandAccessor lo, RandAccessor hi, const T val)
{ // [lo, hi]
    if (val > *(hi - 1))
        return;
    RandAccessor pos = val < *lo ? lo : __upper_bound(lo, hi, val);
    copy_backward(pos, hi, hi + 1);
    *pos = val;
}

} // namespace dsa

#endif