#include "concept_checks.h"

#ifndef ___DST_INTERNAL_DEQUE_H
#define ___DST_INTERNAL_DEQUE_H

/* Class invariants:
 *  For any nonsingular iterator i:
 *    i.node is the address of an element in the map array.  The
 *      contents of i.node is a pointer to the beginning of a node.
 *    i.first == *(i.node) 
 *    i.last  == i.first + node_size
 *    i.cur is a pointer in the range [i.first, i.last).  NOTE:
 *      the implication of this is that i.cur is always a dereferenceable
 *      pointer, even if i is a past-the-end iterator.
 *  Start and Finish are always nonsingular iterators.  NOTE: this means
 *    that an empty deque must have one node, and that a deque
 *    with N elements, where N is the buffer size, must have two nodes.
 *  For every node other than start.node and finish.node, every element
 *    in the node is an initialized object.  If start.node == finish.node,
 *    then [start.cur, finish.cur) are initialized objects, and
 *    the elements outside that range are uninitialized storage.  Otherwise,
 *    [start.cur, start.last) and [finish.first, finish.cur) are initialized
 *    objects, and [start.first, start.cur) and [finish.cur, finish.last)
 *    are uninitialized storage.
 *  [map, map + map_size) is a valid, non-empty range.  
 *  [start.node, finish.node] is a valid range contained within 
 *    [map, map + map_size).  
 *  A pointer in the range [map, map + map_size) points to an allocated node
 *    if and only if the pointer is in the range [start.node, finish.node].
 */

/*
 * In previous versions of deque, there was an extra template 
 * parameter so users could control the node size.  This extension
 * turns out to violate the C++ standard (it can be detected using
 * template template parameters), and it has been removed.
 */

__DST_BEGIN_NAMESPACE

#if defined(__sgi) && !defined(__GNUC__) && (_MIPS_SIM != _MIPS_SIM_ABI32)
#pragma set woff 1174
#pragma set woff 1375
#endif

// Note: this function is simply a kludge to work around several compilers'
//  bugs in handling constant expressions.
static inline size_t __deque_buf_size(size_t __size)
{
    return __size < 512 ? size_t(512 / __size) : size_t(1);
}
template <class _Tp, class _Ref, class _Ptr>
struct __deque_iterator
{
    typedef __deque_iterator<_Tp, _Tp &, _Tp *> iterator;
    typedef __deque_iterator<_Tp, const _Tp &, const _Tp *> const_iterator;
    inline static size_t __s_buffer_size() { return __deque_buf_size(sizeof(_Tp)); }

    typedef random_access_iterator_tag iterator_category;
    typedef _Tp value_type;
    typedef _Ptr pointer;
    typedef _Ref reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef _Tp **__map_pointer;

    typedef __deque_iterator __self;

    _Tp *__m_cur;
    _Tp *__m_first;
    _Tp *__m_last;
    __map_pointer __map_node;

    __deque_iterator(_Tp *__x, __map_pointer __y)
        : __m_cur(__x), __m_first(*__y), __m_last(*__y + __s_buffer_size()), __map_node(__y) {}

    __deque_iterator() : __m_cur(0), __m_first(0), __m_last(0), __map_node(0) {}

    __deque_iterator(const iterator &__x)
        : __m_cur(__x.__m_cur), __m_first(__x.__m_first), __m_last(__x.__m_last), __map_node(__x.__map_node) {}

    reference operator*() const { return *__m_cur; }

#ifndef ___DST_NO_ARROW_OPERATOR
    pointer operator->() const
    {
        return __m_cur;
    }
#endif /* ___DST_NO_ARROW_OPERATOR */

    difference_type operator-(const __self &__x) const
    {
        return difference_type(__s_buffer_size()) * (__map_node - __x.__map_node - 1) + (__m_cur - __m_first) + (__x.__m_last - __x.__m_cur);
    }

    __self &operator++()
    {
        ++__m_cur;
        if (__m_cur == __m_last)
        {
            __m_set_node(__map_node + 1);
            __m_cur = __m_first;
        }
        return *this;
    }
    __self operator++(int)
    {
        __self __tmp = *this;
        ++*this;
        return __tmp;
    }

    __self &operator--()
    {
        if (__m_cur == __m_first)
        {
            __m_set_node(__map_node - 1);
            __m_cur = __m_last;
        }
        --__m_cur;
        return *this;
    }
    __self operator--(int)
    {
        __self __tmp = *this;
        --*this;
        return __tmp;
    }

    __self &operator+=(difference_type __n)
    {
        difference_type __offset = __m_cur - __m_first + __n;
        if (0 <= __offset && __offset < difference_type(__s_buffer_size()))
            __m_cur += __n;
        else
        {
            difference_type __node_offset = __offset > 0 ? __offset / difference_type(__s_buffer_size()) : -difference_type((-__offset - 1) / __s_buffer_size()) - 1;
            __m_set_node(__map_node + __node_offset);
            __m_cur = __m_first + (__offset - __node_offset * difference_type(__s_buffer_size()));
        }
        return *this;
    }

    __self operator+(difference_type __n) const
    {
        __self __tmp = *this;
        return __tmp += __n;
    }

    __self &operator-=(difference_type __n) { return *this += -__n; }

    __self operator-(difference_type __n) const
    {
        __self __tmp = *this;
        return __tmp -= __n;
    }

    reference operator[](difference_type __n) const { return *(*this + __n); }

    bool operator==(const __self &__x) const { return __m_cur == __x.__m_cur; }
    bool operator!=(const __self &__x) const { return !(*this == __x); }
    bool operator<(const __self &__x) const
    {
        return (__map_node == __x.__map_node) ? (__m_cur < __x.__m_cur) : (__map_node < __x.__map_node);
    }
    bool operator>(const __self &__x) const { return __x < *this; }
    bool operator<=(const __self &__x) const { return !(__x < *this); }
    bool operator>=(const __self &__x) const { return !(*this < __x); }

    void __m_set_node(__map_pointer __new_node)
    {
        __map_node = __new_node;
        __m_first = *__new_node;
        __m_last = __m_first + difference_type(__s_buffer_size());
    }
};

template <class _Tp, class _Ref, class _Ptr>
inline __deque_iterator<_Tp, _Ref, _Ptr>
operator+(ptrdiff_t __n, const __deque_iterator<_Tp, _Ref, _Ptr> &__x)
{
    return __x + __n;
}

#ifndef __DST_CLASS_PARTIAL_SPECIALIZATION

template <class _Tp, class _Ref, class _Ptr>
inline random_access_iterator_tag
iterator_category(const __deque_iterator<_Tp, _Ref, _Ptr> &)
{
    return random_access_iterator_tag();
}

template <class _Tp, class _Ref, class _Ptr>
inline _Tp *value_type(const __deque_iterator<_Tp, _Ref, _Ptr> &) { return 0; }

template <class _Tp, class _Ref, class _Ptr>
inline ptrdiff_t *distance_type(const __deque_iterator<_Tp, _Ref, _Ptr> &)
{
    return 0;
}

#endif /* __DST_CLASS_PARTIAL_SPECIALIZATION */

// deque base class.  It has two purposes.  First, its constructor
//  and destructor allocate (but don't initialize) storage.  This makes
//  exception safety easier.  Second, the base class encapsulates all of
//  the differences between stl-style allocators and standard-conforming
//  allocators.

#ifdef __DST_USE_DSA_ALLOCATORS

