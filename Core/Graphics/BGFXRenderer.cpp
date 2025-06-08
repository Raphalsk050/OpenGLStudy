#include "BGFXRenderer.h"

namespace GLStudy {
    void BGFXRenderer::Init(GLFWwindow* window, uint32_t width, uint32_t height) {
        bgfx::Init init;
        init.type = bgfx::RendererType::Count;
        init.resolution.width = width;
        init.resolution.height = height;
        init.resolution.reset = BGFX_RESET_VSYNC;
        bgfx::PlatformData pd{};
        pd.nwh = glfwGetWin32Window(window);
        init.platformData = pd;
        bgfx::init(init);
    }

    void BGFXRenderer::Shutdown() {
        bgfx::shutdown();
    }

    void BGFXRenderer::BeginFrame() {
        bgfx::touch(0);
    }

    void BGFXRenderer::EndFrame() {
        bgfx::frame();
    }
}
