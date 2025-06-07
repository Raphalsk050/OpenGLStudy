#pragma once
#include <string>
#include <vector>
#include <glm.hpp>
#include "Material.h"

namespace GLStudy {

struct VertexData {
    glm::vec3 position{};
    glm::vec3 normal{};
    glm::vec3 tangent{};
    glm::vec2 texcoord{};
};

struct MeshData {
    std::vector<VertexData> vertices;
    std::vector<unsigned int> indices;
    int material_index = -1;
};

struct ModelData {
    std::vector<MeshData> meshes;
    std::vector<Material> materials;
};

class ModelLoader {
public:
    static bool LoadModel(const std::string& path, ModelData& out_model);
};

}
