

#ifndef ___DST_EXCEPTION_H
#define ___DST_EXCEPTION_H

// This header exists solely for portability.  Normally it just includes
// the header <exception>.

// The header <exception> contains low-level functions that interact
// with a compiler's exception-handling mechanism.  It is assumed to
// be supplied with the compiler, rather than with the library, because
// it is inherently tied very closely to the compiler itself.

// On platforms where <exception> does not exist, this header defines
// an exception base class.  This is *not* a substitute for everything
// in <exception>, but it suffices to support a bare minimum of DST
// functionality.

#include "dst_config.h"

#ifndef __DST_NO_EXCEPTION_HEADER

#include <exception>
#define __DST_EXCEPTION_BASE exception

#else /* __DST_NO_EXCEPTION_HEADER */

__DST_BEGIN_NAMESPACE

class _Exception
{
public:
    virtual ~_Exception() __DST_NOTHROW {}
    virtual const char *what() const __DST_NOTHROW { return ""; }
};

#define __DST_EXCEPTION_BASE _Exception

__DST_END_NAMESPACE

#endif /* __DST_NO_EXCEPTION_HEADER */

#endif /* ___DST_EXCEPTION_H */

