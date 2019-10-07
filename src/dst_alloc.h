

/* NOTE: This is an internal header file, included by other DST headers.
 *   You should not attempt to use it directly.
 */

#ifndef ___DST_INTERNAL_ALLOC_H
#define ___DST_INTERNAL_ALLOC_H

#ifdef __SUNPRO_CC
#define __PRIVATE public
// Extra access restrictions prevent us from really making some things
// private.
#else
#define __PRIVATE private
#endif

#ifdef __DST_STATIC_TEMPLATE_MEMBER_BUG
#define __USE_MALLOC
#endif

// This implements some standard node allocators.  These are
// NOT the same as the allocators in the C++ draft standard or in
// in the original DST.  They do not encapsulate different pointer
// types; indeed we assume that there is only one pointer type.
// The allocation primitives are intended to allocate individual objects,
// not larger arenas as with the original DST allocators.

#ifndef __THROW_BAD_ALLOC
#if defined(__DST_NO_BAD_ALLOC) || !defined(__DST_USE_EXCEPTIONS)
#include <stdio.h>
#include <stdlib.h>
#define __THROW_BAD_ALLOC               \
    fprintf(stderr, "out of memory\n"); \
    exit(1)
#else /* Standard conforming out-of-memory handling */
#include <new>
#define __THROW_BAD_ALLOC throw std::bad_alloc()
#endif
#endif

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#ifndef __RESTRICT
#define __RESTRICT
#endif

#ifdef __DST_THREADS
#include "dst_threads.h"
#define __NODE_ALLOCATOR_THREADS true
#ifdef __DST__THREADS
// We test whether threads are in use before locking.
// Perhaps this should be moved into stl_threads.h, but that
// probably makes it harder to avoid the procedure call when
// it isn't needed.
extern "C"
{
    extern int __us_rsthread_malloc;
}
// The above is copied from malloc.h.  Including <malloc.h>
// would be cleaner but fails with certain levels of standard
// conformance.
#define __NODE_ALLOCATOR_LOCK                     \
    if (threads && __us_rsthread_malloc)          \
    {                                             \
        _S_node_allocator_lock._M_acquire_lock(); \
    }
#define __NODE_ALLOCATOR_UNLOCK                   \
    if (threads && __us_rsthread_malloc)          \
    {                                             \
        _S_node_allocator_lock._M_release_lock(); \
    }
#else /* !__DST__THREADS */
#define __NODE_ALLOCATOR_LOCK                         \
    {                                                 \
        if (threads)                                  \
            _S_node_allocator_lock._M_acquire_lock(); \
    }
#define __NODE_ALLOCATOR_UNLOCK                       \
    {                                                 \
        if (threads)                                  \
            _S_node_allocator_lock._M_release_lock(); \
    }
#endif
#else
//  Thread-unsafe
#define __NODE_ALLOCATOR_LOCK
#define __NODE_ALLOCATOR_UNLOCK
#define __NODE_ALLOCATOR_THREADS false
#endif

__DST_BEGIN_NAMESPACE

#if defined(__sgi) && !defined(__GNUC__) && (_MIPS_SIM != _MIPS_SIM_ABI32)
#pragma set woff 1174
#endif

// Malloc-based allocator.  Typically slower than default alloc below.
// Typically thread-safe and more storage efficient.
#ifdef __DST_STATIC_TEMPLATE_MEMBER_BUG
#ifdef __DECLARE_GLOBALS_HERE
void (*__malloc_alloc_oom_handler)() = 0;
// g++ 2.7.2 does not handle static template data members.
#else
extern void (*__malloc_alloc_oom_handler)();
#endif
#endif

template <int __inst>
class __malloc_alloc_template
{

private:
    // malloc_alloc out-of-memory handling
    static void *_S_oom_malloc(size_t);
    static void *_S_oom_realloc(void *, size_t);

#ifndef __DST_STATIC_TEMPLATE_MEMBER_BUG
    static void (*__malloc_alloc_oom_handler)();
#endif

public:
    static void *allocate(size_t _n)
    {
        void *_result = malloc(_n);
        if (0 == _result)
            _result = _S_oom_malloc(_n);
        return _result;
    }

