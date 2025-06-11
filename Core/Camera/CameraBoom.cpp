#include "CameraBoom.h"
#include "Core/Scene/Components.h"
#include "Core/Camera/CameraController.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

namespace GLStudy {

void CameraBoomSystem::OnUpdate(Scene& scene, Timestep /*ts*/) {
    auto view = scene.registry_.view<TransformComponent, CameraBoomComponent>();
    for (auto entity : view) {
        auto& tr = view.get<TransformComponent>(entity);
        auto& boom = view.get<CameraBoomComponent>(entity);
        if (boom.target == entt::null)
            continue;
        const auto& target_tr = scene.registry_.get<TransformComponent>(boom.target);

        glm::vec3 forward{0.0f, 0.0f, -1.0f};
        if (scene.registry_.all_of<CameraControllerComponent>(entity)) {
            const auto& ctrl = scene.registry_.get<CameraControllerComponent>(entity);
            forward = glm::normalize(glm::vec3{
                cos(glm::radians(ctrl.yaw)) * cos(glm::radians(ctrl.pitch)),
                sin(glm::radians(ctrl.pitch)),
                sin(glm::radians(ctrl.yaw)) * cos(glm::radians(ctrl.pitch))});
        } else {
            glm::mat4 rot(1.0f);
            rot = glm::rotate(rot, tr.rotation.y, glm::vec3(0,1,0));
            rot = glm::rotate(rot, tr.rotation.x, glm::vec3(1,0,0));
            forward = glm::normalize(glm::vec3(rot * glm::vec4(0,0,-1,0)));
        }

        tr.position = target_tr.position - forward * boom.arm_length;
        tr.next_position = tr.position;
    }
}

} // namespace GLStudy
