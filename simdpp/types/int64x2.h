/*  Copyright (C) 2011-2014  Povilas Kanapickas <povilas@radix.lt>

    Distributed under the Boost Software License, Version 1.0.
        (See accompanying file LICENSE_1_0.txt or copy at
            http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef LIBSIMDPP_SIMDPP_TYPES_INT64X2_H
#define LIBSIMDPP_SIMDPP_TYPES_INT64X2_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/setup_arch.h>
#include <simdpp/types/fwd.h>
#include <simdpp/types/any.h>
#include <simdpp/core/cast.h>
#include <simdpp/detail/construct_eval.h>
#include <simdpp/detail/array.h>
#include <simdpp/detail/null/mask.h>
#include <cstdint>

namespace simdpp {
#ifndef SIMDPP_DOXYGEN
namespace SIMDPP_ARCH_NAMESPACE {
#endif

/// @ingroup simd_vec_int
/// @{

/** Class representing 2x 64-bit signed integer vector
*/
template<>
class int64<2, void> : public any_int64<2, int64<2,void>> {
public:
    static const unsigned type_tag = SIMDPP_TAG_INT;
    using element_type = int64_t;
    using base_vector_type = int64<2,void>;
    using expr_type = void;

#if SIMDPP_USE_SSE2
    using native_type = __m128i;
#elif SIMDPP_USE_NEON
    using native_type = int64x2_t;
#elif SIMDPP_USE_ALTIVEC
    using native_type = __vector int64_t;
#else
    using native_type = detail::array<int64_t, 2>;
#endif

    int64<2>() = default;
    int64<2>(const int64<2> &) = default;
    int64<2> &operator=(const int64<2> &) = default;

    template<class E> int64<2>(const int64<2,E>& d) { *this = d.eval(); }
    template<class E> int64<2>(const uint64<2,E>& d) { *this = d.eval(); }
    template<class V> explicit int64<2>(const any_vec<16,V>& d)
    {
        *this = bit_cast<int64<2>>(d.wrapped().eval());
    }
    template<class V> int64<2>& operator=(const any_vec<16,V>& d)
    {
        *this = bit_cast<int64<2>>(d.wrapped().eval()); return *this;
    }

    /// @{
    /// Construct from the underlying vector type
    int64<2>(const native_type& d) : d_(d) {}
    int64<2>& operator=(const native_type& d) { d_ = d; return *this; }
    /// @}

    /// Convert to the underlying vector type
    operator native_type() const { return d_; }

#ifndef SIMDPP_DOXYGEN
    template<class E> int64<2>(const expr_vec_construct<E>& e)
    {
        detail::construct_eval_wrapper(*this, e.expr());
    }
    template<class E> int64<2>& operator=(const expr_vec_construct<E>& e)
    {
        detail::construct_eval_wrapper(*this, e.expr()); return *this;
    }
#endif

    /// @{
    /// Access base vectors
    const int64<2>& operator[](unsigned) const { return *this; }
          int64<2>& operator[](unsigned)       { return *this; }
    /// @}

    int64<2> eval() const { return *this; }

#if SIMDPP_USE_NULL && !SIMDPP_DOXYGEN
    /// For internal use only
    const int64_t& el(unsigned i) const  { return d_[i]; }
          int64_t& el(unsigned i)        { return d_[i]; }
#endif

    static int64<2> zero() { return detail::make_zero(); }
    static int64<2> ones() { return detail::make_ones(); }

private:
    native_type d_;
};

/** Class representing 2x 64-bit unsigned integer vector
*/
template<>
class uint64<2, void> : public any_int64<2, uint64<2,void>> {
public:
    static const unsigned type_tag = SIMDPP_TAG_UINT;
    using element_type = uint64_t;
    using base_vector_type = uint64<2,void>;
    using expr_type = void;

#if SIMDPP_USE_SSE2
    using native_type = __m128i;
#elif SIMDPP_USE_NEON
    using native_type = uint64x2_t;
#elif SIMDPP_USE_ALTIVEC
    using native_type = __vector uint64_t;
#else
    using native_type = detail::array<uint64_t, 2>;
#endif

