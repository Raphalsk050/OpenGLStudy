
#ifndef GLTFIO_DEPENDENCY_GRAPH_H
#define GLTFIO_DEPENDENCY_GRAPH_H

#include "third_party/filament/libs/utils/include/utils/Entity.h"

#include "robin_map/include/tsl/robin_map.h"
#include "robin_map/include/tsl/robin_set.h"

#include <queue>
#include <string>

namespace filament {
    class MaterialInstance;
    class Texture;
}

namespace filament::gltfio {

class DependencyGraph {
public:
    using Material = MaterialInstance;
    using Entity = utils::Entity;

    // Pops up to "count" ready-to-render entities off the queue.
    //
    // If "result" is non-null, returns the number of written items.
    // If "result" is null, returns the number of available entities.
    size_t popRenderables(Entity* result, size_t count) noexcept;

    void addEdge(Entity entity, Material* material);
    void addEdge(Material* material, const char* parameter);
    void addEdge(Texture* texture, Material* material, const char* parameter);

    // Commits a set of edges to the graph. This simply triggers a check to see if
    // any entities are already ready, e.g. if any entities are non-textured.
    void commitEdges();

    // Marks the given texture as being fully decoded, with all miplevels initialized.
    void markAsReady(Texture* texture);

    // Causes the dependency graph to enter a disabled state, whereby adding Entity <=> Material
    // edges will immediately mark the entity as ready without actually growing the graph.
    void disableProgressiveReveal();

private:
    struct TextureNode {
        Texture* texture;
        bool ready;
    };

    struct MaterialNode {
        tsl::robin_map<std::string, TextureNode*> params;
    };

    struct EntityNode {
        tsl::robin_set<Material*> materials;
        size_t numReadyMaterials = 0;
    };

    void checkReadiness(Material* material);
    void markAsReady(Material* material);
    TextureNode* getStatus(Texture* texture);

    // The following maps contain the directed edges in the graph.
    tsl::robin_map<Entity, EntityNode, Entity::Hasher> mEntityToMaterial;
    tsl::robin_map<Material*, tsl::robin_set<Entity, Entity::Hasher>> mMaterialToEntity;
    tsl::robin_map<Material*, MaterialNode> mMaterialToTexture;
    tsl::robin_map<Texture*, tsl::robin_set<Material*>> mTextureToMaterial;

    // Each texture (and its readiness flag) can be referenced from multiple nodes, so we own
    // a collection of wrapper objects in the following map. This uses std::unique_ptr to allow
    // nodes to refer to a texture wrapper using a stable weak pointer.
    tsl::robin_map<Texture*, std::unique_ptr<TextureNode>> mTextureNodes;

    std::queue<Entity> mReadyRenderables;
    bool mDisabled = false;
};

} // namespace filament::gltfio

#endif // GLTFIO_DEPENDENCY_GRAPH_H
