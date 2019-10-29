#ifndef ___DST_HASH_SET_H
#define ___DST_HASH_SET_H

#ifndef ___DST_INTERNAL_HASHTABLE_H
#include "dst_hashtable.cc"
#endif

#include "algobase.hpp"
#include "dst_hash_set.cc"

#ifdef __DST_USE_NAMESPACES
using __VDSA::hash;
using __VDSA::hash_multiset;
using __VDSA::hash_set;
using __VDSA::hashtable;
#endif /* __DST_USE_NAMESPACES */

#endif /* ___DST_HASH_SET_H */
