#include "ProgramLayer.h"
#include <glm.hpp>
#include <GLFW/glfw3.h>
#include "Core/Events/WindowApplicationEvent.h"

namespace GLStudy
{
    ProgramLayer::ProgramLayer(Engine* engine) : engine_(engine), scene_(*engine_->GetScene())
    {
        debug_name_ = "ProgramLayer";
    }

    void ProgramLayer::OnAttach()
    {
        Layer::OnAttach();
        entity_ = scene_.CreateEntity();
        entity_.AddComponent<RendererComponent>(MeshType::Cube);

    camera_ = scene_.CreateEntity("MainCamera");
    auto camera_component = camera_.AddComponent<CameraComponent>();
    camera_.AddComponent<CameraControllerComponent>();

    int w, h;
    glfwGetFramebufferSize(engine_->GetWindow(), &w, &h);
    camera_component.camera.SetViewportSize(static_cast<float>(w), static_cast<float>(h));

    camera_.SetPosition({0.0f, 0.0f, 0.0f});

        EntityHandle child = scene_.CreateEntity();
        child.AddComponent<RendererComponent>();
        child.SetPosition({1.2f, 0.0f, 0.0f});
        child.SetParent(entity_);
    }

    void ProgramLayer::OnDetach()
    {
        Layer::OnDetach();
    }

    void ProgramLayer::OnUpdate(Timestep ts)
    {
        Layer::OnUpdate(ts);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    float angle = Time::GetTime();
    entity_.SetRotation(glm::vec3(0.0f, 0.0f, sin(angle)));

    auto& controller = camera_.GetComponent<CameraControllerComponent>().controller;
    controller.OnUpdate(camera_, ts);
    }

    void ProgramLayer::OnImGuiRender()
    {
        Layer::OnImGuiRender();
    }


    bool ProgramLayer::OnKeyPressed(KeyPressedEvent& e)
    {
        bool pressed = (e.IsRepeat() || !e.IsRepeat());
        auto KeyCode = e.GetKeyCode();

        if (!last_key_state_map_.contains(KeyCode))
            last_key_state_map_[KeyCode] = false;


        switch (KeyCode)
        {
        case Key::Space:
            {
                if (!last_key_state_map_[KeyCode])
                {
                    wireframe_enabled_ = !wireframe_enabled_;
                    last_key_state_map_[KeyCode] = true;
                }

                break;
            }

        case Key::Tab:
            {
                if (!last_key_state_map_[KeyCode])
                {
                    camera_movement_enabled_ = !camera_movement_enabled_;
                    last_key_state_map_[KeyCode] = true;
                    auto window = engine_->GetWindow();
                    if (camera_movement_enabled_)
                    {
                        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
                    }
                    else
                    {
                        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
                    }
                }

                break;
            }

        /*case Key::I:
            {
                if (!last_key_state_map_[KeyCode])
                {
                    auto_instancing_enabled_ = !auto_instancing_enabled_;
                    Renderer3D::EnableAutoInstancing(auto_instancing_enabled_);
                    last_key_state_map_[KeyCode] = true;
                }

                break;
            }*/
        }

        return false;
    }

    bool ProgramLayer::OnKeyReleased(KeyReleasedEvent& e)
    {
        auto KeyCode = e.GetKeyCode();

        switch (KeyCode)
        {
        case Key::Space:
            {
                last_key_state_map_[KeyCode] = false;
                break;
            }

        case Key::Tab:
            {
                last_key_state_map_[KeyCode] = false;
                break;
            }

        case Key::I:
            {
                last_key_state_map_[KeyCode] = false;
                break;
            }
        }


        return false;
    }

    void ProgramLayer::OnEvent(Event& e)
    {
        Layer::OnEvent(e);
    EventDispatcher dispatcher(e);
    dispatcher.Dispatch<KeyPressedEvent>(FENGINE_BIND_EVENT_FN(OnKeyPressed));
    dispatcher.Dispatch<KeyReleasedEvent>(FENGINE_BIND_EVENT_FN(OnKeyReleased));
    auto& controller = camera_.GetComponent<CameraControllerComponent>().controller;
    controller.OnEvent(e);
}
} // GLStudy