    static void deallocate(void *_p, size_t /* _n */)
    {
        free(_p);
    }

    static void *reallocate(void *_p, size_t /* old_sz */, size_t _new_sz)
    {
        void *_result = realloc(_p, _new_sz);
        if (__null == _result)
            _result = _S_oom_realloc(_p, _new_sz);
        return _result;
    }

    static void (*__set_malloc_handler(void (*__f)()))()
    {
        void (*_old)() = __malloc_alloc_oom_handler;
        __malloc_alloc_oom_handler = __f;
        return (_old);
    }
};

// malloc_alloc out-of-memory handling

#ifndef __DST_STATIC_TEMPLATE_MEMBER_BUG
template <int __inst>
void (*__malloc_alloc_template<__inst>::__malloc_alloc_oom_handler)() = __null;
#endif

template <int __inst>
void *__malloc_alloc_template<__inst>::_S_oom_malloc(size_t _n)
{
    void (*__my_malloc_handler)();
    void *_result;
    for (;;)
    {
        __my_malloc_handler = __malloc_alloc_oom_handler;
        if (__null == __my_malloc_handler)
            __THROW_BAD_ALLOC;
        (*__my_malloc_handler)();
        _result = malloc(_n);
        if (_result)
            return (_result);
    }
}

template <int __inst>
void *__malloc_alloc_template<__inst>::_S_oom_realloc(void *_p, size_t _n)
{
    void (*__my_malloc_handler)();
    void *_result;
    for (;;)
    {
        __my_malloc_handler = __malloc_alloc_oom_handler;
        if (__null == __my_malloc_handler)
            __THROW_BAD_ALLOC;
        (*__my_malloc_handler)();
        _result = realloc(_p, _n);
        if (_result)
            return (_result);
    }
}

typedef __malloc_alloc_template<0> malloc_alloc;

template <class _Tp, class _Alloc>
class simple_alloc
{

public:
    static _Tp *allocate(size_t _n)
    {
        return 0 == _n ? 0 : (_Tp *)_Alloc::allocate(_n * sizeof(_Tp));
    }
    static _Tp *allocate(void)
    {
        return (_Tp *)_Alloc::allocate(sizeof(_Tp));
    }
    static void deallocate(_Tp *_p, size_t _n)
    {
        if (0 != _n)
            _Alloc::deallocate(_p, _n * sizeof(_Tp));
    }
    static void deallocate(_Tp *_p)
    {
        _Alloc::deallocate(_p, sizeof(_Tp));
    }
};

// Allocator adaptor to check size arguments for debugging.
// Reports errors using assert.  Checking can be disabled with
// NDEBUG, but it's far better to just use the underlying allocator
// instead when no checking is desired.
// There is some evidence that this can confuse Purify.
template <class _Alloc>
class debug_alloc
{

private:
    enum
    {
        _S_extra = 8
    };  // Size of space used to store size.  Note
        // that this must be large enough to preserve
        // alignment.

public:
    static void *allocate(size_t _n)
    {
        char *_result = (char *)_Alloc::allocate(_n + (int)_S_extra);
        *(size_t *)_result = _n;
        return _result + (int)_S_extra;
    }

    static void deallocate(void *_p, size_t _n)
    {
        char *__real_p = (char *)_p - (int)_S_extra;
        assert(*(size_t *)__real_p == _n);
        _Alloc::deallocate(__real_p, _n + (int)_S_extra);
    }

    static void *reallocate(void *_p, size_t _old_sz, size_t _new_sz)
    {
        char *__real_p = (char *)_p - (int)_S_extra;
        assert(*(size_t *)__real_p == _old_sz);
        char *_result = (char *)
            _Alloc::reallocate(__real_p, _old_sz + (int)_S_extra,
                               _new_sz + (int)_S_extra);
        *(size_t *)_result = _new_sz;
        return _result + (int)_S_extra;
    }
};

