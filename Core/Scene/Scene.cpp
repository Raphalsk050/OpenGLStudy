#include "Scene.h"
#include "EntityHandle.h"
#include "Core/Graphics/Renderer.h"
#include "Core/Input/Input.h"
#include "Core/Input/KeyCodes.h"
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

void Scene::OnViewportResize(uint32_t width, uint32_t height)
{
    auto view = registry_.view<CameraComponent>();
    for (auto entity : view)
    {
        auto& cc = view.get<CameraComponent>(entity);
        cc.camera.SetViewportSize(static_cast<float>(width), static_cast<float>(height));
    }
}

void Scene::OnUpdate(Timestep ts)
{
    auto controllers = registry_.view<Transform, CameraControllerComponent>();
    for (auto entity : controllers)
    {
        auto& tr = controllers.get<Transform>(entity);
        auto& ctrl = controllers.get<CameraControllerComponent>(entity);

        glm::vec2 mouse = Input::GetMousePosition();
        if (ctrl.first_mouse)
        {
            ctrl.last_mouse_position = mouse;
            ctrl.first_mouse = false;
        }

        float xoff = mouse.x - ctrl.last_mouse_position.x;
        float yoff = ctrl.last_mouse_position.y - mouse.y;
        ctrl.last_mouse_position = mouse;

        tr.rotation.y += xoff * ctrl.look_sensitivity;
        tr.rotation.x += yoff * ctrl.look_sensitivity;

        const float pitch_limit = glm::radians(89.0f);
        if (tr.rotation.x > pitch_limit) tr.rotation.x = pitch_limit;
        if (tr.rotation.x < -pitch_limit) tr.rotation.x = -pitch_limit;

        glm::vec3 forward{
            cos(tr.rotation.y) * cos(tr.rotation.x),
            sin(tr.rotation.x),
            sin(tr.rotation.y) * cos(tr.rotation.x)
        };
        forward = glm::normalize(forward);

        glm::vec3 move_forward = forward;
        move_forward.y = 0.0f;
        move_forward = glm::length(move_forward) > 0.0f
            ? glm::normalize(move_forward)
            : glm::vec3(0.0f, 0.0f, -1.0f);

        glm::vec3 right = glm::normalize(
            glm::cross(forward, glm::vec3(0.0f, 1.0f, 0.0f)));
        glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

        float velocity = ctrl.move_speed * ts.GetSeconds();
        if (Input::IsKeyPressed(Key::W)) tr.position += move_forward * velocity;
        if (Input::IsKeyPressed(Key::S)) tr.position -= move_forward * velocity;
        if (Input::IsKeyPressed(Key::A)) tr.position -= right * velocity;
        if (Input::IsKeyPressed(Key::D)) tr.position += right * velocity;
        if (Input::IsKeyPressed(Key::Q)) tr.position += up * velocity;
        if (Input::IsKeyPressed(Key::E)) tr.position -= up * velocity;
    }
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
