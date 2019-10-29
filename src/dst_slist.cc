#ifndef ___DST_INTERNAL_SLIST_H
#define ___DST_INTERNAL_SLIST_H

#include "concept_checks.hpp"

__DST_BEGIN_NAMESPACE

#if defined(__llvm) && !defined(__GNUC__) && (_MIPS_SIM != _MIPS_SIM_ABI32)
#pragma set woff 1174
#pragma set woff 1375
#endif

struct _slist_node_base {
    _slist_node_base *_M_next;
    _slist_node_base *_M_prev;
};

template <class _Tp>
struct _slist_node : public _slist_node_base {
    _Tp _M_data;
};

struct _slist_iterator_base {
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef bidirectional_iterator_tag iterator_category;

    _slist_node_base *_M_node;

    _slist_iterator_base(_slist_node_base *__x) : _M_node(__x) {}
    _slist_iterator_base() {}

    void _M_incr() { _M_node = _M_node->_M_next; }
    void _M_decr() { _M_node = _M_node->_M_prev; }

    bool operator==(const _slist_iterator_base &__x) const {
        return _M_node == __x._M_node;
    }
    bool operator!=(const _slist_iterator_base &__x) const {
        return _M_node != __x._M_node;
    }
};

template <class _Tp, class _Ref, class _Ptr>
struct _slist_iterator : public _slist_iterator_base {
    typedef _slist_iterator<_Tp, _Tp &, _Tp *> iterator;
    typedef _slist_iterator<_Tp, const _Tp &, const _Tp *> const_iterator;
    typedef _slist_iterator<_Tp, _Ref, _Ptr> _Self;

    typedef _Tp value_type;
    typedef _Ptr pointer;
    typedef _Ref reference;
    typedef _slist_node<_Tp> __node;

    _slist_iterator(__node *__x) : _slist_iterator_base(__x) {}
    _slist_iterator() {}
    _slist_iterator(const iterator &__x) : _slist_iterator_base(__x._M_node) {}

    reference operator*() const { return ((__node *)_M_node)->_M_data; }

#ifndef ___DST_NO_ARROW_OPERATOR
    pointer operator->() const { return &(operator*()); }
#endif /* ___DST_NO_ARROW_OPERATOR */

    _Self &operator++() {
        this->_M_incr();
        return *this;
    }
    _Self operator++(int) {
        _Self __tmp = *this;
        this->_M_incr();
        return __tmp;
    }
    _Self &operator--() {
        this->_M_decr();
        return *this;
    }
    _Self operator--(int) {
        _Self __tmp = *this;
        this->_M_decr();
        return __tmp;
    }
};

#ifndef __DST_CLASS_PARTIAL_SPECIALIZATION

inline bidirectional_iterator_tag
iterator_category(const _slist_iterator_base &) {
    return bidirectional_iterator_tag();
}

template <class _Tp, class _Ref, class _Ptr>
inline _Tp *value_type(const _slist_iterator<_Tp, _Ref, _Ptr> &) {
    return 0;
}

inline ptrdiff_t *distance_type(const _slist_iterator_base &) { return 0; }

#endif /* __DST_CLASS_PARTIAL_SPECIALIZATION */

// Base class that encapsulates details of allocators.  Three cases:
// an ordinary standard-conforming allocator, a standard-conforming
// allocator with no non-static data, and a  stl-style allocator.
// This complexity is necessary only because we're worrying about backward
// compatibility and because we want to avoid wasting storage on an
// allocator instance if it isn't necessary.

#ifdef __DST_USE_DSA_ALLOCATORS

// Base for general standard-conforming allocators.
template <class _Tp, class _Allocator, bool _IsStatic>
class _slist_alloc_base {
  public:
    typedef
        typename _Alloc_traits<_Tp, _Allocator>::allocator_type allocator_type;
    allocator_type get_allocator() const { return _Node_allocator; }

    _slist_alloc_base(const allocator_type &__a) : _Node_allocator(__a) {}

  protected:
    _slist_node<_Tp> *_M_get_node() { return _Node_allocator.allocate(1); }
    void _M_put_node(_slist_node<_Tp> *__p) {
        _Node_allocator.deallocate(__p, 1);
    }

