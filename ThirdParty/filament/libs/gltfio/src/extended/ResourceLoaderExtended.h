
#ifndef GLTFIO_RESOURCELOADEREXTENDED_H
#define GLTFIO_RESOURCELOADEREXTENDED_H

#include "../FFilamentAsset.h"

#include <vector>

namespace filament::gltfio {

struct ResourceLoaderExtended {
    using BufferSlot = FFilamentAsset::ResourceInfoExtended::BufferSlot;
    static void loadResources(
        std::vector<BufferSlot> const& slots, filament::Engine* engine,
        std::vector<BufferObject*>& bufferObjects);
};

} // namespace filament::gltfio

#endif // GLTFIO_RESOURCELOADEREXTENDED_H
