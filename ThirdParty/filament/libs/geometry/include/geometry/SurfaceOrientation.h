
#ifndef TNT_GEOMETRY_SURFACEORIENTATION_H
#define TNT_GEOMETRY_SURFACEORIENTATION_H

#include "third_party/filament/libs/math/include/math/quat.h"
#include "third_party/filament/libs/math/include/math/vec3.h"
#include "third_party/filament/libs/math/include/math/vec4.h"

#include "third_party/filament/libs/utils/include/utils/compiler.h"

namespace filament {

namespace geometry {

struct OrientationBuilderImpl;
struct OrientationImpl;

class UTILS_PUBLIC SurfaceOrientation {
public:

    class Builder {
    public:
        Builder() noexcept;
        ~Builder() noexcept;
        Builder(Builder&& that) noexcept;
        Builder& operator=(Builder&& that) noexcept;

        Builder& vertexCount(size_t vertexCount) noexcept;

        Builder& normals(const filament::math::float3*, size_t stride = 0) noexcept;
        Builder& tangents(const filament::math::float4*, size_t stride = 0) noexcept;
        Builder& uvs(const filament::math::float2*, size_t stride = 0) noexcept;
        Builder& positions(const filament::math::float3*, size_t stride = 0) noexcept;

        Builder& triangleCount(size_t triangleCount) noexcept;
        Builder& triangles(const filament::math::uint3*) noexcept;
        Builder& triangles(const filament::math::ushort3*) noexcept;

        SurfaceOrientation* build();

    private:
        OrientationBuilderImpl* mImpl;
        Builder(const Builder&) = delete;
        Builder& operator=(const Builder&) = delete;
    };

    ~SurfaceOrientation() noexcept;
    SurfaceOrientation(SurfaceOrientation&& that) noexcept;
    SurfaceOrientation& operator=(SurfaceOrientation&& that) noexcept;

    size_t getVertexCount() const noexcept;

    void getQuats(filament::math::quatf* out, size_t quatCount, size_t stride = 0) const noexcept;
    void getQuats(filament::math::short4* out, size_t quatCount, size_t stride = 0) const noexcept;
    void getQuats(filament::math::quath* out, size_t quatCount, size_t stride = 0) const noexcept;

private:
    SurfaceOrientation(OrientationImpl*) noexcept;
    SurfaceOrientation(const SurfaceOrientation&) = delete;
    SurfaceOrientation& operator=(const SurfaceOrientation&) = delete;
    OrientationImpl* mImpl;
    friend struct OrientationBuilderImpl;
};

} // namespace geometry
} // namespace filament

#endif // TNT_GEOMETRY_SURFACEORIENTATION_H
