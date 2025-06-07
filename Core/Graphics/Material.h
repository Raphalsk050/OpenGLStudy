#pragma once
#include <string>
#include <glm.hpp>

namespace GLStudy {
    enum class ShadingModel {
        Lit = 0,
        Unlit = 1
    };

    enum class BlendMode {
        Opaque = 0,
        Transparent = 1
    };

    class Texture2D; // forward declaration

    struct Material {
        ShadingModel shading{ShadingModel::Lit};
        BlendMode blend{BlendMode::Opaque};
        glm::vec3 albedo{1.0f};
        float metallic{0.0f};
        float roughness{1.0f};
        Texture2D* albedo_tex{nullptr};
        Texture2D* normal_tex{nullptr};
        Texture2D* metallic_tex{nullptr};
        Texture2D* roughness_tex{nullptr};
        Texture2D* ao_tex{nullptr};
        Texture2D* emissive_tex{nullptr};
    };
}
