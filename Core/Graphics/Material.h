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

    void Apply(GLuint shader) const;
}; 

}

#include <gtc/type_ptr.hpp>

inline void GLStudy::Material::Apply(GLuint shader) const {
    glUniform3fv(glGetUniformLocation(shader, "u_AlbedoColor"), 1, glm::value_ptr(albedo_color));
    glUniform1f(glGetUniformLocation(shader, "u_Metallic"), metallic);
    glUniform1f(glGetUniformLocation(shader, "u_Roughness"), roughness);
    glUniform3fv(glGetUniformLocation(shader, "u_EmissiveColor"), 1, glm::value_ptr(emissive_color));

    int slot = 0;
    glUniform1i(glGetUniformLocation(shader, "u_UseAlbedoMap"), has_albedo);
    if (has_albedo) {
        glActiveTexture(GL_TEXTURE0 + slot);
        glBindTexture(GL_TEXTURE_2D, albedo_texture);
        glUniform1i(glGetUniformLocation(shader, "u_AlbedoMap"), slot++);
    }
    glUniform1i(glGetUniformLocation(shader, "u_UseNormalMap"), has_normal);
    if (has_normal) {
        glActiveTexture(GL_TEXTURE0 + slot);
        glBindTexture(GL_TEXTURE_2D, normal_texture);
        glUniform1i(glGetUniformLocation(shader, "u_NormalMap"), slot++);
    }
    glUniform1i(glGetUniformLocation(shader, "u_UseSpecularMap"), has_specular);
    if (has_specular) {
        glActiveTexture(GL_TEXTURE0 + slot);
        glBindTexture(GL_TEXTURE_2D, specular_texture);
        glUniform1i(glGetUniformLocation(shader, "u_SpecularMap"), slot++);
    }
    glUniform1i(glGetUniformLocation(shader, "u_UseAOMap"), has_ao);
    if (has_ao) {
        glActiveTexture(GL_TEXTURE0 + slot);
        glBindTexture(GL_TEXTURE_2D, ao_texture);
        glUniform1i(glGetUniformLocation(shader, "u_AOMap"), slot++);
    }
    glUniform1i(glGetUniformLocation(shader, "u_UseRoughnessMap"), has_roughness);
    if (has_roughness) {
        glActiveTexture(GL_TEXTURE0 + slot);
        glBindTexture(GL_TEXTURE_2D, roughness_texture);
        glUniform1i(glGetUniformLocation(shader, "u_RoughnessMap"), slot++);
    }
    glUniform1i(glGetUniformLocation(shader, "u_UseEmissiveMap"), has_emissive);
    if (has_emissive) {
        glActiveTexture(GL_TEXTURE0 + slot);
        glBindTexture(GL_TEXTURE_2D, emissive_texture);
        glUniform1i(glGetUniformLocation(shader, "u_EmissiveMap"), slot);
    }
}