// Base class for ordinary allocators.
template <class _Tp, class _Alloc, bool __is_static>
class __deque_alloc_base
{
public:
    typedef typename _Alloc_traits<_Tp, _Alloc>::allocator_type allocator_type;
    allocator_type get_allocator() const { return __m_node_allocator; }

    __deque_alloc_base(const allocator_type &__a)
        : __m_node_allocator(__a), __m_map_allocator(__a), __m_map(0), __m_map_size(0)
    {
    }

protected:
    typedef typename _Alloc_traits<_Tp *, _Alloc>::allocator_type __map_allocator_type;

    allocator_type __m_node_allocator;
    __map_allocator_type __m_map_allocator;

    _Tp *__m_allocate_node()
    {
        return __m_node_allocator.allocate(__deque_buf_size(sizeof(_Tp)));
    }
    void __m_deallocate_node(_Tp *__p)
    {
        __m_node_allocator.deallocate(__p, __deque_buf_size(sizeof(_Tp)));
    }
    _Tp **__m_allocate_map(size_t __n)
    {
        return __m_map_allocator.allocate(__n);
    }
    void __m_deallocate_map(_Tp **__p, size_t __n)
    {
        __m_map_allocator.deallocate(__p, __n);
    }

    _Tp **__m_map;
    size_t __m_map_size;
};

// Specialization for instanceless allocators.
template <class _Tp, class _Alloc>
class __deque_alloc_base<_Tp, _Alloc, true>
{
public:
    typedef typename _Alloc_traits<_Tp, _Alloc>::allocator_type allocator_type;
    allocator_type get_allocator() const { return allocator_type(); }

    __deque_alloc_base(const allocator_type &) : __m_map(0), __m_map_size(0) {}

protected:
    typedef typename _Alloc_traits<_Tp, _Alloc>::_Alloc_type __node_alloc_type;
    typedef typename _Alloc_traits<_Tp *, _Alloc>::_Alloc_type __map_alloc_type;

    _Tp *__m_allocate_node()
    {
        return __node_alloc_type::allocate(__deque_buf_size(sizeof(_Tp)));
    }
    void __m_deallocate_node(_Tp *__p)
    {
        __node_alloc_type::deallocate(__p, __deque_buf_size(sizeof(_Tp)));
    }
    _Tp **__m_allocate_map(size_t __n)
    {
        return __map_alloc_type::allocate(__n);
    }
    void __m_deallocate_map(_Tp **__p, size_t __n)
    {
        __map_alloc_type::deallocate(__p, __n);
    }

    _Tp **__m_map;
    size_t __m_map_size;
};

template <class _Tp, class _Alloc>
class __deque_base : public __deque_alloc_base<_Tp, _Alloc, _Alloc_traits<_Tp, _Alloc>::_S_instanceless>
{
public:
    typedef __deque_alloc_base<_Tp, _Alloc, _Alloc_traits<_Tp, _Alloc>::_S_instanceless> __base;
    typedef typename __base::allocator_type allocator_type;
    typedef __deque_iterator<_Tp, _Tp &, _Tp *> iterator;
    typedef __deque_iterator<_Tp, const _Tp &, const _Tp *> const_iterator;

    __deque_base(const allocator_type &__a, size_t __num_elements) : __base(__a), __m_start(), __m_finish()
    {
        __m_initialize_map(__num_elements);
    }
    __deque_base(const allocator_type &__a) : __base(__a), __m_start(), __m_finish() {}
    ~__deque_base();

protected:
    void __m_initialize_map(size_t);
    void __m_create_nodes(_Tp **__nstart, _Tp **__nfinish);
    void __m_destroy_nodes(_Tp **__nstart, _Tp **__nfinish);
    enum
    {
        __s_initial_map_size = 8
    };

protected:
    iterator __m_start;
    iterator __m_finish;
};

#else /* __DST_USE_DSA_ALLOCATORS */

template <class _Tp, class _Alloc>
class __deque_base
{
public:
    typedef __deque_iterator<_Tp, _Tp &, _Tp *> iterator;
    typedef __deque_iterator<_Tp, const _Tp &, const _Tp *> const_iterator;

    typedef _Alloc allocator_type;
    allocator_type get_allocator() const { return allocator_type(); }

    __deque_base(const allocator_type &, size_t __num_elements) : __m_map(0), __m_map_size(0), __m_start(), __m_finish()
    {
        __m_initialize_map(__num_elements);
    }
    __deque_base(const allocator_type &) : __m_map(0), __m_map_size(0), __m_start(), __m_finish() {}
    ~__deque_base();

protected:
    void __m_initialize_map(size_t);
    void __m_create_nodes(_Tp **__nstart, _Tp **__nfinish);
    void __m_destroy_nodes(_Tp **__nstart, _Tp **__nfinish);
    enum
    {
        __s_initial_map_size = 8
    };

protected:
    _Tp **__m_map;
    size_t __m_map_size;
    iterator __m_start;
    iterator __m_finish;

    typedef simple_alloc<_Tp, _Alloc> __node_alloc_type;
    typedef simple_alloc<_Tp *, _Alloc> __map_alloc_type;

    _Tp *__m_allocate_node()
    {
        return __node_alloc_type::allocate(__deque_buf_size(sizeof(_Tp)));
    }
    void __m_deallocate_node(_Tp *__p)
    {
        __node_alloc_type::deallocate(__p, __deque_buf_size(sizeof(_Tp)));
    }
    _Tp **__m_allocate_map(size_t __n)
    {
        return __map_alloc_type::allocate(__n);
    }
    void __m_deallocate_map(_Tp **__p, size_t __n)
    {
        __map_alloc_type::deallocate(__p, __n);
    }
};

#endif /* __DST_USE_DSA_ALLOCATORS */

// Non-inline member functions from __deque_base.

template <class _Tp, class _Alloc>
__deque_base<_Tp, _Alloc>::~__deque_base()
{
    if (__m_map)
    {
        __m_destroy_nodes(__m_start.__map_node, __m_finish.__map_node + 1);
        __m_deallocate_map(__m_map, __m_map_size);
    }
}

template <class _Tp, class _Alloc>
void __deque_base<_Tp, _Alloc>::__m_initialize_map(size_t __num_elements)
{
    size_t __num_nodes = __num_elements / __deque_buf_size(sizeof(_Tp)) + 1;

    __m_map_size = max((size_t)__s_initial_map_size, __num_nodes + 2);
    __m_map = __m_allocate_map(__m_map_size);

    _Tp **__nstart = __m_map + (__m_map_size - __num_nodes) / 2;
    _Tp **__nfinish = __nstart + __num_nodes;

    __DST_TRY
    {
        __m_create_nodes(__nstart, __nfinish);
    }
    __DST_UNWIND((__m_deallocate_map(__m_map, __m_map_size), __m_map = 0, __m_map_size = 0));
    __m_start.__m_set_node(__nstart);
    __m_finish.__m_set_node(__nfinish - 1);
    __m_start.__m_cur = __m_start.__m_first;
    __m_finish.__m_cur = __m_finish.__m_first + __num_elements % __deque_buf_size(sizeof(_Tp));
}

template <class _Tp, class _Alloc>
void __deque_base<_Tp, _Alloc>::__m_create_nodes(_Tp **__nstart, _Tp **__nfinish)
{
    _Tp **__cur;
    __DST_TRY
    {
        for (__cur = __nstart; __cur < __nfinish; ++__cur)
            *__cur = __m_allocate_node();
    }
    __DST_UNWIND(__m_destroy_nodes(__nstart, __cur));
}

