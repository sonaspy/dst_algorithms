

#ifndef ___DST_ITERATOR_H
#define ___DST_ITERATOR_H

#ifndef ___DST_FUNCTION_H
#include "function.hpp"
#endif

#include <stddef.h>

#ifdef __DST_USE_NEW_IOSTREAMS
#include <iosfwd>
#else /* __DST_USE_NEW_IOSTREAMS */
#include "iostream.hpp"
#endif /* __DST_USE_NEW_IOSTREAMS */

#ifndef ___DST_INTERNAL_ITERATOR_BASE_H
#include "dst_iterator_base.hpp"
#endif
#ifndef ___DST_INTERNAL_ITERATOR_H
#include "dst_iterator.hpp"
#endif
#ifndef __TYPE_TRAITS_H
#include "type_traits.hpp"
#endif
#ifndef ___DST_INTERNAL_CONSTRUCT_H
#include "dst_construct.hpp"
#endif
#ifndef ___DST_INTERNAL_RAW_STORAGE_ITERATOR_H
#include "dst_raw_storage_iter.hpp"
#endif

#ifdef __DST_USE_NAMESPACES

// Names from dst_iterator.h

using __VDSA::bidirectional_iterator_tag;
using __VDSA::forward_iterator_tag;
using __VDSA::input_iterator_tag;
using __VDSA::output_iterator_tag;
using __VDSA::random_access_iterator_tag;

#if 0
using __VDSA::iterator;
#endif
using __VDSA::bidirectional_iterator;
using __VDSA::forward_iterator;
using __VDSA::input_iterator;
using __VDSA::output_iterator;
using __VDSA::random_access_iterator;

#ifdef __DST_CLASS_PARTIAL_SPECIALIZATION
using __VDSA::iterator_traits;
#endif

using __VDSA::distance_type;
using __VDSA::iterator_category;
using __VDSA::value_type;

using __VDSA::advance;
using __VDSA::distance;

using __VDSA::back_insert_iterator;
using __VDSA::back_inserter;
using __VDSA::front_insert_iterator;
using __VDSA::front_inserter;
using __VDSA::insert_iterator;
using __VDSA::inserter;

using __VDSA::reverse_bidirectional_iterator;
using __VDSA::reverse_iterator;

using __VDSA::istream_iterator;
using __VDSA::ostream_iterator;

// Names from dst_construct.h
using __VDSA::construct;
using __VDSA::destroy;

// Names from dst_raw_storage_iter.h
using __VDSA::raw_storage_iterator;

#endif /* __DST_USE_NAMESPACES */

#endif /* ___DST_ITERATOR_H */


