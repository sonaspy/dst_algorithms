#ifndef ___DST_INTERNAL_ALGOBASE_H
#define ___DST_INTERNAL_ALGOBASE_H

#ifndef __DST_CONFIG_H
#include "dst_config.h"
#endif
#ifndef ___DST_INTERNAL_RELOPS
#include "dst_relops.h"
#endif
#ifndef ___DST_INTERNAL_PAIR_H
#include "dst_pair.h"
#endif
#ifndef __TYPE_TRAITS_H
#include "type_traits.h"
#endif

#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <stddef.h>
#include <new>

#ifdef __DST_USE_NEW_IOSTREAMS
#include <iosfwd>
#else /* __DST_USE_NEW_IOSTREAMS */
#include "iostream.h"
#endif /* __DST_USE_NEW_IOSTREAMS */

#ifndef ___DST_INTERNAL_ITERATOR_H
#include "dst_iterator_base.h"
#include "dst_iterator.h"
#endif

// We pick up concept_checks.h from dst_iterator_base.h.

__DST_BEGIN_NAMESPACE

// swap and iter_swap

template <class _ForwardIter1, class _ForwardIter2, class _Tp>
inline void __iter_swap(_ForwardIter1 __a, _ForwardIter2 __b, _Tp *) {
    _Tp __tmp = *__a;
    *__a = *__b;
    *__b = __tmp;
}

template <class _ForwardIter1, class _ForwardIter2>
inline void iter_swap(_ForwardIter1 __a, _ForwardIter2 __b) {
    __DST_REQUIRES(_ForwardIter1, _Mutable_ForwardIterator);
    __DST_REQUIRES(_ForwardIter2, _Mutable_ForwardIterator);
    __DST_CONVERTIBLE(typename iterator_traits<_ForwardIter1>::value_type,
                      typename iterator_traits<_ForwardIter2>::value_type);
    __DST_CONVERTIBLE(typename iterator_traits<_ForwardIter2>::value_type,
                      typename iterator_traits<_ForwardIter1>::value_type);
    __iter_swap(__a, __b, __VALUE_TYPE(__a));
}

template <class _Tp> inline void swap(_Tp &__a, _Tp &__b) {
    __DST_REQUIRES(_Tp, _Assignable);
    _Tp __tmp = __a;
    __a = __b;
    __b = __tmp;
}

//--------------------------------------------------
// min and max

#if !defined(__BORLANDC__) || __BORLANDC__ >= 0x540 /* C++ Builder 4.0 */

#undef min
#undef max

template <class _Tp> inline const _Tp &min(const _Tp &__a, const _Tp &__b) {
    __DST_REQUIRES(_Tp, _LessThanComparable);
    return __b < __a ? __b : __a;
}

template <class _Tp> inline const _Tp &max(const _Tp &__a, const _Tp &__b) {
    __DST_REQUIRES(_Tp, _LessThanComparable);
    return __a < __b ? __b : __a;
}

#endif /* __BORLANDC__ */

template <class _Tp, class _Compare>
inline const _Tp &min(const _Tp &__a, const _Tp &__b, _Compare __comp) {
    return __comp(__b, __a) ? __b : __a;
}

template <class _Tp, class _Compare>
inline const _Tp &max(const _Tp &__a, const _Tp &__b, _Compare __comp) {
    return __comp(__a, __b) ? __b : __a;
}

//--------------------------------------------------
// copy

// All of these auxiliary functions serve two purposes.  (1) Replace
// calls to copy with memmove whenever possible.  (Memmove, not memcpy,
// because the input and output ranges are permitted to overlap.)
// (2) If we're using random access iterators, then write the loop as
// a for loop with an explicit count.

template <class _InputIter, class _OutputIter, class _Distance>
inline _OutputIter __copy(_InputIter _first, _InputIter _last,
                          _OutputIter __result, input_iterator_tag,
                          _Distance *) {
    for (; _first != _last; ++__result, ++_first) *__result = *_first;
    return __result;
}