#ifdef __USE_MALLOC

typedef malloc_alloc alloc;
typedef malloc_alloc single_client_alloc;

#else

// Default node allocator.
// With a reasonable compiler, this should be roughly as fast as the
// original DST class-specific allocators, but with less fragmentation.
// Default_alloc_template parameters are experimental and MAY
// DISAPPEAR in the future.  Clients should just use alloc for now.
//
// Important implementation properties:
// 1. If the client request an object of size > _MAX_BYTES, the resulting
//    object will be obtained directly from malloc.
// 2. In all other cases, we allocate an object of size exactly
//    _S_round_up(requested_size).  Thus the client has enough size
//    information that we can return the object to the proper free list
//    without permanently losing part of the object.
//

// The first template parameter specifies whether more than one thread
// may use this allocator.  It is safe to allocate an object from
// one instance of a default_alloc and deallocate it with another
// one.  This effectively transfers its ownership to the second one.
// This may have undesirable effects on reference locality.
// The second parameter is unreferenced and serves only to allow the
// creation of multiple default_alloc instances.
// Node that containers built on different allocator instances have
// different types, limiting the utility of this approach.

#if defined(__SUNPRO_CC) || defined(__GNUC__)
// breaks if we make these template class members:
enum
{
    _ALIGN = 8
};
enum
{
    _MAX_BYTES = 128
};
enum
{
    _NFREELISTS = 16
}; // _MAX_BYTES/_ALIGN
#endif

template <bool threads, int inst>
class __default_alloc_template
{

private:
    // Really we should use static const int x = N
    // instead of enum { x = N }, but few compilers accept the former.
#if !(defined(__SUNPRO_CC) || defined(__GNUC__))
    enum
    {
        _ALIGN = 8
    };
    enum
    {
        _MAX_BYTES = 128
    };
    enum
    {
        _NFREELISTS = 16
    }; // _MAX_BYTES/_ALIGN
#endif
    static inline size_t _S_round_up(size_t _bytes) // Adjust to multiples of 8 bytes
    {
        return (((_bytes) + (size_t)_ALIGN - 1) & ~((size_t)_ALIGN - 1));
    }

    __PRIVATE : union _Obj {
        union _Obj *_Next_free_list_link;
        char _M_client_data[1];
    };

private:
#if defined(__SUNPRO_CC) || defined(__GNUC__) || defined(__HP_aCC)
    static _Obj *__DST_VOLATILE _S_free_list[];
    // Specifying a size results in duplicate def for 4.1
#else
    static _Obj *__DST_VOLATILE _S_free_list[_NFREELISTS];
#endif
    static inline size_t _S_freelist_index(size_t _bytes)
    {
        return ((_bytes) + (size_t)_ALIGN - 1) / (size_t)_ALIGN - 1;
    }

    // Returns an object of size _n, and optionally adds to size _n free list.
    static void *_S_refill(size_t _n);

    // Allocates a chunk for nobjs of size size.  nobjs may be reduced
    // if it is inconvenient to allocate the requested number.
    static char *_S_chunk_alloc(size_t __size, int &_nobjs);

    // Chunk allocation state.
    static char *_S_start_free;
    static char *_S_end_free;
    static size_t _S_heap_size;

#ifdef __DST_THREADS
    static _DST_mutex_lock _S_node_allocator_lock;
#endif

