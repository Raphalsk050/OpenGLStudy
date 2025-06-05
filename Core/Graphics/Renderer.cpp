#include "Renderer.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include <gtc/type_ptr.hpp>

namespace GLStudy {
    void Renderer::Init() {
        shader_prog_ = Shader::CreateShaderProgram("Assets/Shaders/simple_shader.vert", "Assets/Shaders/simple_shader.frag");

        // default VAO/VBO setup will happen per draw call
        glUseProgram(shader_prog_);
        mvp_location_ = glGetUniformLocation(shader_prog_, "u_MVP");
        color_location_ = glGetUniformLocation(shader_prog_, "u_Color");
    }

    void Renderer::DrawTriangle(const glm::mat4& model, const glm::vec4& color, const glm::vec3 vertices[3]) {
        static const unsigned int indices[3] = {0, 1, 2};

        VertexArray va;
        va.Bind();
        VertexBuffer vb(vertices, sizeof(glm::vec3) * 3);
        IndexBuffer ib(indices, 3);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
        glEnableVertexAttribArray(0);

        glUseProgram(shader_prog_);
        glm::mat4 mvp = view_projection_ * model;
        glUniformMatrix4fv(mvp_location_, 1, GL_FALSE, glm::value_ptr(mvp));
        glUniform4fv(color_location_, 1, glm::value_ptr(color));

        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
    }

    void Renderer::DrawCube(const glm::mat4& model, const glm::vec4& color) {
        const glm::vec3 vertices[] = {
            {-0.5f, -0.5f, -0.5f},
            { 0.5f, -0.5f, -0.5f},
            { 0.5f,  0.5f, -0.5f},
            {-0.5f,  0.5f, -0.5f},
            {-0.5f, -0.5f,  0.5f},
            { 0.5f, -0.5f,  0.5f},
            { 0.5f,  0.5f,  0.5f},
            {-0.5f,  0.5f,  0.5f}
        };

        const unsigned int indices[] = {
            0,1,2, 2,3,0,
            4,5,6, 6,7,4,
            0,4,7, 7,3,0,
            1,5,6, 6,2,1,
            3,2,6, 6,7,3,
            0,1,5, 5,4,0
        };

        VertexArray va;
        va.Bind();
        VertexBuffer vb(vertices, sizeof(vertices));
        IndexBuffer ib(indices, 36);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
        glEnableVertexAttribArray(0);

        glUseProgram(shader_prog_);
        glm::mat4 mvp = view_projection_ * model;
        glUniformMatrix4fv(mvp_location_, 1, GL_FALSE, glm::value_ptr(mvp));
        glUniform4fv(color_location_, 1, glm::value_ptr(color));

        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);
    }
}
