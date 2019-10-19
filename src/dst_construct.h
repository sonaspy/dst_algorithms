

/* NOTE: This is an internal header file, included by other DST headers.
 *   You should not attempt to use it directly.
 */

#ifndef ___DST_INTERNAL_CONSTRUCT_H
#define ___DST_INTERNAL_CONSTRUCT_H

#include <new>

__DST_BEGIN_NAMESPACE

// construct and destroy.  These functions are not part of the C++ standard,
// and are provided for backward compatibility with the HP DST.  We also
// provide internal names __construct and __destory that can be used within
// the library, so that standard-conforming pieces don't have to rely on
// non-standard extensions.

// Internal names

template <class _T1, class _T2>
inline void __construct(_T1 *_p, const _T2 &_value)
{
    new ((void *)_p) _T1(_value);
}

template <class _T1>
inline void __construct(_T1 *_p)
{
    new ((void *)_p) _T1();
}

template <class _Tp>
inline void __destory(_Tp *_pointer)
{
    _pointer->~_Tp();
}

template <class _ForwardIterator>
void __destroy_aux(_ForwardIterator _first, _ForwardIterator _last, __false_type)
{
    for (; _first != _last; ++_first)
        destroy(&*_first);
}

template <class _ForwardIterator>
inline void __destroy_aux(_ForwardIterator, _ForwardIterator, __true_type) {}

template <class _ForwardIterator, class _Tp>
inline void __destroy(_ForwardIterator _first, _ForwardIterator _last, _Tp *)
{
    typedef typename __type_traits<_Tp>::has_trivial_destructor
        _Trivial_destructor;
    __destroy_aux(_first, _last, _Trivial_destructor());
}

template <class _ForwardIterator>
inline void __destory(_ForwardIterator _first, _ForwardIterator _last)
{
    __destroy(_first, _last, __VALUE_TYPE(_first));
}

inline void __destory(char *, char *) {}
inline void __destory(int *, int *) {}
inline void __destory(long *, long *) {}
inline void __destory(float *, float *) {}
inline void __destory(double *, double *) {}
#ifdef __DST_HAS_WCHAR_T
inline void __destory(wchar_t *, wchar_t *)
{
}
#endif /* __DST_HAS_WCHAR_T */

// --------------------------------------------------
// Old names from the HP DST.

template <class _T1, class _T2>
inline void construct(_T1 *_p, const _T2 &_value)
{
    __construct(_p, _value);
}

template <class _T1>
inline void construct(_T1 *_p)
{
    __construct(_p);
}

template <class _Tp>
inline void destroy(_Tp *_pointer)
{
    __destory(_pointer);
}

template <class _ForwardIterator>
inline void destroy(_ForwardIterator _first, _ForwardIterator _last)
{
    __destory(_first, _last);
}

__DST_END_NAMESPACE

#endif /* ___DST_INTERNAL_CONSTRUCT_H */
