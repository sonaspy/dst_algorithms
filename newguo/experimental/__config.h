// -*- C++ -*-

#ifndef _LIBCPP_EXPERIMENTAL_CONFIG
#define _LIBCPP_EXPERIMENTAL_CONFIG

#include "../__config.h"

#if !defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
#pragma GCC system_header
#endif

#define _LIBCPP_BEGIN_NAMESPACE_EXPERIMENTAL \
    namespace dsa                            \
    {                                        \
    namespace experimental                   \
    {
#define _LIBCPP_END_NAMESPACE_EXPERIMENTAL \
    }                                      \
    }
#define _VDSA_EXPERIMENTAL dsa::experimental

#define _LIBCPP_BEGIN_NAMESPACE_LFTS                                      \
    _LIBCPP_BEGIN_NAMESPACE_EXPERIMENTAL inline namespace fundamentals_v1 \
    {
#define _LIBCPP_END_NAMESPACE_LFTS \
    }                              \
    }                              \
    }
#define _VDSA_LFTS _VDSA_EXPERIMENTAL::fundamentals_v1

#define _LIBCPP_BEGIN_NAMESPACE_LFTS_V2                                   \
    _LIBCPP_BEGIN_NAMESPACE_EXPERIMENTAL inline namespace fundamentals_v2 \
    {
#define _LIBCPP_END_NAMESPACE_LFTS_V2 \
    }                                 \
    }                                 \
    }
#define _VDSA_LFTS_V2 _VDSA_EXPERIMENTAL::fundamentals_v2

#define _LIBCPP_BEGIN_NAMESPACE_LFTS_PMR       \
    _LIBCPP_BEGIN_NAMESPACE_LFTS namespace pmr \
    {
#define _LIBCPP_END_NAMESPACE_LFTS_PMR \
    _LIBCPP_END_NAMESPACE_LFTS         \
    }
#define _VDSA_LFTS_PMR _VDSA_LFTS::pmr

#define _LIBCPP_BEGIN_NAMESPACE_CHRONO_LFTS \
    _LIBCPP_BEGIN_NAMESPACE_DSA             \
    namespace chrono                        \
    {                                       \
    namespace experimental                  \
    {                                       \
    inline namespace fundamentals_v1        \
    {
#define _LIBCPP_END_NAMESPACE_CHRONO_LFTS \
    _LIBCPP_END_NAMESPACE_DSA             \
    }                                     \
    }                                     \
    }

#define _LIBCPP_BEGIN_NAMESPACE_EXPERIMENTAL_FILESYSTEM       \
    _LIBCPP_BEGIN_NAMESPACE_EXPERIMENTAL namespace filesystem \
    {                                                         \
        inline namespace v1                                   \
        {

#define _LIBCPP_END_NAMESPACE_EXPERIMENTAL_FILESYSTEM \
    }                                                 \
    }                                                 \
    _LIBCPP_END_NAMESPACE_EXPERIMENTAL

#define _VDSA_FS ::dsa::experimental::filesystem::v1

#endif
