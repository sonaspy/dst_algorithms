

#ifndef ___DST_INTERNAL_VECTOR_H
#define ___DST_INTERNAL_VECTOR_H

#include "concept_checks.h"

__DST_BEGIN_NAMESPACE

#if defined(__sgi) && !defined(__GNUC__) && (_MIPS_SIM != _MIPS_SIM_ABI32)
#pragma set woff 1174
#pragma set woff 1375
#endif

// The vector base class serves two purposes.  First, its constructor
// and destructor allocate (but don't initialize) storage.  This makes
// exception safety easier.  Second, the base class encapsulates all of
// the differences between stl-style allocators and standard-conforming
// allocators.

#ifdef __DST_USE_DSA_ALLOCATORS

// Base class for ordinary allocators.
template <class _Tp, class _Allocator, bool _IsStatic>
class __vector_alloc_base
{
public:
    typedef typename __alloc_traits<_Tp, _Allocator>::allocator_type allocator_type;
    allocator_type get_allocator() const { return _M_data_allocator; }

    __vector_alloc_base(const allocator_type &__a) : _M_data_allocator(__a), _M_start(0), _M_finish(0), _M_end_of_storage(0)
    {
    }

    allocator_type _M_data_allocator;
    _Tp *_M_start;
    _Tp *_M_finish;
    _Tp *_M_end_of_storage;

    _Tp *_M_allocate(size_t __n)
    {
        return _M_data_allocator.allocate(__n);
    }
    void _M_deallocate(_Tp *__p, size_t __n)
    {
        if (__p)
            _M_data_allocator.deallocate(__p, __n);
    }
};

// Specialization for allocators that have the property that we don't
// actually have to store an allocator object.
template <class _Tp, class _Allocator>
class __vector_alloc_base<_Tp, _Allocator, true>
{
public:
    typedef typename __alloc_traits<_Tp, _Allocator>::allocator_type allocator_type;
    allocator_type get_allocator() const { return allocator_type(); }

    __vector_alloc_base(const allocator_type &) : _M_start(0), _M_finish(0), _M_end_of_storage(0)
    {
    }

    _Tp *_M_start;
    _Tp *_M_finish;
    _Tp *_M_end_of_storage;

    typedef typename __alloc_traits<_Tp, _Allocator>::_Alloc_type _Alloc_type;
    _Tp *_M_allocate(size_t __n)
    {
        return _Alloc_type::allocate(__n);
    }
    void _M_deallocate(_Tp *__p, size_t __n)
    {
        _Alloc_type::deallocate(__p, __n);
    }
};

template <class _Tp, class _Alloc>
struct __vector_base : public __vector_alloc_base<_Tp, _Alloc, __alloc_traits<_Tp, _Alloc>::_S_instanceless>
{
    typedef __vector_alloc_base<_Tp, _Alloc, __alloc_traits<_Tp, _Alloc>::_S_instanceless> __base;
    typedef typename __base::allocator_type allocator_type;

    __vector_base(const allocator_type &__a) : __base(__a) {}
    __vector_base(size_t __n, const allocator_type &__a) : __base(__a)
    {
        _M_start = _M_allocate(__n);
        _M_finish = _M_start;
        _M_end_of_storage = _M_start + __n;
    }

    ~__vector_base() { _M_deallocate(_M_start, _M_end_of_storage - _M_start); }
};

#else /* __DST_USE_DSA_ALLOCATORS */

template <class _Tp, class _Alloc>
class __vector_base
{
public:
    typedef _Alloc allocator_type;
    allocator_type get_allocator() const { return allocator_type(); }

    __vector_base(const _Alloc &)
        : _M_start(0), _M_finish(0), _M_end_of_storage(0) {}
    __vector_base(size_t __n, const _Alloc &)
        : _M_start(0), _M_finish(0), _M_end_of_storage(0)
    {
        _M_start = _M_allocate(__n);
        _M_finish = _M_start;
        _M_end_of_storage = _M_start + __n;
    }