template <class _Tp, class _Alloc>
void __deque_base<_Tp, _Alloc>::__m_destroy_nodes(_Tp **__nstart, _Tp **__nfinish)
{
    for (_Tp **__n = __nstart; __n < __nfinish; ++__n)
        __m_deallocate_node(*__n);
}

template <class _Tp, class _Alloc = __DST_DEFAULT_ALLOCATOR(_Tp)>
class deque : protected __deque_base<_Tp, _Alloc>
{
    // requirements:

    __DST_CLASS_REQUIRES(_Tp, _Assignable);

    typedef __deque_base<_Tp, _Alloc> __base;

public: // basic types
    typedef _Tp value_type;
    typedef value_type *pointer;
    typedef const value_type *const_pointer;
    typedef value_type &reference;
    typedef const value_type &const_reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;

    typedef typename __base::allocator_type allocator_type;
    allocator_type get_allocator() const { return __base::get_allocator(); }

    // Iterators
    typedef typename __base::iterator iterator;
    typedef typename __base::const_iterator const_iterator;

#ifdef __DST_CLASS_PARTIAL_SPECIALIZATION
    typedef reverse_iterator<const_iterator> const_reverse_iterator;
    typedef reverse_iterator<iterator> reverse_iterator;
#else  /* __DST_CLASS_PARTIAL_SPECIALIZATION */
    typedef reverse_iterator<const_iterator, value_type, const_reference, difference_type> const_reverse_iterator;
    typedef reverse_iterator<iterator, value_type, reference, difference_type>
        reverse_iterator;
#endif /* __DST_CLASS_PARTIAL_SPECIALIZATION */

protected:
    // Internal typedefs
    typedef pointer *__map_pointer;

    static size_t __s_buffer_size() { return __deque_buf_size(sizeof(_Tp)); }

    using __base::__m_allocate_map;
    using __base::__m_allocate_node;
    using __base::__m_create_nodes;
    using __base::__m_deallocate_map;
    using __base::__m_deallocate_node;
    using __base::__m_destroy_nodes;
    using __base::__m_finish;
    using __base::__m_initialize_map;
    using __base::__m_map;
    using __base::__m_map_size;
    using __base::__m_start;

public:
    // basic accessors
    iterator begin() { return __m_start; }
    iterator end() { return __m_finish; }
    const_iterator begin() const { return __m_start; }
    const_iterator end() const { return __m_finish; }

    reverse_iterator rbegin() { return reverse_iterator(__m_finish); }
    reverse_iterator rend() { return reverse_iterator(__m_start); }
    const_reverse_iterator rbegin() const
    {
        return const_reverse_iterator(__m_finish);
    }
    const_reverse_iterator rend() const
    {
        return const_reverse_iterator(__m_start);
    }

    reference operator[](size_type __n)
    {
        return __m_start[difference_type(__n)];
    }
    const_reference operator[](size_type __n) const
    {
        return __m_start[difference_type(__n)];
    }

#ifdef __DST_THROW_RANGE_ERRORS
    void __m_range_check(size_type __n) const
    {
        if (__n >= this->size())
            __dst_throw_range_error("deque");
    }

    reference at(size_type __n)
    {
        __m_range_check(__n);
        return (*this)[__n];
    }
    const_reference at(size_type __n) const
    {
        __m_range_check(__n);
        return (*this)[__n];
    }
#endif /* __DST_THROW_RANGE_ERRORS */

    reference front()
    {
        return *__m_start;
    }
    reference back()
    {
        iterator __tmp = __m_finish;
        --__tmp;
        return *__tmp;
    }
    const_reference front() const { return *__m_start; }
    const_reference back() const
    {
        const_iterator __tmp = __m_finish;
        --__tmp;
        return *__tmp;
    }

    size_type size() const { return __m_finish - __m_start; }
    size_type max_size() const { return size_type(-1); }
    bool empty() const { return __m_finish == __m_start; }

public: // Constructor, destructor.
    explicit deque(const allocator_type &__a = allocator_type())
        : __base(__a, 0) {}
    deque(const deque &__x) : __base(__x.get_allocator(), __x.size())
    {
        uninitialized_copy(__x.begin(), __x.end(), __m_start);
    }
    deque(size_type __n, const value_type &__value,
          const allocator_type &__a = allocator_type()) : __base(__a, __n)
    {
        __m_fill_initialize(__value);
    }
    explicit deque(size_type __n) : __base(allocator_type(), __n)
    {
        __m_fill_initialize(value_type());
    }

#ifdef __DST_MEMBER_TEMPLATES

    // Check whether it's an integral type.  If so, it's not an iterator.
    template <class _InputIterator>
    deque(_InputIterator __first, _InputIterator __last,
          const allocator_type &__a = allocator_type()) : __base(__a)
    {
        typedef typename _Is_integer<_InputIterator>::_Integral _Integral;
        __m_initialize_dispatch(__first, __last, _Integral());
    }

    template <class _Integer>
    void __m_initialize_dispatch(_Integer __n, _Integer __x, __true_type)
    {
        __m_initialize_map(__n);
        __m_fill_initialize(__x);
    }

    template <class _InputIter>
    void __m_initialize_dispatch(_InputIter __first, _InputIter __last,  __false_type)
    {
        __m_range_initialize(__first, __last, __ITERATOR_CATEGORY(__first));
    }

#else /* __DST_MEMBER_TEMPLATES */

    deque(const value_type *__first, const value_type *__last,
          const allocator_type &__a = allocator_type())
        : __base(__a, __last - __first)
    {
        uninitialized_copy(__first, __last, __m_start);
    }
    deque(const_iterator __first, const_iterator __last,
          const allocator_type &__a = allocator_type())
        : __base(__a, __last - __first)
    {
        uninitialized_copy(__first, __last, __m_start);
    }

#endif /* __DST_MEMBER_TEMPLATES */

    ~deque()
    {
        destroy(__m_start, __m_finish);
    }

    deque &operator=(const deque &__x)
    {
        const size_type __len = size();
        if (&__x != this)
        {
            if (__len >= __x.size())
                erase(copy(__x.begin(), __x.end(), __m_start), __m_finish);
            else
            {
                const_iterator __mid = __x.begin() + difference_type(__len);
                copy(__x.begin(), __mid, __m_start);
                insert(__m_finish, __mid, __x.end());
            }
        }
        return *this;
    }

    void swap(deque &__x)
    {
        __VDSA::swap(__m_start, __x.__m_start);
        __VDSA::swap(__m_finish, __x.__m_finish);
        __VDSA::swap(__m_map, __x.__m_map);
        __VDSA::swap(__m_map_size, __x.__m_map_size);
    }

public:
    // assign(), a generalized assignment member function.  Two
    // versions: one that takes a count, and one that takes a range.
    // The range version is a member template, so we dispatch on whether
    // or not the type is an integer.

    void __m_fill_assign(size_type __n, const _Tp &__val)
    {
        if (__n > size())
        {
            fill(begin(), end(), __val);
            insert(end(), __n - size(), __val);
        }
        else
        {
            erase(begin() + __n, end());
            fill(begin(), end(), __val);
        }
    }

    void assign(size_type __n, const _Tp &__val)
    {
        __m_fill_assign(__n, __val);
    }

#ifdef __DST_MEMBER_TEMPLATES

