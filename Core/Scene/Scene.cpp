#include "Scene.h"
#include "EntityHandle.h"
#include "Core/Graphics/Renderer.h"
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

void Scene::Render(Renderer* renderer) {
    glm::mat4 view_projection(1.0f);
    auto camera_view = registry_.view<Transform, CameraComponent>();
    for (auto entity : camera_view) {
        auto& cc = camera_view.get<CameraComponent>(entity);
        if (!cc.primary)
            continue;
        glm::mat4 view = glm::inverse(GetWorldMatrix(entity));
        view_projection = cc.camera.GetProjection() * view;
        break;
    }
    renderer->BeginScene(view_projection);

    auto view = registry_.view<Transform, RendererComponent>();
    for (auto entity : view) {
        auto& rc = view.get<RendererComponent>(entity);

        if (rc.depth_test)
            glEnable(GL_DEPTH_TEST);
        else
            glDisable(GL_DEPTH_TEST);

        if (rc.double_sided || !rc.culling)
            glDisable(GL_CULL_FACE);
        else {
            glEnable(GL_CULL_FACE);
            glCullFace(rc.cull_face);
        }

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
