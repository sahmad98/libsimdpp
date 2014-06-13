/*  Copyright (C) 2013-2014  Povilas Kanapickas <povilas@radix.lt>

    Distributed under the Boost Software License, Version 1.0.
        (See accompanying file LICENSE_1_0.txt or copy at
            http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef LIBSIMDPP_SIMDPP_CORE_I_ADD_H
#define LIBSIMDPP_SIMDPP_CORE_I_ADD_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types.h>
#include <simdpp/detail/expr/i_add.h>
#include <simdpp/detail/get_expr.h>

namespace simdpp {
#ifndef SIMDPP_DOXYGEN
namespace SIMDPP_ARCH_NAMESPACE {
#endif


/** Adds 8-bit integer values.

    @code
    r0 = a0 + b0
    ...
    rN = aN + bN
    @endcode

    @par 256-bit version:
    @icost{SSE2-AVX, NEON, ALTIVEC, 2}
*/
#if SIMDPP_DOXYGEN
template<unsigned N, class V1, class V2>
_PROMOTED_NOMASK_EXPRESSION_ add(const any_int8<N,V1>& a,
                                 const any_int8<N,V2>& b);
#else
template<unsigned N, class V1, class V2>
typename detail::get_expr2_nomask<V1, V2,
                                  expr_add<uint8<N, typename V1::expr_type>,
                                           uint8<N, typename V2::expr_type>>
                                 >::type
        add(const any_int8<N,V1>& a,
            const any_int8<N,V2>& b)
{
    return { { a.wrapped(), b.wrapped() }, 0 };
}
#endif

/** Adds 16-bit integer values.

    @code
    r0 = a0 + b0
    ...
    rN = aN + bN
    @endcode

    @par 256-bit version:
    @icost{SSE2-AVX, NEON, ALTIVEC, 2}
*/
#if SIMDPP_DOXYGEN
template<unsigned N, class V1, class V2>
_PROMOTED_NOMASK_EXPRESSION_ add(const any_int16<N,V1>& a,
                                 const any_int16<N,V2>& b);
#else
template<unsigned N, class V1, class V2>
typename detail::get_expr2_nomask<V1, V2,
                                  expr_add<uint16<N, typename V1::expr_type>,
                                           uint16<N, typename V2::expr_type>>
                                 >::type
        add(const any_int16<N,V1>& a,
            const any_int16<N,V2>& b)
{
    return { { a.wrapped(), b.wrapped() }, 0 };
}
#endif

/** Adds 32-bit integer values.

    @code
    r0 = a0 + b0
    ...
    rN = aN + bN
    @endcode

    @par 256-bit version:
    @icost{SSE2-AVX, NEON, ALTIVEC, 2}
*/
#if SIMDPP_DOXYGEN
template<unsigned N, class V1, class V2>
_PROMOTED_NOMASK_EXPRESSION_ add(const any_int32<N,V1>& a,
                                 const any_int32<N,V2>& b);
#else
template<unsigned N, class V1, class V2>
typename detail::get_expr2_nomask<V1, V2,
                                  expr_add<uint32<N, typename V1::expr_type>,
                                           uint32<N, typename V2::expr_type>>
                                 >::type
        add(const any_int32<N,V1>& a,
            const any_int32<N,V2>& b)
{
    return { { a.wrapped(), b.wrapped() }, 0 };
}
#endif

/** Adds 64-bit integer values.

    @code
    r0 = a0 + b0
    ...
    rN = aN + bN
    @endcode

    @par 128-bit version:
    @icost{ALTIVEC, 5-6}

    @par 256-bit version:
    @icost{SSE2-AVX, NEON, 2}
    @icost{ALTIVEC, 10-11}
*/
#if SIMDPP_DOXYGEN
template<unsigned N, class V1, class V2>
_PROMOTED_NOMASK_EXPRESSION_ add(const any_int64<N,V1>& a,
                                 const any_int64<N,V2>& b);
#else
template<unsigned N, class V1, class V2>
typename detail::get_expr2_nomask<V1, V2,
                                  expr_add<uint64<N, typename V1::expr_type>,
                                           uint64<N, typename V2::expr_type>>
                                 >::type
        add(const any_int64<N,V1>& a,
            const any_int64<N,V2>& b)
{
    return { { a.wrapped(), b.wrapped() }, 0 };
}
#endif

#ifndef SIMDPP_DOXYGEN
} // namespace SIMDPP_ARCH_NAMESPACE
#endif
} // namespace simdpp

#endif