    template <class _InputIterator>
    void assign(_InputIterator __first, _InputIterator __last)
    {
        typedef typename _Is_integer<_InputIterator>::_Integral _Integral;
        __m_assign_dispatch(__first, __last, _Integral());
    }

private: // helper functions for assign()
    template <class _Integer>
    void __m_assign_dispatch(_Integer __n, _Integer __val, __true_type)
    {
        __m_fill_assign((size_type)__n, (_Tp)__val);
    }

    template <class _InputIterator>
    void __m_assign_dispatch(_InputIterator __first, _InputIterator __last, __false_type)
    {
        __m_assign_aux(__first, __last, __ITERATOR_CATEGORY(__first));
    }

    template <class _InputIterator>
    void __m_assign_aux(_InputIterator __first, _InputIterator __last, input_iterator_tag);

    template <class _ForwardIterator>
    void __m_assign_aux(_ForwardIterator __first, _ForwardIterator __last, forward_iterator_tag)
    {
        size_type __len = 0;
        distance(__first, __last, __len);
        if (__len > size())
        {
            _ForwardIterator __mid = __first;
            advance(__mid, size());
            copy(__first, __mid, begin());
            insert(end(), __mid, __last);
        }
        else
            erase(copy(__first, __last, begin()), end());
    }

#endif /* __DST_MEMBER_TEMPLATES */

public: // push_* and pop_*
    void push_back(const value_type &__t)
    {
        if (__m_finish.__m_cur != __m_finish.__m_last - 1)
        {
            construct(__m_finish.__m_cur, __t);
            ++__m_finish.__m_cur;
        }
        else
            __m_push_back_aux(__t);
    }

    void push_back()
    {
        if (__m_finish.__m_cur != __m_finish.__m_last - 1)
        {
            construct(__m_finish.__m_cur);
            ++__m_finish.__m_cur;
        }
        else
            __m_push_back_aux();
    }

    void push_front(const value_type &__t)
    {
        if (__m_start.__m_cur != __m_start.__m_first)
        {
            construct(__m_start.__m_cur - 1, __t);
            --__m_start.__m_cur;
        }
        else
            __m_push_front_aux(__t);
    }

    void push_front()
    {
        if (__m_start.__m_cur != __m_start.__m_first)
        {
            construct(__m_start.__m_cur - 1);
            --__m_start.__m_cur;
        }
        else
            __m_push_front_aux();
    }

    void pop_back()
    {
        if (__m_finish.__m_cur != __m_finish.__m_first)
        {
            --__m_finish.__m_cur;
            destroy(__m_finish.__m_cur);
        }
        else
            __m_pop_back_aux();
    }

    void pop_front()
    {
        if (__m_start.__m_cur != __m_start.__m_last - 1)
        {
            destroy(__m_start.__m_cur);
            ++__m_start.__m_cur;
        }
        else
            __m_pop_front_aux();
    }

public: // Insert
    iterator insert(iterator position, const value_type &__x)
    {
        if (position.__m_cur == __m_start.__m_cur)
        {
            push_front(__x);
            return __m_start;
        }
        else if (position.__m_cur == __m_finish.__m_cur)
        {
            push_back(__x);
            iterator __tmp = __m_finish;
            --__tmp;
            return __tmp;
        }
        else
        {
            return __m_insert_aux(position, __x);
        }
    }

    iterator insert(iterator __position)
    {
        return insert(__position, value_type());
    }

    void insert(iterator __pos, size_type __n, const value_type &__x)
    {
        __m_fill_insert(__pos, __n, __x);
    }

    void __m_fill_insert(iterator __pos, size_type __n, const value_type &__x);

#ifdef __DST_MEMBER_TEMPLATES

    // Check whether it's an integral type.  If so, it's not an iterator.
    template <class _InputIterator>
    void insert(iterator __pos, _InputIterator __first, _InputIterator __last)
    {
        typedef typename _Is_integer<_InputIterator>::_Integral _Integral;
        __m_insert_dispatch(__pos, __first, __last, _Integral());
    }

    template <class _Integer>
    void __m_insert_dispatch(iterator __pos, _Integer __n, _Integer __x, __true_type)
    {
        __m_fill_insert(__pos, (size_type)__n, (value_type)__x);
    }

    template <class _InputIterator>
    void __m_insert_dispatch(iterator __pos, _InputIterator __first, _InputIterator __last, __false_type)
    {
        insert(__pos, __first, __last, __ITERATOR_CATEGORY(__first));
    }

#else /* __DST_MEMBER_TEMPLATES */

    void insert(iterator __pos, const value_type *__first, const value_type *__last);
    void insert(iterator __pos, const_iterator __first, const_iterator __last);

#endif /* __DST_MEMBER_TEMPLATES */

    void resize(size_type __new_size, const value_type &__x)
    {
        const size_type __len = size();
        if (__new_size < __len)
            erase(__m_start + __new_size, __m_finish);
        else
            insert(__m_finish, __new_size - __len, __x);
    }

    void resize(size_type new_size) { resize(new_size, value_type()); }

public: // Erase
    iterator erase(iterator __pos)
    {
        iterator __next = __pos;
        ++__next;
        difference_type __index = __pos - __m_start;
        if (size_type(__index) < (this->size() >> 1))
        {
            copy_backward(__m_start, __pos, __next);
            pop_front();
        }
        else
        {
            copy(__next, __m_finish, __pos);
            pop_back();
        }
        return __m_start + __index;
    }

    iterator erase(iterator __first, iterator __last);
    void clear();

protected: // Internal construction/destruction
    void __m_fill_initialize(const value_type &__value);

#ifdef __DST_MEMBER_TEMPLATES

    template <class _InputIterator>
    void __m_range_initialize(_InputIterator __first, _InputIterator __last, input_iterator_tag);

    template <class _ForwardIterator>
    void __m_range_initialize(_ForwardIterator __first, _ForwardIterator __last, forward_iterator_tag);

#endif /* __DST_MEMBER_TEMPLATES */

protected: // Internal push_* and pop_*
    void __m_push_back_aux(const value_type &);
    void __m_push_back_aux();
    void __m_push_front_aux(const value_type &);
    void __m_push_front_aux();
    void __m_pop_back_aux();
    void __m_pop_front_aux();

protected: // Internal insert functions
#ifdef __DST_MEMBER_TEMPLATES

    template <class _InputIterator>
    void insert(iterator __pos, _InputIterator __first, _InputIterator __last, input_iterator_tag);

    template <class _ForwardIterator>
    void insert(iterator __pos, _ForwardIterator __first, _ForwardIterator __last, forward_iterator_tag);

#endif /* __DST_MEMBER_TEMPLATES */

    iterator __m_insert_aux(iterator __pos, const value_type &__x);
    iterator __m_insert_aux(iterator __pos);
    void __m_insert_aux(iterator __pos, size_type __n, const value_type &__x);

#ifdef __DST_MEMBER_TEMPLATES

    template <class _ForwardIterator>
    void __m_insert_aux(iterator __pos, _ForwardIterator __first, _ForwardIterator __last, size_type __n);

#else /* __DST_MEMBER_TEMPLATES */

    void __m_insert_aux(iterator __pos, const value_type *__first, const value_type *__last, size_type __n);

    void __m_insert_aux(iterator __pos, const_iterator __first, const_iterator __last, size_type __n);

#endif /* __DST_MEMBER_TEMPLATES */

    iterator __m_reserve_elements_at_front(size_type __n)
    {
        size_type __vacancies = __m_start.__m_cur - __m_start.__m_first;
        if (__n > __vacancies)
            __m_new_elements_at_front(__n - __vacancies);
        return __m_start - difference_type(__n);
    }

