// author - sonaspy@outlook.com
// coding - utf_8

#ifndef __ALGORITHMS__
#define __ALGORITHMS__
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <stack>
using namespace std;
__DST_BEGIN_NAMESPACE

// template <class _Tp>
// void swap(_Tp &a, _Tp &b)
// {
//     _Tp _tmp = a;
//     a = b;
//     b = _tmp;
// }
// template <class _Iterator>
// void iter_swap(_Iterator &a, _Iterator &b)
// {
//     swap(*a, *b);
// }


#include <bitset>
template <int _Digit>
bitset<1> __checksum(bitset<_Digit> b, bool _even)
{
    bitset<1> res(b[0]);
    for (int i = 1; i < _Digit; i++)
        res ^= bitset<1>(b[i]);
    return _even ? res : ~res;
}

template <class _RandomAccessIterator>
void __reverse(_RandomAccessIterator _first, _RandomAccessIterator _last)
{
    if (_first < _last)
        for (; _first < --_last; ++_first)
            iter_swap(_first, _last);
}

template <class _RandomAccessIterator>
void print_vector(_RandomAccessIterator _first, _RandomAccessIterator _last)
{
    if (_first < _last)
    {
        std::cout << *(_first);
        for (auto i = _first + 1; i < _last; i++)
            std::cout << " -> " << *i;
    }
    std::cout << endl;
}

template <class _RandomAccessIterator>
void __unique_merge(_RandomAccessIterator _first1, _RandomAccessIterator _last1, _RandomAccessIterator _first2, _RandomAccessIterator _last2, _RandomAccessIterator _res)
{
    _RandomAccessIterator _cur = _res;
    while (_first1 < _last1 && _first2 < _last2)
    {
        if (*_first1 < *_first2)
        {
            if (_cur == _res || *(_cur - 1) != *_first1)
                *(_cur++) = *_first1;
            _first1++;
        }
        else if (*_first2 < *_first1)
        {
            if (_cur == _res || *(_cur - 1) != *_first2)
                *(_cur++) = *_first2;
            _first2++;
        }
        else
        {
            if (_cur == _res || *(_cur - 1) != *_first2)
                *(_cur++) = *_first1;
            _first1++, _first2++;
        }
    }
    while (_first1 < _last1)
        *(_cur++) = *(_first1++);
    while (_first2 < _last2)
        *(_cur++) = *(_first2++);
}

template <class _RandomAccessIterator>
bool array_move(_RandomAccessIterator _first, _RandomAccessIterator _last, int _offset, bool _is_left)
{
    if (_first < _last)
    {
        __reverse(_first, _last);
        if (_is_left)
        {
            __reverse(_first, _last - _offset);
            __reverse(_last - _offset, _last);
        }
        else
        {
            __reverse(_first, _first + _offset);
            __reverse(_first + _offset, _last);
        }
        return true;
    }
    return false;
}
template <class _RandomAccessIterator>
void unique_array(_RandomAccessIterator _first, _RandomAccessIterator _last)
{
    _RandomAccessIterator i = _first, j = _first + 1;
    for (; j < _last; ++j)
        if (*i != *j)
            *(++i) = *j;
}
vector<pair<int, int>> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> mapping;
    vector<pair<int, int>> result;
    for (auto i : nums)
        mapping[i] = 0;
    for (auto i : nums)
    {
        const int gap = target - i;
        if (mapping.count(gap) && !mapping[gap] && !mapping[i])
        {
            result.push_back(make_pair(i, gap));
            mapping[gap] = 1;
            mapping[i] = 1;
        }
    }
    return result;
}

