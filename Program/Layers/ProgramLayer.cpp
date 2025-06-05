#include "ProgramLayer.h"

#include <iostream>
#include <__ostream/basic_ostream.h>

#include "Core/Shader/Shader.h"

namespace GLStudy
{
    ProgramLayer::ProgramLayer()
    {
        debug_name_ = "ProgramLayer";
    }

    void ProgramLayer::OnAttach()
    {
        Layer::OnAttach();
        unsigned int shader = Shader::CreateShaderProgram("Assets/Shaders/simple_shader.vert", "Assets/Shaders/simple_shader.frag");
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
} // GLStudy
