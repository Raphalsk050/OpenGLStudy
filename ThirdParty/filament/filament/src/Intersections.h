
#ifndef TNT_FILAMENT_INTERSECTIONS_H
#define TNT_FILAMENT_INTERSECTIONS_H

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include "third_party/filament/libs/math/include/math/mat4.h"
#include "third_party/filament/libs/math/include/math/vec4.h"

namespace filament {

// sphere radius must be squared
// plane equation must be normalized, sphere radius must be squared
// return float4.w <= 0 if no intersection
inline constexpr math::float4 spherePlaneIntersection(math::float4 s, math::float4 p) noexcept {
    const float d = dot(s.xyz, p.xyz) + p.w;
    const float rr = s.w - d * d;
    s.x -= p.x * d;
    s.y -= p.y * d;
    s.z -= p.z * d;
    s.w = rr;   // new-circle/sphere radius is squared
    return s;
}

// sphere radius must be squared
// plane equation must be normalized and have the form {0,0,1,w}, sphere radius must be squared
// return float4.w <= 0 if no intersection
inline constexpr math::float4 spherePlaneIntersection(math::float4 s, float pw) noexcept {
    return spherePlaneIntersection(s, { 0.f, 0.f, 1.f, pw });
}

// sphere radius must be squared
// this version returns a false-positive intersection in a small area near the origin
// of the cone extended outward by the sphere's radius.
inline constexpr bool sphereConeIntersectionFast(
        math::float4 const& sphere,
        math::float3 const& conePosition,
        math::float3 const& coneAxis,
        float coneSinInverse,
        float coneCosSquared) noexcept {
    const math::float3 u = conePosition - (sphere.w * coneSinInverse) * coneAxis;
    math::float3 const d = sphere.xyz - u;
    float const e = dot(coneAxis, d);
    float const dd = dot(d, d);
    // we do the e>0 last here to avoid a branch
    return (e * e >= dd * coneCosSquared && e > 0);
}

inline constexpr bool sphereConeIntersection(
        math::float4 const& sphere,
        math::float3 const& conePosition,
        math::float3 const& coneAxis,
        float coneSinInverse,
        float coneCosSquared) noexcept {
    if (sphereConeIntersectionFast(sphere,
            conePosition, coneAxis, coneSinInverse, coneCosSquared)) {
        math::float3 const d = sphere.xyz - conePosition;
        float const e = -dot(coneAxis, d);
        float const dd = dot(d, d);
        if (e * e >= dd * (1 - coneCosSquared) && e > 0) {
            return dd <= sphere.w * sphere.w;
        }
        return true;
    }
    return false;
}

// returns the intersection of 3 planes.
// Assumes all planes are intersecting.
//
// 3-planes intersection:
//      -d0.(n1 x n2) - d1.(n2 x n0) - d2.(n0 x n1)
// P = ---------------------------------------------
//                      n0.(n1 x n2)
inline constexpr math::float3 planeIntersection(
        math::float4 const& p0,
        math::float4 const& p1,
        math::float4 const& p2) noexcept {
    auto const c0 = cross(p1.xyz, p2.xyz);
    auto const c1 = cross(p2.xyz, p0.xyz);
    auto const c2 = cross(p0.xyz, p1.xyz);
    return -(p0.w * c0 + p1.w * c1 + p2.w * c2) * (1.0f / dot(p0.xyz, c0));
}

} // namespace filament

#endif // TNT_FILAMENT_INTERSECTIONS_H
