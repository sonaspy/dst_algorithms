#ifndef ___DST_INTERNAL_QUEUE_H
#define ___DST_INTERNAL_QUEUE_H

#include "sequence_concepts.h"

__DST_BEGIN_NAMESPACE

// Forward declarations of operators < and ==, needed for friend declaration.

template <class _Tp, class _Sequence __DST_DEPENDENT_DEFAULT_TMPL(deque<_Tp>)>
class queue;

template <class _Tp, class _Seq>
inline bool operator==(const queue<_Tp, _Seq> &, const queue<_Tp, _Seq> &);

template <class _Tp, class _Seq>
inline bool operator<(const queue<_Tp, _Seq> &, const queue<_Tp, _Seq> &);

template <class _Tp, class _Sequence>
class queue
{
    // requirements:

    __DST_CLASS_REQUIRES(_Tp, _Assignable);
    __DST_CLASS_REQUIRES(_Sequence, _FrontInsertionSequence);
    __DST_CLASS_REQUIRES(_Sequence, _BackInsertionSequence);
    typedef typename _Sequence::value_type _Sequence_value_type;
    __DST_CLASS_REQUIRES_SAME_TYPE(_Tp, _Sequence_value_type);

#ifdef __DST_MEMBER_TEMPLATES
    template <class _Tp1, class _Seq1>
    friend bool operator==(const queue<_Tp1, _Seq1> &,
                           const queue<_Tp1, _Seq1> &);
    template <class _Tp1, class _Seq1>
    friend bool operator<(const queue<_Tp1, _Seq1> &,
                          const queue<_Tp1, _Seq1> &);
#else  /* __DST_MEMBER_TEMPLATES */
    friend bool __DSA_QUALIFIER
    operator== __DST_NULL_TMPL_ARGS(const queue &, const queue &);
    friend bool __DSA_QUALIFIER
    operator<__DST_NULL_TMPL_ARGS(const queue &, const queue &);
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
    queue() : c() {}
    explicit queue(const _Sequence &__c) : c(__c) {}

    bool empty() const { return c.empty(); }
    size_type size() const { return c.size(); }
    reference front() { return c.front(); }
    const_reference front() const { return c.front(); }
    reference back() { return c.back(); }
    const_reference back() const { return c.back(); }
    void push(const value_type &__x) { c.push_back(__x); }
    void pop() { c.pop_front(); }
};

template <class _Tp, class _Sequence>
bool operator==(const queue<_Tp, _Sequence> &__x, const queue<_Tp, _Sequence> &__y)
{
    return __x.c == __y.c;
}

template <class _Tp, class _Sequence>
bool operator<(const queue<_Tp, _Sequence> &__x, const queue<_Tp, _Sequence> &__y)
{
    return __x.c < __y.c;
}

#ifdef __DST_FUNCTION_TMPL_PARTIAL_ORDER

template <class _Tp, class _Sequence>
bool operator!=(const queue<_Tp, _Sequence> &__x, const queue<_Tp, _Sequence> &__y)
{
    return !(__x == __y);
}

template <class _Tp, class _Sequence>
bool operator>(const queue<_Tp, _Sequence> &__x, const queue<_Tp, _Sequence> &__y)
{
    return __y < __x;
}

template <class _Tp, class _Sequence>
bool operator<=(const queue<_Tp, _Sequence> &__x, const queue<_Tp, _Sequence> &__y)
{
    return !(__y < __x);
}

template <class _Tp, class _Sequence>
bool operator>=(const queue<_Tp, _Sequence> &__x, const queue<_Tp, _Sequence> &__y)
{
    return !(__x < __y);
}

#endif /* __DST_FUNCTION_TMPL_PARTIAL_ORDER */

template <class _Tp,
          class _Sequence __DST_DEPENDENT_DEFAULT_TMPL(vector<_Tp>),
          class _Compare __DST_DEPENDENT_DEFAULT_TMPL(less<typename _Sequence::value_type>)>
class priority_queue
{
    // requirements:

    __DST_CLASS_REQUIRES(_Tp, _Assignable);
    __DST_CLASS_REQUIRES(_Sequence, _Sequence);
    __DST_CLASS_REQUIRES(_Sequence, _RandomAccessContainer);
    typedef typename _Sequence::value_type _Sequence_value_type;
    __DST_CLASS_REQUIRES_SAME_TYPE(_Tp, _Sequence_value_type);
    __DST_CLASS_BINARY_FUNCTION_CHECK(_Compare, bool, _Tp, _Tp);

public:
    typedef typename _Sequence::value_type value_type;
    typedef typename _Sequence::size_type size_type;
    typedef _Sequence container_type;

    typedef typename _Sequence::reference reference;
    typedef typename _Sequence::const_reference const_reference;

protected:
    _Sequence c;
    _Compare comp;

public:
    priority_queue() : c() {}
    explicit priority_queue(const _Compare &__x) : c(), comp(__x) {}
    priority_queue(const _Compare &__x, const _Sequence &__s)
        : c(__s), comp(__x)
    {
        make_heap(c.begin(), c.end(), comp);
    }

#ifdef __DST_MEMBER_TEMPLATES
    template <class _InputIterator>
    priority_queue(_InputIterator __first, _InputIterator __last)
        : c(__first, __last)
    {
        make_heap(c.begin(), c.end(), comp);
    }

    template <class _InputIterator>
    priority_queue(_InputIterator __first, _InputIterator __last, const _Compare &__x)
        : c(__first, __last), comp(__x)
    {
        make_heap(c.begin(), c.end(), comp);
    }

    template <class _InputIterator>
    priority_queue(_InputIterator __first, _InputIterator __last, const _Compare &__x, const _Sequence &__s)
        : c(__s), comp(__x)
    {
        c.insert(c.end(), __first, __last);
        make_heap(c.begin(), c.end(), comp);
    }

#else  /* __DST_MEMBER_TEMPLATES */
    priority_queue(const value_type *__first, const value_type *__last)
        : c(__first, __last)
    {
        make_heap(c.begin(), c.end(), comp);
    }

    priority_queue(const value_type *__first, const value_type *__last,
                   const _Compare &__x)
        : c(__first, __last), comp(__x)
    {
        make_heap(c.begin(), c.end(), comp);
    }

    priority_queue(const value_type *__first, const value_type *__last, const _Compare &__x, const _Sequence &__c)
        : c(__c), comp(__x)
    {
        c.insert(c.end(), __first, __last);
        make_heap(c.begin(), c.end(), comp);
    }
#endif /* __DST_MEMBER_TEMPLATES */

    bool empty() const
    {
        return c.empty();
    }
    size_type size() const { return c.size(); }
    const_reference top() const { return c.front(); }
    void push(const value_type &__x)
    {
        __DST_TRY
        {
            c.push_back(__x);
            push_heap(c.begin(), c.end(), comp);
        }
        __DST_UNWIND(c.clear());
    }
    void pop()
    {
        __DST_TRY
        {
            pop_heap(c.begin(), c.end(), comp);
            c.pop_back();
        }
        __DST_UNWIND(c.clear());
    }
};

// no equality is provided

__DST_END_NAMESPACE

#endif /* ___DST_INTERNAL_QUEUE_H */