    ~__vector_base() { _M_deallocate(_M_start, _M_end_of_storage - _M_start); }

    _Tp *_M_start;
    _Tp *_M_finish;
    _Tp *_M_end_of_storage;

    typedef simple_alloc<_Tp, _Alloc> _M_data_allocator;
    _Tp *_M_allocate(size_t __n)
    {
        return _M_data_allocator::allocate(__n);
    }
    void _M_deallocate(_Tp *__p, size_t __n)
    {
        _M_data_allocator::deallocate(__p, __n);
    }
};

#endif /* __DST_USE_DSA_ALLOCATORS */

template <class _Tp, class _Alloc = __DST_DEFAULT_ALLOCATOR(_Tp)>
class vector : public __vector_base<_Tp, _Alloc>
{
    // requirements:

    __DST_CLASS_REQUIRES(_Tp, _Assignable);

private:
    typedef __vector_base<_Tp, _Alloc> __base;

public:
    typedef _Tp value_type;
    typedef value_type *pointer;
    typedef const value_type *const_pointer;
    typedef value_type *iterator;
    typedef const value_type *const_iterator;
    typedef value_type &reference;
    typedef const value_type &const_reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;

    typedef typename __base::allocator_type allocator_type;
    allocator_type get_allocator() const { return __base::get_allocator(); }

#ifdef __DST_CLASS_PARTIAL_SPECIALIZATION
    typedef reverse_iterator<const_iterator> const_reverse_iterator;
    typedef reverse_iterator<iterator> reverse_iterator;
#else  /* __DST_CLASS_PARTIAL_SPECIALIZATION */
    typedef reverse_iterator<const_iterator, value_type, const_reference, difference_type> const_reverse_iterator;
    typedef reverse_iterator<iterator, value_type, reference, difference_type> reverse_iterator;
#endif /* __DST_CLASS_PARTIAL_SPECIALIZATION */

protected:
    using __base::_M_allocate;
    using __base::_M_deallocate;
    using __base::_M_end_of_storage;
    using __base::_M_finish;
    using __base::_M_start;

protected:
    void _M_insert_aux(iterator __position, const _Tp &__x);
    void _M_insert_aux(iterator __position);

public:
    inline iterator begin() { return _M_start; }
    inline const_iterator begin() const { return _M_start; }
    inline iterator end() { return _M_finish; }
    inline const_iterator end() const { return _M_finish; }

    inline reverse_iterator rbegin()
    {
        return reverse_iterator(end());
    }
    inline const_reverse_iterator rbegin() const
    {
        return const_reverse_iterator(end());
    }
    inline reverse_iterator rend()
    {
        return reverse_iterator(begin());
    }
    inline const_reverse_iterator rend() const
    {
        return const_reverse_iterator(begin());
    }

    inline size_type size() const
    {
        return size_type(end() - begin());
    }
    inline size_type max_size() const
    {
        return size_type(-1) / sizeof(_Tp);
    }
    inline size_type capacity() const
    {
        return size_type(_M_end_of_storage - begin());
    }
    inline bool empty() const
    {
        return begin() == end();
    }

    inline reference operator[](size_type __n) { return *(begin() + __n); }
    inline const_reference operator[](size_type __n) const { return *(begin() + __n); }

#ifdef __DST_THROW_RANGE_ERRORS
    void _M_range_check(size_type __n) const
    {
        if (__n >= this->size())
            __dst_throw_range_error("vector");
    }

    reference at(size_type __n)
    {
        _M_range_check(__n);
        return (*this)[__n];
    }
    const_reference at(size_type __n) const
    {
        _M_range_check(__n);
        return (*this)[__n];
    }
#endif /* __DST_THROW_RANGE_ERRORS */

    explicit vector(const allocator_type &__a = allocator_type()) : __base(__a)
    {
    }