// find median in 2 array
template <class _RandomAccessIterator, class _Tp = typename iterator_traits<_RandomAccessIterator>::value_type>
_Tp median_search(_RandomAccessIterator _first1, _RandomAccessIterator _last1, _RandomAccessIterator _first2, _RandomAccessIterator _last2)
{
    _RandomAccessIterator _m1, _m2;
    while (_first1 < _last1 || _first2 < _last2)
    {
        _m1 = _first1 + (_last1 - _first1) / 2;
        _m2 = _first2 + (_last2 - _first2) / 2;
        if (*_m1 == *_m2)
            return *_m1;
        if (*_m1 < *_m2)
        {
            _first1 = (_last1 - _first1) % 2 ? _m1 + 1 : _m1;
            _last2 = _m2;
        }
        else
        {
            _first2 = (_last2 - _first2) % 2 ? _m2 + 1 : _m2;
            _last1 = _m1;
        }
    }
    return min(*_first1, *_first2);
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

template <class _RandomAccessIterator>
bool isparlindrome(_RandomAccessIterator _first, _RandomAccessIterator _last)
{
    if (_first < _last)
        for (; _first < --_last; ++_first)
            if (*_first != *_last)
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
    int64_t _num = n;
    if (_num < 0)
    {
        x = 1 / x;
        _num = -_num;
    }
    double _ans = 1, _cur = x;
    for (int64_t i = _num; i; i /= 2)
    {
        if (i % 2 == 1)
            _ans *= _cur;
        _cur *= _cur;
    }
    return _ans;
}

// heap
template <typename _RandomAccessIterator, typename _Compare>
static inline void __siftdown(_RandomAccessIterator _base, int _pos, int _border, _Compare _comp)
{
    int _up = _pos, _down = _pos * 2 + 1;
    for (; _down < _border; _up = _down, _down = _down * 2 + 1)
    {
        if (_down + 1 < _border && _comp(*(_base + _down), *(_base + _down + 1)))
            _down++;
        if (_comp(*(_base + _up), *(_base + _down)))
            iter_swap(_base + _down, _base + _up);
        else
            break;
    }
}

template <typename _RandomAccessIterator, typename _Compare>
static inline void __makeheap(_RandomAccessIterator _first, _RandomAccessIterator _last, _Compare _comp)
{
    int _pos = (_last - _first) / 2 - 1, _border = _last - _first;
    for (; 0 <= _pos; --_pos)
    {
        __siftdown(_first, _pos, _border, _comp);
    }
}

template <typename _RandomAccessIterator, typename _Compare>
static inline void __pushheap(_RandomAccessIterator _first, _RandomAccessIterator _last, _Compare _comp)
{
    int _pos = _last - _first - 1, _up = (_pos - 1) / 2;
    for (; 1; _pos = _up, _up = (_up - 1) / 2)
    {
        if (_comp(*(_first + _up), *(_first + _pos)))
            iter_swap(_first + _pos, _first + _up);
        else
            break;
        if (!_up)
            break;
    }
}

template <typename _RandomAccessIterator, typename _Compare>
static inline void __popheap(_RandomAccessIterator _first, _RandomAccessIterator _last, _Compare _comp)
{
    iter_swap(_first, _last - 1);
    __siftdown(_first, 0, _last - 1 - _first, _comp);
}

template <typename _RandomAccessIterator, typename _Compare>
static inline bool __isheap(_RandomAccessIterator _first, _RandomAccessIterator _last, _Compare _comp)
{
    int _pos = (_last - _first) / 2 - 1, _border = _last - _first;
    if (!_border)
        return false;
    if (_border % 2 == 0)
    {
        if (_comp(*(_first + _pos), *(_first + _pos * 2 + 1)))
            return false;
        --_pos;
    }
    for (; 0 <= _pos; --_pos)
        if (_comp(*(_first + _pos), *(_first + _pos * 2 + 1)) || _comp(*(_first + _pos), *(_first + _pos * 2 + 2)))
            return false;
    return true;
}

template <class _RandomAccessIterator>
static inline void makeheap(_RandomAccessIterator _first, _RandomAccessIterator _last)
{
    __makeheap(_first, _last, less<typename iterator_traits<_RandomAccessIterator>::value_type>());
}

template <class _RandomAccessIterator, typename _Compare>
static inline void makeheap(_RandomAccessIterator _first, _RandomAccessIterator _last, _Compare _comp)
{
    __makeheap(_first, _last, _comp);
}

template <class _RandomAccessIterator>
static inline void pushheap(_RandomAccessIterator _first, _RandomAccessIterator _last)
{
    __pushheap(_first, _last, less<typename iterator_traits<_RandomAccessIterator>::value_type>());
}

template <class _RandomAccessIterator, typename _Compare>
static inline void pushheap(_RandomAccessIterator _first, _RandomAccessIterator _last, _Compare _comp)
{
    __pushheap(_first, _last, _comp);
}

template <class _RandomAccessIterator>
static inline void popheap(_RandomAccessIterator _first, _RandomAccessIterator _last)
{
    __popheap(_first, _last, less<typename iterator_traits<_RandomAccessIterator>::value_type>());
}

template <class _RandomAccessIterator, typename _Compare>
static inline void popheap(_RandomAccessIterator _first, _RandomAccessIterator _last, _Compare _comp)
{
    __popheap(_first, _last, _comp);
}

template <class _RandomAccessIterator>
static inline bool isheap(_RandomAccessIterator _first, _RandomAccessIterator _last)
{
    return __isheap(_first, _last, less<typename iterator_traits<_RandomAccessIterator>::value_type>());
}

template <class _RandomAccessIterator, typename _Compare>
static inline void isheap(_RandomAccessIterator _first, _RandomAccessIterator _last, _Compare _comp)
{
    __isheap(_first, _last, _comp);
}
//heap

// binary search
template <typename _Tp, typename _RandomAccessIterator>
_RandomAccessIterator __lower_bound(_RandomAccessIterator _first, _RandomAccessIterator _last, const _Tp &_val)
{
    int _length = _last - _first, _half_len;
    _RandomAccessIterator _mid;
    while (_length > 0)
    {
        _half_len = _length >> 1;
        _mid = _first + _half_len;
        if (*_mid < _val)
        {
            _first = _mid + 1;
            _length -= _half_len + 1;
        }
        else
            _length = _half_len;
    }
    return _first;
}

template <typename _Tp, typename _RandomAccessIterator>
_RandomAccessIterator __upper_bound(_RandomAccessIterator _first, _RandomAccessIterator _last, const _Tp &_val)
{
    int _length = _last - _first, _half_len;
    _RandomAccessIterator _mid;
    while (_length > 0)
    {
        _half_len = _length >> 1;
        _mid = _first + _half_len;
        if (*_mid <= _val)
        {
            _first = _mid + 1;
            _length -= _half_len + 1;
        }
        else
            _length = _half_len;
    }
    return _first;
}

template <class _RandomAccessIterator, class _Tp>
_RandomAccessIterator bin_search(_RandomAccessIterator _first, _RandomAccessIterator _last, const _Tp &_val)
{
    _RandomAccessIterator _mid;
    while (_first <= _last)
    {
        _mid = _first + (_last - _first) / 2;
        if (*_mid < _val)
            _first = _mid + 1;
        else if (_val < *_mid)
            _last = _mid - 1;
        else
            return _mid;
    }
    return _last;
}
// binary search

// vector use , push_back rear _val, then __linear_insert(a.begin(), a.end()-1, a.back());
template <typename _RandomAccessIterator, typename _Tp>
inline void __linear_insert(_RandomAccessIterator _first, _RandomAccessIterator _last, const _Tp _val)
{ // [,]
    if (_first < _last)
    {
        if (_val > *(_last - 1))
            return;
        _RandomAccessIterator _pos = _val < *_first ? _first : __upper_bound(_first, _last, _val);
        copy_backward(_pos, _last, _last + 1);
        *_pos = _val;
    }
}

bool isMatch(vector<int> &push_seq, vector<int> &pop_seq, int capacity)
{
    int walk = 0;
    stack<int> s;
    for (int j = 0; j < push_seq.size(); j++)
    {
        s.push(push_seq[j]);
        if (s.size() > capacity)
            break;
        while (s.size() && s.top() == pop_seq[walk])
            s.pop(), walk++;
    }
    return walk == capacity;
}

template <typename _RandomAccessIterator, typename _Tp = typename iterator_traits<_RandomAccessIterator>::value_type>
bool isBSTseq(_RandomAccessIterator _first, _RandomAccessIterator _last)
{
    _RandomAccessIterator i, j;
    bool _less;
    _Tp _val;
    for (i = _first; i < _last - 1; ++i)
    {
        _less = *i < *(i + 1);
        _val = *i;
        if (_less)
        {
            for (j = i + 2; j < _last; ++j)
                if (*i > *j)
                    return false;
        }
        else
        {
            for (j = i + 2; j < _last; ++j)
                if (*i < *j)
                    return false;
        }
    }
    return true;
}

template <typename _RandomAccessIterator, typename _Compare>
pair<_RandomAccessIterator, _RandomAccessIterator> __lcs(_RandomAccessIterator _first, _RandomAccessIterator _last, _Compare _comp)
{
    auto _iter_pair = make_pair(_first, _first + 1);
    _RandomAccessIterator i, j;
    int _maxlen = 1;
    for (i = _first; i < _last - 1; i = j)
    {
        for (j = i + 1; j < _last && _comp(*(j - 1), *j); ++j)
            ;
        if (_maxlen < j - i)
        {
            _iter_pair = make_pair(i, j);
            _maxlen = j - i;
        }
    }
    return _iter_pair;
}

template <typename _RandomAccessIterator, typename _Compare>
inline pair<_RandomAccessIterator, _RandomAccessIterator> lcs(_RandomAccessIterator _first, _RandomAccessIterator _last, _Compare _comp)
{
    return __lcs(_first, _last, _comp);
}
template <typename _RandomAccessIterator>
inline pair<_RandomAccessIterator, _RandomAccessIterator> lcs(_RandomAccessIterator _first, _RandomAccessIterator _last)
{
    return __lcs(_first, _last, less<typename iterator_traits<_RandomAccessIterator>::value_type>());
}

__DST_END_NAMESPACE

#endif