  protected:
    typename _Alloc_traits<_slist_node<_Tp>, _Allocator>::allocator_type
        _Node_allocator;
    _slist_node<_Tp> *_M_node;
};

// Specialization for instanceless allocators.

template <class _Tp, class _Allocator>
class _slist_alloc_base<_Tp, _Allocator, true> {
  public:
    typedef
        typename _Alloc_traits<_Tp, _Allocator>::allocator_type allocator_type;
    allocator_type get_allocator() const { return allocator_type(); }

    _slist_alloc_base(const allocator_type &) {}

  protected:
    typedef typename _Alloc_traits<_slist_node<_Tp>, _Allocator>::_Alloc_type
        _Alloc_type;
    inline _slist_node<_Tp> *_M_get_node() { return _Alloc_type::allocate(1); }
    void _M_put_node(_slist_node<_Tp> *__p) { _Alloc_type::deallocate(__p, 1); }

  protected:
    _slist_node<_Tp> *_M_node;
};

template <class _Tp, class _Alloc>
class _slist_base
    : public _slist_alloc_base<_Tp, _Alloc,
                               _Alloc_traits<_Tp, _Alloc>::_S_instanceless> {
  public:
    typedef _slist_alloc_base<_Tp, _Alloc,
                              _Alloc_traits<_Tp, _Alloc>::_S_instanceless>
        __base;
    typedef typename __base::allocator_type allocator_type;

    _slist_base(const allocator_type &__a) : __base(__a) {
        _M_node = _M_get_node();
        _M_node->_M_next = _M_node;
        _M_node->_M_prev = _M_node;
    }
    ~_slist_base() {
        clear();
        _M_put_node(_M_node);
    }

    void clear();
};

#else /* __DST_USE_DSA_ALLOCATORS */

template <class _Tp, class _Alloc>
class _slist_base {
  public:
    typedef _Alloc allocator_type;
    allocator_type get_allocator() const { return allocator_type(); }

    _slist_base(const allocator_type &) {
        _M_node = _M_get_node();
        _M_node->_M_next = _M_node;
        _M_node->_M_prev = _M_node;
    }
    ~_slist_base() {
        clear();
        _M_put_node(_M_node);
    }

    void clear();

  protected:
    typedef simple_alloc<_slist_node<_Tp>, _Alloc> _Alloc_type;
    inline _slist_node<_Tp> *_M_get_node() { return _Alloc_type::allocate(1); }
    void _M_put_node(_slist_node<_Tp> *__p) { _Alloc_type::deallocate(__p, 1); }

  protected:
    _slist_node<_Tp> *_M_node;
};

#endif /* __DST_USE_DSA_ALLOCATORS */

template <class _Tp, class _Alloc>
void _slist_base<_Tp, _Alloc>::clear() {
    _slist_node<_Tp> *__cur = (_slist_node<_Tp> *)_M_node->_M_next;
    while (__cur != _M_node) {
        _slist_node<_Tp> *__tmp = __cur;
        __cur = (_slist_node<_Tp> *)__cur->_M_next;
        _Destroy(&__tmp->_M_data);
        _M_put_node(__tmp);
    }
    _M_node->_M_next = _M_node;
    _M_node->_M_prev = _M_node;
}

template <class _Tp, class _Alloc = __DST_DEFAULT_ALLOCATOR(_Tp)>
class slist : protected _slist_base<_Tp, _Alloc> {
    // requirements:

    __DST_CLASS_REQUIRES(_Tp, _Assignable);

    typedef _slist_base<_Tp, _Alloc> __base;

  protected:
    typedef void *_Void_pointer;

  public:
    typedef _Tp value_type;
    typedef value_type *pointer;
    typedef const value_type *const_pointer;
    typedef value_type &reference;
    typedef const value_type &const_reference;
    typedef _slist_node<_Tp> __node;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;

    typedef typename __base::allocator_type allocator_type;
    allocator_type get_allocator() const { return __base::get_allocator(); }

