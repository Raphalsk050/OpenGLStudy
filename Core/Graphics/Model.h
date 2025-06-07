#pragma once
#include <vector>
#include <memory>
#include <string>
#include <glm.hpp>
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Material.h"

struct aiNode;
struct aiScene;
struct aiMesh;

namespace GLStudy {

struct Mesh {
    std::unique_ptr<VertexArray> vao;
    std::unique_ptr<VertexBuffer> vbo;
    std::unique_ptr<IndexBuffer> ibo;
    unsigned int index_count = 0;
    int material_index = 0;
};

class Model {
public:
    Model(const std::string& path);

    const std::vector<Mesh>& GetMeshes() const { return meshes_; }
    const std::vector<Material>& GetMaterials() const { return materials_; }

private:
    std::string directory_;
    std::vector<Mesh> meshes_;
    std::vector<Material> materials_;

    void ProcessNode(aiNode* node, const aiScene* scene);
    Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);
};

}
