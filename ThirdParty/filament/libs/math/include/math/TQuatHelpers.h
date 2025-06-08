
#ifndef TNT_MATH_TQUATHELPERS_H
#define TNT_MATH_TQUATHELPERS_H

#include "third_party/filament/libs/math/include/math/compiler.h"
#include "third_party/filament/libs/math/include/math/scalar.h"
#include "third_party/filament/libs/math/include/math/vec3.h"

#include <math.h>
#include <stdint.h>
#include <sys/types.h>

namespace filament::math::details {




template<template<typename T> class QUATERNION, typename T>
class TQuatProductOperators {
public:
    template<typename OTHER>
    constexpr QUATERNION<T>& operator*=(const QUATERNION<OTHER>& r) {
        QUATERNION<T>& q = static_cast<QUATERNION<T>&>(*this);
        q = q * r;
        return q;
    }

    template<typename U, typename = std::enable_if_t<std::is_arithmetic_v<U>>>
    constexpr QUATERNION<T>& operator*=(U v) {
        QUATERNION<T>& lhs = static_cast<QUATERNION<T>&>(*this);
        for (size_t i = 0; i < QUATERNION<T>::size(); i++) {
            lhs[i] *= v;
        }
        return lhs;
    }

    template<typename U, typename = std::enable_if_t<std::is_arithmetic_v<U>>>
    constexpr QUATERNION<T>& operator/=(U v) {
        QUATERNION<T>& lhs = static_cast<QUATERNION<T>&>(*this);
        for (size_t i = 0; i < QUATERNION<T>::size(); i++) {
            lhs[i] /= v;
        }
        return lhs;
    }


    template<typename U>
    friend inline constexpr
    QUATERNION<arithmetic_result_t<T, U>> MATH_PURE operator*(
            const QUATERNION<T>& q, const QUATERNION<U>& r) {
        // could be written as:
        //  return QUATERNION<T>(
        //            q.w*r.w - dot(q.xyz, r.xyz),
        //            q.w*r.xyz + r.w*q.xyz + cross(q.xyz, r.xyz));
        return {
                q.w * r.w - q.x * r.x - q.y * r.y - q.z * r.z,
                q.w * r.x + q.x * r.w + q.y * r.z - q.z * r.y,
                q.w * r.y - q.x * r.z + q.y * r.w + q.z * r.x,
                q.w * r.z + q.x * r.y - q.y * r.x + q.z * r.w
        };
    }

    template<typename U>
    friend inline constexpr
    TVec3<arithmetic_result_t<T, U>> MATH_PURE operator*(const QUATERNION<T>& q, const TVec3<U>& v) {
        // note: if q is known to be a unit quaternion, then this simplifies to:
        //  TVec3<T> t = 2 * cross(q.xyz, v)
        //  return v + (q.w * t) + cross(q.xyz, t)
        return imaginary(q * QUATERNION<U>(v, 0) * inverse(q));
    }


    template<typename U, typename = std::enable_if_t<std::is_arithmetic_v<U>>>
    friend inline constexpr
    QUATERNION<arithmetic_result_t<T, U>> MATH_PURE operator*(QUATERNION<T> q, U scalar) {
        // don't pass q by reference because we need a copy anyway
        return QUATERNION<arithmetic_result_t<T, U>>(q *= scalar);
    }

    template<typename U, typename = std::enable_if_t<std::is_arithmetic_v<U>>>
    friend inline constexpr
    QUATERNION<arithmetic_result_t<T, U>> MATH_PURE operator*(U scalar, QUATERNION<T> q) {
        // don't pass q by reference because we need a copy anyway
        return QUATERNION<arithmetic_result_t<T, U>>(q *= scalar);
    }

    template<typename U, typename = std::enable_if_t<std::is_arithmetic_v<U>>>
    friend inline constexpr
    QUATERNION<arithmetic_result_t<T, U>> MATH_PURE operator/(QUATERNION<T> q, U scalar) {
        // don't pass q by reference because we need a copy anyway
        return QUATERNION<arithmetic_result_t<T, U>>(q /= scalar);
    }
};


template<template<typename T> class QUATERNION, typename T>
class TQuatFunctions {
public:

    template<typename U>
    friend inline constexpr
    arithmetic_result_t<T, U> MATH_PURE dot(
            const QUATERNION<T>& p, const QUATERNION<U>& q) {
        return p.x * q.x +
               p.y * q.y +
               p.z * q.z +
               p.w * q.w;
    }

