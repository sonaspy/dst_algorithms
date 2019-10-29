
#ifndef ___DST_ALLOC_H
#define ___DST_ALLOC_H

#ifndef __DST_CONFIG_H
#include "config.hpp"
#endif
#ifndef ___DST_INTERNAL_ALLOC_H
#include "dst_alloc.cc"
#endif

#ifdef __DST_USE_NAMESPACES

using __VDSA::__default_alloc_template;
using __VDSA::__malloc_alloc_template;
using __VDSA::alloc;
using __VDSA::debug_alloc;
using __VDSA::malloc_alloc;
using __VDSA::simple_alloc;
using __VDSA::single_client_alloc;
#ifdef __DST_STATIC_TEMPLATE_MEMBER_BUG
using __VDSA::__malloc_alloc_oom_handler;
#endif /* __DST_STATIC_TEMPLATE_MEMBER_BUG */
#ifdef __DST_USE_DSA_ALLOCATORS
using __VDSA::allocator;
#endif /* __DST_USE_DSA_ALLOCATORS */

#endif /* __DST_USE_NAMESPACES */

#endif /* ___DST_ALLOC_H */