    vector(size_type __n, const _Tp &__value, const allocator_type &__a = allocator_type()) : __base(__n, __a)
    {
        _M_finish = uninitialized_fill_n(_M_start, __n, __value);
    }

    explicit vector(size_type __n) : __base(__n, allocator_type())
    {
        _M_finish = uninitialized_fill_n(_M_start, __n, _Tp());
    }

    vector(const vector<_Tp, _Alloc> &__x) : __base(__x.size(), __x.get_allocator())
    {
        _M_finish = uninitialized_copy(__x.begin(), __x.end(), _M_start);
    }

#ifdef __DST_MEMBER_TEMPLATES
    // Check whether it's an integral type.  If so, it's not an iterator.
    template <class _InputIterator>
    vector(_InputIterator __first, _InputIterator __last, const allocator_type &__a = allocator_type()) : __base(__a)
    {
        typedef typename _Is_integer<_InputIterator>::_Integral _Integral;
        _M_initialize_aux(__first, __last, _Integral());
    }

    template <class _Integer>
    void _M_initialize_aux(_Integer __n, _Integer __value, __true_type)
    {
        _M_start = _M_allocate(__n);
        _M_end_of_storage = _M_start + __n;
        _M_finish = uninitialized_fill_n(_M_start, __n, __value);
    }

    template <class _InputIterator>
    void _M_initialize_aux(_InputIterator __first, _InputIterator __last, __false_type)
    {
        _M_range_initialize(__first, __last, __ITERATOR_CATEGORY(__first));
    }

#else
    vector(const _Tp *__first, const _Tp *__last, const allocator_type &__a = allocator_type()) : __base(__last - __first, __a)
    {
        _M_finish = uninitialized_copy(__first, __last, _M_start);
    }
#endif /* __DST_MEMBER_TEMPLATES */

    ~vector()
    {
        destroy(_M_start, _M_finish);
    }

    vector<_Tp, _Alloc> &operator=(const vector<_Tp, _Alloc> &__x);

    void reserve(size_type __n)
    {
        if (capacity() < __n)
        {
            const size_type __old_size = size();
            iterator __tmp = _M_allocate_and_copy(__n, _M_start, _M_finish);
            destroy(_M_start, _M_finish);
            _M_deallocate(_M_start, _M_end_of_storage - _M_start);
            _M_start = __tmp;
            _M_finish = __tmp + __old_size;
            _M_end_of_storage = _M_start + __n;
        }
    }

    // assign(), a generalized assignment member function.  Two
    // versions: one that takes a count, and one that takes a range.
    // The range version is a member template, so we dispatch on whether
    // or not the type is an integer.

    void assign(size_type __n, const _Tp &__val) { _M_fill_assign(__n, __val); }
    void _M_fill_assign(size_type __n, const _Tp &__val);

#ifdef __DST_MEMBER_TEMPLATES

    template <class _InputIterator>
    void assign(_InputIterator __first, _InputIterator __last)
    {
        typedef typename _Is_integer<_InputIterator>::_Integral _Integral;
        _M_assign_dispatch(__first, __last, _Integral());
    }

    template <class _Integer>
    void _M_assign_dispatch(_Integer __n, _Integer __val, __true_type)
    {
        _M_fill_assign((size_type)__n, (_Tp)__val);
    }

    template <class _InputIter>
    void _M_assign_dispatch(_InputIter __first, _InputIter __last, __false_type)
    {
        _M_assign_aux(__first, __last, __ITERATOR_CATEGORY(__first));
    }

    template <class _InputIterator>
    void _M_assign_aux(_InputIterator __first, _InputIterator __last,
                        input_iterator_tag);

    template <class _ForwardIterator>
    void _M_assign_aux(_ForwardIterator __first, _ForwardIterator __last,
                        forward_iterator_tag);

#endif /* __DST_MEMBER_TEMPLATES */

