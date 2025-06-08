#pragma once
#include <entt.hpp>
#include <string>
#include "Components.h"
#include "Core/TimeStep.h"
#include "Core/Events/Event.h"

namespace GLStudy {
    class EntityHandle;
    class FilamentRenderer;

    class Scene {
    public:
        Scene() = default;
        EntityHandle CreateEntity(const std::string& name = "Entity");

        void OnUpdate(Timestep ts);
        void OnEvent(Event& e);
        void OnViewportResize(float width, float height);

        void Render(FilamentRenderer* renderer);

        glm::mat4 GetWorldMatrix(entt::entity entity) const;

        entt::registry registry_;
    };
}

#include "EntityHandle.h"

