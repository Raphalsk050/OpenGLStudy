#include "ProgramLayer.h"
#include <glm.hpp>
#include <gtc/random.hpp>
#include "Core/Events/WindowApplicationEvent.h"
#include <array>
#include <memory>
#include "Core/Graphics/Primitives.h"
#include "Core/Utils.h"
#include <boost/thread/future.hpp>

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

        RendererComponent renderer_component_spec{
            .mesh = MeshType::Cube,
            .color = glm::vec4(1.0f, 1.0f,1.0f, 1.0f)

        };

        cube_.AddComponent<RendererComponent>(renderer_component_spec);
        auto future = engine_->GetPhysicsWorld()->AddRigidbodyAsync(
            cube_,
            RigidBodyComponent{.mesh_type = MeshType::Cube, .size = btVector3(1.0f,1.0f,1.0f), .mass = 1.0f});
        future.then([](boost::future<RigidBodyComponent> f){
            (void)f.get();
        });
        cube_.SetPosition({0.0f,5.0f,0.0f});

        int amount = 5;

        /*for (int i = 0 ; i < amount ; i++)
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
        }*/

        auto sphereMesh = std::make_shared<Sphere>(0.5f);
        auto sphereEntity = scene_.CreateEntity("Sphere");
        sphereEntity.AddComponent<RendererComponent>(renderer_component_spec);
        sphereEntity.SetPosition({0.0f,15.0f,0.0f});

        sphereEntity.AddComponent<RigidBodyComponent>(RigidBodyComponent{.mesh_type = MeshType::Cube,.size = btVector3(1.0f,1.0f,1.0f),.mass = 1.0f});

        sphereEntity = scene_.CreateEntity("Sphere");
        sphereEntity.AddComponent<RendererComponent>(RendererComponent{.color = glm::vec4(1.0f,0.0f,0.0f,1.0f), .mesh_ptr = sphereMesh});
        sphereEntity.SetPosition({0.0f,10.0f,0.0f});

        sphereEntity.AddComponent<RigidBodyComponent>(RigidBodyComponent{.mesh_type = MeshType::Sphere,.size = btVector3(0.5f,0.5f,0.5f),.mass = 1.0f});

        auto floor_mesh = std::make_shared<Plane>(100.0f);
        auto floor_entity = scene_.CreateEntity("Floor");
        floor_entity.SetRotation(glm::vec3(0.0f,0.0f,3.14f));
        floor_entity.AddComponent<RendererComponent>(RendererComponent{.color = glm::vec4(1.0f,1.0f,1.0f,1.0f), .mesh_ptr = floor_mesh});
        floor_entity.AddComponent<RigidBodyComponent>(RigidBodyComponent{.mesh_type = MeshType::Cube,.size = btVector3(100.0f, 0.05f, 100.0f),.mass = 0.0f});
        floor_entity.SetPosition({0.0f,0.0f,0.0f});

        camera_ = scene_.CreateEntity("MainCamera");
        camera_.AddComponent<CameraComponent>();
        camera_.AddComponent<CameraControllerComponent>();
        camera_.AddComponent<RigidBodyComponent>();

        btRigidBody* body = camera_.GetComponent<RigidBodyComponent>().body->get();
        btVector3 localPivot = body->getCenterOfMassTransform().inverse() * ConvertMat4ToBtTransform(camera_.GetComponent<TransformComponent>().LocalMatrix()).getOrigin();
        btPoint2PointConstraint* p2p = new btPoint2PointConstraint(*body, localPivot);
        engine_->GetPhysicsWorld()->AddConstraint(p2p, true);

        camera_.SetPosition({0.0f, 1.0f, 5.0f});

        light_ = scene_.CreateEntity("Light");
        light_.AddComponent<LightComponent>(LightComponent{.type = LightType::Directional,
                                                          .color = glm::vec3(1.0f, 1.0f, 1.0f),
                                                          .intensity = 4.0f,.direction = glm::vec3(0.0f, -1.0f, 0.0f)});



        // light_2_ = scene_.CreateEntity("Light_2");
        // light_2_.AddComponent<LightComponent>(LightComponent{.type = LightType::Point,
        //                                                   .color = glm::vec3(1.0f, 0.0f,0.0f),
        //                                                   .intensity = 10.0f});
        // light_2_.SetPosition({0.0f, 0.0f,0.0f});

        /*dummy_model_ = std::make_shared<Model>();
        dummy_model_->LoadModel("Assets/Models/balls.glb");
        model_entity_ = scene_.CreateEntity("DummyModel");
        model_entity_.AddComponent<RendererComponent>(RendererComponent{.mesh = MeshType::Model, .color = glm::vec4(1.0f), .model = dummy_model_});*/

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
