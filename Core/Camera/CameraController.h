#pragma once
#include "Core/TimeStep.h"
#include "Core/Scene/Scene.h"
#include "Core/Events/Event.h"
#include "Core/Events/MouseEvent.h"
#include "Core/Events/KeyEvent.h"

namespace GLStudy {

struct CameraControllerComponent {
    enum class ControlMode { Fly = 0, Orbit, FirstPerson };

    ControlMode mode = ControlMode::Fly;
    float movement_speed = 5.0f;
    float rotation_speed = 0.1f; // degrees per pixel
    float zoom_speed = 1.0f;
    float distance = 10.0f; // for orbit mode
    bool mouse_control_enabled = true;

    // internal state
    bool forward = false;
    bool backward = false;
    bool left = false;
    bool right = false;
    bool up = false;
    bool down = false;

    bool first_mouse = true;
    glm::vec2 last_mouse_position{0.0f};
    float yaw = -90.0f;  // looking towards -Z
    float pitch = 0.0f;
};

class CameraControllerSystem {
public:
    static void OnUpdate(Scene& scene, Timestep ts);
    static void OnEvent(Scene& scene, Event& e);
};

} // namespace GLStudy
