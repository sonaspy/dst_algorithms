

/* NOTE: This is an internal header file, included by other DST headers.
 *   You should not attempt to use it directly.
 */

#ifndef ___DST_INTERNAL_CONSTRUCT_H
#define ___DST_INTERNAL_CONSTRUCT_H

#include <new>

__DST_BEGIN_NAMESPACE

// construct and destroy.  These functions are not part of the C++ standard,
// and are provided for backward compatibility with the HP DST.  We also
// provide internal names _Construct and _Destroy that can be used within
// the library, so that standard-conforming pieces don't have to rely on
// non-standard extensions.

// Internal names

template <class _T1, class _T2>
inline void _Construct(_T1 *_p, const _T2 &_value)
{
    new ((void *)_p) _T1(_value);
}

template <class _T1>
inline void _Construct(_T1 *_p)
{
    new ((void *)_p) _T1();
}

template <class _Tp>
inline void _Destroy(_Tp *_pointer)
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
inline void _Destroy(_ForwardIterator _first, _ForwardIterator _last)
{
    __destroy(_first, _last, __VALUE_TYPE(_first));
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
inline void construct(_T1 *_p, const _T2 &_value)
{
    _Construct(_p, _value);
}

template <class _T1>
inline void construct(_T1 *_p)
{
    _Construct(_p);
}

template <class _Tp>
inline void destroy(_Tp *_pointer)
{
    _Destroy(_pointer);
}

template <class _ForwardIterator>
inline void destroy(_ForwardIterator _first, _ForwardIterator _last)
{
    _Destroy(_first, _last);
}

__DST_END_NAMESPACE

#endif /* ___DST_INTERNAL_CONSTRUCT_H */
