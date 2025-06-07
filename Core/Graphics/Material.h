#pragma once
#include <memory>
#include <glm.hpp>
#include "Texture2D.h"

namespace GLStudy {
    enum class ShadingModel { Lit, Unlit };
    enum class Transparency { Opaque, Transparent };

    struct Material {
        ShadingModel shading{ShadingModel::Lit};
        Transparency transparency{Transparency::Opaque};
        glm::vec3 emissive{0.0f};
        std::shared_ptr<Texture2D> albedo;
        std::shared_ptr<Texture2D> normal;
        std::shared_ptr<Texture2D> specular;
        std::shared_ptr<Texture2D> ao;
        std::shared_ptr<Texture2D> roughness;
        std::shared_ptr<Texture2D> emissive_map;
    };
}
