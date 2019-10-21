
#ifndef __DST_RANGE_ERRORS_H
#define __DST_RANGE_ERRORS_H

// A few places in the DST throw range errors, using standard exception
// classes defined in <stdexcept>.  This header file provides functions
// to throw those exception objects.

// __DST_DONT_THROW_RANGE_ERRORS is a hook so that users can disable
// this exception throwing.

#include "dst_config.h"

#if defined(__DST_CAN_THROW_RANGE_ERRORS) && \
    defined(__DST_USE_EXCEPTIONS) &&         \
    !defined(__DST_DONT_THROW_RANGE_ERRORS)
#define __DST_THROW_RANGE_ERRORS
#endif

#if defined(__DST_THROW_RANGE_ERRORS) &&    \
    defined(__sgi) && !defined(__GNUC__) && \
    _COMPILER_VERSION >= 730 && defined(_STANDARD_C_PLUS_PLUS)

__DST_BEGIN_NAMESPACE
void __dst_throw_range_error(const char *__msg);
void __dst_throw_length_error(const char *__msg);
__DST_END_NAMESPACE

// For other compilers where we're throwing range errors, include the
// stdexcept header and throw the appropriate exceptions directly.
#elif defined(__DST_THROW_RANGE_ERRORS)

#include <stdexcept>

__DST_BEGIN_NAMESPACE
inline void __dst_throw_range_error(const char *__msg)
{
    throw range_error(__msg);
}
inline void __dst_throw_length_error(const char *__msg)
{
    throw length_error(__msg);
}
__DST_END_NAMESPACE

// Otherwise, define inline functions that do nothing.
#else

__DST_BEGIN_NAMESPACE
inline void __dst_throw_range_error(const char *) {}
inline void __dst_throw_length_error(const char *) {}
__DST_END_NAMESPACE

#endif

#endif /* __DST_RANGE_ERRORS_H */