template <class _RandomAccessIter, class _OutputIter, class _Distance>
inline _OutputIter __copy(_RandomAccessIter _first, _RandomAccessIter _last,
                          _OutputIter __result, random_access_iterator_tag,
                          _Distance *) {
    for (_Distance __n = _last - _first; __n > 0; --__n) {
        *__result = *_first;
        ++_first;
        ++__result;
    }
    return __result;
}

template <class _Tp>
inline _Tp *__copy_trivial(const _Tp *_first, const _Tp *_last, _Tp *__result) {
    memmove(__result, _first, sizeof(_Tp) * (_last - _first));
    return __result + (_last - _first);
}

#if defined(__DST_FUNCTION_TMPL_PARTIAL_ORDER)

template <class _InputIter, class _OutputIter>
inline _OutputIter __copy_aux2(_InputIter _first, _InputIter _last,
                               _OutputIter __result, __false_type) {
    return __copy(_first, _last, __result, __ITERATOR_CATEGORY(_first),
                  __DISTANCE_TYPE(_first));
}

template <class _InputIter, class _OutputIter>
inline _OutputIter __copy_aux2(_InputIter _first, _InputIter _last,
                               _OutputIter __result, __true_type) {
    return __copy(_first, _last, __result, __ITERATOR_CATEGORY(_first),
                  __DISTANCE_TYPE(_first));
}

#ifndef __USLC__

template <class _Tp>
inline _Tp *__copy_aux2(_Tp *_first, _Tp *_last, _Tp *__result, __true_type) {
    return __copy_trivial(_first, _last, __result);
}

#endif /* __USLC__ */

template <class _Tp>
inline _Tp *__copy_aux2(const _Tp *_first, const _Tp *_last, _Tp *__result,
                        __true_type) {
    return __copy_trivial(_first, _last, __result);
}

template <class _InputIter, class _OutputIter, class _Tp>
inline _OutputIter __copy_aux(_InputIter _first, _InputIter _last,
                              _OutputIter __result, _Tp *) {
    typedef
        typename __type_traits<_Tp>::has_trivial_assignment_operator _Trivial;
    return __copy_aux2(_first, _last, __result, _Trivial());
}

template <class _InputIter, class _OutputIter>
inline _OutputIter copy(_InputIter _first, _InputIter _last,
                        _OutputIter __result) {
    __DST_REQUIRES(_InputIter, _InputIterator);
    __DST_REQUIRES(_OutputIter, _OutputIterator);
    return __copy_aux(_first, _last, __result, __VALUE_TYPE(_first));
}

// Hack for compilers that don't have partial ordering of function templates
// but do have partial specialization of class templates.
#elif defined(__DST_CLASS_PARTIAL_SPECIALIZATION)

template <class _InputIter, class _OutputIter, class _BoolType>
struct __copy_dispatch {
    static _OutputIter copy(_InputIter _first, _InputIter _last,
                            _OutputIter __result) {
        typedef
            typename iterator_traits<_InputIter>::iterator_category _Category;
        typedef typename iterator_traits<_InputIter>::difference_type _Distance;
        return __copy(_first, _last, __result, _Category(), (_Distance *)0);
    }
};

template <class _Tp> struct __copy_dispatch<_Tp *, _Tp *, __true_type> {
    static _Tp *copy(const _Tp *_first, const _Tp *_last, _Tp *__result) {
        return __copy_trivial(_first, _last, __result);
    }
};

template <class _Tp> struct __copy_dispatch<const _Tp *, _Tp *, __true_type> {
    static _Tp *copy(const _Tp *_first, const _Tp *_last, _Tp *__result) {
        return __copy_trivial(_first, _last, __result);
    }
};

template <class _InputIter, class _OutputIter>
inline _OutputIter copy(_InputIter _first, _InputIter _last,
                        _OutputIter __result) {
    __DST_REQUIRES(_InputIter, _InputIterator);
    __DST_REQUIRES(_OutputIter, _OutputIterator);
    typedef typename iterator_traits<_InputIter>::value_type _Tp;
    typedef
        typename __type_traits<_Tp>::has_trivial_assignment_operator _Trivial;
    return __copy_dispatch<_InputIter, _OutputIter, _Trivial>::copy(
        _first, _last, __result);
}

