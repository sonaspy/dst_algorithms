
#ifndef ___DST_INTERNAL_STACK_H
#define ___DST_INTERNAL_STACK_H

#include "sequence_concepts.h"

__DST_BEGIN_NAMESPACE

// Forward declarations of operators == and <, needed for friend declaration.

template <class _Tp, class _Sequence __DST_DEPENDENT_DEFAULT_TMPL(deque<_Tp>)>
class stack;

template <class _Tp, class _Seq>
bool operator==(const stack<_Tp, _Seq> &__x, const stack<_Tp, _Seq> &__y);

template <class _Tp, class _Seq>
bool operator<(const stack<_Tp, _Seq> &__x, const stack<_Tp, _Seq> &__y);

template <class _Tp, class _Sequence>
class stack {

    // requirements:

    __DST_CLASS_REQUIRES(_Tp, _Assignable);
    __DST_CLASS_REQUIRES(_Sequence, _BackInsertionSequence);
    typedef typename _Sequence::value_type _Sequence_value_type;
    __DST_CLASS_REQUIRES_SAME_TYPE(_Tp, _Sequence_value_type);

#ifdef __DST_MEMBER_TEMPLATES
    template <class _Tp1, class _Seq1>
    friend bool operator==(const stack<_Tp1, _Seq1> &,
                           const stack<_Tp1, _Seq1> &);
    template <class _Tp1, class _Seq1>
    friend bool operator<(const stack<_Tp1, _Seq1> &,
                          const stack<_Tp1, _Seq1> &);
#else  /* __DST_MEMBER_TEMPLATES */
    friend bool __VDSA_QUALIFIER operator==
        __DST_NULL_TMPL_ARGS(const stack &, const stack &);
    friend bool __VDSA_QUALIFIER operator<
        __DST_NULL_TMPL_ARGS(const stack &, const stack &);
#endif /* __DST_MEMBER_TEMPLATES */

  public:
    typedef typename _Sequence::value_type value_type;
    typedef typename _Sequence::size_type size_type;
    typedef _Sequence container_type;

    typedef typename _Sequence::reference reference;
    typedef typename _Sequence::const_reference const_reference;

  protected:
    _Sequence c;

  public:
    stack() : c() {}
    explicit stack(const _Sequence &__s) : c(__s) {}

    bool empty() const { return c.empty(); }
    size_type size() const { return c.size(); }
    reference top() { return c.back(); }
    const_reference top() const { return c.back(); }
    void push(const value_type &__x) { c.push_back(__x); }
    void pop() { c.pop_back(); }
};

template <class _Tp, class _Seq>
bool operator==(const stack<_Tp, _Seq> &__x, const stack<_Tp, _Seq> &__y) {
    return __x.c == __y.c;
}

template <class _Tp, class _Seq>
bool operator<(const stack<_Tp, _Seq> &__x, const stack<_Tp, _Seq> &__y) {
    return __x.c < __y.c;
}

#ifdef __DST_FUNCTION_TMPL_PARTIAL_ORDER

template <class _Tp, class _Seq>
bool operator!=(const stack<_Tp, _Seq> &__x, const stack<_Tp, _Seq> &__y) {
    return !(__x == __y);
}

template <class _Tp, class _Seq>
bool operator>(const stack<_Tp, _Seq> &__x, const stack<_Tp, _Seq> &__y) {
    return __y < __x;
}

template <class _Tp, class _Seq>
bool operator<=(const stack<_Tp, _Seq> &__x, const stack<_Tp, _Seq> &__y) {
    return !(__y < __x);
}

template <class _Tp, class _Seq>
bool operator>=(const stack<_Tp, _Seq> &__x, const stack<_Tp, _Seq> &__y) {
    return !(__x < __y);
}

#endif /* __DST_FUNCTION_TMPL_PARTIAL_ORDER */

__DST_END_NAMESPACE

#endif /* ___DST_INTERNAL_STACK_H */
