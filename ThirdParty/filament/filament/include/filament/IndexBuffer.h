
//! \file

#ifndef TNT_FILAMENT_INDEXBUFFER_H
#define TNT_FILAMENT_INDEXBUFFER_H

#include <filament/FilamentAPI.h>

#include <backend/DriverEnums.h>

#include <backend/BufferDescriptor.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include <stdint.h>
#include <stddef.h>

namespace filament {

class FIndexBuffer;

class Engine;

class UTILS_PUBLIC IndexBuffer : public FilamentAPI {
    struct BuilderDetails;

public:
    using BufferDescriptor = backend::BufferDescriptor;

    enum class IndexType : uint8_t {
        USHORT = uint8_t(backend::ElementType::USHORT),  //!< 16-bit indices
        UINT = uint8_t(backend::ElementType::UINT),      //!< 32-bit indices
    };

    class Builder : public BuilderBase<BuilderDetails> {
        friend struct BuilderDetails;
    public:
        Builder() noexcept;
        Builder(Builder const& rhs) noexcept;
        Builder(Builder&& rhs) noexcept;
        ~Builder() noexcept;
        Builder& operator=(Builder const& rhs) noexcept;
        Builder& operator=(Builder&& rhs) noexcept;

        Builder& indexCount(uint32_t indexCount) noexcept;

        Builder& bufferType(IndexType indexType) noexcept;

        IndexBuffer* UTILS_NONNULL build(Engine& engine);
    private:
        friend class FIndexBuffer;
    };

    void setBuffer(Engine& engine, BufferDescriptor&& buffer, uint32_t byteOffset = 0);

    size_t getIndexCount() const noexcept;

protected:
    // prevent heap allocation
    ~IndexBuffer() = default;
};

} // namespace filament

#endif // TNT_FILAMENT_INDEXBUFFER_H
