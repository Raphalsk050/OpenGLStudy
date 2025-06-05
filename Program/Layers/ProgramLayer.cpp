#include "ProgramLayer.h"
#include <glm.hpp>

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
        camera_.GetComponent<CameraComponent>().camera.SetPerspective(90, 0.03f, 1000.0f);

        float radius = 5.0f;
        glm::vec3 cam_pos{0.0f, 0.0f, (sin(angle)+1.0) * radius};
        camera_.SetPosition(cam_pos);
        //camera_.SetRotation(glm::vec3(0.0f, -angle, 0.0f));
    }

    void ProgramLayer::OnImGuiRender()
    {
        Layer::OnImGuiRender();
    }
} // GLStudy
