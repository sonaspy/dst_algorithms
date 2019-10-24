#ifndef ___DST_INTERNAL_TREE_H
#define ___DST_INTERNAL_TREE_H

/*

Red-black tree class, designed for use in implementing DST
associative containers (set, multiset, map, and multimap). The
insertion and deletion algorithms are based on those in Cormen,
Leiserson, and Rivest, Introduction to Algorithms (MIT Press, 1990),
except that

(1) the header cell is maintained with links not only to the root
but also to the leftmost node of the tree, to enable constant time
begin(), and to the rightmost node of the tree, to enable linear time
performance when used with the generic set algorithms (set_union,
etc.);

(2) when a node being deleted has two children its successor node is
relinked into its place, rather than copied, so that the only
iterators invalidated are those referring to the deleted node.

*/

#include "dst_algobase.h"
#include "dst_alloc.h"
#include "dst_construct.h"
#include "dst_function.h"

__DST_BEGIN_NAMESPACE

#if defined(__sgi) && !defined(__GNUC__) && (_MIPS_SIM != _MIPS_SIM_ABI32)
#pragma set woff 1375
#endif

typedef bool __rbtree_Color_type;
const __rbtree_Color_type __s_rb_tree_red = false;
const __rbtree_Color_type __s_rb_tree_black = true;

struct __rbtree_node_base
{
    typedef __rbtree_Color_type _Color_type;
    typedef __rbtree_node_base *__base_ptr;

    _Color_type __m_color;
    __base_ptr __m_parent;
    __base_ptr __m_left;
    __base_ptr __m_right;

    static __base_ptr __s_minimum(__base_ptr __x)
    {
        while (__x->__m_left != 0)
            __x = __x->__m_left;
        return __x;
    }

    static __base_ptr __s_maximum(__base_ptr __x)
    {
        while (__x->__m_right != 0)
            __x = __x->__m_right;
        return __x;
    }
};

template <class _Value>
struct __rbtree_node : public __rbtree_node_base
{
    typedef __rbtree_node<_Value> *__node_Ptr;
    _Value __m_value_field;
};

struct _rbtree_base_iterator
{
    typedef __rbtree_node_base::__base_ptr __base_ptr;
    typedef bidirectional_iterator_tag iterator_category;
    typedef ptrdiff_t difference_type;
    __base_ptr __m_node;

    void __m_increment()
    {
        if (__m_node->__m_right != 0)
        {
            __m_node = __m_node->__m_right;
            while (__m_node->__m_left != 0)
                __m_node = __m_node->__m_left;
        }
        else
        {
            __base_ptr __y = __m_node->__m_parent;
            while (__m_node == __y->__m_right)
            {
                __m_node = __y;
                __y = __y->__m_parent;
            }
            if (__m_node->__m_right != __y)
                __m_node = __y;
        }
    }

    void __m_decrement()
    {
        if (__m_node->__m_color == __s_rb_tree_red &&
            __m_node->__m_parent->__m_parent == __m_node)
            __m_node = __m_node->__m_right;
        else if (__m_node->__m_left != 0)
        {
            __base_ptr __y = __m_node->__m_left;
            while (__y->__m_right != 0)
                __y = __y->__m_right;
            __m_node = __y;
        }
        else
        {
            __base_ptr __y = __m_node->__m_parent;
            while (__m_node == __y->__m_left)
            {
                __m_node = __y;
                __y = __y->__m_parent;
            }
            __m_node = __y;
        }
    }
};

template <class _Value, class _Ref, class _Ptr>
struct __rbtree_iterator : public _rbtree_base_iterator
{
    typedef _Value value_type;
    typedef _Ref reference;
    typedef _Ptr pointer;
    typedef __rbtree_iterator<_Value, _Value &, _Value *>
        iterator;
    typedef __rbtree_iterator<_Value, const _Value &, const _Value *>
        const_iterator;
    typedef __rbtree_iterator<_Value, _Ref, _Ptr>
        _Self;
    typedef __rbtree_node<_Value> *__node_Ptr;

    __rbtree_iterator() {}
    __rbtree_iterator(__node_Ptr __x) { __m_node = __x; }
    __rbtree_iterator(const iterator &__it) { __m_node = __it.__m_node; }

    reference operator*() const { return __node_Ptr(__m_node)->__m_value_field; }
#ifndef ___DST_NO_ARROW_OPERATOR
    pointer operator->() const
    {
        return &(operator*());
    }
#endif /* ___DST_NO_ARROW_OPERATOR */

    _Self &operator++()
    {
        __m_increment();
        return *this;
    }
    _Self operator++(int)
    {
        _Self __tmp = *this;
        __m_increment();
        return __tmp;
    }

    _Self &operator--()
    {
        __m_decrement();
        return *this;
    }
    _Self operator--(int)
    {
        _Self __tmp = *this;
        __m_decrement();
        return __tmp;
    }
};

inline bool operator==(const _rbtree_base_iterator &__x,
                       const _rbtree_base_iterator &__y)
{
    return __x.__m_node == __y.__m_node;
}

inline bool operator!=(const _rbtree_base_iterator &__x,
                       const _rbtree_base_iterator &__y)
{
    return __x.__m_node != __y.__m_node;
}

#ifndef __DST_CLASS_PARTIAL_SPECIALIZATION

inline bidirectional_iterator_tag
iterator_category(const _rbtree_base_iterator &)
{
    return bidirectional_iterator_tag();
}

inline _rbtree_base_iterator::difference_type *
distance_type(const _rbtree_base_iterator &)
{
    return (_rbtree_base_iterator::difference_type *)0;
}

template <class _Value, class _Ref, class _Ptr>
inline _Value *value_type(const __rbtree_iterator<_Value, _Ref, _Ptr> &)
{
    return (_Value *)0;
}

#endif /* __DST_CLASS_PARTIAL_SPECIALIZATION */

