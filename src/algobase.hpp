

#ifndef ___DST_ALGOBASE_H
#define ___DST_ALGOBASE_H

#ifndef ___DST_PAIR_H
#include "pair.hpp"
#endif

#ifndef ___DST_ITERATOR_H
#include "iterator.hpp"
#endif

#ifndef ___DST_INTERNAL_ALGOBASE_H
#include "dst_algobase.hpp"
#endif

#ifndef ___DST_INTERNAL_UNINITIALIZED_H
#include "dst_uninitialized.hpp"
#endif

#ifdef __DST_USE_NAMESPACES

// Names from dst_algobase.h
using __VDSA::copy;
using __VDSA::copy_backward;
using __VDSA::copy_n;
using __VDSA::equal;
using __VDSA::fill;
using __VDSA::fill_n;
using __VDSA::iter_swap;
using __VDSA::lexicographical_compare;
using __VDSA::lexicographical_compare_3way;
using __VDSA::max;
using __VDSA::min;
using __VDSA::mismatch;
using __VDSA::swap;

// Names from dst_uninitialized.h
using __VDSA::uninitialized_copy;
using __VDSA::uninitialized_copy_n;
using __VDSA::uninitialized_fill;
using __VDSA::uninitialized_fill_n;

#endif /* __DST_USE_NAMESPACES */

#endif /* ___DST_ALGOBASE_H */