    iterator __m_reserve_elements_at_back(size_type __n)
    {
        size_type __vacancies = (__m_finish.__m_last - __m_finish.__m_cur) - 1;
        if (__n > __vacancies)
            __m_new_elements_at_back(__n - __vacancies);
        return __m_finish + difference_type(__n);
    }

    void __m_new_elements_at_front(size_type __new_elements);
    void __m_new_elements_at_back(size_type __new_elements);

protected: // Allocation of __m_map and nodes
    // Makes sure the __m_map has space for new nodes.  Does not actually
    //  add the nodes.  Can invalidate __m_map pointers.  (And consequently,
    //  deque iterators.)

    void __m_reserve_map_at_back(size_type __nodes_to_add = 1)
    {
        if (__nodes_to_add + 1 > __m_map_size - (__m_finish.__map_node - __m_map))
            __m_reallocate_map(__nodes_to_add, false);
    }

    void __m_reserve_map_at_front(size_type __nodes_to_add = 1)
    {
        if (__nodes_to_add > size_type(__m_start.__map_node - __m_map))
            __m_reallocate_map(__nodes_to_add, true);
    }

    void __m_reallocate_map(size_type __nodes_to_add, bool __add_at_front);
};

// Non-inline member functions

#ifdef __DST_MEMBER_TEMPLATES

template <class _Tp, class _Alloc>
template <class _InputIter>
void deque<_Tp, _Alloc>::__m_assign_aux(_InputIter __first, _InputIter __last, input_iterator_tag)
{
    iterator __cur = begin();
    for (; __first != __last && __cur != end(); ++__cur, ++__first)
        *__cur = *__first;
    if (__first == __last)
        erase(__cur, end());
    else
        insert(end(), __first, __last);
}

#endif /* __DST_MEMBER_TEMPLATES */

template <class _Tp, class _Alloc>
void deque<_Tp, _Alloc>::__m_fill_insert(iterator __pos, size_type __n, const value_type &__x)
{
    if (__pos.__m_cur == __m_start.__m_cur)
    {
        iterator __new_start = __m_reserve_elements_at_front(__n);
        __DST_TRY
        {
            uninitialized_fill(__new_start, __m_start, __x);
            __m_start = __new_start;
        }
        __DST_UNWIND(__m_destroy_nodes(__new_start.__map_node, __m_start.__map_node));
    }
    else if (__pos.__m_cur == __m_finish.__m_cur)
    {
        iterator __new_finish = __m_reserve_elements_at_back(__n);
        __DST_TRY
        {
            uninitialized_fill(__m_finish, __new_finish, __x);
            __m_finish = __new_finish;
        }
        __DST_UNWIND(__m_destroy_nodes(__m_finish.__map_node + 1, __new_finish.__map_node + 1));
    }
    else
        __m_insert_aux(__pos, __n, __x);
}

#ifndef __DST_MEMBER_TEMPLATES

template <class _Tp, class _Alloc>
void deque<_Tp, _Alloc>::insert(iterator __pos, const value_type *__first, const value_type *__last)
{
    size_type __n = __last - __first;
    if (__pos.__m_cur == __m_start.__m_cur)
    {
        iterator __new_start = __m_reserve_elements_at_front(__n);
        __DST_TRY
        {
            uninitialized_copy(__first, __last, __new_start);
            __m_start = __new_start;
        }
        __DST_UNWIND(__m_destroy_nodes(__new_start.__map_node, __m_start.__map_node));
    }
    else if (__pos.__m_cur == __m_finish.__m_cur)
    {
        iterator __new_finish = __m_reserve_elements_at_back(__n);
        __DST_TRY
        {
            uninitialized_copy(__first, __last, __m_finish);
            __m_finish = __new_finish;
        }
        __DST_UNWIND(__m_destroy_nodes(__m_finish.__map_node + 1, __new_finish.__map_node + 1));
    }
    else
        __m_insert_aux(__pos, __first, __last, __n);
}

template <class _Tp, class _Alloc>
void deque<_Tp, _Alloc>::insert(iterator __pos, const_iterator __first, const_iterator __last)
{
    size_type __n = __last - __first;
    if (__pos.__m_cur == __m_start.__m_cur)
    {
        iterator __new_start = __m_reserve_elements_at_front(__n);
        __DST_TRY
        {
            uninitialized_copy(__first, __last, __new_start);
            __m_start = __new_start;
        }
        __DST_UNWIND(__m_destroy_nodes(__new_start.__map_node, __m_start.__map_node));
    }
    else if (__pos.__m_cur == __m_finish.__m_cur)
    {
        iterator __new_finish = __m_reserve_elements_at_back(__n);
        __DST_TRY
        {
            uninitialized_copy(__first, __last, __m_finish);
            __m_finish = __new_finish;
        }
        __DST_UNWIND(__m_destroy_nodes(__m_finish.__map_node + 1, __new_finish.__map_node + 1));
    }
    else
        __m_insert_aux(__pos, __first, __last, __n);
}

#endif /* __DST_MEMBER_TEMPLATES */

template <class _Tp, class _Alloc>
typename deque<_Tp, _Alloc>::iterator
deque<_Tp, _Alloc>::erase(iterator __first, iterator __last)
{
    if (__first == __m_start && __last == __m_finish)
    {
        clear();
        return __m_finish;
    }
    else
    {
        difference_type __n = __last - __first;
        difference_type __elems_before = __first - __m_start;
        if (__elems_before < difference_type((this->size() - __n) / 2))
        {
            copy_backward(__m_start, __first, __last);
            iterator __new_start = __m_start + __n;
            destroy(__m_start, __new_start);
            __m_destroy_nodes(__new_start.__map_node, __m_start.__map_node);
            __m_start = __new_start;
        }
        else
        {
            copy(__last, __m_finish, __first);
            iterator __new_finish = __m_finish - __n;
            destroy(__new_finish, __m_finish);
            __m_destroy_nodes(__new_finish.__map_node + 1, __m_finish.__map_node + 1);
            __m_finish = __new_finish;
        }
        return __m_start + __elems_before;
    }
}

template <class _Tp, class _Alloc>
void deque<_Tp, _Alloc>::clear()
{
    for (__map_pointer __node = __m_start.__map_node + 1; __node < __m_finish.__map_node; ++__node)
    {
        destroy(*__node, *__node + __s_buffer_size());
        __m_deallocate_node(*__node);
    }

    if (__m_start.__map_node != __m_finish.__map_node)
    {
        destroy(__m_start.__m_cur, __m_start.__m_last);
        destroy(__m_finish.__m_first, __m_finish.__m_cur);
        __m_deallocate_node(__m_finish.__m_first);
    }
    else
        destroy(__m_start.__m_cur, __m_finish.__m_cur);

    __m_finish = __m_start;
}

// Precondition: __m_start and __m_finish have already been initialized,
// but none of the deque's elements have yet been constructed.
template <class _Tp, class _Alloc>
void deque<_Tp, _Alloc>::__m_fill_initialize(const value_type &__value)
{
    __map_pointer __cur;
    __DST_TRY
    {
        for (__cur = __m_start.__map_node; __cur < __m_finish.__map_node; ++__cur)
        {
            uninitialized_fill(*__cur, *__cur + __s_buffer_size(), __value);
        }
        uninitialized_fill(__m_finish.__m_first, __m_finish.__m_cur, __value);
    }
    __DST_UNWIND(destroy(__m_start, iterator(*__cur, __cur)));
}

