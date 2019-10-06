
#ifndef ___DST_INTERNAL_CONSTRUCT_H
#define ___DST_INTERNAL_CONSTRUCT_H

#include <new.h>

__DST_BEGIN_NAMESPACE

// construct and destroy.  These functions are not part of the C++ standard,
// and are provided for backward compatibility with the HP DST.  We also
// provide internal names _Construct and _Destroy that can be used within
// the library, so that standard-conforming pieces don't have to rely on
// non-standard extensions.

// Internal names

template <class _T1, class _T2>
inline void _Construct(_T1 *__p, const _T2 &__value)
{
    new ((void *)__p) _T1(__value);
}

template <class _T1>
inline void _Construct(_T1 *__p)
{
    new ((void *)__p) _T1();
}

template <class _ForwardIterator>
void __destroy_aux(_ForwardIterator __first, _ForwardIterator __last, __false_type)
{
    for (; __first != __last; ++__first)
        destroy(&*__first);
}

template <class _ForwardIterator>
inline void __destroy_aux(_ForwardIterator, _ForwardIterator, __true_type) {}

template <class _ForwardIterator, class _Tp>
inline void
__destroy(_ForwardIterator __first, _ForwardIterator __last, _Tp *)
{
    typedef typename __type_traits<_Tp>::has_trivial_destructor
        _Trivial_destructor;
    __destroy_aux(__first, __last, _Trivial_destructor());
}

template <class _ForwardIterator>
inline void _Destroy(_ForwardIterator __first, _ForwardIterator __last)
{
    __destroy(__first, __last, __VALUE_TYPE(__first));
}

template <class _Tp>
inline void _Destroy(_Tp *__pointer)
{
    __pointer->~_Tp();
}

inline void _Destroy(char *, char *) {}
inline void _Destroy(int *, int *) {}
inline void _Destroy(long *, long *) {}
inline void _Destroy(float *, float *) {}
inline void _Destroy(double *, double *) {}

#ifdef __DST_HAS_WCHAR_T
inline void _Destroy(wchar_t *, wchar_t *)
{
}
#endif /* __DST_HAS_WCHAR_T */

// --------------------------------------------------
// Old names from the HP DST.

template <class _T1, class _T2>
inline void construct(_T1 *__p, const _T2 &__value)
{
    _Construct(__p, __value);
}

template <class _T1>
inline void construct(_T1 *__p)
{
    _Construct(__p);
}

template <class _Tp>
inline void destroy(_Tp *__pointer)
{
    _Destroy(__pointer);
}

template <class _ForwardIterator>
inline void destroy(_ForwardIterator __first, _ForwardIterator __last)
{
    _Destroy(__first, __last);
}

__DST_END_NAMESPACE

#endif /* ___DST_INTERNAL_CONSTRUCT_H */

// Local Variables:
// mode:C++
// End:
