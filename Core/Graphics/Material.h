#pragma once
#include <string>
#include <memory>
#include "Texture2D.h"

namespace GLStudy {

enum class ShadingModel { Lit, Unlit };

class Material {
public:
    ShadingModel shading = ShadingModel::Lit;
    bool opaque = true;
    bool transparent = false;

    bool has_albedo = false;
    bool has_normal = false;
    bool has_specular = false;
    bool has_roughness = false;
    bool has_ao = false;
    bool has_emissive = false;

    std::shared_ptr<Texture2D> albedo_map;
    std::shared_ptr<Texture2D> normal_map;
    std::shared_ptr<Texture2D> specular_map;
    std::shared_ptr<Texture2D> roughness_map;
    std::shared_ptr<Texture2D> ao_map;
    std::shared_ptr<Texture2D> emissive_map;

    std::string albedo_path;
    std::string normal_path;
    std::string specular_path;
    std::string roughness_path;
    std::string ao_path;
    std::string emissive_path;

    void LoadTextures();
};

}
