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

        float angle = sin(Time().GetTime());
        entity_.SetRotation(glm::vec3(0.0f, 0.0f, angle));
    }

    void ProgramLayer::OnImGuiRender()
    {
        Layer::OnImGuiRender();
    }
} // GLStudy
