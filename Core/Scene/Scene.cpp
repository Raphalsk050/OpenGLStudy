#include "Scene.h"
#include "EntityHandle.h"
#include "Core/Graphics/FilamentRenderer.h"
#include "Core/Graphics/Model.h"
#include "Core/Camera/CameraController.h"
#include <glad/glad.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

namespace GLStudy {

EntityHandle Scene::CreateEntity(const std::string& name) {
    entt::entity e = registry_.create();
    EntityHandle handle{e, this};
    registry_.emplace<Transform>(e);
    registry_.emplace<TagComponent>(e, TagComponent{name});
    return handle;
}

void Scene::OnUpdate(Timestep ts) {
    CameraControllerSystem::OnUpdate(*this, ts);
}

void Scene::OnEvent(Event& e) {
    CameraControllerSystem::OnEvent(*this, e);
}

void Scene::OnViewportResize(float width, float height) {
    auto view = registry_.view<CameraComponent>();
    for (auto entity : view) {
        auto& cc = view.get<CameraComponent>(entity);
        cc.camera.SetViewportSize(width, height);
    }
}

void Scene::Render(FilamentRenderer* renderer) {
    // Minimal rendering flow for Filament
    renderer->BeginFrame();
    renderer->EndFrame();
}

glm::mat4 Scene::GetWorldMatrix(entt::entity entity) const {
    const auto& tr = registry_.get<Transform>(entity);
    glm::mat4 mat = tr.LocalMatrix();
    if (tr.parent != entt::null) {
        mat = GetWorldMatrix(tr.parent) * mat;
    }
    return mat;
}

} // namespace GLStudy
