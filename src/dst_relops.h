
/* NOTE: This is an internal header file, included by other DST headers.
 *   You should not attempt to use it directly.
 */

#ifndef ___DST_INTERNAL_RELOPS
#define ___DST_INTERNAL_RELOPS

__DST_BEGIN_RELOPS_NAMESPACE

template <class _Tp>
inline bool operator!=(const _Tp &__x, const _Tp &__y) {
    return !(__x == __y);
}

template <class _Tp>
inline bool operator>(const _Tp &__x, const _Tp &__y) {
    return __y < __x;
}

template <class _Tp>
inline bool operator<=(const _Tp &__x, const _Tp &__y) {
    return !(__y < __x);
}

template <class _Tp>
inline bool operator>=(const _Tp &__x, const _Tp &__y) {
    return !(__x < __y);
}

__DST_END_RELOPS_NAMESPACE

#endif /* ___DST_INTERNAL_RELOPS */
