#include "ProgramLayer.h"

#include <iostream>

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
        shader_prog_ = Shader::CreateShaderProgram("Assets/Shaders/simple_shader.vert", "Assets/Shaders/simple_shader.frag");
        // 1. create the vertex data
        float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f
        };
        // 2. create the vertex array object
        glGenVertexArrays(1, &vao_);
        glBindVertexArray(vao_);

        // 3. create the vertex buffer object
        glGenBuffers(1, &vbo_);
        glBindBuffer(GL_ARRAY_BUFFER, vbo_);

        // 4. copy the data to inside the created buffer
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glBindVertexArray(vao_);
        glUseProgram(shader_prog_);
    }

    void ProgramLayer::OnDetach()
    {
        Layer::OnDetach();
    }

    void ProgramLayer::OnUpdate(Timestep ts)
    {
        Layer::OnUpdate(ts);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    void ProgramLayer::OnImGuiRender()
    {
        Layer::OnImGuiRender();
    }
} // GLStudy