    uint64<2>() = default;
    uint64<2>(const uint64<2> &) = default;
    uint64<2> &operator=(const uint64<2> &) = default;

    template<class E> uint64<2>(const uint64<2,E>& d) { *this = d.eval(); }
    template<class E> uint64<2>(const int64<2,E>& d) { *this = d.eval(); }
    template<class V> explicit uint64<2>(const any_vec<16,V>& d)
    {
        *this = bit_cast<uint64<2>>(d.wrapped().eval());
    }
    template<class V> uint64<2>& operator=(const any_vec<16,V>& d)
    {
        *this = bit_cast<uint64<2>>(d.wrapped().eval()); return *this;
    }

    /// @{
    /// Construct from the underlying vector type
    uint64<2>(const native_type& d) : d_(d) {}
    uint64<2>& operator=(const native_type& d) { d_ = d; return *this; }
    /// @}

    /// Convert to the underlying vector type
    operator native_type() const { return d_; }

#ifndef SIMDPP_DOXYGEN
    template<class E> uint64<2>(const expr_vec_construct<E>& e)
    {
        detail::construct_eval_wrapper(*this, e.expr());
    }
    template<class E> uint64<2>& operator=(const expr_vec_construct<E>& e)
    {
        detail::construct_eval_wrapper(*this, e.expr()); return *this;
    }
#endif

    /// @{
    /// Access base vectors
    const uint64<2>& operator[](unsigned) const { return *this; }
          uint64<2>& operator[](unsigned)       { return *this; }
    /// @}

    uint64<2> eval() const { return *this; }

#if SIMDPP_USE_NULL && !SIMDPP_DOXYGEN
    /// For uinternal use only
    const uint64_t& el(unsigned i) const  { return d_[i]; }
          uint64_t& el(unsigned i)        { return d_[i]; }
#endif

    static uint64<2> zero() { return detail::make_zero(); }
    static uint64<2> ones() { return detail::make_ones(); }

private:
    native_type d_;
};


/// Class representing possibly optimized mask data for 2x 64-bit integer
/// vector
template<>
class mask_int64<2, void> : public any_int64<2, mask_int64<2,void>> {
public:
    static const unsigned type_tag = SIMDPP_TAG_MASK_INT;
    using base_vector_type = mask_int64<2,void>;
    using expr_type = void;

#if SIMDPP_USE_SSE2
    using native_type = __m128i;
#elif SIMDPP_USE_NEON
    using native_type = uint64x2_t;
#elif SIMDPP_USE_ALTIVEC
    using native_type = uint64<2>;
#else // NULL
    using native_type = detail::array<bool, 2>;
#endif

    mask_int64<2>() = default;
    mask_int64<2>(const mask_int64<2> &) = default;
    mask_int64<2> &operator=(const mask_int64<2> &) = default;

    mask_int64<2>(const native_type& d) : d_(d) {}

#if SIMDPP_USE_SSE2 || SIMDPP_USE_NEON
    mask_int64<2>(const uint64<2>& d) : d_(d) {}
#endif

    template<class E> explicit mask_int64<2>(const mask_float64<2,E>& d)
    {
        *this = bit_cast<mask_int64<2>>(d.eval());
    }
    template<class E> mask_int64<2>& operator=(const mask_float64<2,E>& d)
    {
        *this = bit_cast<mask_int64<2>>(d.eval()); return *this;
    }

    operator native_type() const { return d_; }

    /// Access the underlying type
    uint64<2> unmask() const
    {
    #if SIMDPP_USE_NULL
        return detail::null::unmask_mask<uint64<2>>(*this);
    #else
        return uint64<2>(d_);
    #endif
    }

#if SIMDPP_USE_NULL && !SIMDPP_DOXYGEN
    bool& el(unsigned id) { return d_[id]; }
    const bool& el(unsigned id) const { return d_[id]; }
#endif

    const mask_int64<2>& operator[](unsigned) const { return *this; }
          mask_int64<2>& operator[](unsigned)       { return *this; }

    mask_int64<2> eval() const { return *this; }

private:
    native_type d_;
};

/// @} -- end ingroup

#ifndef SIMDPP_DOXYGEN
} // namespace SIMDPP_ARCH_NAMESPACE
#endif
} // namespace simdpp

#endif
