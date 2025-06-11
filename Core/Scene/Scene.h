#pragma once
#include <entt.hpp>
#include <string>
#include "Components.h"
#include "Core/TimeStep.h"
#include "Core/Events/Event.h"

namespace GLStudy {
    class EntityHandle;
    class Renderer;

    class Scene {
    public:
        Scene() = default;
        EntityHandle CreateEntity(const std::string& name = "Entity");

        void OnUpdate(Timestep ts);
        void LateUpdate(Timestep ts);
        void OnEvent(Event& e);
        void OnViewportResize(float width, float height);

        void Render(Renderer* renderer);

        glm::mat4 GetWorldMatrix(entt::entity entity) const;

        /**
         * Compute the world matrix using interpolation between the previous and
         * current transform state. "alpha" should be in range [0,1] where 0
         * corresponds to the previous state and 1 to the current.
         */
        glm::mat4 GetInterpolatedWorldMatrix(entt::entity entity, float alpha) const;

        entt::registry registry_;
    };
}

#include "EntityHandle.h"