inline void
__rbtree_rotate_left(__rbtree_node_base *__x, __rbtree_node_base *&__root)
{
    __rbtree_node_base *__y = __x->__m_right;
    __x->__m_right = __y->__m_left;
    if (__y->__m_left != 0)
        __y->__m_left->__m_parent = __x;
    __y->__m_parent = __x->__m_parent;

    if (__x == __root)
        __root = __y;
    else if (__x == __x->__m_parent->__m_left)
        __x->__m_parent->__m_left = __y;
    else
        __x->__m_parent->__m_right = __y;
    __y->__m_left = __x;
    __x->__m_parent = __y;
}

inline void
__rbtree_rotate_right(__rbtree_node_base *__x, __rbtree_node_base *&__root)
{
    __rbtree_node_base *__y = __x->__m_left;
    __x->__m_left = __y->__m_right;
    if (__y->__m_right != 0)
        __y->__m_right->__m_parent = __x;
    __y->__m_parent = __x->__m_parent;

    if (__x == __root)
        __root = __y;
    else if (__x == __x->__m_parent->__m_right)
        __x->__m_parent->__m_right = __y;
    else
        __x->__m_parent->__m_left = __y;
    __y->__m_right = __x;
    __x->__m_parent = __y;
}

inline void
__rbtree_rebalance(__rbtree_node_base *__x, __rbtree_node_base *&__root)
{
    __x->__m_color = __s_rb_tree_red;
    while (__x != __root && __x->__m_parent->__m_color == __s_rb_tree_red)
    {
        if (__x->__m_parent == __x->__m_parent->__m_parent->__m_left)
        {
            __rbtree_node_base *__y = __x->__m_parent->__m_parent->__m_right;
            if (__y && __y->__m_color == __s_rb_tree_red)
            {
                __x->__m_parent->__m_color = __s_rb_tree_black;
                __y->__m_color = __s_rb_tree_black;
                __x->__m_parent->__m_parent->__m_color = __s_rb_tree_red;
                __x = __x->__m_parent->__m_parent;
            }
            else
            {
                if (__x == __x->__m_parent->__m_right)
                {
                    __x = __x->__m_parent;
                    __rbtree_rotate_left(__x, __root);
                }
                __x->__m_parent->__m_color = __s_rb_tree_black;
                __x->__m_parent->__m_parent->__m_color = __s_rb_tree_red;
                __rbtree_rotate_right(__x->__m_parent->__m_parent, __root);
            }
        }
        else
        {
            __rbtree_node_base *__y = __x->__m_parent->__m_parent->__m_left;
            if (__y && __y->__m_color == __s_rb_tree_red)
            {
                __x->__m_parent->__m_color = __s_rb_tree_black;
                __y->__m_color = __s_rb_tree_black;
                __x->__m_parent->__m_parent->__m_color = __s_rb_tree_red;
                __x = __x->__m_parent->__m_parent;
            }
            else
            {
                if (__x == __x->__m_parent->__m_left)
                {
                    __x = __x->__m_parent;
                    __rbtree_rotate_right(__x, __root);
                }
                __x->__m_parent->__m_color = __s_rb_tree_black;
                __x->__m_parent->__m_parent->__m_color = __s_rb_tree_red;
                __rbtree_rotate_left(__x->__m_parent->__m_parent, __root);
            }
        }
    }
    __root->__m_color = __s_rb_tree_black;
}

