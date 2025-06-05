#include "CameraController.h"
#include <algorithm>
#include <cmath>

namespace GLStudy {

void CameraController::OnUpdate(EntityHandle entity, Timestep ts) {
    glm::vec3 front;
    front.x = cos(glm::radians(yaw_)) * cos(glm::radians(pitch_));
    front.y = sin(glm::radians(pitch_));
    front.z = sin(glm::radians(yaw_)) * cos(glm::radians(pitch_));
    front = glm::normalize(front);

    glm::vec3 rightDir = glm::normalize(glm::cross(front, glm::vec3(0.0f, 1.0f, 0.0f)));
    glm::vec3 upDir = glm::normalize(glm::cross(rightDir, front));

    glm::vec3 position = entity.GetPosition();
    float velocity = movement_speed_ * ts;
    if (forward_)
        position += front * velocity;
    if (backward_)
        position -= front * velocity;
    if (left_)
        position -= rightDir * velocity;
    if (right_)
        position += rightDir * velocity;
    if (up_)
        position += upDir * velocity;
    if (down_)
        position -= upDir * velocity;
    entity.SetPosition(position);

    glm::vec3 rotation;
    rotation.x = glm::radians(pitch_);
    rotation.y = glm::radians(-(yaw_ + 90.0f));
    rotation.z = 0.0f;
    entity.SetRotation(rotation);
}

void CameraController::OnEvent(Event& e) {
    EventDispatcher dispatcher(e);
    dispatcher.Dispatch<MouseMovedEvent>([this](MouseMovedEvent& ev){ return OnMouseMoved(ev); });
    dispatcher.Dispatch<MouseScrolledEvent>([this](MouseScrolledEvent& ev){ return OnMouseScrolled(ev); });
    dispatcher.Dispatch<KeyPressedEvent>([this](KeyPressedEvent& ev){ return OnKeyPressed(ev); });
    dispatcher.Dispatch<KeyReleasedEvent>([this](KeyReleasedEvent& ev){ return OnKeyReleased(ev); });
}

void CameraController::OnResize(float width, float height) {
    (void)width; (void)height;
}

bool CameraController::OnMouseMoved(MouseMovedEvent& e) {
    if (first_mouse_) {
        last_mouse_pos_.x = e.GetX();
        last_mouse_pos_.y = e.GetY();
        first_mouse_ = false;
    }
    float xoffset = e.GetX() - last_mouse_pos_.x;
    float yoffset = last_mouse_pos_.y - e.GetY();
    last_mouse_pos_.x = e.GetX();
    last_mouse_pos_.y = e.GetY();

    xoffset *= mouse_sensitivity_;
    yoffset *= mouse_sensitivity_;

    yaw_ += xoffset;
    pitch_ += yoffset;

    if (pitch_ > 89.0f)
        pitch_ = 89.0f;
    if (pitch_ < -89.0f)
        pitch_ = -89.0f;

    return false;
}

bool CameraController::OnMouseScrolled(MouseScrolledEvent& e) {
    movement_speed_ = std::max(1.0f, movement_speed_ + e.GetYOffset());
    return false;
}

bool CameraController::OnKeyPressed(KeyPressedEvent& e) {
    switch (e.GetKeyCode()) {
    case Key::W: forward_ = true; break;
    case Key::S: backward_ = true; break;
    case Key::A: left_ = true; break;
    case Key::D: right_ = true; break;
    case Key::Q: up_ = true; break;
    case Key::E: down_ = true; break;
    }
    return false;
}

bool CameraController::OnKeyReleased(KeyReleasedEvent& e) {
    switch (e.GetKeyCode()) {
    case Key::W: forward_ = false; break;
    case Key::S: backward_ = false; break;
    case Key::A: left_ = false; break;
    case Key::D: right_ = false; break;
    case Key::Q: up_ = false; break;
    case Key::E: down_ = false; break;
    }
    return false;
}

} // namespace GLStudy

