
#ifndef TNT_FILAMENT_BACKEND_OPENGL_OPENGL_PLATFORM_EGL_ANDROID_H
#define TNT_FILAMENT_BACKEND_OPENGL_OPENGL_PLATFORM_EGL_ANDROID_H

#include <backend/AcquiredImage.h>
#include <backend/Platform.h>
#include <backend/platforms/OpenGLPlatform.h>
#include <backend/platforms/PlatformEGL.h>

#include "third_party/filament/libs/utils/include/utils/android/PerformanceHintManager.h"

#include <chrono>

#include <stddef.h>
#include <stdint.h>

namespace filament::backend {

class ExternalStreamManagerAndroid;

class PlatformEGLAndroid : public PlatformEGL {
public:

    PlatformEGLAndroid() noexcept;
    ~PlatformEGLAndroid() noexcept override;

protected:

    // --------------------------------------------------------------------------------------------
    // Platform Interface

    int getOSVersion() const noexcept override;

    Driver* createDriver(void* sharedContext,
            const Platform::DriverConfig& driverConfig) noexcept override;

    // --------------------------------------------------------------------------------------------
    // OpenGLPlatform Interface

    void terminate() noexcept override;

    void beginFrame(
            int64_t monotonic_clock_ns,
            int64_t refreshIntervalNs,
            uint32_t frameId) noexcept override;

    void preCommit() noexcept override;

    void setPresentationTime(int64_t presentationTimeInNanosecond) noexcept override;


    Stream* createStream(void* nativeStream) noexcept override;
    void destroyStream(Stream* stream) noexcept override;
    void attach(Stream* stream, intptr_t tname) noexcept override;
    void detach(Stream* stream) noexcept override;
    void updateTexImage(Stream* stream, int64_t* timestamp) noexcept override;

    AcquiredImage transformAcquiredImage(AcquiredImage source) noexcept override;

private:
    struct InitializeJvmForPerformanceManagerIfNeeded {
        InitializeJvmForPerformanceManagerIfNeeded();
    };

    int mOSVersion;
    ExternalStreamManagerAndroid& mExternalStreamManager;
    InitializeJvmForPerformanceManagerIfNeeded const mInitializeJvmForPerformanceManagerIfNeeded;
    utils::PerformanceHintManager mPerformanceHintManager;
    utils::PerformanceHintManager::Session mPerformanceHintSession;

    using clock = std::chrono::high_resolution_clock;
    clock::time_point mStartTimeOfActualWork;
};

} // namespace filament::backend

#endif // TNT_FILAMENT_BACKEND_OPENGL_OPENGL_PLATFORM_EGL_ANDROID_H
