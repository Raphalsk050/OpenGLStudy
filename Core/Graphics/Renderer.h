#pragma once
#include <memory>
#include "glad/glad.h"
#include "Core/Shader/Shader.h"
#include <glm.hpp>
#include <vector>
#include <array>
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
        void DrawSphere(const glm::mat4& model, const glm::vec4& color);
        void DrawCylinder(const glm::mat4& model, const glm::vec4& color);
        void DrawCapsule(const glm::mat4& model, const glm::vec4& color);
        void Flush();
        unsigned int GetShaderProgram() const { return shader_prog_; }
        const std::shared_ptr<Texture2D>& GetBrdfLUT() const { return brdf_lut_texture_; }
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

        std::unique_ptr<VertexArray> sphere_vao_;
        std::unique_ptr<VertexBuffer> sphere_vbo_;
        std::unique_ptr<IndexBuffer> sphere_ibo_;
        std::unique_ptr<VertexBuffer> sphere_instance_vbo_;
        std::vector<InstanceData> sphere_instances_;

        std::unique_ptr<VertexArray> cylinder_vao_;
        std::unique_ptr<VertexBuffer> cylinder_vbo_;
        std::unique_ptr<IndexBuffer> cylinder_ibo_;
        std::unique_ptr<VertexBuffer> cylinder_instance_vbo_;
        std::vector<InstanceData> cylinder_instances_;

        std::unique_ptr<VertexArray> capsule_vao_;
        std::unique_ptr<VertexBuffer> capsule_vbo_;
        std::unique_ptr<IndexBuffer> capsule_ibo_;
        std::unique_ptr<VertexBuffer> capsule_instance_vbo_;
        std::vector<InstanceData> capsule_instances_;

        unsigned int sphere_index_count_ = 0;
        unsigned int cylinder_index_count_ = 0;
        unsigned int capsule_index_count_ = 0;

        glm::vec3 camera_pos_{0.0f};
        std::vector<LightData> lights_;
        int cam_pos_location_ = -1;
        int num_lights_location_ = -1;
        int irradiance_location_ = -1;
        int prefilter_location_ = -1;
        int brdf_lut_location_ = -1;
        int use_ibl_location_ = -1;
        int use_albedo_location_ = -1;
        int use_normal_location_ = -1;
        int use_metallic_location_ = -1;
        int use_roughness_location_ = -1;

        struct LightUniformLocations {
            int type;
            int position;
            int direction;
            int color;
            int intensity;
            int range;
            int inner_cutoff;
            int outer_cutoff;
        };

        std::array<LightUniformLocations, 4> light_uniforms_{};

        std::shared_ptr<Texture2D> brdf_lut_texture_;
    };
}
