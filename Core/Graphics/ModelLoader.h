#pragma once
#include <string>
#include <vector>
#include <glm.hpp>

namespace GLStudy {
    struct VertexData {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec3 tangent;
        glm::vec2 texcoord;
    };

    class ModelLoader {
    public:
        static bool LoadOBJ(const std::string& path,
                             std::vector<VertexData>& vertices,
                             std::vector<unsigned int>& indices);
    };
}
