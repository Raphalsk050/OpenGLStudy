#pragma once
#include "Core/Layer/Layer.h"
#include "Core/engine.h"
#include "Core/Scene/Scene.h"

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

    private:
        Engine* engine_;
        Scene scene_;
        EntityHandle entity_;
    };
} // GLStudy
