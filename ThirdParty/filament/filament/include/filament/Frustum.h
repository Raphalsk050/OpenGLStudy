
//! \file

#ifndef TNT_FILAMENT_FRUSTUM_H
#define TNT_FILAMENT_FRUSTUM_H

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include "third_party/filament/libs/math/include/math/mat4.h"
#include "third_party/filament/libs/math/include/math/vec3.h"
#include "third_party/filament/libs/math/include/math/vec4.h"

#include "third_party/filament/libs/utils/include/utils/unwindows.h" // Because we define NEAR and FAR in the Plane enum.

#include <stdint.h>

namespace filament {

class Box;
class Culler;

class UTILS_PUBLIC Frustum {
public:
    enum class Plane : uint8_t {
        LEFT,
        RIGHT,
        BOTTOM,
        TOP,
        FAR,
        NEAR
    };

    Frustum() = default;
    Frustum(const Frustum& rhs) = default;
    Frustum(Frustum&& rhs) noexcept = default;
    Frustum& operator=(const Frustum& rhs) = default;
    Frustum& operator=(Frustum&& rhs) noexcept = default;

    explicit Frustum(const math::mat4f& pv);

    void setProjection(const math::mat4f& pv);

    math::float4 getNormalizedPlane(Plane plane) const noexcept;

    void getNormalizedPlanes(math::float4 planes[UTILS_NONNULL 6]) const noexcept;

    math::float4 const* UTILS_NONNULL getNormalizedPlanes() const noexcept { return mPlanes; }

    bool intersects(const Box& box) const noexcept;

    bool intersects(const math::float4& sphere) const noexcept;

    float contains(math::float3 p) const noexcept;

private:
    friend class Culler;
    math::float4 mPlanes[6];
};

} // namespace filament

#if !defined(NDEBUG)
namespace utils::io {
class ostream;
} // namespace utils::io
utils::io::ostream& operator<<(utils::io::ostream& out, filament::Frustum const& frustum);
#endif

#endif // TNT_FILAMENT_FRUSTUM_H