  public:
    typedef _slist_iterator<_Tp, _Tp &, _Tp *> iterator;
    typedef _slist_iterator<_Tp, const _Tp &, const _Tp *> const_iterator;

#ifdef __DST_CLASS_PARTIAL_SPECIALIZATION
    typedef reverse_iterator<const_iterator> const_reverse_iterator;
    typedef reverse_iterator<iterator> reverse_iterator;
#else  /* __DST_CLASS_PARTIAL_SPECIALIZATION */
    typedef reverse_bidirectional_iterator<const_iterator, value_type,
                                           const_reference, difference_type>
        const_reverse_iterator;
    typedef reverse_bidirectional_iterator<iterator, value_type, reference,
                                           difference_type>
        reverse_iterator;
#endif /* __DST_CLASS_PARTIAL_SPECIALIZATION */

  protected:
    using __base::_M_get_node;
    using __base::_M_node;
    using __base::_M_put_node;

  protected:
    __node *_M_create_node(const _Tp &__x) {
        __node *__p = _M_get_node();
        __DST_TRY { _Construct(&__p->_M_data, __x); }
        __DST_UNWIND(_M_put_node(__p));
        return __p;
    }

    __node *_M_create_node() {
        __node *__p = _M_get_node();
        __DST_TRY { _Construct(&__p->_M_data); }
        __DST_UNWIND(_M_put_node(__p));
        return __p;
    }

  public:
    explicit slist(const allocator_type &__a = allocator_type())
        : __base(__a) {}

    iterator begin() { return (__node *)(_M_node->_M_next); }
    const_iterator begin() const { return (__node *)(_M_node->_M_next); }

    iterator end() { return _M_node; }
    const_iterator end() const { return _M_node; }

    reverse_iterator rbegin() { return reverse_iterator(end()); }
    const_reverse_iterator rbegin() const {
        return const_reverse_iterator(end());
    }

    reverse_iterator rend() { return reverse_iterator(begin()); }
    const_reverse_iterator rend() const {
        return const_reverse_iterator(begin());
    }

    bool empty() const { return _M_node->_M_next == _M_node; }
    size_type size() const {
        size_type __result = 0;
        distance(begin(), end(), __result);
        return __result;
    }
    size_type max_size() const { return size_type(-1); }

    reference front() { return *begin(); }
    const_reference front() const { return *begin(); }
    reference back() { return *(--end()); }
    const_reference back() const { return *(--end()); }

    void swap(slist<_Tp, _Alloc> &__x) { __VDSA::swap(_M_node, __x._M_node); }

    iterator insert(iterator __position, const _Tp &__x) {
        __node *__tmp = _M_create_node(__x);
        __tmp->_M_next = __position._M_node;
        __tmp->_M_prev = __position._M_node->_M_prev;
        __position._M_node->_M_prev->_M_next = __tmp;
        __position._M_node->_M_prev = __tmp;
        return __tmp;
    }
    iterator insert(iterator __position) { return insert(__position, _Tp()); }
#ifdef __DST_MEMBER_TEMPLATES
    // Check whether it's an integral type.  If so, it's not an iterator.

    template <class _Integer>
    void _M_insert_dispatch(iterator __pos, _Integer __n, _Integer __x,
                            __true_type) {
        _M_fill_insert(__pos, (size_type)__n, (_Tp)__x);
    }

    template <class _InputIterator>
    void _M_insert_dispatch(iterator __pos, _InputIterator __first,
                            _InputIterator __last, __false_type);

    template <class _InputIterator>
    void insert(iterator __pos, _InputIterator __first, _InputIterator __last) {
        typedef typename _Is_integer<_InputIterator>::_Integral _Integral;
        _M_insert_dispatch(__pos, __first, __last, _Integral());
    }

#else  /* __DST_MEMBER_TEMPLATES */
    void insert(iterator __position, const _Tp *__first, const _Tp *__last);
    void insert(iterator __position, const_iterator __first,
                const_iterator __last);
#endif /* __DST_MEMBER_TEMPLATES */
    void insert(iterator __pos, size_type __n, const _Tp &__x) {
        _M_fill_insert(__pos, __n, __x);
    }
    void _M_fill_insert(iterator __pos, size_type __n, const _Tp &__x);