inline __rbtree_node_base *
__rbtree_rebalance_for_erase(__rbtree_node_base *__z,
                             __rbtree_node_base *&__root,
                             __rbtree_node_base *&__leftmost,
                             __rbtree_node_base *&__rightmost)
{
    __rbtree_node_base *__y = __z;
    __rbtree_node_base *__x = 0;
    __rbtree_node_base *__x_parent = 0;
    if (__y->__m_left == 0)       // __z has at most one non-null child. y == z.
        __x = __y->__m_right;     // __x might be null.
    else if (__y->__m_right == 0) // __z has exactly one non-null child. y == z.
        __x = __y->__m_left;      // __x is not null.
    else
    {                         // __z has two non-null children.  Set __y to
        __y = __y->__m_right; //   __z's successor.  __x might be null.
        while (__y->__m_left != 0)
            __y = __y->__m_left;
        __x = __y->__m_right;
    }
    if (__y != __z)
    { // relink y in place of z.  y is z's successor
        __z->__m_left->__m_parent = __y;
        __y->__m_left = __z->__m_left;
        if (__y != __z->__m_right)
        {
            __x_parent = __y->__m_parent;
            if (__x)
                __x->__m_parent = __y->__m_parent;
            __y->__m_parent->__m_left = __x; // __y must be a child of __m_left
            __y->__m_right = __z->__m_right;
            __z->__m_right->__m_parent = __y;
        }
        else
            __x_parent = __y;
        if (__root == __z)
            __root = __y;
        else if (__z->__m_parent->__m_left == __z)
            __z->__m_parent->__m_left = __y;
        else
            __z->__m_parent->__m_right = __y;
        __y->__m_parent = __z->__m_parent;
        __DSA::swap(__y->__m_color, __z->__m_color);
        __y = __z;
        // __y now points to node to be actually deleted
    }
    else
    { // __y == __z
        __x_parent = __y->__m_parent;
        if (__x)
            __x->__m_parent = __y->__m_parent;
        if (__root == __z)
            __root = __x;
        else if (__z->__m_parent->__m_left == __z)
            __z->__m_parent->__m_left = __x;
        else
            __z->__m_parent->__m_right = __x;
        if (__leftmost == __z)
        {
            if (__z->__m_right == 0) // __z->__m_left must be null also
                __leftmost = __z->__m_parent;
            // makes __leftmost == __m_header if __z == __root
            else
                __leftmost = __rbtree_node_base::__s_minimum(__x);
        }
        if (__rightmost == __z)
        {
            if (__z->__m_left == 0) // __z->__m_right must be null also
                __rightmost = __z->__m_parent;
            // makes __rightmost == __m_header if __z == __root
            else // __x == __z->__m_left
                __rightmost = __rbtree_node_base::__s_maximum(__x);
        }
    }
    if (__y->__m_color != __s_rb_tree_red)
    {
        while (__x != __root && (__x == 0 || __x->__m_color == __s_rb_tree_black))
            if (__x == __x_parent->__m_left)
            {
                __rbtree_node_base *__w = __x_parent->__m_right;
                if (__w->__m_color == __s_rb_tree_red)
                {
                    __w->__m_color = __s_rb_tree_black;
                    __x_parent->__m_color = __s_rb_tree_red;
                    __rbtree_rotate_left(__x_parent, __root);
                    __w = __x_parent->__m_right;
                }
                if ((__w->__m_left == 0 ||
                     __w->__m_left->__m_color == __s_rb_tree_black) &&
                    (__w->__m_right == 0 ||
                     __w->__m_right->__m_color == __s_rb_tree_black))
                {
                    __w->__m_color = __s_rb_tree_red;
                    __x = __x_parent;
                    __x_parent = __x_parent->__m_parent;
                }
                else
                {
                    if (__w->__m_right == 0 ||
                        __w->__m_right->__m_color == __s_rb_tree_black)
                    {
                        if (__w->__m_left)
                            __w->__m_left->__m_color = __s_rb_tree_black;
                        __w->__m_color = __s_rb_tree_red;
                        __rbtree_rotate_right(__w, __root);
                        __w = __x_parent->__m_right;
                    }
                    __w->__m_color = __x_parent->__m_color;
                    __x_parent->__m_color = __s_rb_tree_black;
                    if (__w->__m_right)
                        __w->__m_right->__m_color = __s_rb_tree_black;
                    __rbtree_rotate_left(__x_parent, __root);
                    break;
                }
            }
            else
            { // same as above, with __m_right <-> __m_left.
                __rbtree_node_base *__w = __x_parent->__m_left;
                if (__w->__m_color == __s_rb_tree_red)
                {
                    __w->__m_color = __s_rb_tree_black;
                    __x_parent->__m_color = __s_rb_tree_red;
                    __rbtree_rotate_right(__x_parent, __root);
                    __w = __x_parent->__m_left;
                }
                if ((__w->__m_right == 0 ||
                     __w->__m_right->__m_color == __s_rb_tree_black) &&
                    (__w->__m_left == 0 ||
                     __w->__m_left->__m_color == __s_rb_tree_black))
                {
                    __w->__m_color = __s_rb_tree_red;
                    __x = __x_parent;
                    __x_parent = __x_parent->__m_parent;
                }
                else
                {
                    if (__w->__m_left == 0 ||
                        __w->__m_left->__m_color == __s_rb_tree_black)
                    {
                        if (__w->__m_right)
                            __w->__m_right->__m_color = __s_rb_tree_black;
                        __w->__m_color = __s_rb_tree_red;
                        __rbtree_rotate_left(__w, __root);
                        __w = __x_parent->__m_left;
                    }
                    __w->__m_color = __x_parent->__m_color;
                    __x_parent->__m_color = __s_rb_tree_black;
                    if (__w->__m_left)
                        __w->__m_left->__m_color = __s_rb_tree_black;
                    __rbtree_rotate_right(__x_parent, __root);
                    break;
                }
            }
        if (__x)
            __x->__m_color = __s_rb_tree_black;
    }
    return __y;
}

// Base class to encapsulate the differences between old -style
// allocators and standard-conforming allocators.  In order to avoid
// having an empty base class, we arbitrarily move one of rb_tree's
// data members into the base class.

#ifdef __DST_USE_DSA_ALLOCATORS

// __base for general standard-conforming allocators.
template <class _Tp, class _Alloc, bool __s_instanceless>
class __rbtree_alloc_base
{
public:
    typedef typename _Alloc_traits<_Tp, _Alloc>::allocator_type allocator_type;
    allocator_type get_allocator() const { return __m_node_allocator; }

    __rbtree_alloc_base(const allocator_type &__a)
        : __m_node_allocator(__a), __m_header(0) {}

protected:
    typename _Alloc_traits<__rbtree_node<_Tp>, _Alloc>::allocator_type
        __m_node_allocator;
    __rbtree_node<_Tp> *__m_header;

    __rbtree_node<_Tp> *__m_get_node()
    {
        return __m_node_allocator.allocate(1);
    }
    void __m_put_node(__rbtree_node<_Tp> *__p)
    {
        __m_node_allocator.deallocate(__p, 1);
    }
};

// Specialization for instanceless allocators.
template <class _Tp, class _Alloc>
class __rbtree_alloc_base<_Tp, _Alloc, true>
{
public:
    typedef typename _Alloc_traits<_Tp, _Alloc>::allocator_type allocator_type;
    allocator_type get_allocator() const { return allocator_type(); }

    __rbtree_alloc_base(const allocator_type &) : __m_header(0) {}

protected:
    __rbtree_node<_Tp> *__m_header;

    typedef typename _Alloc_traits<__rbtree_node<_Tp>, _Alloc>::_Alloc_type
        _Alloc_type;

    __rbtree_node<_Tp> *__m_get_node()
    {
        return _Alloc_type::allocate(1);
    }
    void __m_put_node(__rbtree_node<_Tp> *__p)
    {
        _Alloc_type::deallocate(__p, 1);
    }
};

template <class _Tp, class _Alloc>
struct _rbtree_base : public __rbtree_alloc_base<_Tp, _Alloc, _Alloc_traits<_Tp, _Alloc>::__s_instanceless>
{
    typedef __rbtree_alloc_base<_Tp, _Alloc, _Alloc_traits<_Tp, _Alloc>::__s_instanceless> __base;
    typedef typename __base::allocator_type allocator_type;

    _rbtree_base(const allocator_type &__a)
        : __base(__a) { __m_header = __m_get_node(); }
    ~_rbtree_base() { __m_put_node(__m_header); }
};

#else /* __DST_USE_DSA_ALLOCATORS */

template <class _Tp, class _Alloc>
struct _rbtree_base
{
    typedef _Alloc allocator_type;
    allocator_type get_allocator() const { return allocator_type(); }

