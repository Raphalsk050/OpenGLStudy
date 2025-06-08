#pragma once
#include <memory>
#include <vector>
#include <glm.hpp>
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Texture.h"

namespace GLStudy {
struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec3 tangent;
    glm::vec2 texcoord;
};

class Mesh {
public:
    Mesh() = default;
    Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices,
         std::shared_ptr<Texture2D> albedo,
         std::shared_ptr<Texture2D> normal = nullptr,
         std::shared_ptr<Texture2D> metallic = nullptr,
         std::shared_ptr<Texture2D> roughness = nullptr);
    void Draw(unsigned int shader) const;
    std::shared_ptr<Texture2D> albedo_;
    std::shared_ptr<Texture2D> normal_;
    std::shared_ptr<Texture2D> metallic_;
    std::shared_ptr<Texture2D> roughness_;
private:
    std::unique_ptr<VertexArray> vao_;
    std::unique_ptr<VertexBuffer> vbo_;
    std::unique_ptr<IndexBuffer> ibo_;
    unsigned int index_count_ = 0;
};
}
