
#ifndef GLTFIO_WIREFRAME_H
#define GLTFIO_WIREFRAME_H

#include <filament/IndexBuffer.h>
#include <filament/VertexBuffer.h>

#include "third_party/filament/libs/utils/include/utils/Entity.h"

namespace filament::gltfio {

struct FFilamentAsset;

struct Wireframe {
    Wireframe(FFilamentAsset* asset);
    ~Wireframe();
    const FFilamentAsset* mAsset;
    utils::Entity mEntity;
    filament::VertexBuffer* mVertexBuffer;
    filament::IndexBuffer* mIndexBuffer;
};

} // namsepace gltfio

#endif // GLTFIO_WIREFRAME_H
