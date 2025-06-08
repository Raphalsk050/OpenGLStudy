
#ifndef TNT_TRIANGLEPRIMITIVE_H
#define TNT_TRIANGLEPRIMITIVE_H

#include "private/backend/DriverApi.h"

#include "third_party/filament/libs/math/include/math/vec2.h"

namespace test {

class TrianglePrimitive {
public:

    using PrimitiveHandle = filament::backend::Handle<filament::backend::HwRenderPrimitive>;
    using BufferObjectHandle = filament::backend::Handle<filament::backend::HwBufferObject>;
    using VertexInfoHandle = filament::backend::Handle<filament::backend::HwVertexBufferInfo>;
    using VertexHandle = filament::backend::Handle<filament::backend::HwVertexBuffer>;
    using IndexHandle = filament::backend::Handle<filament::backend::HwIndexBuffer>;

    using index_type = uint32_t;

    TrianglePrimitive(filament::backend::DriverApi& driverApi, bool allocateLargeBuffers = false);
    ~TrianglePrimitive();

    PrimitiveHandle getRenderPrimitive() const noexcept;

    void updateVertices(const filament::math::float2 vertices[3]) noexcept;
    void updateIndices(const index_type* indices) noexcept;
    void updateIndices(const index_type* indices, int count, int offset) noexcept;

private:

    size_t mVertexCount = 3;
    size_t mIndexCount = 3;

    filament::backend::DriverApi& mDriverApi;

    PrimitiveHandle mRenderPrimitive;
    BufferObjectHandle mBufferObject;
    VertexInfoHandle mVertexBufferInfo;
    VertexHandle mVertexBuffer;
    IndexHandle mIndexBuffer;

};

} // namespace test

#endif