    friend inline
    T MATH_PURE norm(const QUATERNION<T>& q) {
        return std::sqrt(dot(q, q));
    }

    friend inline
    T MATH_PURE length(const QUATERNION<T>& q) {
        return norm(q);
    }

    friend inline
    constexpr T MATH_PURE length2(const QUATERNION<T>& q) {
        return dot(q, q);
    }

    friend inline
    QUATERNION<T> MATH_PURE normalize(const QUATERNION<T>& q) {
        return length(q) ? q / length(q) : QUATERNION<T>(static_cast<T>(1));
    }

    friend inline
    constexpr QUATERNION<T> MATH_PURE conj(const QUATERNION<T>& q) {
        return QUATERNION<T>(q.w, -q.x, -q.y, -q.z);
    }

    friend inline
    constexpr QUATERNION<T> MATH_PURE inverse(const QUATERNION<T>& q) {
        return conj(q) * (T(1) / dot(q, q));
    }

    friend inline
    constexpr T MATH_PURE real(const QUATERNION<T>& q) {
        return q.w;
    }

    friend inline
    constexpr TVec3<T> MATH_PURE imaginary(const QUATERNION<T>& q) {
        return q.xyz;
    }

    friend inline
    constexpr QUATERNION<T> MATH_PURE unreal(const QUATERNION<T>& q) {
        return QUATERNION<T>(q.xyz, 0);
    }

    template<typename U>
    friend inline constexpr
    QUATERNION<arithmetic_result_t<T, U>> MATH_PURE cross(
            const QUATERNION<T>& p, const QUATERNION<U>& q) {
        return unreal(p * q);
    }

    friend inline
    QUATERNION<T> MATH_PURE exp(const QUATERNION<T>& q) {
        const T nq(norm(q.xyz));
        return std::exp(q.w) * QUATERNION<T>((sin(nq) / nq) * q.xyz, cos(nq));
    }

    friend inline
    QUATERNION<T> MATH_PURE log(const QUATERNION<T>& q) {
        const T nq(norm(q));
        return QUATERNION<T>((std::acos(q.w / nq) / norm(q.xyz)) * q.xyz, std::log(nq));
    }

    friend inline
    QUATERNION<T> MATH_PURE pow(const QUATERNION<T>& q, T a) {
        // could also be computed as: exp(a*log(q));
        const T nq(norm(q));
        const T theta(a * std::acos(q.w / nq));
        return std::pow(nq, a) * QUATERNION<T>(normalize(q.xyz) * std::sin(theta), std::cos(theta));
    }

    friend inline
    QUATERNION<T> MATH_PURE slerp(const QUATERNION<T>& p, const QUATERNION<T>& q, T t) {
        // could also be computed as: pow(q * inverse(p), t) * p;
        const T d = dot(p, q);
        const T absd = std::abs(d);
        static constexpr T value_eps = T(10) * std::numeric_limits<T>::epsilon();
        // Prevent blowing up when slerping between two quaternions that are very near each other.
        if ((T(1) - absd) < value_eps) {
            return normalize(lerp(d < 0 ? -p : p, q, t));
        }
        const T npq = std::sqrt(dot(p, p) * dot(q, q));  // ||p|| * ||q||
        const T a = std::acos(filament::math::clamp(absd / npq, T(-1), T(1)));
        const T a0 = a * (1 - t);
        const T a1 = a * t;
        const T sina = sin(a);
        if (sina < value_eps) {
            return normalize(lerp(p, q, t));
        }
        const T isina = 1 / sina;
        const T s0 = std::sin(a0) * isina;
        const T s1 = std::sin(a1) * isina;
        // ensure we're taking the "short" side
        return normalize(s0 * p + ((d < 0) ? (-s1) : (s1)) * q);
    }

    friend inline
    constexpr QUATERNION<T> MATH_PURE lerp(const QUATERNION<T>& p, const QUATERNION<T>& q, T t) {
        return ((1 - t) * p) + (t * q);
    }

    friend inline
    constexpr QUATERNION<T> MATH_PURE nlerp(const QUATERNION<T>& p, const QUATERNION<T>& q, T t) {
        return normalize(lerp(p, q, t));
    }

    friend inline
    constexpr QUATERNION<T> MATH_PURE positive(const QUATERNION<T>& q) {
        return q.w < 0 ? -q : q;
    }
};

}  // namespace filament::math::details

#endif  // TNT_MATH_TQUATHELPERS_H
