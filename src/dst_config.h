
#ifndef __DST_CONFIG_H
#define __DST_CONFIG_H

#if defined(_PTHREADS) && !defined(_NOTHREADS)
#define __DST_PTHREADS
#endif

#if defined(_UITHREADS) && !defined(_PTHREADS) && !defined(_NOTHREADS)
#define __DST_UITHREADS
#endif

#if defined(__sgi) && !defined(__GNUC__)
#include <standards.h>
#if !defined(_BOOL)
#define __DST_NO_BOOL
#endif
#if defined(_MIPS_SIM) && _MIPS_SIM == _ABIO32
#define __DST_STATIC_CONST_INIT_BUG
#endif
#if defined(_WCHAR_T_IS_KEYWORD)
#define __DST_HAS_WCHAR_T
#endif
#if !defined(_TYPENAME_IS_KEYWORD)
#define __DST_NEED_TYPENAME
#endif
#ifdef _PARTIAL_SPECIALIZATION_OF_CLASS_TEMPLATES
#define __DST_CLASS_PARTIAL_SPECIALIZATION
#endif
#if (_COMPILER_VERSION >= 730) && defined(_MIPS_SIM) && _MIPS_SIM != _ABIO32
#define __DST_FUNCTION_TMPL_PARTIAL_ORDER
#endif
#ifdef _MEMBER_TEMPLATES
#define __DST_MEMBER_TEMPLATES
#define __DST_TEMPLATE_FRIENDS
#define __DST_MEMBER_TEMPLATE_CLASSES
#endif
#if defined(_MEMBER_TEMPLATE_KEYWORD)
#define __DST_MEMBER_TEMPLATE_KEYWORD
#endif
#if defined(_STANDARD_C_PLUS_PLUS)
#define __DST_EXPLICIT_FUNCTION_TMPL_ARGS
#endif
#if (_COMPILER_VERSION >= 730) && defined(_MIPS_SIM) && _MIPS_SIM != _ABIO32
#define __DST_MEMBER_TEMPLATE_KEYWORD
#endif
#if COMPILER_VERSION < 720 || (defined(_MIPS_SIM) && _MIPS_SIM == _ABIO32)
#define __DST_DEFAULT_CONSTRUCTOR_BUG
#endif
#if !defined(_EXPLICIT_IS_KEYWORD)
#define __DST_NEED_EXPLICIT
#endif
#ifdef __EXCEPTIONS
#define __DST_USE_EXCEPTIONS
#endif
#if (_COMPILER_VERSION >= 721) && defined(_NAMESPACES)
#define __DST_HAS_NAMESPACES
#endif
#if (_COMPILER_VERSION < 721) || \
    !defined(__DST_HAS_NAMESPACES) || defined(__DST_NO_NAMESPACES)
#define __DST_NO_EXCEPTION_HEADER
#endif
#if _COMPILER_VERSION < 730 || !defined(_STANDARD_C_PLUS_PLUS) || \
    !defined(_NAMESPACES)
#define __DST_NO_BAD_ALLOC
#endif
#if !defined(_NOTHREADS) && !defined(__DST_PTHREADS)
#define __DST__THREADS
#endif
#if defined(_LONGLONG) && defined(_API) && _API
#define __DST_LONG_LONG
#endif
#if _COMPILER_VERSION >= 730 && defined(_STANDARD_C_PLUS_PLUS)
#define __DST_USE_NEW_IOSTREAMS
#endif
#if _COMPILER_VERSION >= 730 && defined(_STANDARD_C_PLUS_PLUS)
#define __DST_CAN_THROW_RANGE_ERRORS
#endif
#if _COMPILER_VERSION >= 730 && defined(_STANDARD_C_PLUS_PLUS)
#define ___DST_USE_AUTO_PTR_CONVERSIONS
#endif
#endif

