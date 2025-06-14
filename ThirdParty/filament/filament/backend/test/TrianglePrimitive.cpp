
#include "TrianglePrimitive.h"

namespace test {

using namespace filament;
using namespace filament::backend;

static constexpr filament::math::float2 gVertices[3] = {
    { -1.0, -1.0 },
    {  1.0, -1.0 },
    { -1.0,  1.0 }
};

static constexpr TrianglePrimitive::index_type gIndices[3] = { 0, 1, 2 };

TrianglePrimitive::TrianglePrimitive(filament::backend::DriverApi& driverApi,
        bool allocateLargeBuffers) : mDriverApi(driverApi) {
    mVertexCount = allocateLargeBuffers ? 2048 : 3;
    mIndexCount = allocateLargeBuffers ? 4096 : 3;
    AttributeArray attributes = {
            Attribute {
                    .offset = 0,
                    .stride = sizeof(filament::math::float2),
                    .buffer = 0,
                    .type = ElementType::FLOAT2,
                    .flags = 0
            }
    };

    // location 5 comes from test_MissingRequiredAttributes.cpp shader
    attributes[5].flags |= Attribute::FLAG_INTEGER_TARGET;

    const size_t size = sizeof(math::float2) * 3;
    mBufferObject = mDriverApi.createBufferObject(size, BufferObjectBinding::VERTEX, BufferUsage::STATIC);
    mVertexBufferInfo = mDriverApi.createVertexBufferInfo(1, 1, attributes);
    mVertexBuffer = mDriverApi.createVertexBuffer(mVertexCount, mVertexBufferInfo);

    mDriverApi.setVertexBufferObject(mVertexBuffer, 0, mBufferObject);
    BufferDescriptor vertexBufferDesc(gVertices, size);
    mDriverApi.updateBufferObject(mBufferObject, std::move(vertexBufferDesc), 0);

    ElementType elementType = ElementType::UINT;
    static_assert(sizeof(index_type) == 4);
    mIndexBuffer = mDriverApi.createIndexBuffer(elementType, mIndexCount, BufferUsage::STATIC);
    BufferDescriptor indexBufferDesc(gIndices, sizeof(index_type) * 3);
    mDriverApi.updateIndexBuffer(mIndexBuffer, std::move(indexBufferDesc), 0);

    mRenderPrimitive = mDriverApi.createRenderPrimitive(
            mVertexBuffer, mIndexBuffer, PrimitiveType::TRIANGLES);
}

void TrianglePrimitive::updateVertices(const filament::math::float2 vertices[3]) noexcept {
    void* buffer = malloc(sizeof(filament::math::float2) * mVertexCount);
    filament::math::float2* vertBuffer = (filament::math::float2*) buffer;
    std::copy(vertices, vertices + 3, vertBuffer);

    BufferDescriptor vBuffer(vertBuffer, sizeof(filament::math::float2) * mVertexCount,
            [] (void* buffer, size_t size, void* user) {
        free(buffer);
    });
    mDriverApi.updateBufferObject(mBufferObject, std::move(vBuffer), 0);
}

void TrianglePrimitive::updateIndices(const index_type indices[3]) noexcept {
    void* buffer = malloc(sizeof(index_type) * mIndexCount);
    index_type* indexBuffer = (index_type*) buffer;
    std::copy(indices, indices + 3, indexBuffer);

    BufferDescriptor bufferDesc(indexBuffer, sizeof(index_type) * mIndexCount,
            [] (void* buffer, size_t size, void* user) {
        free(buffer);
    });
    mDriverApi.updateIndexBuffer(mIndexBuffer, std::move(bufferDesc), 0);
}

void TrianglePrimitive::updateIndices(const index_type* indices, int count, int offset) noexcept {
    void* buffer = malloc(sizeof(index_type) * count);
    index_type* indexBuffer = (index_type*) buffer;
    std::copy(indices, indices + count, indexBuffer);

    BufferDescriptor bufferDesc(indexBuffer, sizeof(index_type) * count,
            [] (void* buffer, size_t size, void* user) {
        free(buffer);
    });
    mDriverApi.updateIndexBuffer(mIndexBuffer, std::move(bufferDesc), offset * sizeof(index_type));
}

TrianglePrimitive::~TrianglePrimitive() {
    mDriverApi.destroyBufferObject(mBufferObject);
    mDriverApi.destroyVertexBuffer(mVertexBuffer);
    mDriverApi.destroyVertexBufferInfo(mVertexBufferInfo);
    mDriverApi.destroyIndexBuffer(mIndexBuffer);
    mDriverApi.destroyRenderPrimitive(mRenderPrimitive);
}

TrianglePrimitive::PrimitiveHandle TrianglePrimitive::getRenderPrimitive() const noexcept {
    return mRenderPrimitive;
}

} // namespae test
