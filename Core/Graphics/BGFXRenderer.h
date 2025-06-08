#pragma once
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

namespace GLStudy {
    class BGFXRenderer {
    public:
        BGFXRenderer() = default;
        void Init(GLFWwindow* window, uint32_t width, uint32_t height);
        void Shutdown();
        void BeginFrame();
        void EndFrame();
    };
}