// SCO UDK 7 compiler (UnixWare 7x, OSR 5, UnixWare 2x)
#if defined(__USLC__)
#define __DST_HAS_WCHAR_T
#define __DST_CLASS_PARTIAL_SPECIALIZATION
#define __DST_PARTIAL_SPECIALIZATION_SYNTAX
#define __DST_FUNCTION_TMPL_PARTIAL_ORDER
#define __DST_MEMBER_TEMPLATES
#define __DST_MEMBER_TEMPLATE_CLASSES
#define __DST_USE_EXCEPTIONS
#define __DST_HAS_NAMESPACES
#define __DST_USE_NAMESPACES
#define __DST_LONG_LONG
#if defined(_REENTRANT)
#define _UITHREADS /* if      UnixWare < 7.0.1 */
#define __DST_UITHREADS
//   use the following defines instead of the UI threads defines when
//   you want to use POSIX threads
//#         define _PTHREADS      /* only if UnixWare >=7.0.1 */
//#         define __DST_PTHREADS
#endif
#endif

#ifdef __GNUC__
#if __GNUC__ == 2 && __GNUC_MINOR__ <= 7
#define __DST_STATIC_TEMPLATE_MEMBER_BUG
#endif
#if __GNUC__ < 2
#define __DST_NEED_TYPENAME
#define __DST_NEED_EXPLICIT
#endif
#if __GNUC__ == 2 && __GNUC_MINOR__ <= 8
#define __DST_NO_EXCEPTION_HEADER
#define __DST_NO_BAD_ALLOC
#endif
#if __GNUC__ == 2 && __GNUC_MINOR__ >= 8
#define __DST_CLASS_PARTIAL_SPECIALIZATION
#define __DST_FUNCTION_TMPL_PARTIAL_ORDER
#define __DST_EXPLICIT_FUNCTION_TMPL_ARGS
#define __DST_MEMBER_TEMPLATES
#define __DST_CAN_THROW_RANGE_ERRORS
//    g++ 2.8.1 supports member template functions, but not member
//    template nested classes.
#if __GNUC_MINOR__ >= 9
#define __DST_MEMBER_TEMPLATE_CLASSES
#define __DST_TEMPLATE_FRIENDS
#define ___DST_USE_AUTO_PTR_CONVERSIONS
#define __DST_HAS_NAMESPACES
//#       define __DST_USE_NEW_IOSTREAMS
#endif
#endif
#define __DST_DEFAULT_CONSTRUCTOR_BUG
#ifdef __EXCEPTIONS
#define __DST_USE_EXCEPTIONS
#endif
#ifdef _REENTRANT
#define __DST_PTHREADS
#endif
#if (__GNUC__ < 2) || (__GNUC__ == 2 && __GNUC_MINOR__ < 95)
#define __DST_NO_FUNCTION_PTR_IN_CLASS_TEMPLATE
#endif
#endif

#if defined(__SUNPRO_CC)
#define __DST_NO_BOOL
#define __DST_NEED_TYPENAME
#define __DST_NEED_EXPLICIT
#define __DST_USE_EXCEPTIONS
#ifdef _REENTRANT
#define __DST_PTHREADS
#endif
#define ___DST_NO_ARROW_OPERATOR
#define __DST_PARTIAL_SPECIALIZATION_SYNTAX
#define __DST_NO_EXCEPTION_HEADER
#define __DST_NO_BAD_ALLOC
#endif

#if defined(__COMO__)
#define __DST_MEMBER_TEMPLATES
#define __DST_MEMBER_TEMPLATE_CLASSES
#define __DST_TEMPLATE_FRIENDS
#define __DST_CLASS_PARTIAL_SPECIALIZATION
#define __DST_USE_EXCEPTIONS
#define __DST_HAS_NAMESPACES
#endif

// Intel compiler, which uses the EDG front end.
#if defined(__ICL)
#define __DST_LONG_LONG
#define __DST_MEMBER_TEMPLATES
#define __DST_MEMBER_TEMPLATE_CLASSES
#define __DST_TEMPLATE_FRIENDS
#define __DST_FUNCTION_TMPL_PARTIAL_ORDER
#define __DST_CLASS_PARTIAL_SPECIALIZATION
#define __DST_NO_DRAND48
#define __DST_HAS_NAMESPACES
#define __DST_USE_EXCEPTIONS
#define __DST_MEMBER_TEMPLATE_KEYWORD
#ifdef _CPPUNWIND
#define __DST_USE_EXCEPTIONS
#endif
#ifdef _MT
#define __DST_WIN32THREADS
#endif
#endif

