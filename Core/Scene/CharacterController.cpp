#include "CharacterController.h"
#include "Components.h"
#include "Core/Input/Input.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

namespace GLStudy {

static entt::entity GetPrimaryCamera(Scene& scene) {
    auto view = scene.registry_.view<TransformComponent, CameraComponent>();
    for (auto entity : view) {
        auto& cc = view.get<CameraComponent>(entity);
        if (cc.primary)
            return entity;
    }
    return entt::null;
}

void CharacterControllerSystem::OnUpdate(Scene& scene, Timestep ts) {
    entt::entity cam_ent = GetPrimaryCamera(scene);
    glm::vec3 cam_forward{0.0f,0.0f,-1.0f};
    glm::vec3 cam_right{1.0f,0.0f,0.0f};
    if (cam_ent != entt::null) {
        const auto& cam_tr = scene.registry_.get<TransformComponent>(cam_ent);
        glm::mat4 rot(1.0f);
        rot = glm::rotate(rot, cam_tr.rotation.y, glm::vec3(0,1,0));
        rot = glm::rotate(rot, cam_tr.rotation.x, glm::vec3(1,0,0));
        cam_forward = glm::normalize(glm::vec3(rot * glm::vec4(0,0,-1,0)));
        cam_right = glm::normalize(glm::cross(cam_forward, glm::vec3(0,1,0)));
    }

    auto view = scene.registry_.view<TransformComponent, CharacterControllerComponent, RigidBodyComponent>();
    for (auto entity : view) {
        auto& tr = view.get<TransformComponent>(entity);
        auto& cc = view.get<CharacterControllerComponent>(entity);
        auto& rb = view.get<RigidBodyComponent>(entity);
        glm::vec3 move_dir{0.0f};
        if (Input::IsKeyPressed(Key::W)) move_dir += cam_forward;
        if (Input::IsKeyPressed(Key::S)) move_dir -= cam_forward;
        if (Input::IsKeyPressed(Key::D)) move_dir += cam_right;
        if (Input::IsKeyPressed(Key::A)) move_dir -= cam_right;
        if (glm::length(move_dir) > 0.0f)
            move_dir = glm::normalize(move_dir);
        tr.position += move_dir * cc.move_speed * ts.GetSeconds();

        if (Input::IsKeyPressed(Key::Space) && rb.body) {
            rb.body->get()->applyCentralImpulse(btVector3(0, cc.jump_force, 0));
        }
    }
}

} // namespace GLStudy