    // It would be nice to use _DST_auto_lock here.  But we
    // don't need the NULL check.  And we do need a test whether
    // threads have actually been started.
    class _Lock;
    friend class _Lock;
    class _Lock
    {
    public:
        _Lock() { __NODE_ALLOCATOR_LOCK; }
        ~_Lock() { __NODE_ALLOCATOR_UNLOCK; }
    };

public:
    /* _n must be > 0      */
    static void *allocate(size_t _n)
    {
        void *_ret = __null;

        if (_n > (size_t)_MAX_BYTES)
        {
            _ret = malloc_alloc::allocate(_n);
        }
        else
        {
            _Obj *__DST_VOLATILE *_my_free_list = _S_free_list + _S_freelist_index(_n);
            // Acquire the lock here with a constructor call.
            // This ensures that it is released in exit or during stack
            // unwinding.
#ifndef _NOTHREADS
            /*REFERENCED*/
            _Lock __lock_instance;
#endif
            _Obj *__RESTRICT _result = *_my_free_list;
            if (_result == __null)
                _ret = _S_refill(_S_round_up(_n));
            else
            {
                *_my_free_list = _result->_Next_free_list_link;
                _ret = _result;
            }
        }
        return _ret;
    };

    /* _p may not be __null */
    static void deallocate(void *_p, size_t _n)
    {
        if (_n > (size_t)_MAX_BYTES)
            malloc_alloc::deallocate(_p, _n);
        else
        {
            _Obj *__DST_VOLATILE *_my_free_list = _S_free_list + _S_freelist_index(_n);
            _Obj *_q = (_Obj *)_p;

            // acquire lock
#ifndef _NOTHREADS
            /*REFERENCED*/
            _Lock __lock_instance;
#endif /* _NOTHREADS */
            _q->_Next_free_list_link = *_my_free_list;
            *_my_free_list = _q;
            // lock is released here
        }
    }

    static void *reallocate(void *_p, size_t _old_sz, size_t _new_sz);

};

typedef __default_alloc_template<__NODE_ALLOCATOR_THREADS, 0> alloc;
typedef __default_alloc_template<false, 0> single_client_alloc;

template <bool __threads, int __inst>
inline bool operator==(const __default_alloc_template<__threads, __inst> &, const __default_alloc_template<__threads, __inst> &)
{
    return true;
}

#ifdef __DST_FUNCTION_TMPL_PARTIAL_ORDER
template <bool __threads, int __inst>
inline bool operator!=(const __default_alloc_template<__threads, __inst> &, const __default_alloc_template<__threads, __inst> &)
{
    return false;
}
#endif /* __DST_FUNCTION_TMPL_PARTIAL_ORDER */

// We allocate memory in large chunks in order to avoid fragmenting
// the malloc heap too much.
// We assume that size is properly aligned.
// We hold the allocation lock.
template <bool __threads, int __inst>
char *__default_alloc_template<__threads, __inst>::_S_chunk_alloc(size_t __size, int &_nobjs)
{
    char *_result;
    size_t __total_bytes = __size * _nobjs;
    size_t _bytes_left = _S_end_free - _S_start_free;

    if (_bytes_left >= __total_bytes)
    {
        _result = _S_start_free;
        _S_start_free += __total_bytes;
        return (_result);
    }
    else if (_bytes_left >= __size)
    {
        _nobjs = (int)(_bytes_left / __size);
        __total_bytes = __size * _nobjs;
        _result = _S_start_free;
        _S_start_free += __total_bytes;
        return (_result);
    }
    else
    {
        size_t _bytes_to_get =
            2 * __total_bytes + _S_round_up(_S_heap_size >> 4);
        // Try to make use of the left-over piece.
        if (_bytes_left > 0)
        {
            _Obj *__DST_VOLATILE *_my_free_list =
                _S_free_list + _S_freelist_index(_bytes_left);

            ((_Obj *)_S_start_free)->_Next_free_list_link = *_my_free_list;
            *_my_free_list = (_Obj *)_S_start_free;
        }
        _S_start_free = (char *)malloc(_bytes_to_get);
        if (0 == _S_start_free)
        {
            size_t _i;
            _Obj *__DST_VOLATILE *_my_free_list;
            _Obj *_p;
            // Try to make do with what we have.  That can't
            // hurt.  We do not try smaller requests, since that tends
            // to result in disaster on multi-process machines.
            for (_i = __size;
                 _i <= (size_t)_MAX_BYTES;
                 _i += (size_t)_ALIGN)
            {
                _my_free_list = _S_free_list + _S_freelist_index(_i);
                _p = *_my_free_list;
                if (0 != _p)
                {
                    *_my_free_list = _p->_Next_free_list_link;
                    _S_start_free = (char *)_p;
                    _S_end_free = _S_start_free + _i;
                    return (_S_chunk_alloc(__size, _nobjs));
                    // Any leftover piece will eventually make it to the
                    // right free list.
                }
            }
            _S_end_free = 0; // In case of exception.
            _S_start_free = (char *)malloc_alloc::allocate(_bytes_to_get);
            // This should either throw an
            // exception or remedy the situation.  Thus we assume it
            // succeeded.
        }
        _S_heap_size += _bytes_to_get;
        _S_end_free = _S_start_free + _bytes_to_get;
        return (_S_chunk_alloc(__size, _nobjs));
    }
}

