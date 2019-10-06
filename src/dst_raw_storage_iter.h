
/* NOTE: This is an internal header file, included by other DST headers.
 * You should not attempt to use it directly.
 */

#ifndef ___DST_INTERNAL_RAW_STORAGE_ITERATOR_H
#define ___DST_INTERNAL_RAW_STORAGE_ITERATOR_H

__DST_BEGIN_NAMESPACE

template <class _ForwardIterator, class _Tp>
class raw_storage_iterator
{
protected:
    _ForwardIterator _M_iter;

public:
    typedef output_iterator_tag iterator_category;
    typedef void value_type;
    typedef void difference_type;
    typedef void pointer;
    typedef void reference;

    explicit raw_storage_iterator(_ForwardIterator __x) : _M_iter(__x) {}
    raw_storage_iterator &operator*() { return *this; }
    raw_storage_iterator &operator=(const _Tp &__element)
    {
        construct(&*_M_iter, __element);
        return *this;
    }
    raw_storage_iterator<_ForwardIterator, _Tp> &operator++()
    {
        ++_M_iter;
        return *this;
    }
    raw_storage_iterator<_ForwardIterator, _Tp> operator++(int)
    {
        raw_storage_iterator<_ForwardIterator, _Tp> __tmp = *this;
        ++_M_iter;
        return __tmp;
    }
};

#ifndef __DST_CLASS_PARTIAL_SPECIALIZATION

template <class _ForwardIterator, class _Tp>
inline output_iterator_tag
iterator_category(const raw_storage_iterator<_ForwardIterator, _Tp> &)
{
    return output_iterator_tag();
}

#endif /* __DST_CLASS_PARTIAL_SPECIALIZATION */

__DST_END_NAMESPACE

#endif /* ___DST_INTERNAL_RAW_STORAGE_ITERATOR_H */