    reference front()
    {
        return *begin();
    }
    const_reference front() const { return *begin(); }
    reference back() { return *(end() - 1); }
    const_reference back() const { return *(end() - 1); }

    void push_back(const _Tp &__x)
    {
        if (_M_finish != _M_end_of_storage)
        {
            construct(_M_finish, __x);
            ++_M_finish;
        }
        else
            _M_insert_aux(end(), __x);
    }
    void push_back()
    {
        if (_M_finish != _M_end_of_storage)
        {
            construct(_M_finish);
            ++_M_finish;
        }
        else
            _M_insert_aux(end());
    }
    void swap(vector<_Tp, _Alloc> &__x)
    {
        __VDSA::swap(_M_start, __x._M_start);
        __VDSA::swap(_M_finish, __x._M_finish);
        __VDSA::swap(_M_end_of_storage, __x._M_end_of_storage);
    }

    iterator insert(iterator __position, const _Tp &__x)
    {
        size_type __n = __position - begin();
        if (_M_finish != _M_end_of_storage && __position == end())
        {
            construct(_M_finish, __x);
            ++_M_finish;
        }
        else
            _M_insert_aux(__position, __x);
        return begin() + __n;
    }
    iterator insert(iterator __position)
    {
        size_type __n = __position - begin();
        if (_M_finish != _M_end_of_storage && __position == end())
        {
            construct(_M_finish);
            ++_M_finish;
        }
        else
            _M_insert_aux(__position);
        return begin() + __n;
    }
#ifdef __DST_MEMBER_TEMPLATES
    // Check whether it's an integral type.  If so, it's not an iterator.
    template <class _InputIterator>
    void insert(iterator __pos, _InputIterator __first, _InputIterator __last)
    {
        typedef typename _Is_integer<_InputIterator>::_Integral _Integral;
        _M_insert_dispatch(__pos, __first, __last, _Integral());
    }

    template <class _Integer>
    void _M_insert_dispatch(iterator __pos, _Integer __n, _Integer __val,
                             __true_type)
    {
        _M_fill_insert(__pos, (size_type)__n, (_Tp)__val);
    }

    template <class _InputIterator>
    void _M_insert_dispatch(iterator __pos,
                             _InputIterator __first, _InputIterator __last,
                             __false_type)
    {
        _M_range_insert(__pos, __first, __last, __ITERATOR_CATEGORY(__first));
    }
#else  /* __DST_MEMBER_TEMPLATES */
    void insert(iterator __position,
                const_iterator __first, const_iterator __last);
#endif /* __DST_MEMBER_TEMPLATES */

    void insert(iterator __pos, size_type __n, const _Tp &__x)
    {
        _M_fill_insert(__pos, __n, __x);
    }

    void _M_fill_insert(iterator __pos, size_type __n, const _Tp &__x);

    void pop_back()
    {
        --_M_finish;
        destroy(_M_finish);
    }
    iterator erase(iterator __position)
    {
        if (__position + 1 != end())
            copy(__position + 1, _M_finish, __position);
        --_M_finish;
        destroy(_M_finish);
        return __position;
    }
    iterator erase(iterator __first, iterator __last)
    {
        iterator __i = copy(__last, _M_finish, __first);
        destroy(__i, _M_finish);
        _M_finish = _M_finish - (__last - __first);
        return __first;
    }