    void push_front(const _Tp &__x) { insert(begin(), __x); }
    void push_front() { insert(begin()); }
    void push_back(const _Tp &__x) { insert(end(), __x); }
    void push_back() { insert(end()); }

    iterator erase(iterator __position) {
        _slist_node_base *__next_node = __position._M_node->_M_next;
        _slist_node_base *__prev_node = __position._M_node->_M_prev;
        __node *__n = (__node *)__position._M_node;
        __prev_node->_M_next = __next_node;
        __next_node->_M_prev = __prev_node;
        _Destroy(&__n->_M_data);
        _M_put_node(__n);
        return iterator((__node *)__next_node);
    }
    iterator erase(iterator __first, iterator __last);
    void clear() { __base::clear(); }

    void resize(size_type __new_size, const _Tp &__x);
    void resize(size_type __new_size) { this->resize(__new_size, _Tp()); }

    void pop_front() { erase(begin()); }
    void pop_back() {
        iterator __tmp = end();
        erase(--__tmp);
    }
    slist(size_type __n, const _Tp &__value,
          const allocator_type &__a = allocator_type())
        : __base(__a) {
        insert(begin(), __n, __value);
    }
    explicit slist(size_type __n) : __base(allocator_type()) {
        insert(begin(), __n, _Tp());
    }

#ifdef __DST_MEMBER_TEMPLATES

    // We don't need any dispatching tricks here, because insert does all of
    // that anyway.
    template <class _InputIterator>
    slist(_InputIterator __first, _InputIterator __last,
          const allocator_type &__a = allocator_type())
        : __base(__a) {
        insert(begin(), __first, __last);
    }

#else /* __DST_MEMBER_TEMPLATES */

    slist(const _Tp *__first, const _Tp *__last,
          const allocator_type &__a = allocator_type())
        : __base(__a) {
        this->insert(begin(), __first, __last);
    }
    slist(const_iterator __first, const_iterator __last,
          const allocator_type &__a = allocator_type())
        : __base(__a) {
        this->insert(begin(), __first, __last);
    }

#endif /* __DST_MEMBER_TEMPLATES */
    slist(const slist<_Tp, _Alloc> &__x) : __base(__x.get_allocator()) {
        insert(begin(), __x.begin(), __x.end());
    }

    ~slist() {}

    slist<_Tp, _Alloc> &operator=(const slist<_Tp, _Alloc> &__x);

  public:
    // assign(), a generalized assignment member function.  Two
    // versions: one that takes a count, and one that takes a range.
    // The range version is a member template, so we dispatch on whether
    // or not the type is an integer.

    void assign(size_type __n, const _Tp &__val) { _M_fill_assign(__n, __val); }

    void _M_fill_assign(size_type __n, const _Tp &__val);

#ifdef __DST_MEMBER_TEMPLATES

    template <class _InputIterator>
    void assign(_InputIterator __first, _InputIterator __last) {
        typedef typename _Is_integer<_InputIterator>::_Integral _Integral;
        _M_assign_dispatch(__first, __last, _Integral());
    }

    template <class _Integer>
    void _M_assign_dispatch(_Integer __n, _Integer __val, __true_type) {
        _M_fill_assign((size_type)__n, (_Tp)__val);
    }

    template <class _InputIterator>
    void _M_assign_dispatch(_InputIterator __first, _InputIterator __last,
                            __false_type);

#endif /* __DST_MEMBER_TEMPLATES */

  protected:
    void transfer(iterator __position, iterator __first, iterator __last) {
        if (__position != __last) {
            // Remove [first, last) from its old position.
            __last._M_node->_M_prev->_M_next = __position._M_node;
            __first._M_node->_M_prev->_M_next = __last._M_node;
            __position._M_node->_M_prev->_M_next = __first._M_node;

            // Splice [first, last) into its new position.
            _slist_node_base *__tmp = __position._M_node->_M_prev;
            __position._M_node->_M_prev = __last._M_node->_M_prev;
            __last._M_node->_M_prev = __first._M_node->_M_prev;
            __first._M_node->_M_prev = __tmp;
        }
    }