// Mingw32, egcs compiler using the Microsoft C runtime
#if defined(__MINGW32__)
#define __DST_NO_DRAND48
#ifdef _MT
#define __DST_WIN32THREADS
#endif
#endif

// Cygwin32, egcs compiler on MS Windows
#if defined(__CYGWIN__)
#define __DST_NO_DRAND48
#endif

// Microsoft compiler.
#if defined(_MSC_VER) && !defined(__ICL) && !defined(__MWERKS__)
#define __DST_NO_DRAND48
#define __DST_STATIC_CONST_INIT_BUG
#define __DST_NEED_TYPENAME
#define __DST_NO_USING_CLAUSE_IN_CLASS
#define __DST_NO_FRIEND_TEMPLATE_CLASS
#if _MSC_VER < 1100 /* 1000 is version 4.0, 1100 is 5.0, 1200 is 6.0. */
#define __DST_NEED_EXPLICIT
#define __DST_NO_BOOL
#define __DST_NO_BAD_ALLOC
#endif
#if _MSC_VER > 1000
#include <yvals.h>
#define __DST_DONT_USE_BOOL_TYPEDEF
#endif
#define __DST_NON_TYPE_TMPL_PARAM_BUG
#define ___DST_NO_ARROW_OPERATOR
#define __DST_DEFAULT_CONSTRUCTOR_BUG
#ifdef _CPPUNWIND
#define __DST_USE_EXCEPTIONS
#endif
#ifdef _MT
#define __DST_WIN32THREADS
#endif
#if _MSC_VER >= 1200
#define __DST_PARTIAL_SPECIALIZATION_SYNTAX
#define __DST_HAS_NAMESPACES
#define __DST_CAN_THROW_RANGE_ERRORS
#define NOMINMAX
#undef min
#undef max
// disable warning 'initializers put in unrecognized initialization area'
#pragma warning(disable : 4075)
// disable warning 'empty controlled statement found'
#pragma warning(disable : 4390)
// disable warning 'debug symbol greater than 255 chars'
#pragma warning(disable : 4786)
#endif
#if _MSC_VER < 1100
#define __DST_NO_EXCEPTION_HEADER
#define __DST_NO_BAD_ALLOC
#endif
// Because of a Microsoft front end bug, we must not provide a
// namespace qualifier when declaring a friend function.
#define __DSA_QUALIFIER
#endif

#if defined(__BORLANDC__)
#define __DST_NO_BAD_ALLOC
#define __DST_NO_DRAND48
#define __DST_DEFAULT_CONSTRUCTOR_BUG
#if __BORLANDC__ >= 0x540 /* C++ Builder 4.0 */
#define __DST_CLASS_PARTIAL_SPECIALIZATION
#define __DST_FUNCTION_TMPL_PARTIAL_ORDER
#define __DST_EXPLICIT_FUNCTION_TMPL_ARGS
#define __DST_MEMBER_TEMPLATES
#define __DST_TEMPLATE_FRIENDS
#else
#define __DST_NEED_TYPENAME
#define __DST_LIMITED_DEFAULT_TEMPLATES
#define ___DST_NO_ARROW_OPERATOR
#define __DST_NON_TYPE_TMPL_PARAM_BUG
#endif
#ifdef _CPPUNWIND
#define __DST_USE_EXCEPTIONS
#endif
#ifdef __MT__
#define __DST_WIN32THREADS
#endif
#endif

#if defined(__DST_NO_BOOL) && !defined(__DST_DONT_USE_BOOL_TYPEDEF)
typedef int bool;
#define true 1
#define false 0
#endif

#ifdef __DST_NEED_TYPENAME
#define typename
#endif

#ifdef __DST_LIMITED_DEFAULT_TEMPLATES
#define __DST_DEPENDENT_DEFAULT_TMPL(_Tp)
#else
#define __DST_DEPENDENT_DEFAULT_TMPL(_Tp) = _Tp
#endif

#ifdef __DST_MEMBER_TEMPLATE_KEYWORD
#define __DST_TEMPLATE template
#else
#define __DST_TEMPLATE
#endif

#ifdef __DST_NEED_EXPLICIT
#define explicit
#endif

