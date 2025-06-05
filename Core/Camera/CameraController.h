#pragma once
#include "../TimeStep.h"
#include "../Events/Event.h"
#include "../Events/MouseEvent.h"
#include "../Events/KeyEvent.h"
#include "../Input/Input.h"
#include "../Input/KeyCodes.h"
#include "../Input/MouseCodes.h"

namespace GLStudy {
    class EntityHandle;
}
#include <glm.hpp>

namespace GLStudy {
    class CameraController {
    public:
        CameraController() = default;
        void OnUpdate(EntityHandle entity, Timestep ts);
        void OnEvent(Event& e);
        void OnResize(float width, float height); // not used currently
        float movement_speed_ = 5.0f;
        float mouse_sensitivity_ = 0.1f;
    private:
        bool OnMouseMoved(MouseMovedEvent& e);
        bool OnMouseScrolled(MouseScrolledEvent& e);
        bool OnKeyPressed(KeyPressedEvent& e);
        bool OnKeyReleased(KeyReleasedEvent& e);

        bool first_mouse_ = true;
        glm::vec2 last_mouse_pos_ = {0.0f, 0.0f};
        float yaw_ = -90.0f;
        float pitch_ = 0.0f;
        bool forward_ = false;
        bool backward_ = false;
        bool left_ = false;
        bool right_ = false;
        bool up_ = false;
        bool down_ = false;
    };
}
