#pragma once

#include "Core/Input/KeyCodes.h"
#include "Core/Input/MouseCodes.h"
#include <glm.hpp>
#ifndef GLFW_INCLUDE_NONE
#define GLFW_INCLUDE_NONE
#endif
#include <GLFW/glfw3.h>

namespace GLStudy {
    class Input {
    public:
        static void Init(GLFWwindow* window);
        static bool IsKeyPressed(KeyCode key);
        static bool IsKeyReleased(KeyCode key);
        static bool IsMouseButtonPressed(MouseCode button);
        static glm::vec2 GetMousePosition();
        static float GetMouseX();
        static float GetMouseY();
    private:
        static GLFWwindow* window_;
    };
}
