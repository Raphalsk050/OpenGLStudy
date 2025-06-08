
#ifndef GLTFIO_ASSETLOADER_H
#define GLTFIO_ASSETLOADER_H

#include <filament/Engine.h>
#include <filament/Material.h>

#include <gltfio/FilamentAsset.h>
#include <gltfio/FilamentInstance.h>
#include <gltfio/MaterialProvider.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"

namespace utils {
    class EntityManager;
    class NameComponentManager;
}

namespace filament::gltfio {

class NodeManager;

// Use this struct to enable mikktspace-based tangent-space computation.
struct AssetConfigurationExtended {
    //! Optional The same parameter as provided to \struct ResourceConfiguration ResourceLoader.h
    //! gltfio/ResourceLoader.h
    char const* gltfPath;

    //! Client can use this method to check if the extended implementation is supported on their
    //! platform or not.
    static bool isSupported();
};

struct AssetConfiguration {
    //! The engine that the loader should pass to builder objects (e.g.
    //! filament::VertexBuffer::Builder).
    class filament::Engine* engine;

    //! Controls whether the loader uses filamat to generate materials on the fly, or loads a small
    //! set of precompiled ubershader materials. Deleting the MaterialProvider is the client's
    //! responsibility. See createJitShaderProvider() and createUbershaderProvider().
    MaterialProvider* materials;

    //! Optional manager for associating string names with entities in the transform hierarchy.
    utils::NameComponentManager* names = nullptr;

    //! Overrides the factory used for creating entities in the transform hierarchy. If this is not
    //! specified, AssetLoader will use the singleton EntityManager associated with the current
    //! process.
    utils::EntityManager* entities = nullptr;

    //! Optional default node name for anonymous nodes
    char* defaultNodeName = nullptr;

    //! Optional to enable mikktspace tangents. Lifetime of struct only needs to be maintained for
    //  the duration of the constructor of AssetLoader.
    AssetConfigurationExtended* ext = nullptr;
};

class UTILS_PUBLIC AssetLoader {
public:

    static AssetLoader* create(const AssetConfiguration& config);

    static void destroy(AssetLoader** loader);

    FilamentAsset* createAsset(const uint8_t* bytes, uint32_t nbytes);

    FilamentAsset* createInstancedAsset(const uint8_t* bytes, uint32_t numBytes,
            FilamentInstance** instances, size_t numInstances);

    FilamentInstance* createInstance(FilamentAsset* asset);

    void enableDiagnostics(bool enable = true);

    void destroyAsset(const FilamentAsset* asset);

    const filament::Material* const* getMaterials() const noexcept;

    size_t getMaterialsCount() const noexcept;

    utils::NameComponentManager* getNames() const noexcept;

    NodeManager& getNodeManager() noexcept;

    MaterialProvider& getMaterialProvider() noexcept;

};

} // namespace filament::gltfio

#endif // GLTFIO_ASSETLOADER_H
