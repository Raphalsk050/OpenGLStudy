#include "ProgramLayer.h"
#include <glm/glm.hpp>

namespace GLStudy
{
    ProgramLayer::ProgramLayer(Engine* engine) : engine_(engine)
    {
        debug_name_ = "ProgramLayer";
    }

    void ProgramLayer::OnAttach()
    {
        Layer::OnAttach();
        entity_ = scene_.CreateEntity();
        entity_.AddComponent<RendererComponent>();

        EntityHandle child = scene_.CreateEntity();
        child.AddComponent<RendererComponent>();
        child.SetPosition({1.0f, 0.0f, 0.0f});
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

        scene_.Render(engine_->GetRenderer());
    }

    void ProgramLayer::OnImGuiRender()
    {
        Layer::OnImGuiRender();
    }
} // GLStudy
