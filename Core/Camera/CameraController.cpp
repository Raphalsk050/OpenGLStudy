#include "CameraController.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <gtx/quaternion.hpp>
#include <gtx/euler_angles.hpp>
#include "Core/Scene/Components.h"

namespace GLStudy {

static void ApplyMouseMovement(CameraControllerComponent& cc, MouseMovedEvent& e) {
    if (!cc.mouse_control_enabled)
        return;
    if (cc.first_mouse) {
        cc.last_mouse_position = {e.GetX(), e.GetY()};
        cc.first_mouse = false;
    }

    float xoffset = e.GetX() - cc.last_mouse_position.x;
    float yoffset = cc.last_mouse_position.y - e.GetY();
    cc.last_mouse_position = {e.GetX(), e.GetY()};

    xoffset *= cc.rotation_speed;
    yoffset *= cc.rotation_speed;

    cc.yaw += xoffset;
    cc.pitch += yoffset;

    if (cc.pitch > 89.0f) cc.pitch = 89.0f;
    if (cc.pitch < -89.0f) cc.pitch = -89.0f;
}

static void ApplyMouseScroll(CameraControllerComponent& cc, MouseScrolledEvent& e) {
    float zoomAmount = e.GetYOffset() * cc.zoom_speed;
    cc.movement_speed = std::max(1.0f, cc.movement_speed + zoomAmount);
}

static void ApplyKeyPressed(CameraControllerComponent& cc, KeyPressedEvent& e) {
    switch (e.GetKeyCode()) {
    case Key::W: cc.forward = true; break;
    case Key::S: cc.backward = true; break;
    case Key::A: cc.left = true; break;
    case Key::D: cc.right = true; break;
    case Key::Q: cc.up = true; break;
    case Key::E: cc.down = true; break;
    }
}

static void ApplyKeyReleased(CameraControllerComponent& cc, KeyReleasedEvent& e) {
    switch (e.GetKeyCode()) {
    case Key::W: cc.forward = false; break;
    case Key::S: cc.backward = false; break;
    case Key::A: cc.left = false; break;
    case Key::D: cc.right = false; break;
    case Key::Q: cc.up = false; break;
    case Key::E: cc.down = false; break;
    }
}

void CameraControllerSystem::OnEvent(Scene& scene, Event& e) {
    EventDispatcher dispatcher(e);
    dispatcher.Dispatch<MouseMovedEvent>([&](MouseMovedEvent& me){
        auto view = scene.registry_.view<CameraControllerComponent>();
        for (auto entity : view)
            ApplyMouseMovement(view.get<CameraControllerComponent>(entity), me);
        return false;
    });
    dispatcher.Dispatch<MouseScrolledEvent>([&](MouseScrolledEvent& me){
        auto view = scene.registry_.view<CameraControllerComponent>();
        for (auto entity : view)
            ApplyMouseScroll(view.get<CameraControllerComponent>(entity), me);
        return false;
    });
    dispatcher.Dispatch<KeyPressedEvent>([&](KeyPressedEvent& ke){
        auto view = scene.registry_.view<CameraControllerComponent>();
        for (auto entity : view)
            ApplyKeyPressed(view.get<CameraControllerComponent>(entity), ke);
        return false;
    });
    dispatcher.Dispatch<KeyReleasedEvent>([&](KeyReleasedEvent& ke){
        auto view = scene.registry_.view<CameraControllerComponent>();
        for (auto entity : view)
            ApplyKeyReleased(view.get<CameraControllerComponent>(entity), ke);
        return false;
    });
}

void CameraControllerSystem::OnUpdate(Scene& scene, Timestep ts) {
    auto view = scene.registry_.view<TransformComponent, CameraControllerComponent>();
    for (auto entity : view) {
        auto& tr = view.get<TransformComponent>(entity);
        auto& cc = view.get<CameraControllerComponent>(entity);

        glm::vec3 front{
            cos(glm::radians(cc.yaw)) * cos(glm::radians(cc.pitch)),
            sin(glm::radians(cc.pitch)),
            sin(glm::radians(cc.yaw)) * cos(glm::radians(cc.pitch))
        };
        front = glm::normalize(front);
        glm::vec3 right = glm::normalize(glm::cross(front, glm::vec3(0.0f,1.0f,0.0f)));
        glm::vec3 up = glm::normalize(glm::cross(right, front));

        glm::vec3 position = tr.position;
        float velocity = cc.movement_speed * ts.GetSeconds();
        if (cc.forward)  position += front * velocity;
        if (cc.backward) position -= front * velocity;
        if (cc.right)    position += right * velocity;
        if (cc.left)     position -= right * velocity;
        if (cc.up)       position += up * velocity;
        if (cc.down)     position -= up * velocity;

        tr.position = position;

        // build orientation matrix applying yaw then pitch
        glm::mat4 rotMat = glm::yawPitchRoll(glm::radians(cc.yaw), glm::radians(cc.pitch), 0.0f);
        glm::quat orient = glm::quat_cast(rotMat);
        tr.rotation = glm::eulerAngles(orient);
    }
}

} // namespace GLStudy