/* Returns an object of size _n, and optionally adds to size _n free list.*/
/* We assume that _n is properly aligned.                                */
/* We hold the allocation lock.                                         */
template <bool __threads, int __inst>
void *__default_alloc_template<__threads, __inst>::_S_refill(size_t _n)
{
    int _nobjs = 20;
    char *_chunk = _S_chunk_alloc(_n, _nobjs);
    _Obj *__DST_VOLATILE *_my_free_list,
        *_result,
        *_current_obj,
        *_next_obj;
    int _i;

    if (1 == _nobjs)
        return _chunk;

    _my_free_list = _S_free_list + _S_freelist_index(_n);

    // Build free list in chunk
    _result = (_Obj *)_chunk;
    *_my_free_list = _next_obj = (_Obj *)(_chunk + _n);
    for (_i = 2;; _i++)
    {
        _current_obj = _next_obj;
        _next_obj = (_Obj *)((char *)_next_obj + _n);
        if (_nobjs == _i)
        {
            _current_obj->_Next_free_list_link = __null;
            break;
        }
        else
        {
            _current_obj->_Next_free_list_link = _next_obj;
        }
    }
    return _result;
}

template <bool threads, int inst>
void *__default_alloc_template<threads, inst>::reallocate(void *_p, size_t _old_sz, size_t _new_sz)
{
    void *_result;
    size_t __copy_sz;

    if (_old_sz > (size_t)_MAX_BYTES && _new_sz > (size_t)_MAX_BYTES)
    {
        return (realloc(_p, _new_sz));
    }
    if (_S_round_up(_old_sz) == _S_round_up(_new_sz))
        return (_p);
    _result = allocate(_new_sz);
    __copy_sz = _new_sz > _old_sz ? _old_sz : _new_sz;
    memcpy(_result, _p, __copy_sz);
    deallocate(_p, _old_sz);
    return (_result);
}

#ifdef __DST_THREADS
template <bool __threads, int __inst>
_DST_mutex_lock
    __default_alloc_template<__threads, __inst>::_S_node_allocator_lock
        __DST_MUTEX_INITIALIZER;
#endif

template <bool __threads, int __inst>
char *__default_alloc_template<__threads, __inst>::_S_start_free = __null;

template <bool __threads, int __inst>
char *__default_alloc_template<__threads, __inst>::_S_end_free = __null;

template <bool __threads, int __inst>
size_t __default_alloc_template<__threads, __inst>::_S_heap_size = 0;

template <bool __threads, int __inst>
typename __default_alloc_template<__threads, __inst>::_Obj *__DST_VOLATILE
    __default_alloc_template<__threads, __inst>::_S_free_list[
#if defined(__SUNPRO_CC) || defined(__GNUC__) || defined(__HP_aCC)
        _NFREELISTS
#else
        __default_alloc_template<__threads, __inst>::_NFREELISTS
#endif
] = {
        __null,
        __null,
        __null,
        __null,
        __null,
        __null,
        __null,
        __null,
        __null,
        __null,
        __null,
        __null,
        __null,
        __null,
        __null,
        __null,
};
// The 16 zeros are necessary to make version 4.1 of the SunPro
// compiler happy.  Otherwise it appears to allocate too little
// space for the array.

