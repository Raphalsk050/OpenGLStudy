
//! \file

#ifndef TNT_FILAMENT_VERTEXBUFFER_H
#define TNT_FILAMENT_VERTEXBUFFER_H

#include <filament/FilamentAPI.h>
#include <filament/MaterialEnums.h>

#include <backend/BufferDescriptor.h>
#include <backend/DriverEnums.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include <stddef.h>
#include <stdint.h>

namespace filament {

class FVertexBuffer;

class BufferObject;
class Engine;

class UTILS_PUBLIC VertexBuffer : public FilamentAPI {
    struct BuilderDetails;

public:
    using AttributeType = backend::ElementType;
    using BufferDescriptor = backend::BufferDescriptor;

    class Builder : public BuilderBase<BuilderDetails> {
        friend struct BuilderDetails;
    public:
        Builder() noexcept;
        Builder(Builder const& rhs) noexcept;
        Builder(Builder&& rhs) noexcept;
        ~Builder() noexcept;
        Builder& operator=(Builder const& rhs) noexcept;
        Builder& operator=(Builder&& rhs) noexcept;

        Builder& bufferCount(uint8_t bufferCount) noexcept;

        Builder& vertexCount(uint32_t vertexCount) noexcept;

        Builder& enableBufferObjects(bool enabled = true) noexcept;

        Builder& attribute(VertexAttribute attribute, uint8_t bufferIndex,
                AttributeType attributeType,
                uint32_t byteOffset = 0, uint8_t byteStride = 0) noexcept;

        Builder& normalized(VertexAttribute attribute, bool normalize = true) noexcept;

        Builder& advancedSkinning(bool enabled) noexcept;

        VertexBuffer* UTILS_NONNULL build(Engine& engine);

    private:
        friend class FVertexBuffer;
    };

    size_t getVertexCount() const noexcept;

    void setBufferAt(Engine& engine, uint8_t bufferIndex, BufferDescriptor&& buffer,
            uint32_t byteOffset = 0);

    void setBufferObjectAt(Engine& engine, uint8_t bufferIndex,
            BufferObject const*  UTILS_NONNULL bufferObject);

protected:
    // prevent heap allocation
    ~VertexBuffer() = default;
};

} // namespace filament

#endif // TNT_FILAMENT_VERTEXBUFFER_H
