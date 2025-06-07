#pragma once
#include <memory>
#include "glad/glad.h"
#include "Core/Shader/Shader.h"
#include <glm.hpp>
#include <vector>
#include <unordered_map>
#include "Core/Scene/Components.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "ModelLoader.h"
#include "Material.h"

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
                        const std::vector<LightData>& lights);

        void DrawMesh(MeshType type,
                      const glm::mat4& model,
                      const glm::vec4& color,
                      const std::string& path = "");
        void Flush();
    private:
        struct InstanceData {
            glm::mat4 model;
            glm::vec4 color;
        };

        struct MeshRenderData {
            std::unique_ptr<VertexArray> vao;
            std::unique_ptr<VertexBuffer> vbo;
            std::unique_ptr<IndexBuffer> ibo;
            std::unique_ptr<VertexBuffer> instance_vbo;
            std::vector<InstanceData> instances;
            unsigned int index_count = 0;
            int material_index = -1;
        };

        MeshRenderData& GetOrCreateMeshData(const std::string& key,
                                            const std::vector<VertexData>& vertices = {},
                                            const std::vector<unsigned int>& indices = {});

        void InitDefaultMeshes();

        unsigned int shader_prog_ = 0;
        int view_proj_location_ = -1;
        glm::mat4 view_projection_{1.0f};

        std::unordered_map<std::string, MeshRenderData> meshes_;
        std::unordered_map<std::string, std::vector<MeshRenderData>> model_meshes_;
        std::unordered_map<std::string, std::vector<Material>> model_materials_;

        glm::vec3 camera_pos_{0.0f};
        std::vector<LightData> lights_;
        int cam_pos_location_ = -1;
        int num_lights_location_ = -1;
        int use_albedo_location_ = -1;
    };
}
