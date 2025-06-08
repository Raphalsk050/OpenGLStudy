#include "Input.h"
#ifndef GLFW_INCLUDE_NONE
#define GLFW_INCLUDE_NONE
#endif
#include <GLFW/glfw3.h>

namespace GLStudy {

GLFWwindow* Input::window_ = nullptr;

void Input::Init(GLFWwindow* window) {
    window_ = window;
}

bool Input::IsKeyPressed(KeyCode key) {
    if (!window_) return false;
    auto state = glfwGetKey(window_, key);
    return state == GLFW_PRESS || state == GLFW_REPEAT;
}

bool Input::IsKeyReleased(KeyCode key) {
    if (!window_) return false;
    auto state = glfwGetKey(window_, key);
    return state == GLFW_RELEASE;
}

bool Input::IsMouseButtonPressed(MouseCode button) {
    if (!window_) return false;
    auto state = glfwGetMouseButton(window_, button);
    return state == GLFW_PRESS;
}

glm::vec2 Input::GetMousePosition() {
    double x, y;
    if (!window_) return {0.0f, 0.0f};
    glfwGetCursorPos(window_, &x, &y);
    return {static_cast<float>(x), static_cast<float>(y)};
}

float Input::GetMouseX() {
    return GetMousePosition().x;
}

float Input::GetMouseY() {
    return GetMousePosition().y;
}

}