    void resize(size_type __new_size, const _Tp &__x)
    {
        if (__new_size < size())
            erase(begin() + __new_size, end());
        else
            insert(end(), __new_size - size(), __x);
    }
    void resize(size_type __new_size) { resize(__new_size, _Tp()); }
    void clear() { erase(begin(), end()); }

protected:
#ifdef __DST_MEMBER_TEMPLATES
    template <class _ForwardIterator>
    iterator _M_allocate_and_copy(size_type __n, _ForwardIterator __first,
                                   _ForwardIterator __last)
    {
        iterator __result = _M_allocate(__n);
        __DST_TRY
        {
            uninitialized_copy(__first, __last, __result);
            return __result;
        }
        __DST_UNWIND(_M_deallocate(__result, __n));
    }
#else  /* __DST_MEMBER_TEMPLATES */
    iterator _M_allocate_and_copy(size_type __n, const_iterator __first,
                                   const_iterator __last)
    {
        iterator __result = _M_allocate(__n);
        __DST_TRY
        {
            uninitialized_copy(__first, __last, __result);
            return __result;
        }
        __DST_UNWIND(_M_deallocate(__result, __n));
    }
#endif /* __DST_MEMBER_TEMPLATES */

#ifdef __DST_MEMBER_TEMPLATES
    template <class _InputIterator>
    void _M_range_initialize(_InputIterator __first,
                              _InputIterator __last, input_iterator_tag)
    {
        for (; __first != __last; ++__first)
            push_back(*__first);
    }

    // This function is only called by the constructor.
    template <class _ForwardIterator>
    void _M_range_initialize(_ForwardIterator __first,
                              _ForwardIterator __last, forward_iterator_tag)
    {
        size_type __n = 0;
        distance(__first, __last, __n);
        _M_start = _M_allocate(__n);
        _M_end_of_storage = _M_start + __n;
        _M_finish = uninitialized_copy(__first, __last, _M_start);
    }

    template <class _InputIterator>
    void _M_range_insert(iterator __pos,
                          _InputIterator __first, _InputIterator __last,
                          input_iterator_tag);

    template <class _ForwardIterator>
    void _M_range_insert(iterator __pos,
                          _ForwardIterator __first, _ForwardIterator __last,
                          forward_iterator_tag);

#endif /* __DST_MEMBER_TEMPLATES */
};

template <class _Tp, class _Alloc>
inline bool
operator==(const vector<_Tp, _Alloc> &__x, const vector<_Tp, _Alloc> &__y)
{
    return __x.size() == __y.size() &&
           equal(__x.begin(), __x.end(), __y.begin());
}

template <class _Tp, class _Alloc>
inline bool
operator<(const vector<_Tp, _Alloc> &__x, const vector<_Tp, _Alloc> &__y)
{
    return lexicographical_compare(__x.begin(), __x.end(),
                                   __y.begin(), __y.end());
}

#ifdef __DST_FUNCTION_TMPL_PARTIAL_ORDER

template <class _Tp, class _Alloc>
inline void swap(vector<_Tp, _Alloc> &__x, vector<_Tp, _Alloc> &__y)
{
    __x.swap(__y);
}

template <class _Tp, class _Alloc>
inline bool
operator!=(const vector<_Tp, _Alloc> &__x, const vector<_Tp, _Alloc> &__y)
{
    return !(__x == __y);
}

template <class _Tp, class _Alloc>
inline bool
operator>(const vector<_Tp, _Alloc> &__x, const vector<_Tp, _Alloc> &__y)
{
    return __y < __x;
}

template <class _Tp, class _Alloc>
inline bool
operator<=(const vector<_Tp, _Alloc> &__x, const vector<_Tp, _Alloc> &__y)
{
    return !(__y < __x);
}

template <class _Tp, class _Alloc>
inline bool
operator>=(const vector<_Tp, _Alloc> &__x, const vector<_Tp, _Alloc> &__y)
{
    return !(__x < __y);
}

#endif /* __DST_FUNCTION_TMPL_PARTIAL_ORDER */