  public:
    void splice(iterator __position, slist &__x) {
        if (!__x.empty())
            this->transfer(__position, __x.begin(), __x.end());
    }
    void splice(iterator __position, slist &, iterator __i) {
        iterator __j = __i;
        ++__j;
        if (__position == __i || __position == __j)
            return;
        this->transfer(__position, __i, __j);
    }
    void splice(iterator __position, slist &, iterator __first,
                iterator __last) {
        if (__first != __last)
            this->transfer(__position, __first, __last);
    }
    void remove(const _Tp &__value);
    void unique();
    void merge(slist &__x);
    void reverse();
    void sort();

#ifdef __DST_MEMBER_TEMPLATES
    template <class _Predicate>
    void remove_if(_Predicate);
    template <class _BinaryPredicate>
    void unique(_BinaryPredicate);
    template <class _StrictWeakOrdering>
    void merge(slist &, _StrictWeakOrdering);
    template <class _StrictWeakOrdering>
    void sort(_StrictWeakOrdering);
#endif /* __DST_MEMBER_TEMPLATES */
};

template <class _Tp, class _Alloc>
inline bool operator==(const slist<_Tp, _Alloc> &__x,
                       const slist<_Tp, _Alloc> &__y) {
    typedef typename slist<_Tp, _Alloc>::const_iterator const_iterator;
    const_iterator __end1 = __x.end();
    const_iterator __end2 = __y.end();

    const_iterator __i1 = __x.begin();
    const_iterator __i2 = __y.begin();
    while (__i1 != __end1 && __i2 != __end2 && *__i1 == *__i2) {
        ++__i1;
        ++__i2;
    }
    return __i1 == __end1 && __i2 == __end2;
}

template <class _Tp, class _Alloc>
inline bool operator<(const slist<_Tp, _Alloc> &__x,
                      const slist<_Tp, _Alloc> &__y) {
    return lexicographical_compare(__x.begin(), __x.end(), __y.begin(),
                                   __y.end());
}

#ifdef __DST_FUNCTION_TMPL_PARTIAL_ORDER

template <class _Tp, class _Alloc>
inline bool operator!=(const slist<_Tp, _Alloc> &__x,
                       const slist<_Tp, _Alloc> &__y) {
    return !(__x == __y);
}

template <class _Tp, class _Alloc>
inline bool operator>(const slist<_Tp, _Alloc> &__x,
                      const slist<_Tp, _Alloc> &__y) {
    return __y < __x;
}

template <class _Tp, class _Alloc>
inline bool operator<=(const slist<_Tp, _Alloc> &__x,
                       const slist<_Tp, _Alloc> &__y) {
    return !(__y < __x);
}

template <class _Tp, class _Alloc>
inline bool operator>=(const slist<_Tp, _Alloc> &__x,
                       const slist<_Tp, _Alloc> &__y) {
    return !(__x < __y);
}

template <class _Tp, class _Alloc>
inline void swap(slist<_Tp, _Alloc> &__x, slist<_Tp, _Alloc> &__y) {
    __x.swap(__y);
}

#endif /* __DST_FUNCTION_TMPL_PARTIAL_ORDER */

#ifdef __DST_MEMBER_TEMPLATES

template <class _Tp, class _Alloc>
template <class _InputIter>
void slist<_Tp, _Alloc>::_M_insert_dispatch(iterator __position,
                                            _InputIter __first,
                                            _InputIter __last, __false_type) {
    for (; __first != __last; ++__first)
        insert(__position, *__first);
}

#else /* __DST_MEMBER_TEMPLATES */

template <class _Tp, class _Alloc>
void slist<_Tp, _Alloc>::insert(iterator __position, const _Tp *__first,
                                const _Tp *__last) {
    for (; __first != __last; ++__first)
        insert(__position, *__first);
}

template <class _Tp, class _Alloc>
void slist<_Tp, _Alloc>::insert(iterator __position, const_iterator __first,
                                const_iterator __last) {
    for (; __first != __last; ++__first)
        insert(__position, *__first);
}