#ifdef __DST_MEMBER_TEMPLATES

template <class _Tp, class _Alloc>
template <class _InputIterator>
void deque<_Tp, _Alloc>::__m_range_initialize(_InputIterator __first, _InputIterator __last, input_iterator_tag)
{
    __m_initialize_map(0);
    __DST_TRY
    {
        for (; __first != __last; ++__first)
            push_back(*__first);
    }
    __DST_UNWIND(clear());
}

template <class _Tp, class _Alloc>
template <class _ForwardIterator>
void deque<_Tp, _Alloc>::__m_range_initialize(_ForwardIterator __first, _ForwardIterator __last, forward_iterator_tag)
{
    size_type __n = 0;
    distance(__first, __last, __n);
    __m_initialize_map(__n);

    __map_pointer __cur_node;
    __DST_TRY
    {
        for (__cur_node = __m_start.__map_node;
             __cur_node < __m_finish.__map_node;
             ++__cur_node)
        {
            _ForwardIterator __mid = __first;
            advance(__mid, __s_buffer_size());
            uninitialized_copy(__first, __mid, *__cur_node);
            __first = __mid;
        }
        uninitialized_copy(__first, __last, __m_finish.__m_first);
    }
    __DST_UNWIND(destroy(__m_start, iterator(*__cur_node, __cur_node)));
}

#endif /* __DST_MEMBER_TEMPLATES */

// Called only if __m_finish.__m_cur == __m_finish.__m_last - 1.
template <class _Tp, class _Alloc>
void deque<_Tp, _Alloc>::__m_push_back_aux(const value_type &__t)
{
    value_type __t_copy = __t;
    __m_reserve_map_at_back();
    *(__m_finish.__map_node + 1) = __m_allocate_node();
    __DST_TRY
    {
        construct(__m_finish.__m_cur, __t_copy);
        __m_finish.__m_set_node(__m_finish.__map_node + 1);
        __m_finish.__m_cur = __m_finish.__m_first;
    }
    __DST_UNWIND(__m_deallocate_node(*(__m_finish.__map_node + 1)));
}

// Called only if __m_finish.__m_cur == __m_finish.__m_last - 1.
template <class _Tp, class _Alloc>
void deque<_Tp, _Alloc>::__m_push_back_aux()
{
    __m_reserve_map_at_back();
    *(__m_finish.__map_node + 1) = __m_allocate_node();
    __DST_TRY
    {
        construct(__m_finish.__m_cur);
        __m_finish.__m_set_node(__m_finish.__map_node + 1);
        __m_finish.__m_cur = __m_finish.__m_first;
    }
    __DST_UNWIND(__m_deallocate_node(*(__m_finish.__map_node + 1)));
}

// Called only if __m_start.__m_cur == __m_start.__m_first.
template <class _Tp, class _Alloc>
void deque<_Tp, _Alloc>::__m_push_front_aux(const value_type &__t)
{
    value_type __t_copy = __t;
    __m_reserve_map_at_front();
    *(__m_start.__map_node - 1) = __m_allocate_node();
    __DST_TRY
    {
        __m_start.__m_set_node(__m_start.__map_node - 1);
        __m_start.__m_cur = __m_start.__m_last - 1;
        construct(__m_start.__m_cur, __t_copy);
    }
    __DST_UNWIND((++__m_start, __m_deallocate_node(*(__m_start.__map_node - 1))));
}

// Called only if __m_start.__m_cur == __m_start.__m_first.
template <class _Tp, class _Alloc>
void deque<_Tp, _Alloc>::__m_push_front_aux()
{
    __m_reserve_map_at_front();
    *(__m_start.__map_node - 1) = __m_allocate_node();
    __DST_TRY
    {
        __m_start.__m_set_node(__m_start.__map_node - 1);
        __m_start.__m_cur = __m_start.__m_last - 1;
        construct(__m_start.__m_cur);
    }
    __DST_UNWIND((++__m_start, __m_deallocate_node(*(__m_start.__map_node - 1))));
}

// Called only if __m_finish.__m_cur == __m_finish.__m_first.
template <class _Tp, class _Alloc>
void deque<_Tp, _Alloc>::__m_pop_back_aux()
{
    __m_deallocate_node(__m_finish.__m_first);
    __m_finish.__m_set_node(__m_finish.__map_node - 1);
    __m_finish.__m_cur = __m_finish.__m_last - 1;
    destroy(__m_finish.__m_cur);
}

// Called only if __m_start.__m_cur == __m_start.__m_last - 1.  Note that
// if the deque has at least one element (a precondition for this member
// function), and if __m_start.__m_cur == __m_start.__m_last, then the deque
// must have at least two nodes.
template <class _Tp, class _Alloc>
void deque<_Tp, _Alloc>::__m_pop_front_aux()
{
    destroy(__m_start.__m_cur);
    __m_deallocate_node(__m_start.__m_first);
    __m_start.__m_set_node(__m_start.__map_node + 1);
    __m_start.__m_cur = __m_start.__m_first;
}

#ifdef __DST_MEMBER_TEMPLATES

template <class _Tp, class _Alloc>
template <class _InputIterator>
void deque<_Tp, _Alloc>::insert(iterator __pos, _InputIterator __first, _InputIterator __last, input_iterator_tag)
{
    copy(__first, __last, inserter(*this, __pos));
}

template <class _Tp, class _Alloc>
template <class _ForwardIterator>
void deque<_Tp, _Alloc>::insert(iterator __pos, _ForwardIterator __first, _ForwardIterator __last, forward_iterator_tag)
{
    size_type __n = 0;
    distance(__first, __last, __n);
    if (__pos.__m_cur == __m_start.__m_cur)
    {
        iterator __new_start = __m_reserve_elements_at_front(__n);
        __DST_TRY
        {
            uninitialized_copy(__first, __last, __new_start);
            __m_start = __new_start;
        }
        __DST_UNWIND(__m_destroy_nodes(__new_start.__map_node, __m_start.__map_node));
    }
    else if (__pos.__m_cur == __m_finish.__m_cur)
    {
        iterator __new_finish = __m_reserve_elements_at_back(__n);
        __DST_TRY
        {
            uninitialized_copy(__first, __last, __m_finish);
            __m_finish = __new_finish;
        }
        __DST_UNWIND(__m_destroy_nodes(__m_finish.__map_node + 1, __new_finish.__map_node + 1));
    }
    else
        __m_insert_aux(__pos, __first, __last, __n);
}

#endif /* __DST_MEMBER_TEMPLATES */

template <class _Tp, class _Alloc>
typename deque<_Tp, _Alloc>::iterator
deque<_Tp, _Alloc>::__m_insert_aux(iterator __pos, const value_type &__x)
{
    difference_type __index = __pos - __m_start;
    value_type __x_copy = __x;
    if (size_type(__index) < this->size() / 2)
    {
        push_front(front());
        iterator __front1 = __m_start;
        ++__front1;
        iterator __front2 = __front1;
        ++__front2;
        __pos = __m_start + __index;
        iterator __pos1 = __pos;
        ++__pos1;
        copy(__front2, __pos1, __front1);
    }
    else
    {
        push_back(back());
        iterator __back1 = __m_finish;
        --__back1;
        iterator __back2 = __back1;
        --__back2;
        __pos = __m_start + __index;
        copy_backward(__pos, __back2, __back1);
    }
    *__pos = __x_copy;
    return __pos;
}

