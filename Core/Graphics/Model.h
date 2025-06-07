#pragma once
#include <vector>
#include <memory>
#include <string>
#include <glm.hpp>
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Material.h"

namespace GLStudy {
    struct Mesh {
        std::unique_ptr<VertexArray> vao;
        std::unique_ptr<VertexBuffer> vbo;
        std::unique_ptr<IndexBuffer> ibo;
        unsigned int index_count = 0;
        Material material;
    };

    class Model {
    public:
        bool LoadFromFile(const std::string& path);
        const std::vector<Mesh>& GetMeshes() const { return meshes_; }
    private:
        std::vector<Mesh> meshes_;
    };
}
