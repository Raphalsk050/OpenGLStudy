#pragma once
#include "Core/Layer/Layer.h"
#include "Core/engine.h"
#include "Core/Scene/Scene.h"
#include "Core/Camera/SceneCamera.h"
#include "Core/Camera/CameraController.h"
#include "Core/Events/KeyEvent.h"
#include "Core/Scene/Components.h"
#include "Core/Graphics/Model.h"
#include <unordered_map>

namespace GLStudy
{
    class ProgramLayer : public Layer
    {
    public:
        ProgramLayer(Engine* engine);
        ~ProgramLayer() = default;
        void OnAttach() override;
        void OnDetach() override;
        void OnUpdate(Timestep ts) override;
        void OnImGuiRender() override;
        void OnEvent(Event& e) override;

    private:
        Engine* engine_;
        Scene& scene_;
        EntityHandle cube_;
        EntityHandle cube_2_;
        EntityHandle light_;
        EntityHandle light_2_;
        EntityHandle camera_;
        EntityHandle model_entity_;
        std::shared_ptr<Model> dummy_model_;
        std::unordered_map<KeyCode, bool> last_key_state_map_;

        // debug controls
        bool camera_movement_enabled_ = false;
        bool wireframe_enabled_ = false;

        bool OnKeyPressed(KeyPressedEvent& e);
        bool OnKeyReleased(KeyReleasedEvent& e);
    };
} // GLStudy