template <class _Tp, class _Alloc>
typename deque<_Tp, _Alloc>::iterator
deque<_Tp, _Alloc>::__m_insert_aux(iterator __pos)
{
    difference_type __index = __pos - __m_start;
    if (__index < size() / 2)
    {
        push_front(front());
        iterator __front1 = __m_start;
        ++__front1;
        iterator __front2 = __front1;
        ++__front2;
        __pos = __m_start + __index;
        iterator __pos1 = __pos;
        ++__pos1;
        copy(__front2, __pos1, __front1);
    }
    else
    {
        push_back(back());
        iterator __back1 = __m_finish;
        --__back1;
        iterator __back2 = __back1;
        --__back2;
        __pos = __m_start + __index;
        copy_backward(__pos, __back2, __back1);
    }
    *__pos = value_type();
    return __pos;
}

template <class _Tp, class _Alloc>
void deque<_Tp, _Alloc>::__m_insert_aux(iterator __pos,
                                        size_type __n,
                                        const value_type &__x)
{
    const difference_type __elems_before = __pos - __m_start;
    size_type __length = this->size();
    value_type __x_copy = __x;
    if (__elems_before < difference_type(__length / 2))
    {
        iterator __new_start = __m_reserve_elements_at_front(__n);
        iterator __old_start = __m_start;
        __pos = __m_start + __elems_before;
        __DST_TRY
        {
            if (__elems_before >= difference_type(__n))
            {
                iterator __start_n = __m_start + difference_type(__n);
                uninitialized_copy(__m_start, __start_n, __new_start);
                __m_start = __new_start;
                copy(__start_n, __pos, __old_start);
                fill(__pos - difference_type(__n), __pos, __x_copy);
            }
            else
            {
                __uninitialized_copy_fill(__m_start, __pos, __new_start, __m_start, __x_copy);
                __m_start = __new_start;
                fill(__old_start, __pos, __x_copy);
            }
        }
        __DST_UNWIND(__m_destroy_nodes(__new_start.__map_node, __m_start.__map_node));
    }
    else
    {
        iterator __new_finish = __m_reserve_elements_at_back(__n);
        iterator __old_finish = __m_finish;
        const difference_type __elems_after =
            difference_type(__length) - __elems_before;
        __pos = __m_finish - __elems_after;
        __DST_TRY
        {
            if (__elems_after > difference_type(__n))
            {
                iterator __finish_n = __m_finish - difference_type(__n);
                uninitialized_copy(__finish_n, __m_finish, __m_finish);
                __m_finish = __new_finish;
                copy_backward(__pos, __finish_n, __old_finish);
                fill(__pos, __pos + difference_type(__n), __x_copy);
            }
            else
            {
                __uninitialized_fill_copy(__m_finish, __pos + difference_type(__n), __x_copy, __pos, __m_finish);
                __m_finish = __new_finish;
                fill(__pos, __old_finish, __x_copy);
            }
        }
        __DST_UNWIND(__m_destroy_nodes(__m_finish.__map_node + 1, __new_finish.__map_node + 1));
    }
}

#ifdef __DST_MEMBER_TEMPLATES

template <class _Tp, class _Alloc>
template <class _ForwardIterator>
void deque<_Tp, _Alloc>::__m_insert_aux(iterator __pos, _ForwardIterator __first, _ForwardIterator __last, size_type __n)
{
    const difference_type __elemsbefore = __pos - __m_start;
    size_type __length = size();
    if (__elemsbefore < __length / 2)
    {
        iterator __new_start = __m_reserve_elements_at_front(__n);
        iterator __old_start = __m_start;
        __pos = __m_start + __elemsbefore;
        __DST_TRY
        {
            if (__elemsbefore >= difference_type(__n))
            {
                iterator __start_n = __m_start + difference_type(__n);
                uninitialized_copy(__m_start, __start_n, __new_start);
                __m_start = __new_start;
                copy(__start_n, __pos, __old_start);
                copy(__first, __last, __pos - difference_type(__n));
            }
            else
            {
                _ForwardIterator __mid = __first;
                advance(__mid, difference_type(__n) - __elemsbefore);
                __uninitialized_copy_copy(__m_start, __pos, __first, __mid, __new_start);
                __m_start = __new_start;
                copy(__mid, __last, __old_start);
            }
        }
        __DST_UNWIND(__m_destroy_nodes(__new_start.__map_node, __m_start.__map_node));
    }
    else
    {
        iterator __new_finish = __m_reserve_elements_at_back(__n);
        iterator __old_finish = __m_finish;
        const difference_type __elemsafter = difference_type(__length) - __elemsbefore;
        __pos = __m_finish - __elemsafter;
        __DST_TRY
        {
            if (__elemsafter > difference_type(__n))
            {
                iterator __finish_n = __m_finish - difference_type(__n);
                uninitialized_copy(__finish_n, __m_finish, __m_finish);
                __m_finish = __new_finish;
                copy_backward(__pos, __finish_n, __old_finish);
                copy(__first, __last, __pos);
            }
            else
            {
                _ForwardIterator __mid = __first;
                advance(__mid, __elemsafter);
                __uninitialized_copy_copy(__mid, __last, __pos, __m_finish, __m_finish);
                __m_finish = __new_finish;
                copy(__first, __mid, __pos);
            }
        }
        __DST_UNWIND(__m_destroy_nodes(__m_finish.__map_node + 1, __new_finish.__map_node + 1));
    }
}

#else /* __DST_MEMBER_TEMPLATES */

template <class _Tp, class _Alloc>
void deque<_Tp, _Alloc>::__m_insert_aux(iterator __pos, const value_type *__first, const value_type *__last, size_type __n)
{
    const difference_type __elemsbefore = __pos - __m_start;
    size_type __length = size();
    if (__elemsbefore < __length / 2)
    {
        iterator __new_start = __m_reserve_elements_at_front(__n);
        iterator __old_start = __m_start;
        __pos = __m_start + __elemsbefore;
        __DST_TRY
        {
            if (__elemsbefore >= difference_type(__n))
            {
                iterator __start_n = __m_start + difference_type(__n);
                uninitialized_copy(__m_start, __start_n, __new_start);
                __m_start = __new_start;
                copy(__start_n, __pos, __old_start);
                copy(__first, __last, __pos - difference_type(__n));
            }
            else
            {
                const value_type *__mid =
                    __first + (difference_type(__n) - __elemsbefore);
                __uninitialized_copy_copy(__m_start, __pos, __first, __mid, __new_start);
                __m_start = __new_start;
                copy(__mid, __last, __old_start);
            }
        }
        __DST_UNWIND(__m_destroy_nodes(__new_start.__map_node, __m_start.__map_node));
    }
    else
    {
        iterator __new_finish = __m_reserve_elements_at_back(__n);
        iterator __old_finish = __m_finish;
        const difference_type __elemsafter = difference_type(__length) - __elemsbefore;
        __pos = __m_finish - __elemsafter;
        __DST_TRY
        {
            if (__elemsafter > difference_type(__n))
            {
                iterator __finish_n = __m_finish - difference_type(__n);
                uninitialized_copy(__finish_n, __m_finish, __m_finish);
                __m_finish = __new_finish;
                copy_backward(__pos, __finish_n, __old_finish);
                copy(__first, __last, __pos);
            }
            else
            {
                const value_type *__mid = __first + __elemsafter;
                __uninitialized_copy_copy(__mid, __last, __pos, __m_finish, __m_finish);
                __m_finish = __new_finish;
                copy(__first, __mid, __pos);
            }
        }
        __DST_UNWIND(__m_destroy_nodes(__m_finish.__map_node + 1, __new_finish.__map_node + 1));
    }
}