    _rbtree_base(const allocator_type &)
        : __m_header(0) { __m_header = __m_get_node(); }
    ~_rbtree_base() { __m_put_node(__m_header); }

protected:
    __rbtree_node<_Tp> *__m_header;

    typedef simple_alloc<__rbtree_node<_Tp>, _Alloc> _Alloc_type;

    __rbtree_node<_Tp> *__m_get_node()
    {
        return _Alloc_type::allocate(1);
    }
    void __m_put_node(__rbtree_node<_Tp> *__p)
    {
        _Alloc_type::deallocate(__p, 1);
    }
};

#endif /* __DST_USE_DSA_ALLOCATORS */

template <class _Key, class _Value, class _KeyOfValue, class _Compare,
          class _Alloc = __DST_DEFAULT_ALLOCATOR(_Value)>
class __rbtree : protected _rbtree_base<_Value, _Alloc>
{
    typedef _rbtree_base<_Value, _Alloc> __base;

protected:
    typedef __rbtree_node_base *__base_ptr;
    typedef __rbtree_node<_Value> __rbtree_node;
    typedef __rbtree_Color_type _Color_type;

public:
    typedef _Key key_type;
    typedef _Value value_type;
    typedef value_type *pointer;
    typedef const value_type *const_pointer;
    typedef value_type &reference;
    typedef const value_type &const_reference;
    typedef __rbtree_node *__node_Ptr;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;

    typedef typename __base::allocator_type allocator_type;
    allocator_type get_allocator() const { return __base::get_allocator(); }

protected:
#ifdef __DST_USE_NAMESPACES
    using __base::__m_get_node;
    using __base::__m_header;
    using __base::__m_put_node;
#endif /* __DST_USE_NAMESPACES */

protected:
    __node_Ptr __m_create_node(const value_type &__x)
    {
        __node_Ptr __tmp = __m_get_node();
        __DST_TRY
        {
            construct(&__tmp->__m_value_field, __x);
        }
        __DST_UNWIND(__m_put_node(__tmp));
        return __tmp;
    }

    __node_Ptr __m_clone_node(__node_Ptr __x)
    {
        __node_Ptr __tmp = __m_create_node(__x->__m_value_field);
        __tmp->__m_color = __x->__m_color;
        __tmp->__m_left = 0;
        __tmp->__m_right = 0;
        return __tmp;
    }

    void destroy_node(__node_Ptr __p)
    {
        destroy(&__p->__m_value_field);
        __m_put_node(__p);
    }

protected:
    size_type __m_node_count; // keeps track of size of tree
    _Compare __m_key_compare;

    __node_Ptr &__m_root() const
    {
        return (__node_Ptr &)__m_header->__m_parent;
    }
    __node_Ptr &__m_leftmost() const
    {
        return (__node_Ptr &)__m_header->__m_left;
    }
    __node_Ptr &__m_rightmost() const
    {
        return (__node_Ptr &)__m_header->__m_right;
    }

    static __node_Ptr &__s_left(__node_Ptr __x)
    {
        return (__node_Ptr &)(__x->__m_left);
    }
    static __node_Ptr &__s_right(__node_Ptr __x)
    {
        return (__node_Ptr &)(__x->__m_right);
    }
    static __node_Ptr &__s_parent(__node_Ptr __x)
    {
        return (__node_Ptr &)(__x->__m_parent);
    }
    static reference __s_value(__node_Ptr __x)
    {
        return __x->__m_value_field;
    }
    static const _Key &__s_key(__node_Ptr __x)
    {
        return _KeyOfValue()(__s_value(__x));
    }
    static _Color_type &__s_color(__node_Ptr __x)
    {
        return (_Color_type &)(__x->__m_color);
    }

    static __node_Ptr &__s_left(__base_ptr __x)
    {
        return (__node_Ptr &)(__x->__m_left);
    }
    static __node_Ptr &__s_right(__base_ptr __x)
    {
        return (__node_Ptr &)(__x->__m_right);
    }
    static __node_Ptr &__s_parent(__base_ptr __x)
    {
        return (__node_Ptr &)(__x->__m_parent);
    }
    static reference __s_value(__base_ptr __x)
    {
        return ((__node_Ptr)__x)->__m_value_field;
    }
    static const _Key &__s_key(__base_ptr __x)
    {
        return _KeyOfValue()(__s_value(__node_Ptr(__x)));
    }
    static _Color_type &__s_color(__base_ptr __x)
    {
        return (_Color_type &)(__node_Ptr(__x)->__m_color);
    }

    static __node_Ptr __s_minimum(__node_Ptr __x)
    {
        return (__node_Ptr)__rbtree_node_base::__s_minimum(__x);
    }

    static __node_Ptr __s_maximum(__node_Ptr __x)
    {
        return (__node_Ptr)__rbtree_node_base::__s_maximum(__x);
    }

public:
    typedef __rbtree_iterator<value_type, reference, pointer> iterator;
    typedef __rbtree_iterator<value_type, const_reference, const_pointer>
        const_iterator;

#ifdef __DST_CLASS_PARTIAL_SPECIALIZATION
    typedef reverse_iterator<const_iterator> const_reverse_iterator;
    typedef reverse_iterator<iterator> reverse_iterator;
#else  /* __DST_CLASS_PARTIAL_SPECIALIZATION */
    typedef reverse_bidirectional_iterator<iterator, value_type, reference,
                                           difference_type>
        reverse_iterator;
    typedef reverse_bidirectional_iterator<const_iterator, value_type,
                                           const_reference, difference_type>
        const_reverse_iterator;
#endif /* __DST_CLASS_PARTIAL_SPECIALIZATION */

private:
    iterator __m_insert(__base_ptr __x, __base_ptr __y, const value_type &__v);
    __node_Ptr __m_copy(__node_Ptr __x, __node_Ptr __p);
    void __m_erase(__node_Ptr __x);

public:
    // allocation/deallocation
    __rbtree()
        : __base(allocator_type()), __m_node_count(0), __m_key_compare()
    {
        __m_empty_initialize();
    }

