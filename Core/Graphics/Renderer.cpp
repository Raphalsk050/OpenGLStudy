#include "Renderer.h"
#include <glm/gtc/type_ptr.hpp>
#include <filament/Material.h>
#include <filament/LightManager.h>
#include <backend/platforms/PlatformFactory.h>
#include <GLFW/glfw3native.h>

namespace GLStudy {

Renderer::~Renderer() {
    if (engine_) {
        if (scene_) engine_->destroy(scene_);
        if (view_) engine_->destroy(view_);
        if (renderer_) engine_->destroy(renderer_);
        if (swap_chain_) engine_->destroy(swap_chain_);
        filament::Engine::destroy(&engine_);
    }
}

void Renderer::Init(GLFWwindow* window) {
    engine_ = filament::Engine::create(filament::Engine::Backend::OPENGL);
#ifdef _WIN32
    void* nativeWindow = glfwGetWin32Window(window);
#elif defined(__APPLE__)
    void* nativeWindow = glfwGetCocoaWindow(window);
#else
    void* nativeWindow = (void*)glfwGetX11Window(window);
#endif
    swap_chain_ = engine_->createSwapChain(nativeWindow);
    renderer_ = engine_->createRenderer();
    view_ = engine_->createView();
    scene_ = engine_->createScene();
    view_->setScene(scene_);
}

void Renderer::BeginScene(SceneCamera* camera,
                          const glm::vec3& cam_pos,
                          const std::vector<LightData>& lights) {
    if (camera) {
        if (!camera->GetFilamentCamera())
            camera->CreateFilamentCamera(engine_);
        view_->setCamera(camera->GetFilamentCamera());
    }
    // Lights would be converted to filament lights here (not implemented)
}

void Renderer::DrawTriangle(const glm::mat4& model, const glm::vec4& color) {
    // TODO implement renderable creation using Filament
}

void Renderer::DrawCube(const glm::mat4& model, const glm::vec4& color) {
    // TODO implement renderable creation using Filament
}

void Renderer::Flush() {
    if (!renderer_->beginFrame(swap_chain_))
        return;
    renderer_->render(view_);
    renderer_->endFrame();
}

} // namespace GLStudy
