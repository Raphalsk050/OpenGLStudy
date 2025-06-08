
#ifndef TNT_FILAMENT_ATLASALLOCATOR_H
#define TNT_FILAMENT_ATLASALLOCATOR_H

#include "third_party/filament/libs/utils/include/utils/QuadTree.h"

#include <filament/Viewport.h>

#include <private/filament/EngineEnums.h>

class AtlasAllocator_AllocateFirstLevel_Test;
class AtlasAllocator_AllocateSecondLevel_Test;
class AtlasAllocator_AllocateMixed0_Test;
class AtlasAllocator_AllocateMixed1_Test;
class AtlasAllocator_AllocateMixed2_Test;

namespace filament {

class AtlasAllocator {

    struct Node {
        // whether this node is allocated. Implies no children.
        constexpr bool isAllocated() const noexcept { return allocated; }
        // whether this node has children. Implies it's not allocated.
        constexpr bool hasChildren() const noexcept { return children != 0; }
        // whether this node has all four children. Implies hasChildren().
        constexpr bool hasAllChildren() const noexcept { return children == 4; }
        bool allocated      : 1;    // true / false
        uint8_t children    : 3;    // 0, 1, 2, 3, 4
    };

    // this determines the number of layers we can use (3 layers == 64 quadtree entries)
    static constexpr size_t LAYERS_DEPTH = 3u;

    // this determines how many "sub-sizes" we can have from the base size.
    // e.g. with a max texture size of 1024, we can allocate 1024, 512, 256 and 128 textures.
    static constexpr size_t QUAD_TREE_DEPTH = 4u;

    // LAYERS_DEPTH limits the number of layers
    static_assert(CONFIG_MAX_SHADOW_LAYERS <= 1u << (LAYERS_DEPTH * 2u));

    // QuadTreeArray is limited to a maximum depth of 7
    using QuadTree = utils::QuadTreeArray<Node, LAYERS_DEPTH + QUAD_TREE_DEPTH>;
    using NodeId = QuadTree::NodeId;

public:
    explicit AtlasAllocator(size_t maxTextureSize) noexcept;

    struct Allocation {
        int32_t layer = -1;
        Viewport viewport;
    };
    Allocation allocate(size_t textureSize) noexcept;

    void clear(size_t maxTextureSize = 1024) noexcept;

private:
    friend AtlasAllocator_AllocateFirstLevel_Test;
    friend AtlasAllocator_AllocateSecondLevel_Test;
    friend AtlasAllocator_AllocateMixed0_Test;
    friend AtlasAllocator_AllocateMixed1_Test;
    friend AtlasAllocator_AllocateMixed2_Test;

    QuadTree::NodeId allocateInLayer(size_t n) noexcept;

    // quad-tree array to store the allocated list
    QuadTree mQuadTree{};
    uint8_t mMaxTextureSizePot = 0;
};

} // namespace filament

#endif // TNT_FILAMENT_ATLASALLOCATOR_H