template <class _Tp, class _Alloc>
void deque<_Tp, _Alloc>::__m_insert_aux(iterator __pos, const_iterator __first, const_iterator __last, size_type __n)
{
    const difference_type __elemsbefore = __pos - __m_start;
    size_type __length = size();
    if (__elemsbefore < __length / 2)
    {
        iterator __new_start = __m_reserve_elements_at_front(__n);
        iterator __old_start = __m_start;
        __pos = __m_start + __elemsbefore;
        __DST_TRY
        {
            if (__elemsbefore >= __n)
            {
                iterator __start_n = __m_start + __n;
                uninitialized_copy(__m_start, __start_n, __new_start);
                __m_start = __new_start;
                copy(__start_n, __pos, __old_start);
                copy(__first, __last, __pos - difference_type(__n));
            }
            else
            {
                const_iterator __mid = __first + (__n - __elemsbefore);
                __uninitialized_copy_copy(__m_start, __pos, __first, __mid,
                                          __new_start);
                __m_start = __new_start;
                copy(__mid, __last, __old_start);
            }
        }
        __DST_UNWIND(__m_destroy_nodes(__new_start.__map_node, __m_start.__map_node));
    }
    else
    {
        iterator __new_finish = __m_reserve_elements_at_back(__n);
        iterator __old_finish = __m_finish;
        const difference_type __elemsafter = __length - __elemsbefore;
        __pos = __m_finish - __elemsafter;
        __DST_TRY
        {
            if (__elemsafter > __n)
            {
                iterator __finish_n = __m_finish - difference_type(__n);
                uninitialized_copy(__finish_n, __m_finish, __m_finish);
                __m_finish = __new_finish;
                copy_backward(__pos, __finish_n, __old_finish);
                copy(__first, __last, __pos);
            }
            else
            {
                const_iterator __mid = __first + __elemsafter;
                __uninitialized_copy_copy(__mid, __last, __pos, __m_finish, __m_finish);
                __m_finish = __new_finish;
                copy(__first, __mid, __pos);
            }
        }
        __DST_UNWIND(__m_destroy_nodes(__m_finish.__map_node + 1, __new_finish.__map_node + 1));
    }
}

#endif /* __DST_MEMBER_TEMPLATES */

template <class _Tp, class _Alloc>
void deque<_Tp, _Alloc>::__m_new_elements_at_front(size_type __new_elems)
{
    size_type __new_nodes = (__new_elems + __s_buffer_size() - 1) / __s_buffer_size();
    __m_reserve_map_at_front(__new_nodes);
    size_type __i;
    __DST_TRY
    {
        for (__i = 1; __i <= __new_nodes; ++__i)
            *(__m_start.__map_node - __i) = __m_allocate_node();
    }
#ifdef __DST_USE_EXCEPTIONS
    catch (...)
    {
        for (size_type __j = 1; __j < __i; ++__j)
            __m_deallocate_node(*(__m_start.__map_node - __j));
        throw;
    }
#endif /* __DST_USE_EXCEPTIONS */
}

template <class _Tp, class _Alloc>
void deque<_Tp, _Alloc>::__m_new_elements_at_back(size_type __new_elems)
{
    size_type __new_nodes = (__new_elems + __s_buffer_size() - 1) / __s_buffer_size();
    __m_reserve_map_at_back(__new_nodes);
    size_type __i;
    __DST_TRY
    {
        for (__i = 1; __i <= __new_nodes; ++__i)
            *(__m_finish.__map_node + __i) = __m_allocate_node();
    }
#ifdef __DST_USE_EXCEPTIONS
    catch (...)
    {
        for (size_type __j = 1; __j < __i; ++__j)
            __m_deallocate_node(*(__m_finish.__map_node + __j));
        throw;
    }
#endif /* __DST_USE_EXCEPTIONS */
}

template <class _Tp, class _Alloc>
void deque<_Tp, _Alloc>::__m_reallocate_map(size_type __nodes_to_add, bool __add_at_front)
{
    size_type __old_num_nodes = __m_finish.__map_node - __m_start.__map_node + 1;
    size_type __new_num_nodes = __old_num_nodes + __nodes_to_add;

    __map_pointer __new_nstart;
    if (__m_map_size > 2 * __new_num_nodes)
    {
        __new_nstart = __m_map + (__m_map_size - __new_num_nodes) / 2 + (__add_at_front ? __nodes_to_add : 0);
        if (__new_nstart < __m_start.__map_node)
            copy(__m_start.__map_node, __m_finish.__map_node + 1, __new_nstart);
        else
            copy_backward(__m_start.__map_node, __m_finish.__map_node + 1, __new_nstart + __old_num_nodes);
    }
    else
    {
        size_type __new_map_size =
            __m_map_size + max(__m_map_size, __nodes_to_add) + 2;

        __map_pointer __new_map = __m_allocate_map(__new_map_size);
        __new_nstart = __new_map + (__new_map_size - __new_num_nodes) / 2 + (__add_at_front ? __nodes_to_add : 0);
        copy(__m_start.__map_node, __m_finish.__map_node + 1, __new_nstart);
        __m_deallocate_map(__m_map, __m_map_size);

        __m_map = __new_map;
        __m_map_size = __new_map_size;
    }

    __m_start.__m_set_node(__new_nstart);
    __m_finish.__m_set_node(__new_nstart + __old_num_nodes - 1);
}

// Nonmember functions.

template <class _Tp, class _Alloc>
inline bool operator==(const deque<_Tp, _Alloc> &__x, const deque<_Tp, _Alloc> &__y)
{
    return __x.size() == __y.size() && equal(__x.begin(), __x.end(), __y.begin());
}

template <class _Tp, class _Alloc>
inline bool operator<(const deque<_Tp, _Alloc> &__x, const deque<_Tp, _Alloc> &__y)
{
    return lexicographical_compare(__x.begin(), __x.end(), __y.begin(), __y.end());
}

#ifdef __DST_FUNCTION_TMPL_PARTIAL_ORDER

template <class _Tp, class _Alloc>
inline bool operator!=(const deque<_Tp, _Alloc> &__x, const deque<_Tp, _Alloc> &__y)
{
    return !(__x == __y);
}

template <class _Tp, class _Alloc>
inline bool operator>(const deque<_Tp, _Alloc> &__x, const deque<_Tp, _Alloc> &__y)
{
    return __y < __x;
}

template <class _Tp, class _Alloc>
inline bool operator<=(const deque<_Tp, _Alloc> &__x, const deque<_Tp, _Alloc> &__y)
{
    return !(__y < __x);
}
template <class _Tp, class _Alloc>
inline bool operator>=(const deque<_Tp, _Alloc> &__x, const deque<_Tp, _Alloc> &__y)
{
    return !(__x < __y);
}

template <class _Tp, class _Alloc>
inline void swap(deque<_Tp, _Alloc> &__x, deque<_Tp, _Alloc> &__y)
{
    __x.swap(__y);
}

#endif /* __DST_FUNCTION_TMPL_PARTIAL_ORDER */

#if defined(__sgi) && !defined(__GNUC__) && (_MIPS_SIM != _MIPS_SIM_ABI32)
#pragma reset woff 1174
#pragma reset woff 1375
#endif

__DST_END_NAMESPACE

#endif /* ___DST_INTERNAL_DEQUE_H */