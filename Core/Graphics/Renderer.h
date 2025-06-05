#pragma once
#include <memory>
#include "glad/glad.h"
#include "Core/Shader/Shader.h"
#include <glm/glm.hpp>
#include "Core/Scene/Components.h"

namespace GLStudy {
    class Renderer {
    public:
        Renderer() = default;
        void Init();
        void DrawTriangle(const glm::mat4& model, const glm::vec4& color,
                          const glm::vec3 vertices[3]);
        void DrawTriangle(const glm::mat4& model, const glm::vec4& color)
        {
            static const glm::vec3 default_vertices[3] = {
                {-0.5f, -0.5f, 0.0f}, {0.5f, -0.5f, 0.0f}, {0.0f, 0.5f, 0.0f}};
            DrawTriangle(model, color, default_vertices);
        }
        void DrawCube(const glm::mat4& model, const glm::vec4& color);
    private:
        unsigned int shader_prog_ = 0;
        int mvp_location_ = -1;
        int color_location_ = -1;
    };
}
