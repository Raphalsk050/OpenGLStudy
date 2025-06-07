#pragma once
#include "glad/glad.h"
#include <glm.hpp>

namespace GLStudy {

enum class MaterialShading {
    Lit = 0,
    Unlit = 1
};

struct Material {
    MaterialShading shading = MaterialShading::Lit;
    bool opaque = true;
    bool transparent = false;

    glm::vec3 albedo_color{1.0f};
    glm::vec3 emissive_color{0.0f};
    float metallic = 0.0f;
    float roughness = 1.0f;

    GLuint albedo_texture = 0;
    GLuint normal_texture = 0;
    GLuint specular_texture = 0;
    GLuint ao_texture = 0;
    GLuint roughness_texture = 0;
    GLuint emissive_texture = 0;

    bool has_albedo = false;
    bool has_normal = false;
    bool has_specular = false;
    bool has_ao = false;
    bool has_roughness = false;
    bool has_emissive = false;
};

}