#ifdef __DST_EXPLICIT_FUNCTION_TMPL_ARGS
#define __DST_NULL_TMPL_ARGS <>
#else
#define __DST_NULL_TMPL_ARGS
#endif

#define __DST_TEMPLATE_NULL template <>

// Use standard-conforming allocators if we have the necessary language
// features.  __DST_USE__ALLOCATORS is a hook so that users can
// disable new-style allocators, and continue to use the same kind of
// allocators as before, without having to edit library headers.
#if defined(__DST_CLASS_PARTIAL_SPECIALIZATION) && \
    defined(__DST_MEMBER_TEMPLATES) &&             \
    defined(__DST_MEMBER_TEMPLATE_CLASSES) &&      \
    !defined(__DST_NO_BOOL) &&                     \
    !defined(__DST_NON_TYPE_TMPL_PARAM_BUG) &&     \
    !defined(__DST_LIMITED_DEFAULT_TEMPLATES) &&   \
    !defined(__DST_USE__ALLOCATORS)
#define __DST_USE_DSA_ALLOCATORS
#endif

#ifndef __DST_DEFAULT_ALLOCATOR
#ifdef __DST_USE_DSA_ALLOCATORS
#define __DST_DEFAULT_ALLOCATOR(T) allocator<T>
#else
#define __DST_DEFAULT_ALLOCATOR(T) alloc
#endif
#endif

// __DST_NO_NAMESPACES is a hook so that users can disable namespaces
// without having to edit library headers.  __DST_NO_RELOPS_NAMESPACE is
// a hook so that users can disable the dsa::rel_ops namespace, keeping
// the relational operator template in namespace dsa, without having to
// edit library headers.

#define __DST_USE_NAMESPACES
#define __DSA dsa
#define __DST_BEGIN_NAMESPACE \
    namespace dsa             \
    {
#define __DST_END_NAMESPACE }

#define __DST_USE_NAMESPACE_FOR_RELOPS
#define __DST_BEGIN_RELOPS_NAMESPACE \
    namespace dsa                    \
    {                                \
    namespace rel_ops                \
    {
#define __DST_END_RELOPS_NAMESPACE \
    }                              \
    }
#define __DSA_RELOPS dsa::rel_ops


// Some versions of the EDG front end sometimes require an explicit
// namespace spec where they shouldn't.  This macro facilitates that.
// If the bug becomes irrelevant, then all uses of __DSA_QUALIFIER
// should be removed.  The 7.3 beta  compiler has this bug, but the
// MR version is not expected to have it.

#if defined(__DST_USE_NAMESPACES) && !defined(__DSA_QUALIFIER)
#define __DSA_QUALIFIER dsa::
#else
#define __DSA_QUALIFIER
#endif

#ifdef __DST_USE_EXCEPTIONS

#define __DST_TRY try
#define __DST_CATCH_ALL catch (...)
#define __DST_THROW(x) throw x
#define __DST_RETHROW throw
#define __DST_NOTHROW throw()
#define __DST_UNWIND(action) \
    catch (...)              \
    {                        \
        action;              \
        throw;               \
    }

#else

#define __DST_TRY
#define __DST_CATCH_ALL if (false)
#define __DST_THROW(x)
#define __DST_RETHROW
#define __DST_NOTHROW
#define __DST_UNWIND(action)

#endif

#ifdef __DST_ASSERTIONS
#include <dsaio.h>
#define __dst_assert(expr)                                   \
    if (!(expr))                                             \
    {                                                        \
        fprintf(dsaerr, "%s:%d DST assertion failure: %s\n", \
                __FILE__, __LINE__, #expr);                  \
        abort();                                             \
    }
#else
#define __dst_assert(expr)
#endif

#if defined(__DST_WIN32THREADS) || defined(__DST__THREADS) || defined(__DST_PTHREADS) || defined(__DST_UITHREADS)
#define __DST_THREADS
#define __DST_VOLATILE volatile
#else
#define __DST_VOLATILE
#endif

#if defined(__DST_CLASS_PARTIAL_SPECIALIZATION) && defined(__DST_MEMBER_TEMPLATES) && !defined(_DST_NO_CONCEPT_CHECKS)
#define __DST_USE_CONCEPT_CHECKS
#endif

#endif /* __DST_CONFIG_H */


