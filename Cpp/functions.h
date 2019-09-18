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