
#ifndef TNT_FILAMENT_DETAILS_INDEXBUFFER_H
#define TNT_FILAMENT_DETAILS_INDEXBUFFER_H

#include "downcast.h"

#include <backend/Handle.h>

#include <filament/IndexBuffer.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"

namespace filament {

class FEngine;

class FIndexBuffer : public IndexBuffer {
public:
    FIndexBuffer(FEngine& engine, const Builder& builder);

    // frees driver resources, object becomes invalid
    void terminate(FEngine& engine);

    backend::Handle<backend::HwIndexBuffer> getHwHandle() const noexcept { return mHandle; }

    size_t getIndexCount() const noexcept { return mIndexCount; }

    void setBuffer(FEngine& engine, BufferDescriptor&& buffer, uint32_t byteOffset = 0);

private:
    friend class IndexBuffer;
    backend::Handle<backend::HwIndexBuffer> mHandle;
    uint32_t mIndexCount;
};

FILAMENT_DOWNCAST(IndexBuffer)

} // namespace filament

#endif // TNT_FILAMENT_DETAILS_INDEXBUFFER_H
