#pragma once
#include <memory>
#include "glad/glad.h"
#include "Core/Shader/Shader.h"
#include <glm.hpp>
#include <vector>
#include "Core/Scene/Components.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

namespace GLStudy {
    class Renderer {
    public:
        Renderer() = default;
        void Init();

        void BeginScene(const glm::mat4& view_projection)
        {
            view_projection_ = view_projection;
        }

        void DrawTriangle(const glm::mat4& model, const glm::vec4& color);
        void DrawCube(const glm::mat4& model, const glm::vec4& color);
        void Flush();
    private:
        struct InstanceData {
            glm::mat4 model;
            glm::vec4 color;
        };

        unsigned int shader_prog_ = 0;
        int view_proj_location_ = -1;
        glm::mat4 view_projection_{1.0f};

        std::unique_ptr<VertexArray> triangle_vao_;
        std::unique_ptr<VertexBuffer> triangle_vbo_;
        std::unique_ptr<IndexBuffer> triangle_ibo_;
        std::unique_ptr<VertexBuffer> triangle_instance_vbo_;
        std::vector<InstanceData> triangle_instances_;

        std::unique_ptr<VertexArray> cube_vao_;
        std::unique_ptr<VertexBuffer> cube_vbo_;
        std::unique_ptr<IndexBuffer> cube_ibo_;
        std::unique_ptr<VertexBuffer> cube_instance_vbo_;
        std::vector<InstanceData> cube_instances_;
    };
}
