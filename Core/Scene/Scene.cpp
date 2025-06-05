#include "Scene.h"
#include "EntityHandle.h"
#include "Core/Graphics/Renderer.h"
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

void Scene::Render(Renderer* renderer) {
    glm::mat4 view_projection(1.0f);
    auto camera_view = registry_.view<Transform, CameraComponent>();
    for (auto entity : camera_view) {
        auto& cc = camera_view.get<CameraComponent>(entity);
        if (!cc.primary)
            continue;
        const auto& tr = camera_view.get<Transform>(entity);
        glm::mat4 view;
        if (registry_.all_of<CameraControllerComponent>(entity)) {
            const auto& ctrl = registry_.get<CameraControllerComponent>(entity);
            glm::vec3 front{
                cos(glm::radians(ctrl.yaw)) * cos(glm::radians(ctrl.pitch)),
                sin(glm::radians(ctrl.pitch)),
                sin(glm::radians(ctrl.yaw)) * cos(glm::radians(ctrl.pitch))};
            front = glm::normalize(front);
            view = glm::lookAt(tr.position, tr.position + front, glm::vec3(0.0f, 1.0f, 0.0f));
        } else {
            view = glm::inverse(GetWorldMatrix(entity));
        }
        view_projection = cc.camera.GetProjection() * view;
        break;
    }
    renderer->BeginScene(view_projection);

    auto view = registry_.view<Transform, RendererComponent>();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    for (auto entity : view) {
        auto& rc = view.get<RendererComponent>(entity);

        switch (rc.mesh) {
        case MeshType::Cube:
            renderer->DrawCube(GetWorldMatrix(entity), rc.color);
            break;
        case MeshType::Triangle:
        default:
            renderer->DrawTriangle(GetWorldMatrix(entity), rc.color);
            break;
        }
    }
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
