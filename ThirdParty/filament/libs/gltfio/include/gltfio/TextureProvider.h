
#ifndef GLTFIO_TEXTUREPROVIDER_H
#define GLTFIO_TEXTUREPROVIDER_H

#include <stddef.h>
#include <stdint.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/BitmaskEnum.h"

namespace filament {
    class Engine;
    class Texture;
}

namespace filament::gltfio {

class UTILS_PUBLIC TextureProvider {
public:
    using Texture = filament::Texture;

    enum class TextureFlags : uint64_t {
        NONE = 0,
        sRGB = 1 << 0,
    };

    virtual Texture* pushTexture(const uint8_t* data, size_t byteCount,
            const char* mimeType, TextureFlags flags) = 0;

    virtual Texture* popTexture() = 0;

    virtual void updateQueue() = 0;

    virtual const char* getPushMessage() const = 0;

    virtual const char* getPopMessage() const = 0;

    virtual void waitForCompletion() = 0;

    virtual void cancelDecoding() = 0;

    virtual size_t getPoppedCount() const = 0;

TextureProvider* createStbProvider(filament::Engine* engine);

TextureProvider* createKtx2Provider(filament::Engine* engine);

} // namespace filament::gltfio

template<> struct utils::EnableBitMaskOperators<filament::gltfio::TextureProvider::TextureFlags>
        : public std::true_type {};

#endif // GLTFIO_TEXTUREPROVIDER_H
