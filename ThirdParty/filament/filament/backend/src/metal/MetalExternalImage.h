
#ifndef TNT_METALEXTERNALIMAGE_H
#define TNT_METALEXTERNALIMAGE_H

#import <backend/DriverEnums.h>

#include <CoreVideo/CoreVideo.h>
#include <Metal/Metal.h>

namespace filament {
namespace backend {

struct MetalContext;

class MetalExternalImage {

public:

    MetalExternalImage(MetalContext& context,
            TextureSwizzle r = TextureSwizzle::CHANNEL_0,
            TextureSwizzle g = TextureSwizzle::CHANNEL_1,
            TextureSwizzle b = TextureSwizzle::CHANNEL_2,
            TextureSwizzle a = TextureSwizzle::CHANNEL_3) noexcept;

    bool isValid() const noexcept;

    void set(CVPixelBufferRef image) noexcept;

    void set(CVPixelBufferRef image, size_t plane) noexcept;

    size_t getWidth() const noexcept { return mWidth; }

    size_t getHeight() const noexcept { return mHeight; }

    id<MTLTexture> getMetalTextureForDraw() const noexcept;

    static void shutdown(MetalContext& context) noexcept;

    static void assertWritableImage(CVPixelBufferRef image);

private:

    void unset();

    CVMetalTextureRef createTextureFromImage(CVPixelBufferRef image, MTLPixelFormat format,
            size_t plane);
    id<MTLTexture> createRgbTexture(size_t width, size_t height);
    id<MTLTexture> createSwizzledTextureView(id<MTLTexture> texture) const;
    id<MTLTexture> createSwizzledTextureView(CVMetalTextureRef texture) const;
    void ensureComputePipelineState();
    id<MTLCommandBuffer> encodeColorConversionPass(id<MTLTexture> inYPlane, id<MTLTexture>
            inCbCrTexture, id<MTLTexture> outTexture);

    static constexpr size_t Y_PLANE = 0;
    static constexpr size_t CBCR_PLANE = 1;

    MetalContext& mContext;

    // If the external image has a single plane, mImage and mTexture hold references to the image
    // and created Metal texture, respectively.
    // mTextureView is a view of mTexture with any swizzling applied.
    CVPixelBufferRef mImage = nullptr;
    CVMetalTextureRef mTexture = nullptr;
    id<MTLTexture> mTextureView = nullptr;
    size_t mWidth = 0;
    size_t mHeight = 0;

    // If the external image is in the YCbCr format, this holds the result of the converted RGB
    // texture.
    id<MTLTexture> mRgbTexture = nil;

    struct {
        TextureSwizzle r, g, b, a;
    } mSwizzle;
};

} // namespace backend
} // namespace filament

#endif //TNT_METALEXTERNALIMAGE_H
