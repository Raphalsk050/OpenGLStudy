#include "ProgramLayer.h"
#include <glm.hpp>
#include <gtc/random.hpp>
#include "Core/Events/WindowApplicationEvent.h"
#include <array>
#include <memory>
#include "Core/Graphics/Primitives.h"
#include "Core/Utils.h"

namespace GLStudy
{
    ProgramLayer::ProgramLayer(Engine* engine) : engine_(engine), scene_(*engine_->GetScene())
    {
        debug_name_ = "ProgramLayer";
    }

    void ProgramLayer::OnAttach()
    {
        Layer::OnAttach();
        //cube_ = scene_.CreateEntity("Cube");
        floor_ = scene_.CreateEntity("Floor");
        sphere_ = scene_.CreateEntity("Sphere");

        std::shared_ptr<Capsule> sphere_mesh(new Capsule(0.5));
        std::shared_ptr<Plane> plane_mesh(new Plane(100.0f));

        RendererComponent cube_renderer_spec{
            .mesh = MeshType::Cube,
            .color = glm::vec4(1.0f, 0.0f, 1.0f, 1.0f)
        };

        RendererComponent sphere_renderer_spec{
            .mesh = MeshType::Model,
            .color = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f),
            .depth_test = true,
            .culling = true,
            .cull_face = GL_BACK,
            .double_sided = false,
            .model = nullptr,
            .mesh_ptr = sphere_mesh
        };

        RendererComponent plane_renderer_spec{
            .mesh = MeshType::Model,
            .color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),
            .depth_test = true,
            .culling = true,
            .cull_face = GL_BACK,
            .double_sided = false,
            .model = nullptr,
            .mesh_ptr = plane_mesh
        };

        int amount = 5;

        for (int i = -amount/2; i < amount/2; i++)
        {
            for (int j = -amount/2; j < amount/2; j++)
            {
                auto cube = scene_.CreateEntity("Cube");
                cube.AddComponent<RendererComponent>(cube_renderer_spec);
                auto cube_rigidbody_future = engine_->GetPhysicsWorld()->AddRigidbody(
                    cube,
                    RigidBodyComponent{.mesh_type = MeshType::Cube, .size = btVector3(1.0f, 1.0f, 1.0f), .mass = 1.0f});
                cube.SetPosition({i, 1.0, j});
            }
        }

        floor_.AddComponent<RendererComponent>(plane_renderer_spec);
        auto floor_rigidbody_future = engine_->GetPhysicsWorld()->AddRigidbody(
            floor_,
            RigidBodyComponent{.mesh_type = MeshType::Cube, .size = btVector3(100.0f, 0.05f, 100.0f), .mass = 0.0f});
        sphere_.SetPosition({0.0f, 0.0f, 0.0f});

        sphere_.AddComponent<RendererComponent>(sphere_renderer_spec);
        auto sphere_rigidbody_future = engine_->GetPhysicsWorld()->AddRigidbody(
            sphere_,
            RigidBodyComponent{
                .mesh_type = MeshType::Sphere,
                .size = btVector3(1.0, 2.0, 1.0),
                .mass = 1.0f,
                .angular_factor = btVector3(0.0f, 0.0f, 0.0f),
                .disable_sleep = true
            });
        sphere_.SetPosition({0.0f, 15.0f, 0.0f});
        sphere_.AddComponent<CharacterControllerComponent>(CharacterControllerComponent{.camera_type = CameraType::ThirdPerson});



        camera_ = scene_.CreateEntity("MainCamera");
        camera_.AddComponent<CameraComponent>();
        camera_.AddComponent<CameraControllerComponent>();
        camera_.SetPosition({0.0f, 1.0f, 5.0f});
        camera_.AddComponent<CameraBoomComponent>(CameraBoomComponent{5.0f, true, sphere_.Raw()});



        light_ = scene_.CreateEntity("Light");
        light_.AddComponent<LightComponent>(LightComponent{
            .type = LightType::Directional,
            .color = glm::vec3(1.0f, 1.0f, 1.0f),
            .intensity = 4.0f, .direction = glm::vec3(0.0f, -1.0f, 0.0f)
        });


        skybox_entity_ = scene_.CreateEntity("Skybox");
        auto skybox = std::make_shared<Skybox>();
        if (skybox->Load("Assets/Textures/Skybox/TCom_ColorfulAlley_colorful_alley_1K_hdri_sphere.exr", true))
            skybox_entity_.AddComponent<SkyboxComponent>(SkyboxComponent{skybox});
    }

    void ProgramLayer::OnDetach()
    {
        Layer::OnDetach();
    }

    void ProgramLayer::OnUpdate(Timestep ts)
    {
        Layer::OnUpdate(ts);
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
