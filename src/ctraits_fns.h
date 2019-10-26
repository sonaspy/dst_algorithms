#ifndef ___DST_INTERNAL_CTRAITS_FUNCTIONS_H
#define ___DST_INTERNAL_CTRAITS_FUNCTIONS_H

// This file contains a few small adapters that allow a character
// traits class to be used as a function object.

__DST_BEGIN_NAMESPACE

template <class _Traits>
struct _Eq_traits : public binary_function<typename _Traits::char_type,
                                           typename _Traits::char_type, bool> {
    bool operator()(const typename _Traits::char_type &__x,
                    const typename _Traits::char_type &__y) const {
        return _Traits::eq(__x, __y);
    }
};

template <class _Traits>
struct _Eq_int_traits
    : public binary_function<typename _Traits::char_type,
                             typename _Traits::int_type, bool> {
    bool operator()(const typename _Traits::char_type &__x,
                    const typename _Traits::int_type &__y) const {
        return _Traits::eq_int_type(_Traits::to_int_type(__x), __y);
    }
};

template <class _Traits>
struct _Lt_traits : public binary_function<typename _Traits::char_type,
                                           typename _Traits::char_type, bool> {
    bool operator()(const typename _Traits::char_type &__x,
                    const typename _Traits::char_type &__y) const {
        return _Traits::lt(__x, __y);
    }
};

__DST_END_NAMESPACE

#endif /* ___DST_INTERNAL_CTRAITS_FUNCTIONS_H */