#ifndef ___DST_ALGO_H
#define ___DST_ALGO_H

#include "algobase.hpp"
#include "tempbuf.hpp"
#include "dst_algo.hpp"
#include "dst_numeric.hpp"

#ifdef __DST_USE_NAMESPACES

// Names from "dst_algo.hpp"
using __VDSA::adjacent_find;
using __VDSA::binary_search;
using __VDSA::count;
using __VDSA::count_if;
using __VDSA::equal_range;
using __VDSA::find;
using __VDSA::find_end;
using __VDSA::find_first_of;
using __VDSA::find_if;
using __VDSA::for_each;
using __VDSA::generate;
using __VDSA::generate_n;
using __VDSA::includes;
using __VDSA::inplace_merge;
using __VDSA::is_heap;
using __VDSA::is_sorted;
using __VDSA::lower_bound;
using __VDSA::max_element;
using __VDSA::merge;
using __VDSA::min_element;
using __VDSA::next_permutation;
using __VDSA::nth_element;
using __VDSA::partial_sort;
using __VDSA::partial_sort_copy;
using __VDSA::partition;
using __VDSA::prev_permutation;
using __VDSA::random_sample;
using __VDSA::random_sample_n;
using __VDSA::random_shuffle;
using __VDSA::remove;
using __VDSA::remove_copy;
using __VDSA::remove_copy_if;
using __VDSA::remove_if;
using __VDSA::replace;
using __VDSA::replace_copy;
using __VDSA::replace_copy_if;
using __VDSA::replace_if;
using __VDSA::reverse;
using __VDSA::reverse_copy;
using __VDSA::rotate;
using __VDSA::rotate_copy;
using __VDSA::search;
using __VDSA::search_n;
using __VDSA::set_difference;
using __VDSA::set_intersection;
using __VDSA::set_symmetric_difference;
using __VDSA::set_union;
using __VDSA::sort;
using __VDSA::stable_partition;
using __VDSA::stable_sort;
using __VDSA::swap_ranges;
using __VDSA::transform;
using __VDSA::unique;
using __VDSA::unique_copy;
using __VDSA::upper_bound;

// Names from dst_heap.h
using __VDSA::make_heap;
using __VDSA::pop_heap;
using __VDSA::push_heap;
using __VDSA::sort_heap;

// Names from "dst_numeric.hpp"
using __VDSA::accumulate;
using __VDSA::adjacent_difference;
using __VDSA::inner_product;
using __VDSA::iota;
using __VDSA::partial_sum;
using __VDSA::power;

#endif /* __DST_USE_NAMESPACES */

#endif /* ___DST_ALGO_H */