#endif /* ! __USE_MALLOC */

// This implements allocators as specified in the C++ standard.
//
// Note that standard-conforming allocators use many language features
// that are not yet widely implemented.  In particular, they rely on
// member templates, partial specialization, partial ordering of function
// templates, the typename keyword, and the use of the template keyword
// to refer to a template member of a dependent type.

#ifdef __DST_USE_DSA_ALLOCATORS

template <class _Tp>
class allocator
{
    typedef alloc _Alloc; // The underlying allocator.
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef _Tp *pointer;
    typedef const _Tp *const_pointer;
    typedef _Tp &reference;
    typedef const _Tp &const_reference;
    typedef _Tp value_type;

    template <class _Tp1>
    struct rebind
    {
        typedef allocator<_Tp1> other;
    };

    allocator() __DST_NOTHROW {}
    allocator(const allocator &) __DST_NOTHROW {}
    template <class _Tp1>
    allocator(const allocator<_Tp1> &) __DST_NOTHROW {}
    ~allocator() __DST_NOTHROW {}

    pointer address(reference __x) const { return &__x; }
    const_pointer address(const_reference __x) const { return &__x; }

    // _n is permitted to be 0.  The C++ standard says nothing about what
    // the return value is when _n == 0.
    _Tp *allocate(size_type _n, const void * = 0)
    {
        return _n != 0 ? static_cast<_Tp *>(_Alloc::allocate(_n * sizeof(_Tp)))
                        : 0;
    }

    // _p is not permitted to be a null pointer.
    void deallocate(pointer _p, size_type _n)
    {
        _Alloc::deallocate(_p, _n * sizeof(_Tp));
    }

    size_type max_size() const __DST_NOTHROW
    {
        return size_t(-1) / sizeof(_Tp);
    }

    void construct(pointer _p, const _Tp &__val) { new (_p) _Tp(__val); }
    void destroy(pointer _p) { _p->~_Tp(); }
};

template <>
class allocator<void>
{
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef void *pointer;
    typedef const void *const_pointer;
    typedef void value_type;

    template <class _Tp1>
    struct rebind
    {
        typedef allocator<_Tp1> other;
    };
};

template <class _T1, class _T2>
inline bool operator==(const allocator<_T1> &, const allocator<_T2> &)
{
    return true;
}

template <class _T1, class _T2>
inline bool operator!=(const allocator<_T1> &, const allocator<_T2> &)
{
    return false;
}

// Allocator adaptor to turn an -style allocator (e.g. alloc, malloc_alloc)
// into a standard-conforming allocator.   Note that this adaptor does
// *not* assume that all objects of the underlying alloc class are
// identical, nor does it assume that all of the underlying alloc's
// member functions are static member functions.  Note, also, that
// __allocator<_Tp, alloc> is essentially the same thing as allocator<_Tp>.

template <class _Tp, class _Alloc>
struct __allocator
{
    _Alloc __underlying_alloc;

    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef _Tp *pointer;
    typedef const _Tp *const_pointer;
    typedef _Tp &reference;
    typedef const _Tp &const_reference;
    typedef _Tp value_type;

    template <class _Tp1>
    struct rebind
    {
        typedef __allocator<_Tp1, _Alloc> other;
    };

    __allocator() __DST_NOTHROW {}
    __allocator(const __allocator &__a) __DST_NOTHROW
        : __underlying_alloc(__a.__underlying_alloc) {}
    template <class _Tp1>
    __allocator(const __allocator<_Tp1, _Alloc> &__a) __DST_NOTHROW
        : __underlying_alloc(__a.__underlying_alloc) {}
    ~__allocator() __DST_NOTHROW {}

