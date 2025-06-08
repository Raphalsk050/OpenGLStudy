
#ifndef TNT_FILAMENT_DETAILS_CULLER_H
#define TNT_FILAMENT_DETAILS_CULLER_H

#include <filament/Frustum.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/Slice.h"

#include "third_party/filament/libs/math/include/math/vec4.h"
#include "third_party/filament/libs/math/include/math/vec2.h"

namespace filament {


class Culler {
public:
    // Culler can only process buffers with a size multiple of MODULO
    static constexpr size_t MODULO = 8u;
    static inline size_t round(size_t count) noexcept {
        return (count + (MODULO - 1)) & ~(MODULO - 1);
    }

    using result_type = uint8_t;

    static void intersects(result_type* results,
            Frustum const& frustum,
            math::float3 const* center,
            math::float3 const* extent,
            size_t count, size_t bit) noexcept;

    static void intersects(
            result_type* results,
            Frustum const& frustum,
            math::float4 const* b,
            size_t count) noexcept;

    static bool intersects(
            Frustum const& frustum,
            Box const& box) noexcept;

    static bool intersects(
            Frustum const& frustum,
            math::float4 const& sphere) noexcept;


    struct UTILS_PUBLIC Test {
        static void intersects(result_type* results,
                Frustum const& frustum,
                math::float3 const* c,
                math::float3 const* e,
                size_t count) noexcept;

        static void intersects(result_type* results,
                Frustum const& frustum,
                math::float4 const* b,
                size_t count) noexcept;
    };
};

} // namespace filament

#endif // TNT_FILAMENT_DETAILS_CULLER_H
