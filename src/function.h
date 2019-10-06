#ifndef ___DST_FUNCTION_H
#define ___DST_FUNCTION_H

#ifndef __DST_CONFIG_H
#include "dst_config.h"
#endif
#ifndef ___DST_INTERNAL_RELOPS
#include "dst_relops.h"
#endif
#include <stddef.h>
#ifndef ___DST_INTERNAL_FUNCTION_H
#include "dst_function.h"
#endif

#ifdef __DST_USE_NAMESPACE_FOR_RELOPS

// Names from dst_relops.h
using __DSA_RELOPS::operator!=;
using __DSA_RELOPS::operator>;
using __DSA_RELOPS::operator<=;
using __DSA_RELOPS::operator>=;

#endif /* __DST_USE_NAMESPACE_FOR_RELOPS */

#ifdef __DST_USE_NAMESPACES

// Names from dst_function.h
using __DSA::binary_compose;
using __DSA::binary_function;
using __DSA::binary_negate;
using __DSA::bind1st;
using __DSA::bind2nd;
using __DSA::binder1st;
using __DSA::binder2nd;
using __DSA::compose1;
using __DSA::compose2;
using __DSA::const_mem_fun1_ref_t;
using __DSA::const_mem_fun1_t;
using __DSA::const_mem_fun_ref_t;
using __DSA::const_mem_fun_t;
using __DSA::constant0;
using __DSA::constant1;
using __DSA::constant2;
using __DSA::constant_binary_fun;
using __DSA::constant_unary_fun;
using __DSA::constant_void_fun;
using __DSA::divides;
using __DSA::equal_to;
using __DSA::greater;
using __DSA::greater_equal;
using __DSA::identity;
using __DSA::identity_element;
using __DSA::less;
using __DSA::less_equal;
using __DSA::logical_and;
using __DSA::logical_not;
using __DSA::logical_or;
using __DSA::mem_fun;
using __DSA::mem_fun1;
using __DSA::mem_fun1_ref;
using __DSA::mem_fun1_ref_t;
using __DSA::mem_fun1_t;
using __DSA::mem_fun_ref;
using __DSA::mem_fun_ref_t;
using __DSA::mem_fun_t;
using __DSA::minus;
using __DSA::modulus;
using __DSA::multiplies;
using __DSA::negate;
using __DSA::not1;
using __DSA::not2;
using __DSA::not_equal_to;
using __DSA::plus;
using __DSA::pointer_to_binary_function;
using __DSA::pointer_to_unary_function;
using __DSA::project1st;
using __DSA::project2nd;
using __DSA::ptr_fun;
using __DSA::select1st;
using __DSA::select2nd;
using __DSA::subtractive_rng;
using __DSA::unary_compose;
using __DSA::unary_function;
using __DSA::unary_negate;

#endif /* __DST_USE_NAMESPACES */

#endif /* ___DST_FUNCTION_H */
