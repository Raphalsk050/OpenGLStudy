
#ifndef TNT_FILAMENT_BACKEND_OPENGL_ANDROID_EXTERNAL_STREAM_MANAGER_ANDROID_H
#define TNT_FILAMENT_BACKEND_OPENGL_ANDROID_EXTERNAL_STREAM_MANAGER_ANDROID_H

#include "private/backend/VirtualMachineEnv.h"

#include <backend/Platform.h>

#if __has_include(<android/surface_texture.h>)
#   include <android/surface_texture.h>
#   include <android/surface_texture_jni.h>
#else
struct ASurfaceTexture;
typedef struct ASurfaceTexture ASurfaceTexture;
#endif

namespace filament::backend {

class ExternalStreamManagerAndroid {
public:
    using Stream = Platform::Stream;

    // must be called on GLES thread
    static ExternalStreamManagerAndroid& create() noexcept;

    // must be called on GLES thread
    static void destroy(ExternalStreamManagerAndroid* pExternalStreamManagerAndroid) noexcept;

    Stream* acquire(jobject surfaceTexture) noexcept;
    void release(Stream* stream) noexcept;

    // attach Stream to current GLES context
    void attach(Stream* stream, intptr_t tname) noexcept;

    // detach Stream to current GLES context
    void detach(Stream* stream) noexcept;

    // must be called on GLES context thread, updates the stream content
    void updateTexImage(Stream* stream, int64_t* timestamp) noexcept;

private:
    ExternalStreamManagerAndroid() noexcept;
    ~ExternalStreamManagerAndroid() noexcept;

    VirtualMachineEnv& mVm;
    JNIEnv* mJniEnv = nullptr;

    struct EGLStream : public Stream {
        jobject             jSurfaceTexture = nullptr;
        ASurfaceTexture*    nSurfaceTexture = nullptr;
    };

    inline JNIEnv* getEnvironment() noexcept {
        JNIEnv* env = mJniEnv;
        if (UTILS_UNLIKELY(!env)) {
            return getEnvironmentSlow();
        }
        return env;
    }

    JNIEnv* getEnvironmentSlow() noexcept;

    jmethodID mSurfaceTextureClass_updateTexImage{};
    jmethodID mSurfaceTextureClass_getTimestamp{};
    jmethodID mSurfaceTextureClass_attachToGLContext{};
    jmethodID mSurfaceTextureClass_detachFromGLContext{};
};

} // namespace filament::backend

#endif //TNT_FILAMENT_BACKEND_OPENGL_ANDROID_EXTERNAL_STREAM_MANAGER_ANDROID_H