#endif /* __DST_MEMBER_TEMPLATES */

template <class _Tp, class _Alloc>
void slist<_Tp, _Alloc>::_M_fill_insert(iterator __position, size_type __n,
                                        const _Tp &__x) {
    for (; __n > 0; --__n)
        insert(__position, __x);
}

template <class _Tp, class _Alloc>
typename slist<_Tp, _Alloc>::iterator
slist<_Tp, _Alloc>::erase(iterator __first, iterator __last) {
    while (__first != __last)
        erase(__first++);
    return __last;
}

template <class _Tp, class _Alloc>
void slist<_Tp, _Alloc>::resize(size_type __new_size, const _Tp &__x) {
    iterator __i = begin();
    size_type __len = 0;
    for (; __i != end() && __len < __new_size; ++__i, ++__len)
        ;
    if (__len == __new_size)
        erase(__i, end());
    else // __i == end()
        insert(end(), __new_size - __len, __x);
}

template <class _Tp, class _Alloc>
slist<_Tp, _Alloc> &slist<_Tp, _Alloc>::
operator=(const slist<_Tp, _Alloc> &__x) {
    if (this != &__x) {
        iterator __first1 = begin();
        iterator __last1 = end();
        const_iterator __first2 = __x.begin();
        const_iterator __last2 = __x.end();
        while (__first1 != __last1 && __first2 != __last2)
            *__first1++ = *__first2++;
        if (__first2 == __last2)
            erase(__first1, __last1);
        else
            insert(__last1, __first2, __last2);
    }
    return *this;
}

template <class _Tp, class _Alloc>
void slist<_Tp, _Alloc>::_M_fill_assign(size_type __n, const _Tp &__val) {
    iterator __i = begin();
    for (; __i != end() && __n > 0; ++__i, --__n)
        *__i = __val;
    if (__n > 0)
        insert(end(), __n, __val);
    else
        erase(__i, end());
}

#ifdef __DST_MEMBER_TEMPLATES

template <class _Tp, class _Alloc>
template <class _InputIter>
void slist<_Tp, _Alloc>::_M_assign_dispatch(_InputIter __first2,
                                            _InputIter __last2, __false_type) {
    iterator __first1 = begin();
    iterator __last1 = end();
    for (; __first1 != __last1 && __first2 != __last2; ++__first1, ++__first2)
        *__first1 = *__first2;
    if (__first2 == __last2)
        erase(__first1, __last1);
    else
        insert(__last1, __first2, __last2);
}

#endif /* __DST_MEMBER_TEMPLATES */

template <class _Tp, class _Alloc>
void slist<_Tp, _Alloc>::remove(const _Tp &__value) {
    iterator __first = begin();
    iterator __last = end();
    while (__first != __last) {
        iterator __next = __first;
        ++__next;
        if (*__first == __value)
            erase(__first);
        __first = __next;
    }
}

template <class _Tp, class _Alloc>
void slist<_Tp, _Alloc>::unique() {
    iterator __first = begin();
    iterator __last = end();
    if (__first == __last)
        return;
    iterator __next = __first;
    while (++__next != __last) {
        if (*__first == *__next)
            erase(__next);
        else
            __first = __next;
        __next = __first;
    }
}

template <class _Tp, class _Alloc>
void slist<_Tp, _Alloc>::merge(slist<_Tp, _Alloc> &__x) {
    iterator __first1 = begin();
    iterator __last1 = end();
    iterator __first2 = __x.begin();
    iterator __last2 = __x.end();
    while (__first1 != __last1 && __first2 != __last2)
        if (*__first2 < *__first1) {
            iterator __next = __first2;
            transfer(__first1, __first2, ++__next);
            __first2 = __next;
        } else
            ++__first1;
    if (__first2 != __last2)
        transfer(__last1, __first2, __last2);
}

inline void __slist_base_reverse(_slist_node_base *__p) {
    _slist_node_base *__tmp = __p;
    do {
        __VDSA::swap(__tmp->_M_next, __tmp->_M_prev);
        __tmp = __tmp->_M_prev; // Old next node is now prev.
    } while (__tmp != __p);
}

