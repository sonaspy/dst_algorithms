

#ifndef ___DST_ITERATOR_H
#define ___DST_ITERATOR_H

#ifndef ___DST_FUNCTION_H
#include "function.h"
#endif

#include <stddef.h>

#ifdef __DST_USE_NEW_IOSTREAMS
#include <iosfwd>
#else /* __DST_USE_NEW_IOSTREAMS */
#include "iostream.h"
#endif /* __DST_USE_NEW_IOSTREAMS */

#ifndef ___DST_INTERNAL_ITERATOR_BASE_H
#include "dst_iterator_base.h"
#endif
#ifndef ___DST_INTERNAL_ITERATOR_H
#include "dst_iterator.h"
#endif
#ifndef __TYPE_TRAITS_H
#include "type_traits.h"
#endif
#ifndef ___DST_INTERNAL_CONSTRUCT_H
#include "dst_construct.h"
#endif
#ifndef ___DST_INTERNAL_RAW_STORAGE_ITERATOR_H
#include "dst_raw_storage_iter.h"
#endif

#ifdef __DST_USE_NAMESPACES

// Names from dst_iterator.h

using __DSA::bidirectional_iterator_tag;
using __DSA::forward_iterator_tag;
using __DSA::input_iterator_tag;
using __DSA::output_iterator_tag;
using __DSA::random_access_iterator_tag;

#if 0
using __DSA::iterator;
#endif
using __DSA::bidirectional_iterator;
using __DSA::forward_iterator;
using __DSA::input_iterator;
using __DSA::output_iterator;
using __DSA::random_access_iterator;

#ifdef __DST_CLASS_PARTIAL_SPECIALIZATION
using __DSA::iterator_traits;
#endif

using __DSA::distance_type;
using __DSA::iterator_category;
using __DSA::value_type;

using __DSA::advance;
using __DSA::distance;

using __DSA::back_insert_iterator;
using __DSA::back_inserter;
using __DSA::front_insert_iterator;
using __DSA::front_inserter;
using __DSA::insert_iterator;
using __DSA::inserter;

using __DSA::reverse_bidirectional_iterator;
using __DSA::reverse_iterator;

using __DSA::istream_iterator;
using __DSA::ostream_iterator;

// Names from dst_construct.h
using __DSA::construct;
using __DSA::destroy;

// Names from dst_raw_storage_iter.h
using __DSA::raw_storage_iterator;

#endif /* __DST_USE_NAMESPACES */

#endif /* ___DST_ITERATOR_H */