template <class _Tp, class _Alloc>
vector<_Tp, _Alloc> &
vector<_Tp, _Alloc>::operator=(const vector<_Tp, _Alloc> &__x)
{
    if (&__x != this)
    {
        const size_type __xlen = __x.size();
        if (__xlen > capacity())
        {
            iterator __tmp = _M_allocate_and_copy(__xlen, __x.begin(), __x.end());
            destroy(_M_start, _M_finish);
            _M_deallocate(_M_start, _M_end_of_storage - _M_start);
            _M_start = __tmp;
            _M_end_of_storage = _M_start + __xlen;
        }
        else if (size() >= __xlen)
        {
            iterator __i = copy(__x.begin(), __x.end(), begin());
            destroy(__i, _M_finish);
        }
        else
        {
            copy(__x.begin(), __x.begin() + size(), _M_start);
            uninitialized_copy(__x.begin() + size(), __x.end(), _M_finish);
        }
        _M_finish = _M_start + __xlen;
    }
    return *this;
}

template <class _Tp, class _Alloc>
void vector<_Tp, _Alloc>::_M_fill_assign(size_t __n, const value_type &__val)
{
    if (__n > capacity())
    {
        vector<_Tp, _Alloc> __tmp(__n, __val, get_allocator());
        __tmp.swap(*this);
    }
    else if (__n > size())
    {
        fill(begin(), end(), __val);
        _M_finish = uninitialized_fill_n(_M_finish, __n - size(), __val);
    }
    else
        erase(fill_n(begin(), __n, __val), end());
}

#ifdef __DST_MEMBER_TEMPLATES

template <class _Tp, class _Alloc>
template <class _InputIter>
void vector<_Tp, _Alloc>::_M_assign_aux(_InputIter __first, _InputIter __last,
                                         input_iterator_tag)
{
    iterator __cur = begin();
    for (; __first != __last && __cur != end(); ++__cur, ++__first)
        *__cur = *__first;
    if (__first == __last)
        erase(__cur, end());
    else
        insert(end(), __first, __last);
}

template <class _Tp, class _Alloc>
template <class _ForwardIter>
void vector<_Tp, _Alloc>::_M_assign_aux(_ForwardIter __first, _ForwardIter __last,
                                         forward_iterator_tag)
{
    size_type __len = 0;
    distance(__first, __last, __len);

    if (__len > capacity())
    {
        iterator __tmp = _M_allocate_and_copy(__len, __first, __last);
        destroy(_M_start, _M_finish);
        _M_deallocate(_M_start, _M_end_of_storage - _M_start);
        _M_start = __tmp;
        _M_end_of_storage = _M_finish = _M_start + __len;
    }
    else if (size() >= __len)
    {
        iterator __new_finish = copy(__first, __last, _M_start);
        destroy(__new_finish, _M_finish);
        _M_finish = __new_finish;
    }
    else
    {
        _ForwardIter __mid = __first;
        advance(__mid, size());
        copy(__first, __mid, _M_start);
        _M_finish = uninitialized_copy(__mid, __last, _M_finish);
    }
}

#endif /* __DST_MEMBER_TEMPLATES */

template <class _Tp, class _Alloc>
void vector<_Tp, _Alloc>::_M_insert_aux(iterator __position, const _Tp &__x)
{
    if (_M_finish != _M_end_of_storage)  // storage still suffice the demand
    {
        construct(_M_finish, *(_M_finish - 1));
        ++_M_finish;
        _Tp __x_copy = __x;
        copy_backward(__position, _M_finish - 2, _M_finish - 1);
        *__position = __x_copy;
    }
    else
    {
        const size_type __old_size = size();
        const size_type __len = __old_size != 0 ? 2 * __old_size : 1;
        iterator __new_start = _M_allocate(__len);
        iterator __new_finish = __new_start;
        __DST_TRY
        {
            __new_finish = uninitialized_copy(_M_start, __position, __new_start);
            construct(__new_finish, __x);
            ++__new_finish;
            __new_finish = uninitialized_copy(__position, _M_finish, __new_finish);
        }
        __DST_UNWIND((destroy(__new_start, __new_finish), _M_deallocate(__new_start, __len)));
        destroy(begin(), end());
        _M_deallocate(_M_start, _M_end_of_storage - _M_start);
        // adjust the iterators, previous ones are deprecated
        _M_start = __new_start;
        _M_finish = __new_finish;
        _M_end_of_storage = __new_start + __len;
    }
}

