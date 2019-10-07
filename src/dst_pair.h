
/* NOTE: This is an internal header file, included by other DST headers.
 *   You should not attempt to use it directly.
 */

#ifndef ___DST_INTERNAL_PAIR_H
#define ___DST_INTERNAL_PAIR_H

__DST_BEGIN_NAMESPACE

template <class _T1, class _T2>
struct pair
{
    typedef _T1 first_type;
    typedef _T2 second_type;

    _T1 first;
    _T2 second;
    pair() : first(_T1()), second(_T2()) {}
    pair(const _T1 &__a, const _T2 &__b) : first(__a), second(__b) {}

#ifdef __DST_MEMBER_TEMPLATES
    template <class _U1, class _U2>
    pair(const pair<_U1, _U2> &_p) : first(_p.first), second(_p.second)
    {
    }
#endif
};

template <class _T1, class _T2>
inline bool operator==(const pair<_T1, _T2> &__x, const pair<_T1, _T2> &__y)
{
    return __x.first == __y.first && __x.second == __y.second;
}

template <class _T1, class _T2>
inline bool operator<(const pair<_T1, _T2> &__x, const pair<_T1, _T2> &__y)
{
    return __x.first < __y.first ||
           (!(__y.first < __x.first) && __x.second < __y.second);
}

#ifdef __DST_FUNCTION_TMPL_PARTIAL_ORDER

template <class _T1, class _T2>
inline bool operator!=(const pair<_T1, _T2> &__x, const pair<_T1, _T2> &__y)
{
    return !(__x == __y);
}

template <class _T1, class _T2>
inline bool operator>(const pair<_T1, _T2> &__x, const pair<_T1, _T2> &__y)
{
    return __y < __x;
}

template <class _T1, class _T2>
inline bool operator<=(const pair<_T1, _T2> &__x, const pair<_T1, _T2> &__y)
{
    return !(__y < __x);
}

template <class _T1, class _T2>
inline bool operator>=(const pair<_T1, _T2> &__x, const pair<_T1, _T2> &__y)
{
    return !(__x < __y);
}

#endif /* __DST_FUNCTION_TMPL_PARTIAL_ORDER */

template <class _T1, class _T2>
inline pair<_T1, _T2> make_pair(const _T1 &__x, const _T2 &__y)
{
    return pair<_T1, _T2>(__x, __y);
}

__DST_END_NAMESPACE

#endif /* ___DST_INTERNAL_PAIR_H */