    __rbtree(const _Compare &__comp)
        : __base(allocator_type()), __m_node_count(0), __m_key_compare(__comp)
    {
        __m_empty_initialize();
    }

    __rbtree(const _Compare &__comp, const allocator_type &__a)
        : __base(__a), __m_node_count(0), __m_key_compare(__comp)
    {
        __m_empty_initialize();
    }

    __rbtree(const __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc> &__x)
        : __base(__x.get_allocator()),
          __m_node_count(0), __m_key_compare(__x.__m_key_compare)
    {
        if (__x.__m_root() == 0)
            __m_empty_initialize();
        else
        {
            __s_color(__m_header) = __s_rb_tree_red;
            __m_root() = __m_copy(__x.__m_root(), __m_header);
            __m_leftmost() = __s_minimum(__m_root());
            __m_rightmost() = __s_maximum(__m_root());
        }
        __m_node_count = __x.__m_node_count;
    }
    ~__rbtree() { clear(); }
    __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc> &
    operator=(const __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc> &__x);

private:
    void __m_empty_initialize()
    {
        __s_color(__m_header) = __s_rb_tree_red; // used to distinguish header from
                                                 // __root, in iterator.operator++
        __m_root() = 0;
        __m_leftmost() = __m_header;
        __m_rightmost() = __m_header;
    }

public:
    // accessors:
    _Compare key_comp() const { return __m_key_compare; }
    iterator begin() { return __m_leftmost(); }
    const_iterator begin() const { return __m_leftmost(); }
    iterator end() { return __m_header; }
    const_iterator end() const { return __m_header; }
    reverse_iterator rbegin() { return reverse_iterator(end()); }
    const_reverse_iterator rbegin() const
    {
        return const_reverse_iterator(end());
    }
    reverse_iterator rend() { return reverse_iterator(begin()); }
    const_reverse_iterator rend() const
    {
        return const_reverse_iterator(begin());
    }
    bool empty() const { return __m_node_count == 0; }
    size_type size() const { return __m_node_count; }
    size_type max_size() const { return size_type(-1); }

    void swap(__rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc> &__t)
    {
        __DSA::swap(__m_header, __t.__m_header);
        __DSA::swap(__m_node_count, __t.__m_node_count);
        __DSA::swap(__m_key_compare, __t.__m_key_compare);
    }

public:
    // insert/erase
    pair<iterator, bool> insert_unique(const value_type &__x);
    iterator insert_equal(const value_type &__x);

    iterator insert_unique(iterator __position, const value_type &__x);
    iterator insert_equal(iterator __position, const value_type &__x);

#ifdef __DST_MEMBER_TEMPLATES
    template <class _InputIterator>
    void insert_unique(_InputIterator __first, _InputIterator __last);
    template <class _InputIterator>
    void insert_equal(_InputIterator __first, _InputIterator __last);
#else  /* __DST_MEMBER_TEMPLATES */
    void insert_unique(const_iterator __first, const_iterator __last);
    void insert_unique(const value_type *__first, const value_type *__last);
    void insert_equal(const_iterator __first, const_iterator __last);
    void insert_equal(const value_type *__first, const value_type *__last);
#endif /* __DST_MEMBER_TEMPLATES */

    void erase(iterator __position);
    size_type erase(const key_type &__x);
    void erase(iterator __first, iterator __last);
    void erase(const key_type *__first, const key_type *__last);
    void clear()
    {
        if (__m_node_count != 0)
        {
            __m_erase(__m_root());
            __m_leftmost() = __m_header;
            __m_root() = 0;
            __m_rightmost() = __m_header;
            __m_node_count = 0;
        }
    }

public:
    // set operations:
    iterator find(const key_type &__x);
    const_iterator find(const key_type &__x) const;
    size_type count(const key_type &__x) const;
    iterator lower_bound(const key_type &__x);
    const_iterator lower_bound(const key_type &__x) const;
    iterator upper_bound(const key_type &__x);
    const_iterator upper_bound(const key_type &__x) const;
    pair<iterator, iterator> equal_range(const key_type &__x);
    pair<const_iterator, const_iterator> equal_range(const key_type &__x) const;

public:
    // Debugging.
    bool __rb_verify() const;
};

template <class _Key, class _Value, class _KeyOfValue,
          class _Compare, class _Alloc>
inline bool
operator==(const __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc> &__x,
           const __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc> &__y)
{
    return __x.size() == __y.size() &&
           equal(__x.begin(), __x.end(), __y.begin());
}

template <class _Key, class _Value, class _KeyOfValue,
          class _Compare, class _Alloc>
inline bool
operator<(const __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc> &__x,
          const __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc> &__y)
{
    return lexicographical_compare(__x.begin(), __x.end(),
                                   __y.begin(), __y.end());
}

#ifdef __DST_FUNCTION_TMPL_PARTIAL_ORDER

template <class _Key, class _Value, class _KeyOfValue,
          class _Compare, class _Alloc>
inline bool
operator!=(const __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc> &__x,
           const __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc> &__y)
{
    return !(__x == __y);
}

template <class _Key, class _Value, class _KeyOfValue,
          class _Compare, class _Alloc>
inline bool
operator>(const __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc> &__x,
          const __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc> &__y)
{
    return __y < __x;
}

template <class _Key, class _Value, class _KeyOfValue,
          class _Compare, class _Alloc>
inline bool
operator<=(const __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc> &__x,
           const __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc> &__y)
{
    return !(__y < __x);
}

template <class _Key, class _Value, class _KeyOfValue,
          class _Compare, class _Alloc>
inline bool
operator>=(const __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc> &__x,
           const __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc> &__y)
{
    return !(__x < __y);
}

template <class _Key, class _Value, class _KeyOfValue,
          class _Compare, class _Alloc>
inline void
swap(__rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc> &__x,
     __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc> &__y)
{
    __x.swap(__y);
}

#endif /* __DST_FUNCTION_TMPL_PARTIAL_ORDER */

