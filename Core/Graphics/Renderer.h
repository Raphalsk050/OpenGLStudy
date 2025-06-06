#pragma once
#include <memory>
#include "glad/glad.h"
#include "Core/Shader/Shader.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <vector>
#include "Core/Scene/Components.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "ShadowMap.h"

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
            has_shadow_light_ = false;
            for (const auto& l : lights_) {
                if (l.type == LightType::Directional) {
                    glm::mat4 lightProj = glm::ortho(-25.0f, 25.0f, -25.0f, 25.0f, 0.1f, 100.0f);
                    glm::mat4 lightView = glm::lookAt(l.position, l.position + l.direction, glm::vec3(0.0f, 1.0f, 0.0f));
                    shadow_map_->SetLightSpaceMatrix(lightProj * lightView);
                    has_shadow_light_ = true;
                    break;
                }
            }
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
        int light_space_location_ = -1;
        int shadow_map_location_ = -1;
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
        std::unique_ptr<ShadowMap> shadow_map_;
        unsigned int depth_shader_prog_ = 0;
        int depth_light_space_loc_ = -1;
        bool has_shadow_light_ = false;
    };
}
