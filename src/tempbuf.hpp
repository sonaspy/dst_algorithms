#ifndef ___DST_TEMPBUF_H
#define ___DST_TEMPBUF_H

#ifndef ___DST_PAIR_H
#include "pair.hpp"
#endif
#include <limits.h> /* XXX should use <climits> */
#include <stddef.h> /* XXX should use <cstddef> */
#include <stdlib.h> /* XXX should use <cstdlib> */
#include "type_traits.hpp"
#include "dst_construct.hpp"
#include "dst_uninitialized.hpp"
#include "dst_tempbuf.hpp"

#ifdef __DST_USE_NAMESPACES

using __VDSA::get_temporary_buffer;
using __VDSA::return_temporary_buffer;
using __VDSA::temporary_buffer;

#endif /* __DST_USE_NAMESPACES */

#endif /* ___DST_TEMPBUF_H */