template <class _Key, class _Value, class _KeyOfValue,
          class _Compare, class _Alloc>
__rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc> &
__rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::operator=(const __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc> &__x)
{
    if (this != &__x)
    {
        // Note that _Key may be a constant type.
        clear();
        __m_node_count = 0;
        __m_key_compare = __x.__m_key_compare;
        if (__x.__m_root() == 0)
        {
            __m_root() = 0;
            __m_leftmost() = __m_header;
            __m_rightmost() = __m_header;
        }
        else
        {
            __m_root() = __m_copy(__x.__m_root(), __m_header);
            __m_leftmost() = __s_minimum(__m_root());
            __m_rightmost() = __s_maximum(__m_root());
            __m_node_count = __x.__m_node_count;
        }
    }
    return *this;
}

template <class _Key, class _Value, class _KeyOfValue,
          class _Compare, class _Alloc>
typename __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::iterator
__rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::__m_insert(__base_ptr __x_, __base_ptr __y_, const _Value &__v)
{
    __node_Ptr __x = (__node_Ptr)__x_;
    __node_Ptr __y = (__node_Ptr)__y_;
    __node_Ptr __z;

    if (__y == __m_header || __x != 0 ||
        __m_key_compare(_KeyOfValue()(__v), __s_key(__y)))
    {
        __z = __m_create_node(__v);
        __s_left(__y) = __z; // also makes __m_leftmost() = __z
                             //    when __y == __m_header
        if (__y == __m_header)
        {
            __m_root() = __z;
            __m_rightmost() = __z;
        }
        else if (__y == __m_leftmost())
            __m_leftmost() = __z; // maintain __m_leftmost() pointing to min node
    }
    else
    {
        __z = __m_create_node(__v);
        __s_right(__y) = __z;
        if (__y == __m_rightmost())
            __m_rightmost() = __z; // maintain __m_rightmost() pointing to max node
    }
    __s_parent(__z) = __y;
    __s_left(__z) = 0;
    __s_right(__z) = 0;
    __rbtree_rebalance(__z, __m_header->__m_parent);
    ++__m_node_count;
    return iterator(__z);
}

template <class _Key, class _Value, class _KeyOfValue,
          class _Compare, class _Alloc>
typename __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::iterator
__rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::insert_equal(const _Value &__v)
{
    __node_Ptr __y = __m_header;
    __node_Ptr __x = __m_root();
    while (__x != 0)
    {
        __y = __x;
        __x = __m_key_compare(_KeyOfValue()(__v), __s_key(__x)) ? __s_left(__x) : __s_right(__x);
    }
    return __m_insert(__x, __y, __v);
}

template <class _Key, class _Value, class _KeyOfValue,
          class _Compare, class _Alloc>
pair<typename __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::iterator,
     bool>
__rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::insert_unique(const _Value &__v)
{
    __node_Ptr __y = __m_header;
    __node_Ptr __x = __m_root();
    bool __comp = true;
    while (__x != 0)
    {
        __y = __x;
        __comp = __m_key_compare(_KeyOfValue()(__v), __s_key(__x));
        __x = __comp ? __s_left(__x) : __s_right(__x);
    }
    iterator __j = iterator(__y);
    if (__comp)
    {
        if (__j == begin())
            return pair<iterator, bool>(__m_insert(__x, __y, __v), true);
        else
            --__j;
    }
    if (__m_key_compare(__s_key(__j.__m_node), _KeyOfValue()(__v)))
        return pair<iterator, bool>(__m_insert(__x, __y, __v), true);
    return pair<iterator, bool>(__j, false);
}

template <class _Key, class _Val, class _KeyOfValue,
          class _Compare, class _Alloc>
typename __rbtree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator
__rbtree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::insert_unique(iterator __position, const _Val &__v)
{
    if (__position.__m_node == __m_header->__m_left)
    { // begin()
        if (size() > 0 &&
            __m_key_compare(_KeyOfValue()(__v), __s_key(__position.__m_node)))
            return __m_insert(__position.__m_node, __position.__m_node, __v);
        // first argument just needs to be non-null
        else
            return insert_unique(__v).first;
    }
    else if (__position.__m_node == __m_header)
    { // end()
        if (__m_key_compare(__s_key(__m_rightmost()), _KeyOfValue()(__v)))
            return __m_insert(0, __m_rightmost(), __v);
        else
            return insert_unique(__v).first;
    }
    else
    {
        iterator __before = __position;
        --__before;
        if (__m_key_compare(__s_key(__before.__m_node), _KeyOfValue()(__v)) && __m_key_compare(_KeyOfValue()(__v), __s_key(__position.__m_node)))
        {
            if (__s_right(__before.__m_node) == 0)
                return __m_insert(0, __before.__m_node, __v);
            else
                return __m_insert(__position.__m_node, __position.__m_node, __v);
            // first argument just needs to be non-null
        }
        else
            return insert_unique(__v).first;
    }
}

template <class _Key, class _Val, class _KeyOfValue,
          class _Compare, class _Alloc>
typename __rbtree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator
__rbtree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::insert_equal(iterator __position, const _Val &__v)
{
    if (__position.__m_node == __m_header->__m_left)
    { // begin()
        if (size() > 0 &&
            !__m_key_compare(__s_key(__position.__m_node), _KeyOfValue()(__v)))
            return __m_insert(__position.__m_node, __position.__m_node, __v);
        // first argument just needs to be non-null
        else
            return insert_equal(__v);
    }
    else if (__position.__m_node == __m_header)
    { // end()
        if (!__m_key_compare(_KeyOfValue()(__v), __s_key(__m_rightmost())))
            return __m_insert(0, __m_rightmost(), __v);
        else
            return insert_equal(__v);
    }
    else
    {
        iterator __before = __position;
        --__before;
        if (!__m_key_compare(_KeyOfValue()(__v), __s_key(__before.__m_node)) && !__m_key_compare(__s_key(__position.__m_node), _KeyOfValue()(__v)))
        {
            if (__s_right(__before.__m_node) == 0)
                return __m_insert(0, __before.__m_node, __v);
            else
                return __m_insert(__position.__m_node, __position.__m_node, __v);
            // first argument just needs to be non-null
        }
        else
            return insert_equal(__v);
    }
}

