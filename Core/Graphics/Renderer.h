#pragma once
#include <memory>
#include <vector>
#include <glm.hpp>
#include <GLFW/glfw3.h>
#include <filament/Engine.h>
#include <filament/Renderer.h>
#include <filament/Scene.h>
#include <filament/View.h>
#include <filament/SwapChain.h>
#include <filament/Camera.h>
#include <filament/RenderableManager.h>
#include <utils/Entity.h>
#include <utils/EntityManager.h>
#include "Core/Scene/Components.h"
#include "Core/Camera/SceneCamera.h"

namespace GLStudy {
    // Renderer wrapper around Filament
    class Renderer {
    public:
        Renderer() = default;
        ~Renderer();
        void Init(GLFWwindow* window);

        struct LightData {
            LightType type;
            glm::vec3 position;
            glm::vec3 direction;
            glm::vec3 color;
            float intensity;
            float range;
            float inner_cutoff;
            float outer_cutoff;
        };

        void BeginScene(SceneCamera* camera,
                        const glm::vec3& cam_pos,
                        const std::vector<LightData>& lights);
        void DrawTriangle(const glm::mat4& model, const glm::vec4& color);
        void DrawCube(const glm::mat4& model, const glm::vec4& color);
        void Flush();
        filament::Engine* GetEngine() const { return engine_; }
    private:
        filament::Engine* engine_ = nullptr;
        filament::SwapChain* swap_chain_ = nullptr;
        filament::Renderer* renderer_ = nullptr;
        filament::Scene* scene_ = nullptr;
        filament::View* view_ = nullptr;

        utils::Entity triangle_{};
        utils::Entity cube_{};
        filament::MaterialInstance* color_material_ = nullptr;
    };
}
