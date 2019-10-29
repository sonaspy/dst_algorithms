#ifndef ___DST_FUNCTION_H
#define ___DST_FUNCTION_H

#ifndef __DST_CONFIG_H
#include "dst_config.hpp"
#endif
#ifndef ___DST_INTERNAL_RELOPS
#include "dst_relops.hpp"
#endif
#include <stddef.h>
#ifndef ___DST_INTERNAL_FUNCTION_H
#include "dst_function.hpp"
#endif

#ifdef __DST_USE_NAMESPACE_FOR_RELOPS

// Names from dst_relops.h
using __VDSA_RELOPS::operator!=;
using __VDSA_RELOPS::operator>;
using __VDSA_RELOPS::operator<=;
using __VDSA_RELOPS::operator>=;

#endif /* __DST_USE_NAMESPACE_FOR_RELOPS */

#ifdef __DST_USE_NAMESPACES

// Names from dst_function.h
using __VDSA::binary_compose;
using __VDSA::binary_function;
using __VDSA::binary_negate;
using __VDSA::bind1st;
using __VDSA::bind2nd;
using __VDSA::binder1st;
using __VDSA::binder2nd;
using __VDSA::compose1;
using __VDSA::compose2;
using __VDSA::const_mem_fun1_ref_t;
using __VDSA::const_mem_fun1_t;
using __VDSA::const_mem_fun_ref_t;
using __VDSA::const_mem_fun_t;
using __VDSA::constant0;
using __VDSA::constant1;
using __VDSA::constant2;
using __VDSA::constant_binary_fun;
using __VDSA::constant_unary_fun;
using __VDSA::constant_void_fun;
using __VDSA::divides;
using __VDSA::equal_to;
using __VDSA::greater;
using __VDSA::greater_equal;
using __VDSA::identity;
using __VDSA::identity_element;
using __VDSA::less;
using __VDSA::less_equal;
using __VDSA::logical_and;
using __VDSA::logical_not;
using __VDSA::logical_or;
using __VDSA::mem_fun;
using __VDSA::mem_fun1;
using __VDSA::mem_fun1_ref;
using __VDSA::mem_fun1_ref_t;
using __VDSA::mem_fun1_t;
using __VDSA::mem_fun_ref;
using __VDSA::mem_fun_ref_t;
using __VDSA::mem_fun_t;
using __VDSA::minus;
using __VDSA::modulus;
using __VDSA::multiplies;
using __VDSA::negate;
using __VDSA::not1;
using __VDSA::not2;
using __VDSA::not_equal_to;
using __VDSA::plus;
using __VDSA::pointer_to_binary_function;
using __VDSA::pointer_to_unary_function;
using __VDSA::project1st;
using __VDSA::project2nd;
using __VDSA::ptr_fun;
using __VDSA::select1st;
using __VDSA::select2nd;
using __VDSA::subtractive_rng;
using __VDSA::unary_compose;
using __VDSA::unary_function;
using __VDSA::unary_negate;

#endif /* __DST_USE_NAMESPACES */

#endif /* ___DST_FUNCTION_H */
