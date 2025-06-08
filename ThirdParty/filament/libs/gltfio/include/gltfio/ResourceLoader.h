
#ifndef GLTFIO_RESOURCELOADER_H
#define GLTFIO_RESOURCELOADER_H

#include <gltfio/FilamentAsset.h>

#include <filament/VertexBuffer.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"

namespace filament {
    class Engine;
}

namespace filament::gltfio {

struct FFilamentAsset;
class AssetPool;
class TextureProvider;

struct ResourceConfiguration {
    //! The engine that the loader should pass to builder objects (e.g.
    //! filament::Texture::Builder).
    class filament::Engine* engine;

    //! Optional path or URI that points to the base glTF file. This is used solely
    //! to resolve relative paths. The string pointer is not retained.
    const char* gltfPath;

    //! If true, adjusts skinning weights to sum to 1. Well formed glTF files do not need this,
    //! but it is useful for robustness.
    bool normalizeSkinningWeights;
};

class UTILS_PUBLIC ResourceLoader {
public:
    using BufferDescriptor = filament::backend::BufferDescriptor;

    explicit ResourceLoader(const ResourceConfiguration& config);
    ~ResourceLoader();


    void setConfiguration(const ResourceConfiguration& config);

    void addResourceData(const char* uri, BufferDescriptor&& buffer);

    void addTextureProvider(const char* mimeType, TextureProvider* provider);

    bool hasResourceData(const char* uri) const;

    void evictResourceData();

    bool loadResources(FilamentAsset* asset);

    bool asyncBeginLoad(FilamentAsset* asset);

    float asyncGetLoadProgress() const;

    void asyncUpdateLoad();

    void asyncCancelLoad();

private:
    bool loadResources(FFilamentAsset* asset, bool async);
    struct Impl;
    Impl* pImpl;
};

} // namespace filament::gltfio

#endif // GLTFIO_RESOURCELOADER_H

