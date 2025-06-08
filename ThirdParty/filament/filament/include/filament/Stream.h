
#ifndef TNT_FILAMENT_STREAM_H
#define TNT_FILAMENT_STREAM_H

#include <filament/FilamentAPI.h>

#include <backend/DriverEnums.h>
#include <backend/CallbackHandler.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include <stdint.h>

namespace filament {

class FStream;

class Engine;

class UTILS_PUBLIC Stream : public FilamentAPI {
    struct BuilderDetails;

public:
    using Callback = backend::StreamCallback;
    using StreamType = backend::StreamType;

    class Builder : public BuilderBase<BuilderDetails> {
        friend struct BuilderDetails;
    public:
        Builder() noexcept;
        Builder(Builder const& rhs) noexcept;
        Builder(Builder&& rhs) noexcept;
        ~Builder() noexcept;
        Builder& operator=(Builder const& rhs) noexcept;
        Builder& operator=(Builder&& rhs) noexcept;

        Builder& stream(void* UTILS_NULLABLE stream) noexcept;

        Builder& width(uint32_t width) noexcept;

        Builder& height(uint32_t height) noexcept;

        Stream* UTILS_NONNULL build(Engine& engine);

    private:
        friend class FStream;
    };

    StreamType getStreamType() const noexcept;

    void setAcquiredImage(void* UTILS_NONNULL image,
            Callback UTILS_NONNULL callback, void* UTILS_NULLABLE userdata) noexcept;

    void setAcquiredImage(void* UTILS_NONNULL image,
            backend::CallbackHandler* UTILS_NULLABLE handler,
            Callback UTILS_NONNULL callback, void* UTILS_NULLABLE userdata) noexcept;

    void setDimensions(uint32_t width, uint32_t height) noexcept;

    int64_t getTimestamp() const noexcept;

protected:
    // prevent heap allocation
    ~Stream() = default;
};

} // namespace filament

#endif // TNT_FILAMENT_STREAM_H
