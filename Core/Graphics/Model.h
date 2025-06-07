#pragma once
#include <vector>
#include <string>
#include <memory>
#include <glm.hpp>
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Material.h"

struct aiNode;
struct aiScene;
struct aiMesh;
struct aiMaterial;

namespace GLStudy {
    struct Vertex {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec3 tangent;
        glm::vec2 texcoord;
    };

    struct Mesh {
        std::unique_ptr<VertexArray> vao;
        std::unique_ptr<VertexBuffer> vbo;
        std::unique_ptr<IndexBuffer> ibo;
        unsigned int index_count = 0;
        Material material;
    };

    class Model {
    public:
        Model(const std::string& path);
        const std::vector<Mesh>& GetMeshes() const { return meshes_; }
    private:
        std::vector<Mesh> meshes_;
        std::string directory_;
        void LoadModel(const std::string& path);
        void ProcessNode(aiNode* node, const aiScene* scene);
        Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);
        Material LoadMaterial(aiMaterial* mat);
    };
}
