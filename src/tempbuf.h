#ifndef ___DST_TEMPBUF_H
#define ___DST_TEMPBUF_H

#ifndef ___DST_PAIR_H
#include "pair.h"
#endif
#include <limits.h> /* XXX should use <climits> */
#include <stddef.h> /* XXX should use <cstddef> */
#include <stdlib.h> /* XXX should use <cstdlib> */
#include "type_traits.h"
#include "dst_construct.h"
#include "dst_uninitialized.h"
#include "dst_tempbuf.h"

#ifdef __DST_USE_NAMESPACES

using __VDSA::get_temporary_buffer;
using __VDSA::return_temporary_buffer;
using __VDSA::temporary_buffer;

#endif /* __DST_USE_NAMESPACES */

#endif /* ___DST_TEMPBUF_H */