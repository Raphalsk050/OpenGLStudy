
#include "RenderPrimitive.h"

#include <filament/RenderableManager.h>
#include <filament/MaterialEnums.h>

#include "details/IndexBuffer.h"
#include "details/MaterialInstance.h"
#include "details/VertexBuffer.h"

#include <private/backend/CommandStream.h>
#include <backend/DriverApiForward.h>

#include "third_party/filament/libs/utils/include/utils/debug.h"

#include <stddef.h>

namespace filament {

void FRenderPrimitive::init(HwRenderPrimitiveFactory& factory, backend::DriverApi& driver,
        const RenderableManager::Builder::Entry& entry) noexcept {

    assert_invariant(entry.materialInstance);

    mMaterialInstance = downcast(entry.materialInstance);
    mBlendOrder = entry.blendOrder;

    if (entry.indices && entry.vertices) {
        FVertexBuffer* vertexBuffer = downcast(entry.vertices);
        FIndexBuffer* indexBuffer = downcast(entry.indices);
        set(factory, driver, entry.type, vertexBuffer, indexBuffer, entry.offset, entry.count);
    }
}

void FRenderPrimitive::terminate(HwRenderPrimitiveFactory& factory, backend::DriverApi& driver) {
    if (mHandle) {
        factory.destroy(driver, mHandle);
    }
}

void FRenderPrimitive::set(HwRenderPrimitiveFactory& factory, backend::DriverApi& driver,
        RenderableManager::PrimitiveType type,
        FVertexBuffer* vertexBuffer, FIndexBuffer* indexBuffer,
        size_t offset, size_t count) noexcept {
    if (mHandle) {
        factory.destroy(driver, mHandle);
    }

    AttributeBitset const enabledAttributes = vertexBuffer->getDeclaredAttributes();

    auto const& ebh = vertexBuffer->getHwHandle();
    auto const& ibh = indexBuffer->getHwHandle();

    mHandle = factory.create(driver, ebh, ibh, type);
    mVertexBufferInfoHandle = vertexBuffer->getVertexBufferInfoHandle();

    mPrimitiveType = type;
    mIndexOffset = offset;
    mIndexCount = count;
    mEnabledAttributes = enabledAttributes;
}

} // namespace filament
