#include "FilamentRenderer.h"

using namespace filament;

namespace GLStudy {

void FilamentRenderer::Init(void* native_window) {
    engine_ = Engine::create(Engine::Backend::OPENGL);
    swapchain_ = engine_->createSwapChain(native_window);
    renderer_ = engine_->createRenderer();
    scene_ = engine_->createScene();
    view_ = engine_->createView();
    camera_ = engine_->createCamera();
    view_->setScene(scene_);
    view_->setCamera(camera_);
}

void FilamentRenderer::BeginFrame() {
    if (renderer_) {
        renderer_->beginFrame(swapchain_);
    }
}

void FilamentRenderer::EndFrame() {
    if (renderer_) {
        renderer_->render(view_);
        renderer_->endFrame();
    }
}

void FilamentRenderer::Shutdown() {
    if (!engine_) return;
    engine_->destroy(renderer_);
    engine_->destroy(swapchain_);
    engine_->destroy(scene_);
    engine_->destroy(view_);
    engine_->destroy(camera_);
    Engine::destroy(&engine_);
}

}