template <class _Tp, class _Alloc>
void vector<_Tp, _Alloc>::_M_insert_aux(iterator __position)
{
    if (_M_finish != _M_end_of_storage)
    {
        construct(_M_finish, *(_M_finish - 1));
        ++_M_finish;
        copy_backward(__position, _M_finish - 2, _M_finish - 1);
        *__position = _Tp();
    }
    else
    {
        const size_type __old_size = size();
        const size_type __len = __old_size != 0 ? 2 * __old_size : 1;
        iterator __new_start = _M_allocate(__len);
        iterator __new_finish = __new_start;
        __DST_TRY
        {
            __new_finish = uninitialized_copy(_M_start, __position, __new_start);
            construct(__new_finish);
            ++__new_finish;
            __new_finish = uninitialized_copy(__position, _M_finish, __new_finish);
        }
        __DST_UNWIND((destroy(__new_start, __new_finish),
                      _M_deallocate(__new_start, __len)));
        destroy(begin(), end());
        _M_deallocate(_M_start, _M_end_of_storage - _M_start);
        _M_start = __new_start;
        _M_finish = __new_finish;
        _M_end_of_storage = __new_start + __len;
    }
}

template <class _Tp, class _Alloc>
void vector<_Tp, _Alloc>::_M_fill_insert(iterator __position, size_type __n, const _Tp &__x)
{
    if (__n != 0)
    {
        if (size_type(_M_end_of_storage - _M_finish) >= __n)
        {
            _Tp __x_copy = __x;
            const size_type __elems_after = _M_finish - __position;
            iterator __old_finish = _M_finish;
            if (__elems_after > __n)
            {
                uninitialized_copy(_M_finish - __n, _M_finish, _M_finish);
                _M_finish += __n;
                copy_backward(__position, __old_finish - __n, __old_finish);
                fill(__position, __position + __n, __x_copy);
            }
            else
            {
                uninitialized_fill_n(_M_finish, __n - __elems_after, __x_copy);
                _M_finish += __n - __elems_after;
                uninitialized_copy(__position, __old_finish, _M_finish);
                _M_finish += __elems_after;
                fill(__position, __old_finish, __x_copy);
            }
        }
        else
        {
            const size_type __old_size = size();
            const size_type __len = __old_size + max(__old_size, __n);
            iterator __new_start = _M_allocate(__len);
            iterator __new_finish = __new_start;
            __DST_TRY
            {
                __new_finish = uninitialized_copy(_M_start, __position, __new_start);
                __new_finish = uninitialized_fill_n(__new_finish, __n, __x);
                __new_finish = uninitialized_copy(__position, _M_finish, __new_finish);
            }
            __DST_UNWIND((destroy(__new_start, __new_finish),
                          _M_deallocate(__new_start, __len)));
            destroy(_M_start, _M_finish);
            _M_deallocate(_M_start, _M_end_of_storage - _M_start);
            _M_start = __new_start;
            _M_finish = __new_finish;
            _M_end_of_storage = __new_start + __len;
        }
    }
}

#ifdef __DST_MEMBER_TEMPLATES

template <class _Tp, class _Alloc>
template <class _InputIterator>
void vector<_Tp, _Alloc>::_M_range_insert(iterator __pos,
                                           _InputIterator __first,
                                           _InputIterator __last,
                                           input_iterator_tag)
{
    for (; __first != __last; ++__first)
    {
        __pos = insert(__pos, *__first);
        ++__pos;
    }
}

