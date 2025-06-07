#include "ProgramLayer.h"
#include <glm.hpp>
#include <gtc/random.hpp>
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
        cube_ = scene_.CreateEntity();

        RendererComponent renderer_component_spec{};
        renderer_component_spec.mesh = MeshType::Cube;
        renderer_component_spec.color = glm::vec4(1.0f,1.0f,1.0f,1.0f);

        int amount = 5;

        for (int i = 0 ; i < amount ; i++)
        {
            for (int j = 0 ; j < amount ; j++)
            {
                for (int k = 0 ; k < amount ; k++)
                {
                    cube_ = scene_.CreateEntity();
                    renderer_component_spec.color = glm::vec4(glm::linearRand(0.0f,1.0f), glm::linearRand(0.0f,1.0f), glm::linearRand(0.0f,1.0f), 1.0f);
                    cube_.AddComponent<RendererComponent>(renderer_component_spec);
                    cube_.SetPosition(glm::vec3(i - amount/2.0f, k - amount/2.0f, j - amount/2.0f));
                    cube_.SetScale(glm::vec3(0.5f));
                }
            }
        }

        camera_ = scene_.CreateEntity("MainCamera");
        camera_.AddComponent<CameraComponent>();
        camera_.AddComponent<CameraControllerComponent>();
        camera_.SetPosition({0.0f, 0.0f, 5.0f});

        light_ = scene_.CreateEntity("Light");
        light_.AddComponent<LightComponent>(LightComponent{.type = LightType::Directional,
                                                          .color = glm::vec3(1.0f, 1.0f, 1.0f),
                                                          .intensity = 1.0f,.direction = glm::vec3(-1.0f, -1.0f, 0.0f)});

        light_2_ = scene_.CreateEntity("Light_2");
        light_2_.AddComponent<LightComponent>(LightComponent{.type = LightType::Point,
                                                          .color = glm::vec3(1.0f, 0.0f,0.0f),
                                                          .intensity = 10.0f});
        light_2_.SetPosition({0.0f, 0.0f,0.0f});
    }

    void ProgramLayer::OnDetach()
    {
        Layer::OnDetach();
    }

    void ProgramLayer::OnUpdate(Timestep ts)
    {
        Layer::OnUpdate(ts);
        /*cube_.SetRotation(glm::vec3(0.0f, 0.0f, Time::GetTime()));
        cube_2_.SetRotation(glm::vec3(0.0f, 0.0f, Time::GetTime() * 2.0));*/
        light_.SetPosition(glm::vec3(sin(Time::GetTime()), 1.0f, cos(Time::GetTime())));
        light_2_.SetPosition(glm::vec3(sin(Time::GetTime() * 2.0f), 1.0f, cos(Time::GetTime() * 2.0f)));
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
    }
} // GLStudy
