
//! \file

#ifndef TNT_FILAMENT_BUFFEROBJECT_H
#define TNT_FILAMENT_BUFFEROBJECT_H

#include <filament/FilamentAPI.h>

#include <backend/DriverEnums.h>
#include <backend/BufferDescriptor.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include <stdint.h>
#include <stddef.h>

namespace filament {

class FBufferObject;

class Engine;

class UTILS_PUBLIC BufferObject : public FilamentAPI {
    struct BuilderDetails;

public:
    using BufferDescriptor = backend::BufferDescriptor;
    using BindingType = backend::BufferObjectBinding;

    class Builder : public BuilderBase<BuilderDetails> {
        friend struct BuilderDetails;
    public:
        Builder() noexcept;
        Builder(Builder const& rhs) noexcept;
        Builder(Builder&& rhs) noexcept;
        ~Builder() noexcept;
        Builder& operator=(Builder const& rhs) noexcept;
        Builder& operator=(Builder&& rhs) noexcept;

        Builder& size(uint32_t byteCount) noexcept;

        Builder& bindingType(BindingType bindingType) noexcept;

        BufferObject* UTILS_NONNULL build(Engine& engine);
    private:
        friend class FBufferObject;
    };

    void setBuffer(Engine& engine, BufferDescriptor&& buffer, uint32_t byteOffset = 0);

    size_t getByteCount() const noexcept;

protected:
    // prevent heap allocation
    ~BufferObject() = default;
};

} // namespace filament

#endif // TNT_FILAMENT_BUFFEROBJECT_H