template <class _Tp, class _Alloc>
template <class _ForwardIterator>
void vector<_Tp, _Alloc>::_M_range_insert(iterator __position,
                                           _ForwardIterator __first,
                                           _ForwardIterator __last,
                                           forward_iterator_tag)
{
    if (__first != __last)
    {
        size_type __n = 0;
        distance(__first, __last, __n);
        if (size_type(_M_end_of_storage - _M_finish) >= __n)
        {
            const size_type __elems_after = _M_finish - __position;
            iterator __old_finish = _M_finish;
            if (__elems_after > __n)
            {
                uninitialized_copy(_M_finish - __n, _M_finish, _M_finish);
                _M_finish += __n;
                copy_backward(__position, __old_finish - __n, __old_finish);
                copy(__first, __last, __position);
            }
            else
            {
                _ForwardIterator __mid = __first;
                advance(__mid, __elems_after);
                uninitialized_copy(__mid, __last, _M_finish);
                _M_finish += __n - __elems_after;
                uninitialized_copy(__position, __old_finish, _M_finish);
                _M_finish += __elems_after;
                copy(__first, __mid, __position);
            }
        }
        else
        {
            const size_type __old_size = size();
            const size_type __len = __old_size + max(__old_size, __n);
            iterator __new_start = _M_allocate(__len);
            iterator __new_finish = __new_start;
            __DST_TRY
            {
                __new_finish = uninitialized_copy(_M_start, __position, __new_start);
                __new_finish = uninitialized_copy(__first, __last, __new_finish);
                __new_finish = uninitialized_copy(__position, _M_finish, __new_finish);
            }
            __DST_UNWIND((destroy(__new_start, __new_finish),
                          _M_deallocate(__new_start, __len)));
            destroy(_M_start, _M_finish);
            _M_deallocate(_M_start, _M_end_of_storage - _M_start);
            _M_start = __new_start;
            _M_finish = __new_finish;
            _M_end_of_storage = __new_start + __len;
        }
    }
}

#else /* __DST_MEMBER_TEMPLATES */

template <class _Tp, class _Alloc>
void vector<_Tp, _Alloc>::insert(iterator __position,  const_iterator __first,  const_iterator __last)
{
    if (__first != __last)
    {
        size_type __n = 0;
        distance(__first, __last, __n);
        if (size_type(_M_end_of_storage - _M_finish) >= __n)
        {
            const size_type __elems_after = _M_finish - __position;
            iterator __old_finish = _M_finish;
            if (__elems_after > __n)
            {
                uninitialized_copy(_M_finish - __n, _M_finish, _M_finish);
                _M_finish += __n;
                copy_backward(__position, __old_finish - __n, __old_finish);
                copy(__first, __last, __position);
            }
            else
            {
                uninitialized_copy(__first + __elems_after, __last, _M_finish);
                _M_finish += __n - __elems_after;
                uninitialized_copy(__position, __old_finish, _M_finish);
                _M_finish += __elems_after;
                copy(__first, __first + __elems_after, __position);
            }
        }
        else
        {
            const size_type __old_size = size();
            const size_type __len = __old_size + max(__old_size, __n);
            iterator __new_start = _M_allocate(__len);
            iterator __new_finish = __new_start;
            __DST_TRY
            {
                __new_finish = uninitialized_copy(_M_start, __position, __new_start);
                __new_finish = uninitialized_copy(__first, __last, __new_finish);
                __new_finish = uninitialized_copy(__position, _M_finish, __new_finish);
            }
            __DST_UNWIND((destroy(__new_start, __new_finish),
                          _M_deallocate(__new_start, __len)));
            destroy(_M_start, _M_finish);
            _M_deallocate(_M_start, _M_end_of_storage - _M_start);
            _M_start = __new_start;
            _M_finish = __new_finish;
            _M_end_of_storage = __new_start + __len;
        }
    }
}

#endif /* __DST_MEMBER_TEMPLATES */

#if defined(__sgi) && !defined(__GNUC__) && (_MIPS_SIM != _MIPS_SIM_ABI32)
#pragma reset woff 1174
#pragma reset woff 1375
#endif

__DST_END_NAMESPACE

#endif /* ___DST_INTERNAL_VECTOR_H */