// Fallback for compilers with neither partial ordering nor partial
// specialization.  Define the faster version for the basic builtin
// types.
#else /* __DST_CLASS_PARTIAL_SPECIALIZATION */

template <class _InputIter, class _OutputIter>
inline _OutputIter copy(_InputIter _first, _InputIter _last,
                        _OutputIter __result) {
    return __copy(_first, _last, __result, __ITERATOR_CATEGORY(_first),
                  __DISTANCE_TYPE(_first));
}

#define ___DST_DECLARE_COPY_TRIVIAL(_Tp)                                       \
    inline _Tp *copy(const _Tp *_first, const _Tp *_last, _Tp *__result) {     \
        memmove(__result, _first, sizeof(_Tp) * (_last - _first));             \
        return __result + (_last - _first);                                    \
    }

___DST_DECLARE_COPY_TRIVIAL(char)
___DST_DECLARE_COPY_TRIVIAL(signed char)
___DST_DECLARE_COPY_TRIVIAL(unsigned char)
___DST_DECLARE_COPY_TRIVIAL(short)
___DST_DECLARE_COPY_TRIVIAL(unsigned short)
___DST_DECLARE_COPY_TRIVIAL(int)
___DST_DECLARE_COPY_TRIVIAL(unsigned int)
___DST_DECLARE_COPY_TRIVIAL(long)
___DST_DECLARE_COPY_TRIVIAL(unsigned long)
#ifdef __DST_HAS_WCHAR_T
___DST_DECLARE_COPY_TRIVIAL(wchar_t)
#endif
#ifdef _DST_LONG_LONG
___DST_DECLARE_COPY_TRIVIAL(long long)
___DST_DECLARE_COPY_TRIVIAL(unsigned long long)
#endif
___DST_DECLARE_COPY_TRIVIAL(float)
___DST_DECLARE_COPY_TRIVIAL(double)
___DST_DECLARE_COPY_TRIVIAL(long double)

#undef ___DST_DECLARE_COPY_TRIVIAL
#endif /* __DST_CLASS_PARTIAL_SPECIALIZATION */

//--------------------------------------------------
// copy_backward

template <class _BidirectionalIter1, class _BidirectionalIter2, class _Distance>
inline _BidirectionalIter2
__copy_backward(_BidirectionalIter1 _first, _BidirectionalIter1 _last,
                _BidirectionalIter2 __result, bidirectional_iterator_tag,
                _Distance *) {
    while (_first != _last) *--__result = *--_last;
    return __result;
}

template <class _RandomAccessIter, class _BidirectionalIter, class _Distance>
inline _BidirectionalIter
__copy_backward(_RandomAccessIter _first, _RandomAccessIter _last,
                _BidirectionalIter __result, random_access_iterator_tag,
                _Distance *) {
    for (_Distance __n = _last - _first; __n > 0; --__n) *--__result = *--_last;
    return __result;
}

#ifdef __DST_CLASS_PARTIAL_SPECIALIZATION

// This dispatch class is a workaround for compilers that do not
// have partial ordering of function templates.  All we're doing is
// creating a specialization so that we can turn a call to copy_backward
// into a memmove whenever possible.

template <class _BidirectionalIter1, class _BidirectionalIter2, class _BoolType>
struct __copy_backward_dispatch {
    typedef
        typename iterator_traits<_BidirectionalIter1>::iterator_category _Cat;
    typedef typename iterator_traits<_BidirectionalIter1>::difference_type
        _Distance;

    static _BidirectionalIter2 copy(_BidirectionalIter1 _first,
                                    _BidirectionalIter1 _last,
                                    _BidirectionalIter2 __result) {
        return __copy_backward(_first, _last, __result, _Cat(), (_Distance *)0);
    }
};

template <class _Tp>
struct __copy_backward_dispatch<_Tp *, _Tp *, __true_type> {
    static _Tp *copy(const _Tp *_first, const _Tp *_last, _Tp *__result) {
        const ptrdiff_t _Num = _last - _first;
        memmove(__result - _Num, _first, sizeof(_Tp) * _Num);
        return __result - _Num;
    }
};