    pointer address(reference __x) const { return &__x; }
    const_pointer address(const_reference __x) const { return &__x; }

    // _n is permitted to be 0.
    _Tp *allocate(size_type _n, const void * = 0)
    {
        return _n != 0
                   ? static_cast<_Tp *>(__underlying_alloc.allocate(_n * sizeof(_Tp)))
                   : 0;
    }

    // _p is not permitted to be a null pointer.
    void deallocate(pointer _p, size_type _n)
    {
        __underlying_alloc.deallocate(_p, _n * sizeof(_Tp));
    }

    size_type max_size() const __DST_NOTHROW
    {
        return size_t(-1) / sizeof(_Tp);
    }

    void construct(pointer _p, const _Tp &__val) { new (_p) _Tp(__val); }
    void destroy(pointer _p) { _p->~_Tp(); }
};

template <class _Alloc>
class __allocator<void, _Alloc>
{
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef void *pointer;
    typedef const void *const_pointer;
    typedef void value_type;

    template <class _Tp1>
    struct rebind
    {
        typedef __allocator<_Tp1, _Alloc> other;
    };
};

template <class _Tp, class _Alloc>
inline bool operator==(const __allocator<_Tp, _Alloc> &__a1,
                       const __allocator<_Tp, _Alloc> &__a2)
{
    return __a1.__underlying_alloc == __a2.__underlying_alloc;
}

#ifdef __DST_FUNCTION_TMPL_PARTIAL_ORDER
template <class _Tp, class _Alloc>
inline bool operator!=(const __allocator<_Tp, _Alloc> &__a1,
                       const __allocator<_Tp, _Alloc> &__a2)
{
    return __a1.__underlying_alloc != __a2.__underlying_alloc;
}
#endif /* __DST_FUNCTION_TMPL_PARTIAL_ORDER */

// Comparison operators for all of the predifined -style allocators.
// This ensures that __allocator<malloc_alloc> (for example) will
// work correctly.

template <int inst>
inline bool operator==(const __malloc_alloc_template<inst> &,
                       const __malloc_alloc_template<inst> &)
{
    return true;
}

#ifdef __DST_FUNCTION_TMPL_PARTIAL_ORDER
template <int __inst>
inline bool operator!=(const __malloc_alloc_template<__inst> &,
                       const __malloc_alloc_template<__inst> &)
{
    return false;
}
#endif /* __DST_FUNCTION_TMPL_PARTIAL_ORDER */

template <class _Alloc>
inline bool operator==(const debug_alloc<_Alloc> &,
                       const debug_alloc<_Alloc> &)
{
    return true;
}

#ifdef __DST_FUNCTION_TMPL_PARTIAL_ORDER
template <class _Alloc>
inline bool operator!=(const debug_alloc<_Alloc> &,
                       const debug_alloc<_Alloc> &)
{
    return false;
}
#endif /* __DST_FUNCTION_TMPL_PARTIAL_ORDER */

// Another allocator adaptor: _Alloc_traits.  This serves two
// purposes.  First, make it possible to write containers that can use
// either -style allocators or standard-conforming allocator.
// Second, provide a mechanism so that containers can query whether or
// not the allocator has distinct instances.  If not, the container
// can avoid wasting a word of memory to store an empty object.

// This adaptor uses partial specialization.  The general case of
// _Alloc_traits<_Tp, _Alloc> assumes that _Alloc is a
// standard-conforming allocator, possibly with non-equal instances
// and non-static members.  (It still behaves correctly even if _Alloc
// has static member and if all instances are equal.  Refinements
// affect performance, not correctness.)

