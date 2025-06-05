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

    private:
        unsigned int vbo_, vao_, shader_prog_;
    };
} // GLStudy
