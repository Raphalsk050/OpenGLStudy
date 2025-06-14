
#ifndef TNT_FILAMENT_DETAILS_RENDERPRIMITIVE_H
#define TNT_FILAMENT_DETAILS_RENDERPRIMITIVE_H

#include <filament/RenderableManager.h>

#include "components/RenderableManager.h"

#include "details/MaterialInstance.h"

#include <backend/DriverEnums.h>
#include <backend/Handle.h>

#include <stdint.h>

namespace filament {

class FEngine;
class FVertexBuffer;
class FIndexBuffer;
class FRenderer;
class HwRenderPrimitiveFactory;

class FRenderPrimitive {
public:
    FRenderPrimitive() noexcept = default;

    void init(HwRenderPrimitiveFactory& factory, backend::DriverApi& driver,
            const RenderableManager::Builder::Entry& entry) noexcept;

    void set(HwRenderPrimitiveFactory& factory, backend::DriverApi& driver,
            RenderableManager::PrimitiveType type,
            FVertexBuffer* vertexBuffer, FIndexBuffer* indexBuffer, size_t offset,
            size_t count) noexcept;

    // frees driver resources, object becomes invalid
    void terminate(HwRenderPrimitiveFactory& factory, backend::DriverApi& driver);

    const FMaterialInstance* getMaterialInstance() const noexcept { return mMaterialInstance; }
    backend::RenderPrimitiveHandle getHwHandle() const noexcept { return mHandle; }
    backend::VertexBufferInfoHandle getVertexBufferInfoHandle() const { return mVertexBufferInfoHandle; }
    uint32_t getIndexOffset() const noexcept { return mIndexOffset; }
    uint32_t getIndexCount() const noexcept { return mIndexCount; }
    uint32_t getMorphingBufferOffset() const noexcept { return mMorphingBufferOffset; }

    backend::PrimitiveType getPrimitiveType() const noexcept { return mPrimitiveType; }
    AttributeBitset getEnabledAttributes() const noexcept { return mEnabledAttributes; }
    uint16_t getBlendOrder() const noexcept { return mBlendOrder; }
    bool isGlobalBlendOrderEnabled() const noexcept { return mGlobalBlendOrderEnabled; }

    void setMaterialInstance(FMaterialInstance const* mi) noexcept { mMaterialInstance = mi; }

    void setBlendOrder(uint16_t order) noexcept {
        mBlendOrder = static_cast<uint16_t>(order & 0x7FFF);
    }

    void setGlobalBlendOrderEnabled(bool enabled) noexcept {
        mGlobalBlendOrderEnabled = enabled;
    }

    void setMorphingBufferOffset(uint32_t offset) noexcept {
        mMorphingBufferOffset = offset;
    }

private:
    // These first fields are dereferences from PrimitiveInfo, keep them together
    struct {
        FMaterialInstance const* mMaterialInstance = nullptr;
        backend::Handle<backend::HwRenderPrimitive> mHandle = {};
        backend::Handle<backend::HwVertexBufferInfo> mVertexBufferInfoHandle = {};
        uint32_t mIndexOffset = 0;
        uint32_t mIndexCount = 0;
        uint32_t mMorphingBufferOffset = 0;
    };

    AttributeBitset mEnabledAttributes = {};
    uint16_t mBlendOrder = 0;
    bool mGlobalBlendOrderEnabled = false;
    backend::PrimitiveType mPrimitiveType = backend::PrimitiveType::TRIANGLES;
};

} // namespace filament

#endif // TNT_FILAMENT_DETAILS_RENDERPRIMITIVE_H
