#pragma once
#include "Core/Layer/Layer.h"

namespace GLStudy
{
    class ProgramLayer : public Layer
    {
    public:
        ProgramLayer();
        ~ProgramLayer() = default;
        void OnAttach() override;
        void OnDetach() override;
        void OnUpdate(Timestep ts) override;
        void OnImGuiRender() override;
    };
} // GLStudy