#ifdef __DST_MEMBER_TEMPLATES

template <class _Key, class _Val, class _KoV, class _Cmp, class _Alloc>
template <class _II>
void __rbtree<_Key, _Val, _KoV, _Cmp, _Alloc>::insert_equal(_II __first, _II __last)
{
    for (; __first != __last; ++__first)
        insert_equal(*__first);
}

template <class _Key, class _Val, class _KoV, class _Cmp, class _Alloc>
template <class _II>
void __rbtree<_Key, _Val, _KoV, _Cmp, _Alloc>::insert_unique(_II __first, _II __last)
{
    for (; __first != __last; ++__first)
        insert_unique(*__first);
}

#else /* __DST_MEMBER_TEMPLATES */

template <class _Key, class _Val, class _KoV, class _Cmp, class _Alloc>
void __rbtree<_Key, _Val, _KoV, _Cmp, _Alloc>::insert_equal(const _Val *__first, const _Val *__last)
{
    for (; __first != __last; ++__first)
        insert_equal(*__first);
}

template <class _Key, class _Val, class _KoV, class _Cmp, class _Alloc>
void __rbtree<_Key, _Val, _KoV, _Cmp, _Alloc>::insert_equal(const_iterator __first, const_iterator __last)
{
    for (; __first != __last; ++__first)
        insert_equal(*__first);
}

template <class _Key, class _Val, class _KoV, class _Cmp, class _Alloc>
void __rbtree<_Key, _Val, _KoV, _Cmp, _Alloc>::insert_unique(const _Val *__first, const _Val *__last)
{
    for (; __first != __last; ++__first)
        insert_unique(*__first);
}

template <class _Key, class _Val, class _KoV, class _Cmp, class _Alloc>
void __rbtree<_Key, _Val, _KoV, _Cmp, _Alloc>::insert_unique(const_iterator __first, const_iterator __last)
{
    for (; __first != __last; ++__first)
        insert_unique(*__first);
}

#endif /* __DST_MEMBER_TEMPLATES */

template <class _Key, class _Value, class _KeyOfValue,
          class _Compare, class _Alloc>
inline void __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::erase(iterator __position)
{
    __node_Ptr __y =
        (__node_Ptr)__rbtree_rebalance_for_erase(__position.__m_node,
                                                 __m_header->__m_parent,
                                                 __m_header->__m_left,
                                                 __m_header->__m_right);
    destroy_node(__y);
    --__m_node_count;
}

template <class _Key, class _Value, class _KeyOfValue,
          class _Compare, class _Alloc>
typename __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::size_type
__rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::erase(const _Key &__x)
{
    pair<iterator, iterator> __p = equal_range(__x);
    size_type __n = 0;
    distance(__p.first, __p.second, __n);
    erase(__p.first, __p.second);
    return __n;
}

template <class _Key, class _Val, class _KoV, class _Compare, class _Alloc>
typename __rbtree<_Key, _Val, _KoV, _Compare, _Alloc>::__node_Ptr
__rbtree<_Key, _Val, _KoV, _Compare, _Alloc>::__m_copy(__node_Ptr __x, __node_Ptr __p)
{
    // structural copy.  __x and __p must be non-null.
    __node_Ptr __top = __m_clone_node(__x);
    __top->__m_parent = __p;

    __DST_TRY
    {
        if (__x->__m_right)
            __top->__m_right = __m_copy(__s_right(__x), __top);
        __p = __top;
        __x = __s_left(__x);

        while (__x != 0)
        {
            __node_Ptr __y = __m_clone_node(__x);
            __p->__m_left = __y;
            __y->__m_parent = __p;
            if (__x->__m_right)
                __y->__m_right = __m_copy(__s_right(__x), __y);
            __p = __y;
            __x = __s_left(__x);
        }
    }
    __DST_UNWIND(__m_erase(__top));

    return __top;
}

template <class _Key, class _Value, class _KeyOfValue,
          class _Compare, class _Alloc>
void __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::__m_erase(__node_Ptr __x)
{
    // erase without rebalancing
    while (__x != 0)
    {
        __m_erase(__s_right(__x));
        __node_Ptr __y = __s_left(__x);
        destroy_node(__x);
        __x = __y;
    }
}

template <class _Key, class _Value, class _KeyOfValue,
          class _Compare, class _Alloc>
void __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::erase(iterator __first, iterator __last)
{
    if (__first == begin() && __last == end())
        clear();
    else
        while (__first != __last)
            erase(__first++);
}

template <class _Key, class _Value, class _KeyOfValue,
          class _Compare, class _Alloc>
void __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::erase(const _Key *__first, const _Key *__last)
{
    while (__first != __last)
        erase(*__first++);
}

template <class _Key, class _Value, class _KeyOfValue,
          class _Compare, class _Alloc>
typename __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::iterator
__rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::find(const _Key &__k)
{
    __node_Ptr __y = __m_header; // Last node which is not less than __k.
    __node_Ptr __x = __m_root(); // Current node.

    while (__x != 0)
        if (!__m_key_compare(__s_key(__x), __k))
            __y = __x, __x = __s_left(__x);
        else
            __x = __s_right(__x);

    iterator __j = iterator(__y);
    return (__j == end() || __m_key_compare(__k, __s_key(__j.__m_node))) ? end() : __j;
}

template <class _Key, class _Value, class _KeyOfValue,
          class _Compare, class _Alloc>
typename __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::const_iterator
__rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::find(const _Key &__k) const
{
    __node_Ptr __y = __m_header; /* Last node which is not less than __k. */
    __node_Ptr __x = __m_root(); /* Current node. */

    while (__x != 0)
    {
        if (!__m_key_compare(__s_key(__x), __k))
            __y = __x, __x = __s_left(__x);
        else
            __x = __s_right(__x);
    }
    const_iterator __j = const_iterator(__y);
    return (__j == end() || __m_key_compare(__k, __s_key(__j.__m_node))) ? end() : __j;
}

