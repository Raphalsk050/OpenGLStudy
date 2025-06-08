
#ifndef TNT_GEOMETRY_TANGENTSPACEMESH_H
#define TNT_GEOMETRY_TANGENTSPACEMESH_H

#include "third_party/filament/libs/math/include/math/quat.h"
#include "third_party/filament/libs/math/include/math/vec3.h"
#include "third_party/filament/libs/math/include/math/vec4.h"

#include <variant>

namespace filament {
namespace geometry {

struct TangentSpaceMeshInput;
struct TangentSpaceMeshOutput;

class TangentSpaceMesh {
public:
    enum class Algorithm : uint8_t {
        DEFAULT = 0,

        MIKKTSPACE = 1,

        LENGYEL = 2,

        HUGHES_MOLLER = 3,

        FRISVAD = 4,
    };

    enum class AuxAttribute : uint8_t {
        UV1 = 0x0,
        COLORS = 0x1,
        JOINTS = 0x2,
        WEIGHTS = 0x3,
    };

    using InData = std::variant<filament::math::float2 const*, filament::math::float3 const*,
            filament::math::float4 const*, filament::math::ushort3 const*,
            filament::math::ushort4 const*>;

    class Builder {
    public:
        Builder() noexcept;
        ~Builder() noexcept;

        Builder(Builder&& that) noexcept;

        Builder& operator=(Builder&& that) noexcept;

        Builder(Builder const&) = delete;
        Builder& operator=(Builder const&) = delete;

        Builder& vertexCount(size_t vertexCount) noexcept;

        Builder& normals(filament::math::float3 const* normals, size_t stride = 0) noexcept;

        Builder& tangents(filament::math::float4 const* tangents, size_t stride = 0) noexcept;

        Builder& uvs(filament::math::float2 const* uvs, size_t stride = 0) noexcept;

        Builder& aux(AuxAttribute attribute, InData data, size_t stride = 0) noexcept;

        Builder& positions(filament::math::float3 const* positions, size_t stride = 0) noexcept;

        Builder& triangleCount(size_t triangleCount) noexcept;

        Builder& triangles(filament::math::uint3 const* triangles) noexcept;

        Builder& triangles(filament::math::ushort3 const* triangles) noexcept;

        Builder& algorithm(Algorithm algorithm) noexcept;

        TangentSpaceMesh* build();

    private:
        TangentSpaceMesh* mMesh = nullptr;
    };

     static void destroy(TangentSpaceMesh* mesh) noexcept;

    TangentSpaceMesh(TangentSpaceMesh&& that) noexcept;

    TangentSpaceMesh& operator=(TangentSpaceMesh&& that) noexcept;

    TangentSpaceMesh(TangentSpaceMesh const&) = delete;
    TangentSpaceMesh& operator=(TangentSpaceMesh const&) = delete;

    size_t getVertexCount() const noexcept;

    void getPositions(filament::math::float3* out, size_t stride = 0) const;

    void getUVs(filament::math::float2* out, size_t stride = 0) const;

    void getQuats(filament::math::quatf* out, size_t stride = 0) const noexcept;

    void getQuats(filament::math::short4* out, size_t stride = 0) const noexcept;

    void getQuats(filament::math::quath* out, size_t stride = 0) const noexcept;

    template<typename T>
    using is_supported_aux_t =
            typename std::enable_if<std::is_same<filament::math::float2, T>::value ||
                                    std::is_same<filament::math::float3, T>::value ||
                                    std::is_same<filament::math::float4, T>::value ||
                                    std::is_same<filament::math::ushort3, T>::value ||
                                    std::is_same<filament::math::ushort4, T>::value>::type;
    template<typename T, typename = is_supported_aux_t<T>>
    void getAux(AuxAttribute attribute, T* out, size_t stride = 0) const noexcept;

    size_t getTriangleCount() const noexcept;

    void getTriangles(filament::math::uint3* out) const;

    void getTriangles(filament::math::ushort3* out) const;

    bool remeshed() const noexcept;

private:
    ~TangentSpaceMesh() noexcept;
    TangentSpaceMesh() noexcept;
    TangentSpaceMeshInput* mInput;
    TangentSpaceMeshOutput* mOutput;

    friend class Builder;
};

} // namespace geometry
} // namespace filament

#endif //TNT_GEOMETRY_TANGENTSPACEMESH_H
