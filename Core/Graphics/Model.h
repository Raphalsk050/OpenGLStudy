#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Mesh.h"

struct aiNode;
struct aiScene;
struct aiMesh;
namespace GLStudy {
class Model {
public:
    bool LoadModel(const std::string& path);
    void Draw(unsigned int shader, const glm::mat4& transform) const;
private:
    void ProcessNode(aiNode* node, const aiScene* scene);
    Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);
    std::vector<Mesh> meshes_;
    std::string directory_;
};
}
