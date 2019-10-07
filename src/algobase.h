

#ifndef ___DST_ALGOBASE_H
#define ___DST_ALGOBASE_H

#ifndef ___DST_PAIR_H
#include "pair.h"
#endif
#ifndef ___DST_ITERATOR_H
#include "iterator.h"
#endif
#ifndef ___DST_INTERNAL_ALGOBASE_H
#include "dst_algobase.h"
#endif
#ifndef ___DST_INTERNAL_UNINITIALIZED_H
#include "dst_uninitialized.h"
#endif

#ifdef __DST_USE_NAMESPACES

// Names from dst_algobase.h
using __DSA::copy;
using __DSA::copy_backward;
using __DSA::copy_n;
using __DSA::equal;
using __DSA::fill;
using __DSA::fill_n;
using __DSA::iter_swap;
using __DSA::lexicographical_compare;
using __DSA::lexicographical_compare_3way;
using __DSA::max;
using __DSA::min;
using __DSA::mismatch;
using __DSA::swap;

// Names from dst_uninitialized.h
using __DSA::uninitialized_copy;
using __DSA::uninitialized_copy_n;
using __DSA::uninitialized_fill;
using __DSA::uninitialized_fill_n;

#endif /* __DST_USE_NAMESPACES */

#endif /* ___DST_ALGOBASE_H */

// Local Variables:
// mode:C++
// End:
