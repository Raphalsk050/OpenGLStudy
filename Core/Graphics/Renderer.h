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
#include "Texture.h"

namespace GLStudy {
    class Renderer {
    public:
        Renderer() = default;
        void Init();

        struct LightData {
            LightType type;
            glm::vec3 position;
            glm::vec3 direction;
            glm::vec3 color;
            float intensity;
            float range;
            float inner_cutoff;
            float outer_cutoff;
        };

        void BeginScene(const glm::mat4& view_projection,
                        const glm::vec3& cam_pos,
                        const std::vector<LightData>& lights)
        {
            view_projection_ = view_projection;
            camera_pos_ = cam_pos;
            lights_ = lights;
        }

        void DrawTriangle(const glm::mat4& model, const glm::vec4& color);
        void DrawCube(const glm::mat4& model, const glm::vec4& color);
        void Flush();
        unsigned int GetShaderProgram() const { return shader_prog_; }

        // skybox / IBL
        bool LoadSkybox(const std::string& path);
        void DrawSkybox();
    private:
        struct InstanceData {
            glm::mat4 model;
            glm::vec4 color;
        };

        unsigned int shader_prog_ = 0;
        int view_proj_location_ = -1;
        int model_location_ = -1;
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

        glm::vec3 camera_pos_{0.0f};
        std::vector<LightData> lights_;
        int cam_pos_location_ = -1;
        int num_lights_location_ = -1;

        // skybox resources
        unsigned int skybox_shader_ = 0;
        unsigned int skybox_vao_ = 0;
        unsigned int skybox_vbo_ = 0;
        std::unique_ptr<Texture2D> hdr_texture_;
    };
}
