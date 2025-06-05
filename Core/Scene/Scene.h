#pragma once
#include <entt.hpp>
#include <string>
#include "Components.h"

namespace GLStudy {
    class EntityHandle;
    class Renderer;

    class Scene {
    public:
        Scene() = default;
        EntityHandle CreateEntity(const std::string& name = "Entity");

        void Render(Renderer* renderer);

        glm::mat4 GetWorldMatrix(entt::entity entity) const;

        entt::registry registry_;
    };
}

#include "EntityHandle.h"

