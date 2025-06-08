#include "Scene.h"
#include "EntityHandle.h"
#include "Core/Graphics/Renderer.h"
#include "Core/Graphics/Model.h"
#include "Core/Graphics/Skybox.h"
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
    glm::mat4 view_matrix(1.0f);
    glm::mat4 projection(1.0f);
    glm::vec3 cam_pos{0.0f};
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    auto camera_view = registry_.view<Transform, CameraComponent>();
    for (auto entity : camera_view) {
        auto& cc = camera_view.get<CameraComponent>(entity);
        if (!cc.primary)
            continue;
        const auto& tr = camera_view.get<Transform>(entity);
        if (registry_.all_of<CameraControllerComponent>(entity)) {
            const auto& ctrl = registry_.get<CameraControllerComponent>(entity);
            glm::vec3 front{
                cos(glm::radians(ctrl.yaw)) * cos(glm::radians(ctrl.pitch)),
                sin(glm::radians(ctrl.pitch)),
                sin(glm::radians(ctrl.yaw)) * cos(glm::radians(ctrl.pitch))};
            front = glm::normalize(front);
            view_matrix = glm::lookAt(tr.position, tr.position + front, glm::vec3(0.0f, 1.0f, 0.0f));
        } else {
            view_matrix = glm::inverse(GetWorldMatrix(entity));
        }
        projection = cc.camera.GetProjection();
        view_projection = projection * view_matrix;
        cam_pos = tr.position;
        break;
    }
    std::vector<Renderer::LightData> lights;
    auto light_view = registry_.view<Transform, LightComponent>();
    for (auto entity : light_view) {
        const auto& lt = light_view.get<LightComponent>(entity);
        const auto& tr = light_view.get<Transform>(entity);
        Renderer::LightData data{};
        data.type = lt.type;
        data.position = tr.position;
        data.direction = lt.direction;
        data.color = lt.color;
        data.intensity = lt.intensity;
        data.range = lt.range;
        data.inner_cutoff = glm::cos(glm::radians(lt.inner_cutoff));
        data.outer_cutoff = glm::cos(glm::radians(lt.outer_cutoff));
        lights.push_back(data);
    }
    renderer->BeginScene(view_projection, cam_pos, lights);

    auto sky_view = registry_.view<SkyboxComponent>();
    bool has_skybox = false;
    for (auto entity : sky_view) {
        auto& sb = sky_view.get<SkyboxComponent>(entity);
        if (sb.skybox) {
            sb.skybox->Draw(view_matrix, projection);
            sb.skybox->Bind(4);
            sb.skybox->Bind(5);
            sb.skybox->Bind(6);
            has_skybox = true;
            break;
        }
    }
    glUseProgram(renderer->GetShaderProgram());
    glUniform1i(glGetUniformLocation(renderer->GetShaderProgram(), "u_IrradianceMap"), 4);
    glUniform1i(glGetUniformLocation(renderer->GetShaderProgram(), "u_PrefilterMap"), 5);
    glUniform1i(glGetUniformLocation(renderer->GetShaderProgram(), "u_BrdfLUT"), 6);
    glUniform1i(glGetUniformLocation(renderer->GetShaderProgram(), "u_UseIBL"), has_skybox ? 1 : 0);
    if(renderer->GetBrdfLUT())
        renderer->GetBrdfLUT()->Bind(6);

    auto render_view = registry_.view<Transform, RendererComponent>();
    auto model_view = registry_.view<Transform, ModelComponent>();

    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    //glEnable(GL_CULL_FACE);
    //glFrontFace(GL_CCW);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    for (auto entity : render_view) {
        auto& rc = render_view.get<RendererComponent>(entity);

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
    renderer->Flush();
    for (auto entity : model_view) {
        auto& mc = model_view.get<ModelComponent>(entity);
        if (mc.model)
            mc.model->Draw(renderer->GetShaderProgram(), GetWorldMatrix(entity));
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