template <class _Tp>
struct __copy_backward_dispatch<const _Tp *, _Tp *, __true_type> {
    static _Tp *copy(const _Tp *_first, const _Tp *_last, _Tp *__result) {
        return __copy_backward_dispatch<_Tp *, _Tp *, __true_type>::copy(
            _first, _last, __result);
    }
};

template <class _BI1, class _BI2>
inline _BI2 copy_backward(_BI1 _first, _BI1 _last, _BI2 __result) {
    __DST_REQUIRES(_BI1, _BidirectionalIterator);
    __DST_REQUIRES(_BI2, _Mutable_BidirectionalIterator);
    __DST_CONVERTIBLE(typename iterator_traits<_BI1>::value_type,
                      typename iterator_traits<_BI2>::value_type);
    typedef typename __type_traits<typename iterator_traits<_BI2>::value_type>::
        has_trivial_assignment_operator _Trivial;
    return __copy_backward_dispatch<_BI1, _BI2, _Trivial>::copy(_first, _last,
                                                                __result);
}

#else /* __DST_CLASS_PARTIAL_SPECIALIZATION */

template <class _BI1, class _BI2>
inline _BI2 copy_backward(_BI1 _first, _BI1 _last, _BI2 __result) {
    return __copy_backward(_first, _last, __result, __ITERATOR_CATEGORY(_first),
                           __DISTANCE_TYPE(_first));
}

#endif /* __DST_CLASS_PARTIAL_SPECIALIZATION */

//--------------------------------------------------
// copy_n (not part of the DST standard)

template <class _InputIter, class _Size, class _OutputIter>
pair<_InputIter, _OutputIter> __copy_n(_InputIter _first, _Size __count,
                                       _OutputIter __result,
                                       input_iterator_tag) {
    for (; __count > 0; --__count) {
        *__result = *_first;
        ++_first;
        ++__result;
    }
    return pair<_InputIter, _OutputIter>(_first, __result);
}

template <class _RAIter, class _Size, class _OutputIter>
inline pair<_RAIter, _OutputIter> __copy_n(_RAIter _first, _Size __count,
                                           _OutputIter __result,
                                           random_access_iterator_tag) {
    _RAIter _last = _first + __count;
    return pair<_RAIter, _OutputIter>(_last, copy(_first, _last, __result));
}

template <class _InputIter, class _Size, class _OutputIter>
inline pair<_InputIter, _OutputIter> __copy_n(_InputIter _first, _Size __count,
                                              _OutputIter __result) {
    return __copy_n(_first, __count, __result, __ITERATOR_CATEGORY(_first));
}

template <class _InputIter, class _Size, class _OutputIter>
inline pair<_InputIter, _OutputIter> copy_n(_InputIter _first, _Size __count,
                                            _OutputIter __result) {
    __DST_REQUIRES(_InputIter, _InputIterator);
    __DST_REQUIRES(_OutputIter, _OutputIterator);
    return __copy_n(_first, __count, __result);
}

//--------------------------------------------------
// fill and fill_n

template <class _ForwardIter, class _Tp>
void fill(_ForwardIter _first, _ForwardIter _last, const _Tp &_value) {
    __DST_REQUIRES(_ForwardIter, _Mutable_ForwardIterator);
    for (; _first != _last; ++_first) *_first = _value;
}

template <class _OutputIter, class _Size, class _Tp>
_OutputIter fill_n(_OutputIter _first, _Size __n, const _Tp &_value) {
    __DST_REQUIRES(_OutputIter, _OutputIterator);
    for (; __n > 0; --__n, ++_first) *_first = _value;
    return _first;
}

// Specialization: for one-byte types we can use memset.

inline void fill(unsigned char *_first, unsigned char *_last,
                 const unsigned char &__c) {
    unsigned char __tmp = __c;
    memset(_first, __tmp, _last - _first);
}

inline void fill(signed char *_first, signed char *_last,
                 const signed char &__c) {
    signed char __tmp = __c;
    memset(_first, static_cast<unsigned char>(__tmp), _last - _first);
}

inline void fill(char *_first, char *_last, const char &__c) {
    char __tmp = __c;
    memset(_first, static_cast<unsigned char>(__tmp), _last - _first);
}

#ifdef __DST_FUNCTION_TMPL_PARTIAL_ORDER

