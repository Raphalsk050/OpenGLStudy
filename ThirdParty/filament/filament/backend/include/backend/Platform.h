
//! \file

#ifndef TNT_FILAMENT_BACKEND_PLATFORM_H
#define TNT_FILAMENT_BACKEND_PLATFORM_H

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/Invocable.h"

#include <stddef.h>
#include <stdint.h>

namespace filament::backend {

class Driver;

class UTILS_PUBLIC Platform {
public:
    struct SwapChain {};
    struct Fence {};
    struct Stream {};

    enum class StereoscopicType : uint8_t {
        NONE,
        INSTANCED,
        MULTIVIEW,
    };

    struct DriverConfig {
        size_t handleArenaSize = 0;

        size_t textureUseAfterFreePoolSize = 0;

        size_t metalUploadBufferSizeBytes = 512 * 1024;

        bool disableParallelShaderCompile = false;

        bool disableHandleUseAfterFreeCheck = false;

        bool forceGLES2Context = false;

        StereoscopicType stereoscopicType = StereoscopicType::NONE;
    };

    Platform() noexcept;

    virtual ~Platform() noexcept;

    virtual int getOSVersion() const noexcept = 0;

    virtual backend::Driver* UTILS_NULLABLE createDriver(void* UTILS_NULLABLE sharedContext,
            const DriverConfig& driverConfig) noexcept = 0;

    virtual bool pumpEvents() noexcept;

    using InsertBlobFunc = utils::Invocable<
            void(const void* UTILS_NONNULL key, size_t keySize,
                    const void* UTILS_NONNULL value, size_t valueSize)>;

    using RetrieveBlobFunc = utils::Invocable<
            size_t(const void* UTILS_NONNULL key, size_t keySize,
                    void* UTILS_NONNULL value, size_t valueSize)>;

    void setBlobFunc(InsertBlobFunc&& insertBlob, RetrieveBlobFunc&& retrieveBlob) noexcept;

    bool hasInsertBlobFunc() const noexcept;

    bool hasRetrieveBlobFunc() const noexcept;

    bool hasBlobFunc() const noexcept {
        return hasInsertBlobFunc() || hasRetrieveBlobFunc();
    }

    void insertBlob(const void* UTILS_NONNULL key, size_t keySize,
            const void* UTILS_NONNULL value, size_t valueSize);

    size_t retrieveBlob(const void* UTILS_NONNULL key, size_t keySize,
            void* UTILS_NONNULL value, size_t valueSize);

    using DebugUpdateStatFunc = utils::Invocable<void(const char* UTILS_NONNULL key, uint64_t value)>;

    void setDebugUpdateStatFunc(DebugUpdateStatFunc&& debugUpdateStat) noexcept;

    bool hasDebugUpdateStatFunc() const noexcept;

    void debugUpdateStat(const char* UTILS_NONNULL key, uint64_t value);

private:
    InsertBlobFunc mInsertBlob;
    RetrieveBlobFunc mRetrieveBlob;
    DebugUpdateStatFunc mDebugUpdateStat;
};

} // namespace filament

#endif // TNT_FILAMENT_BACKEND_PLATFORM_H