// There are always two members: allocator_type, which is a standard-
// conforming allocator type for allocating objects of type _Tp, and
// _S_instanceless, a static const member of type bool.  If
// _S_instanceless is true, this means that there is no difference
// between any two instances of type allocator_type.  Furthermore, if
// _S_instanceless is true, then _Alloc_traits has one additional
// member: _Alloc_type.  This type encapsulates allocation and
// deallocation of objects of type _Tp through a static interface; it
// has two member functions, whose signatures are
//    static _Tp* allocate(size_t)
//    static void deallocate(_Tp*, size_t)

// The fully general version.

template <class _Tp, class _Allocator>
struct _Alloc_traits
{
    static const bool _S_instanceless = false;
    typedef typename _Allocator::__DST_TEMPLATE rebind<_Tp>::other
        allocator_type;
};

template <class _Tp, class _Allocator>
const bool _Alloc_traits<_Tp, _Allocator>::_S_instanceless;

// The version for the default allocator.

template <class _Tp, class _Tp1>
struct _Alloc_traits<_Tp, allocator<_Tp1>>
{
    static const bool _S_instanceless = true;
    typedef simple_alloc<_Tp, alloc> _Alloc_type;
    typedef allocator<_Tp> allocator_type;
};

// Versions for the predefined -style allocators.

template <class _Tp, int __inst>
struct _Alloc_traits<_Tp, __malloc_alloc_template<__inst>>
{
    static const bool _S_instanceless = true;
    typedef simple_alloc<_Tp, __malloc_alloc_template<__inst>> _Alloc_type;
    typedef __allocator<_Tp, __malloc_alloc_template<__inst>> allocator_type;
};

template <class _Tp, bool __threads, int __inst>
struct _Alloc_traits<_Tp, __default_alloc_template<__threads, __inst>>
{
    static const bool _S_instanceless = true;
    typedef simple_alloc<_Tp, __default_alloc_template<__threads, __inst>>
        _Alloc_type;
    typedef __allocator<_Tp, __default_alloc_template<__threads, __inst>>
        allocator_type;
};

template <class _Tp, class _Alloc>
struct _Alloc_traits<_Tp, debug_alloc<_Alloc>>
{
    static const bool _S_instanceless = true;
    typedef simple_alloc<_Tp, debug_alloc<_Alloc>> _Alloc_type;
    typedef __allocator<_Tp, debug_alloc<_Alloc>> allocator_type;
};

// Versions for the __allocator adaptor used with the predefined
// -style allocators.

template <class _Tp, class _Tp1, int __inst>
struct _Alloc_traits<_Tp,
                     __allocator<_Tp1, __malloc_alloc_template<__inst>>>
{
    static const bool _S_instanceless = true;
    typedef simple_alloc<_Tp, __malloc_alloc_template<__inst>> _Alloc_type;
    typedef __allocator<_Tp, __malloc_alloc_template<__inst>> allocator_type;
};

template <class _Tp, class _Tp1, bool __thr, int __inst>
struct _Alloc_traits<_Tp,
                     __allocator<_Tp1,
                                 __default_alloc_template<__thr, __inst>>>
{
    static const bool _S_instanceless = true;
    typedef simple_alloc<_Tp, __default_alloc_template<__thr, __inst>>
        _Alloc_type;
    typedef __allocator<_Tp, __default_alloc_template<__thr, __inst>>
        allocator_type;
};

template <class _Tp, class _Tp1, class _Alloc>
struct _Alloc_traits<_Tp, __allocator<_Tp1, debug_alloc<_Alloc>>>
{
    static const bool _S_instanceless = true;
    typedef simple_alloc<_Tp, debug_alloc<_Alloc>> _Alloc_type;
    typedef __allocator<_Tp, debug_alloc<_Alloc>> allocator_type;
};

#endif /* __DST_USE_DSA_ALLOCATORS */

#if defined(__sgi) && !defined(__GNUC__) && (_MIPS_SIM != _MIPS_SIM_ABI32)
#pragma reset woff 1174
#endif

__DST_END_NAMESPACE

#undef __PRIVATE

#endif /* ___DST_INTERNAL_ALLOC_H */