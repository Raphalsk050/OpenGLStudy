#pragma once
#include <filament/Engine.h>
#include <filament/Renderer.h>
#include <filament/SwapChain.h>
#include <filament/Scene.h>
#include <filament/View.h>
#include <filament/Camera.h>

namespace GLStudy {
class FilamentRenderer {
public:
    FilamentRenderer() = default;
    void Init(void* native_window);
    void BeginFrame();
    void EndFrame();
    void Shutdown();

    filament::Engine* GetEngine() const { return engine_; }
    filament::Renderer* GetRenderer() const { return renderer_; }
    filament::Scene* GetScene() const { return scene_; }
    filament::View* GetView() const { return view_; }
    filament::Camera* GetCamera() const { return camera_; }

private:
    filament::Engine* engine_ = nullptr;
    filament::Renderer* renderer_ = nullptr;
    filament::SwapChain* swapchain_ = nullptr;
    filament::Scene* scene_ = nullptr;
    filament::View* view_ = nullptr;
    filament::Camera* camera_ = nullptr;
};
}