template <class _Tp, class _Alloc>
inline void slist<_Tp, _Alloc>::reverse() {
    __slist_base_reverse(this->_M_node);
}

template <class _Tp, class _Alloc>
void slist<_Tp, _Alloc>::sort() {
    // Do nothing if the slist has length 0 or 1.
    if (_M_node->_M_next != _M_node && _M_node->_M_next->_M_next != _M_node) {
        slist<_Tp, _Alloc> __carry;
        slist<_Tp, _Alloc> __counter[64];
        int __fill = 0;
        while (!empty()) {
            __carry.splice(__carry.begin(), *this, begin());
            int __i = 0;
            while (__i < __fill && !__counter[__i].empty()) {
                __counter[__i].merge(__carry);
                __carry.swap(__counter[__i++]);
            }
            __carry.swap(__counter[__i]);
            if (__i == __fill)
                ++__fill;
        }

        for (int __i = 1; __i < __fill; ++__i)
            __counter[__i].merge(__counter[__i - 1]);
        swap(__counter[__fill - 1]);
    }
}

#ifdef __DST_MEMBER_TEMPLATES

template <class _Tp, class _Alloc>
template <class _Predicate>
void slist<_Tp, _Alloc>::remove_if(_Predicate __pred) {
    iterator __first = begin();
    iterator __last = end();
    while (__first != __last) {
        iterator __next = __first;
        ++__next;
        if (__pred(*__first))
            erase(__first);
        __first = __next;
    }
}

template <class _Tp, class _Alloc>
template <class _BinaryPredicate>
void slist<_Tp, _Alloc>::unique(_BinaryPredicate __binary_pred) {
    iterator __first = begin();
    iterator __last = end();
    if (__first == __last)
        return;
    iterator __next = __first;
    while (++__next != __last) {
        if (__binary_pred(*__first, *__next))
            erase(__next);
        else
            __first = __next;
        __next = __first;
    }
}

template <class _Tp, class _Alloc>
template <class _StrictWeakOrdering>
void slist<_Tp, _Alloc>::merge(slist<_Tp, _Alloc> &__x,
                               _StrictWeakOrdering __comp) {
    iterator __first1 = begin();
    iterator __last1 = end();
    iterator __first2 = __x.begin();
    iterator __last2 = __x.end();
    while (__first1 != __last1 && __first2 != __last2)
        if (__comp(*__first2, *__first1)) {
            iterator __next = __first2;
            transfer(__first1, __first2, ++__next);
            __first2 = __next;
        } else
            ++__first1;
    if (__first2 != __last2)
        transfer(__last1, __first2, __last2);
}

template <class _Tp, class _Alloc>
template <class _StrictWeakOrdering>
void slist<_Tp, _Alloc>::sort(_StrictWeakOrdering __comp) {
    // Do nothing if the slist has length 0 or 1.
    if (_M_node->_M_next != _M_node && _M_node->_M_next->_M_next != _M_node) {
        slist<_Tp, _Alloc> __carry;
        slist<_Tp, _Alloc> __counter[64];
        int __fill = 0;
        while (!empty()) {
            __carry.splice(__carry.begin(), *this, begin());
            int __i = 0;
            while (__i < __fill && !__counter[__i].empty()) {
                __counter[__i].merge(__carry, __comp);
                __carry.swap(__counter[__i++]);
            }
            __carry.swap(__counter[__i]);
            if (__i == __fill)
                ++__fill;
        }

        for (int __i = 1; __i < __fill; ++__i)
            __counter[__i].merge(__counter[__i - 1], __comp);
        swap(__counter[__fill - 1]);
    }
}

#endif /* __DST_MEMBER_TEMPLATES */

#if defined(__llvm) && !defined(__GNUC__) && (_MIPS_SIM != _MIPS_SIM_ABI32)
#pragma reset woff 1174
#pragma reset woff 1375
#endif

__DST_END_NAMESPACE

#endif /* ___DST_INTERNAL_SLIST_H */
