
//! \file

#ifndef TNT_FILAMENT_BOX_H
#define TNT_FILAMENT_BOX_H

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include "third_party/filament/libs/math/include/math/mat3.h"
#include "third_party/filament/libs/math/include/math/mat4.h"
#include "third_party/filament/libs/math/include/math/vec3.h"
#include "third_party/filament/libs/math/include/math/vec4.h"

#include <float.h>

#include <stddef.h>

namespace filament {

class UTILS_PUBLIC Box {
public:
    math::float3 halfExtent = {};

    constexpr bool isEmpty() const noexcept {
        return length2(halfExtent) == 0;
    }

    constexpr math::float3 getMin() const noexcept {
        return center - halfExtent;
    }

    constexpr math::float3 getMax() const noexcept {
        return center + halfExtent;
    }

    Box& set(const math::float3& min, const math::float3& max) noexcept {
        // float3 ctor needed for Visual Studio
        center     = (max + min) * math::float3(0.5f);
        halfExtent = (max - min) * math::float3(0.5f);
        return *this;
    }

    Box& unionSelf(const Box& box) noexcept {
        set(min(getMin(), box.getMin()), max(getMax(), box.getMax()));
        return *this;
    }

    constexpr Box translateTo(const math::float3& tr) const noexcept {
        return Box{ tr, halfExtent };
    }

    math::float4 getBoundingSphere() const noexcept {
        return { center, length(halfExtent) };
    }

    static Box transform(const math::mat3f& m, math::float3 const& t, const Box& box) noexcept {
        return { m * box.center + t, abs(m) * box.halfExtent };
    }

    friend Box rigidTransform(Box const& box, const math::mat4f& m) noexcept {
        return transform(m.upperLeft(), m[3].xyz, box);
    }
};

struct UTILS_PUBLIC Aabb {

    math::float3 max = -FLT_MAX;

    math::float3 center() const noexcept {
        // float3 ctor needed for Visual Studio
        return (max + min) * math::float3(0.5f);
    }

    math::float3 extent() const noexcept {
        // float3 ctor needed for Visual Studio
        return (max - min) * math::float3(0.5f);
    }

    bool isEmpty() const noexcept {
        return any(greaterThanEqual(min, max));
    }

    struct Corners {
        using value_type = math::float3;
        value_type const* begin() const { return vertices; }
        value_type const* end() const { return vertices + 8; }
        value_type * begin() { return vertices; }
        value_type * end() { return vertices + 8; }
        value_type const* data() const { return vertices; }
        value_type * data() { return vertices; }
        size_t size() const { return 8; }
        value_type const& operator[](size_t i) const noexcept { return vertices[i]; }
        value_type& operator[](size_t i) noexcept { return vertices[i]; }
        value_type vertices[8];
    };

    Corners getCorners() const {
        return Aabb::Corners{ .vertices = {
                { min.x, min.y, min.z },
                { max.x, min.y, min.z },
                { min.x, max.y, min.z },
                { max.x, max.y, min.z },
                { min.x, min.y, max.z },
                { max.x, min.y, max.z },
                { min.x, max.y, max.z },
                { max.x, max.y, max.z },
        }};
    }

    float contains(math::float3 p) const noexcept {
        // we don't use std::max to avoid a dependency on <algorithm>
        auto const maximum = [](auto a, auto b) { return a > b ? a : b; };
        float d = min.x - p.x;
        d = maximum(d, min.y - p.y);
        d = maximum(d, min.z - p.z);
        d = maximum(d, p.x - max.x);
        d = maximum(d, p.y - max.y);
        d = maximum(d, p.z - max.z);
        return d;
    }

    static Aabb transform(const math::mat3f& m, math::float3 const& t, const Aabb& box) noexcept {
        // Fast AABB transformation per Jim Arvo in Graphics Gems (1990).
        Aabb result{ t, t };
        for (size_t col = 0; col < 3; ++col) {
            for (size_t row = 0; row < 3; ++row) {
                const float a = m[col][row] * box.min[col];
                const float b = m[col][row] * box.max[col];
                result.min[row] += a < b ? a : b;
                result.max[row] += a < b ? b : a;
            }
        }
        return result;
    }

    Aabb transform(const math::mat4f& m) const noexcept {
        return transform(m.upperLeft(), m[3].xyz, *this);
    }
};

} // namespace filament

#endif // TNT_FILAMENT_BOX_H