template <class _Size>
inline unsigned char *fill_n(unsigned char *_first, _Size __n,
                             const unsigned char &__c) {
    fill(_first, _first + __n, __c);
    return _first + __n;
}

template <class _Size>
inline signed char *fill_n(char *_first, _Size __n, const signed char &__c) {
    fill(_first, _first + __n, __c);
    return _first + __n;
}

template <class _Size>
inline char *fill_n(char *_first, _Size __n, const char &__c) {
    fill(_first, _first + __n, __c);
    return _first + __n;
}

#endif /* __DST_FUNCTION_TMPL_PARTIAL_ORDER */

//--------------------------------------------------
// equal and mismatch

template <class _InputIter1, class _InputIter2>
pair<_InputIter1, _InputIter2>
mismatch(_InputIter1 __first1, _InputIter1 __last1, _InputIter2 __first2) {
    __DST_REQUIRES(_InputIter1, _InputIterator);
    __DST_REQUIRES(_InputIter2, _InputIterator);
    __DST_REQUIRES(typename iterator_traits<_InputIter1>::value_type,
                   _EqualityComparable);
    __DST_REQUIRES(typename iterator_traits<_InputIter2>::value_type,
                   _EqualityComparable);
    while (__first1 != __last1 && *__first1 == *__first2) {
        ++__first1;
        ++__first2;
    }
    return pair<_InputIter1, _InputIter2>(__first1, __first2);
}

template <class _InputIter1, class _InputIter2, class _BinaryPredicate>
pair<_InputIter1, _InputIter2>
mismatch(_InputIter1 __first1, _InputIter1 __last1, _InputIter2 __first2,
         _BinaryPredicate __binary_pred) {
    __DST_REQUIRES(_InputIter1, _InputIterator);
    __DST_REQUIRES(_InputIter2, _InputIterator);
    while (__first1 != __last1 && __binary_pred(*__first1, *__first2)) {
        ++__first1;
        ++__first2;
    }
    return pair<_InputIter1, _InputIter2>(__first1, __first2);
}

template <class _InputIter1, class _InputIter2>
inline bool equal(_InputIter1 __first1, _InputIter1 __last1,
                  _InputIter2 __first2) {
    __DST_REQUIRES(_InputIter1, _InputIterator);
    __DST_REQUIRES(_InputIter2, _InputIterator);
    __DST_REQUIRES(typename iterator_traits<_InputIter1>::value_type,
                   _EqualityComparable);
    __DST_REQUIRES(typename iterator_traits<_InputIter2>::value_type,
                   _EqualityComparable);
    for (; __first1 != __last1; ++__first1, ++__first2)
        if (*__first1 != *__first2)
            return false;
    return true;
}

template <class _InputIter1, class _InputIter2, class _BinaryPredicate>
inline bool equal(_InputIter1 __first1, _InputIter1 __last1,
                  _InputIter2 __first2, _BinaryPredicate __binary_pred) {
    __DST_REQUIRES(_InputIter1, _InputIterator);
    __DST_REQUIRES(_InputIter2, _InputIterator);
    for (; __first1 != __last1; ++__first1, ++__first2)
        if (!__binary_pred(*__first1, *__first2))
            return false;
    return true;
}

//--------------------------------------------------
// lexicographical_compare and lexicographical_compare_3way.
// (the latter is not part of the DST standard.)

template <class _InputIter1, class _InputIter2>
bool lexicographical_compare(_InputIter1 __first1, _InputIter1 __last1,
                             _InputIter2 __first2, _InputIter2 __last2) {
    __DST_REQUIRES(_InputIter1, _InputIterator);
    __DST_REQUIRES(_InputIter2, _InputIterator);
    __DST_REQUIRES(typename iterator_traits<_InputIter1>::value_type,
                   _LessThanComparable);
    __DST_REQUIRES(typename iterator_traits<_InputIter2>::value_type,
                   _LessThanComparable);
    for (; __first1 != __last1 && __first2 != __last2; ++__first1, ++__first2) {
        if (*__first1 < *__first2)
            return true;
        if (*__first2 < *__first1)
            return false;
    }
    return __first1 == __last1 && __first2 != __last2;
}

