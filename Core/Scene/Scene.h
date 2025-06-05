#pragma once
#include <entt.hpp>
#include <string>
#include "Components.h"
#include "Core/TimeStep.h"

namespace GLStudy {
    class EntityHandle;
    class Renderer;

    class Scene {
    public:
        Scene() = default;
        EntityHandle CreateEntity(const std::string& name = "Entity");

        void OnUpdate(Timestep ts);
        void OnViewportResize(uint32_t width, uint32_t height);

        void Render(Renderer* renderer);

        glm::mat4 GetWorldMatrix(entt::entity entity) const;

        entt::registry registry_;
    };
}

#include "EntityHandle.h"

