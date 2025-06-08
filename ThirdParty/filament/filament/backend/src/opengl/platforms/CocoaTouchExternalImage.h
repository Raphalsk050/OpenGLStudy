
#ifndef FILAMENT_DRIVER_OPENGL_COCOA_TOUCH_EXTERNAL_IMAGE
#define FILAMENT_DRIVER_OPENGL_COCOA_TOUCH_EXTERNAL_IMAGE

#include "../gl_headers.h"

#include <backend/platforms/OpenGLPlatform.h>

#include <CoreVideo/CoreVideo.h>

namespace filament::backend {

class CocoaTouchExternalImage final : public OpenGLPlatform::ExternalTexture {
public:

    class SharedGl {
    public:
        SharedGl() noexcept;
        ~SharedGl() noexcept;

        SharedGl(const SharedGl&) = delete;
        SharedGl& operator=(const SharedGl&) = delete;

        GLuint program = 0;
        GLuint sampler = 0;
        GLuint fragmentShader = 0;
        GLuint vertexShader = 0;
    };

    CocoaTouchExternalImage(const CVOpenGLESTextureCacheRef textureCache,
            const SharedGl& sharedGl) noexcept;
    ~CocoaTouchExternalImage() noexcept;

    bool set(CVPixelBufferRef p) noexcept;

    GLuint getGlTexture() const noexcept;
    GLuint getInternalFormat() const noexcept;
    GLuint getTarget() const noexcept;

private:

    void release() noexcept;
    CVOpenGLESTextureRef createTextureFromImage(CVPixelBufferRef image, GLuint glFormat,
            GLenum format, size_t plane) noexcept;
    GLuint encodeColorConversionPass(GLuint yPlaneTexture, GLuint colorTexture, size_t width,
            size_t height) noexcept;

    class State {
    public:
        void save() noexcept;
        void restore() noexcept;

    private:
        GLint textureBinding[2] = { 0 };
        GLint framebuffer = 0;
        GLint array = 0;
        GLint vertexAttrib = 0;
        GLint vertexArray = 0;
        GLint viewport[4] = { 0 };
        GLint activeTexture = 0;
        GLint sampler[2] = { 0 };
    } mState;

    GLuint mFBO = 0;
    const SharedGl& mSharedGl;

    bool mEncodedToRgb = false;
    GLuint mRgbTexture = 0;

    const CVOpenGLESTextureCacheRef mTextureCache;
    CVPixelBufferRef mImage = nullptr;
    CVOpenGLESTextureRef mTexture = nullptr;

};

} // namespace filament::backend

#endif