template <class _Key, class _Value, class _KeyOfValue,
          class _Compare, class _Alloc>
typename __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::size_type
__rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::count(const _Key &__k) const
{
    pair<const_iterator, const_iterator> __p = equal_range(__k);
    size_type __n = 0;
    distance(__p.first, __p.second, __n);
    return __n;
}

template <class _Key, class _Value, class _KeyOfValue,
          class _Compare, class _Alloc>
typename __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::iterator
__rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::lower_bound(const _Key &__k)
{
    __node_Ptr __y = __m_header; /* Last node which is not less than __k. */
    __node_Ptr __x = __m_root(); /* Current node. */

    while (__x != 0)
        if (!__m_key_compare(__s_key(__x), __k))
            __y = __x, __x = __s_left(__x);
        else
            __x = __s_right(__x);

    return iterator(__y);
}

template <class _Key, class _Value, class _KeyOfValue,
          class _Compare, class _Alloc>
typename __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::const_iterator
__rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::lower_bound(const _Key &__k) const
{
    __node_Ptr __y = __m_header; /* Last node which is not less than __k. */
    __node_Ptr __x = __m_root(); /* Current node. */

    while (__x != 0)
        if (!__m_key_compare(__s_key(__x), __k))
            __y = __x, __x = __s_left(__x);
        else
            __x = __s_right(__x);

    return const_iterator(__y);
}

template <class _Key, class _Value, class _KeyOfValue,
          class _Compare, class _Alloc>
typename __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::iterator
__rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::upper_bound(const _Key &__k)
{
    __node_Ptr __y = __m_header; /* Last node which is greater than __k. */
    __node_Ptr __x = __m_root(); /* Current node. */

    while (__x != 0)
        if (__m_key_compare(__k, __s_key(__x)))
            __y = __x, __x = __s_left(__x);
        else
            __x = __s_right(__x);

    return iterator(__y);
}

template <class _Key, class _Value, class _KeyOfValue,
          class _Compare, class _Alloc>
typename __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::const_iterator
__rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::upper_bound(const _Key &__k) const
{
    __node_Ptr __y = __m_header; /* Last node which is greater than __k. */
    __node_Ptr __x = __m_root(); /* Current node. */

    while (__x != 0)
        if (__m_key_compare(__k, __s_key(__x)))
            __y = __x, __x = __s_left(__x);
        else
            __x = __s_right(__x);

    return const_iterator(__y);
}

template <class _Key, class _Value, class _KeyOfValue,
          class _Compare, class _Alloc>
inline pair<typename __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::iterator,
            typename __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::iterator>
__rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::equal_range(const _Key &__k)
{
    return pair<iterator, iterator>(lower_bound(__k), upper_bound(__k));
}

template <class _Key, class _Value, class _KoV, class _Compare, class _Alloc>
inline pair<typename __rbtree<_Key, _Value, _KoV, _Compare, _Alloc>::const_iterator,
            typename __rbtree<_Key, _Value, _KoV, _Compare, _Alloc>::const_iterator>
__rbtree<_Key, _Value, _KoV, _Compare, _Alloc>::equal_range(const _Key &__k) const
{
    return pair<const_iterator, const_iterator>(lower_bound(__k),
                                                upper_bound(__k));
}

inline int
__black_count(__rbtree_node_base *__node, __rbtree_node_base *__root)
{
    if (__node == 0)
        return 0;
    else
    {
        int __bc = __node->__m_color == __s_rb_tree_black ? 1 : 0;
        if (__node == __root)
            return __bc;
        else
            return __bc + __black_count(__node->__m_parent, __root);
    }
}

template <class _Key, class _Value, class _KeyOfValue,
          class _Compare, class _Alloc>
bool __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::__rb_verify() const
{
    if (__m_node_count == 0 || begin() == end())
        return __m_node_count == 0 && begin() == end() &&
               __m_header->__m_left == __m_header && __m_header->__m_right == __m_header;

    int __len = __black_count(__m_leftmost(), __m_root());
    for (const_iterator __it = begin(); __it != end(); ++__it)
    {
        __node_Ptr __x = (__node_Ptr)__it.__m_node;
        __node_Ptr __L = __s_left(__x);
        __node_Ptr __R = __s_right(__x);

        if (__x->__m_color == __s_rb_tree_red)
            if ((__L && __L->__m_color == __s_rb_tree_red) ||
                (__R && __R->__m_color == __s_rb_tree_red))
                return false;

        if (__L && __m_key_compare(__s_key(__x), __s_key(__L)))
            return false;
        if (__R && __m_key_compare(__s_key(__R), __s_key(__x)))
            return false;

        if (!__L && !__R && __black_count(__x, __m_root()) != __len)
            return false;
    }

    if (__m_leftmost() != __rbtree_node_base::__s_minimum(__m_root()))
        return false;
    if (__m_rightmost() != __rbtree_node_base::__s_maximum(__m_root()))
        return false;

    return true;
}

// Class rb_tree is not part of the C++ standard.  It is provided for
// compatibility with the HP DST.

template <class _Key, class _Value, class _KeyOfValue, class _Compare,
          class _Alloc = __DST_DEFAULT_ALLOCATOR(_Value)>
struct rb_tree : public __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>
{
    typedef __rbtree<_Key, _Value, _KeyOfValue, _Compare, _Alloc> __base;
    typedef typename __base::allocator_type allocator_type;

    rb_tree(const _Compare &__comp = _Compare(),
            const allocator_type &__a = allocator_type())
        : __base(__comp, __a) {}

    ~rb_tree() {}
};

#if defined(__sgi) && !defined(__GNUC__) && (_MIPS_SIM != _MIPS_SIM_ABI32)
#pragma reset woff 1375
#endif

__DST_END_NAMESPACE

#endif /* ___DST_INTERNAL_TREE_H */