template <class _InputIter1, class _InputIter2, class _Compare>
bool lexicographical_compare(_InputIter1 __first1, _InputIter1 __last1,
                             _InputIter2 __first2, _InputIter2 __last2,
                             _Compare __comp) {
    __DST_REQUIRES(_InputIter1, _InputIterator);
    __DST_REQUIRES(_InputIter2, _InputIterator);
    for (; __first1 != __last1 && __first2 != __last2; ++__first1, ++__first2) {
        if (__comp(*__first1, *__first2))
            return true;
        if (__comp(*__first2, *__first1))
            return false;
    }
    return __first1 == __last1 && __first2 != __last2;
}

inline bool lexicographical_compare(const unsigned char *__first1,
                                    const unsigned char *__last1,
                                    const unsigned char *__first2,
                                    const unsigned char *__last2) {
    const size_t __len1 = __last1 - __first1;
    const size_t __len2 = __last2 - __first2;
    const int __result = memcmp(__first1, __first2, min(__len1, __len2));
    return __result != 0 ? __result < 0 : __len1 < __len2;
}

inline bool lexicographical_compare(const char *__first1, const char *__last1,
                                    const char *__first2, const char *__last2) {
#if CHAR_MAX == SCHAR_MAX
    return lexicographical_compare(
        (const signed char *)__first1, (const signed char *)__last1,
        (const signed char *)__first2, (const signed char *)__last2);
#else  /* CHAR_MAX == SCHAR_MAX */
    return lexicographical_compare(
        (const unsigned char *)__first1, (const unsigned char *)__last1,
        (const unsigned char *)__first2, (const unsigned char *)__last2);
#endif /* CHAR_MAX == SCHAR_MAX */
}

template <class _InputIter1, class _InputIter2>
int __lexicographical_compare_3way(_InputIter1 __first1, _InputIter1 __last1,
                                   _InputIter2 __first2, _InputIter2 __last2) {
    while (__first1 != __last1 && __first2 != __last2) {
        if (*__first1 < *__first2)
            return -1;
        if (*__first2 < *__first1)
            return 1;
        ++__first1;
        ++__first2;
    }
    if (__first2 == __last2) {
        return !(__first1 == __last1);
    } else {
        return -1;
    }
}

inline int __lexicographical_compare_3way(const unsigned char *__first1,
                                          const unsigned char *__last1,
                                          const unsigned char *__first2,
                                          const unsigned char *__last2) {
    const ptrdiff_t __len1 = __last1 - __first1;
    const ptrdiff_t __len2 = __last2 - __first2;
    const int __result = memcmp(__first1, __first2, min(__len1, __len2));
    return __result != 0 ? __result
                         : (__len1 == __len2 ? 0 : (__len1 < __len2 ? -1 : 1));
}

inline int __lexicographical_compare_3way(const char *__first1,
                                          const char *__last1,
                                          const char *__first2,
                                          const char *__last2) {
#if CHAR_MAX == SCHAR_MAX
    return __lexicographical_compare_3way(
        (const signed char *)__first1, (const signed char *)__last1,
        (const signed char *)__first2, (const signed char *)__last2);
#else
    return __lexicographical_compare_3way(
        (const unsigned char *)__first1, (const unsigned char *)__last1,
        (const unsigned char *)__first2, (const unsigned char *)__last2);
#endif
}

template <class _InputIter1, class _InputIter2>
int lexicographical_compare_3way(_InputIter1 __first1, _InputIter1 __last1,
                                 _InputIter2 __first2, _InputIter2 __last2) {
    __DST_REQUIRES(_InputIter1, _InputIterator);
    __DST_REQUIRES(_InputIter2, _InputIterator);
    __DST_REQUIRES(typename iterator_traits<_InputIter1>::value_type,
                   _LessThanComparable);
    __DST_REQUIRES(typename iterator_traits<_InputIter2>::value_type,
                   _LessThanComparable);
    return __lexicographical_compare_3way(__first1, __last1, __first2, __last2);
}

__DST_END_NAMESPACE

#endif /* ___DST_INTERNAL_ALGOBASE_H */
