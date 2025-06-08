#include "Renderer.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include <gtc/type_ptr.hpp>
#include <string>
#include <vector>
#include <cmath>

namespace {
float RadicalInverse_VdC(unsigned int bits) {
    bits = (bits << 16u) | (bits >> 16u);
    bits = ((bits & 0x55555555u) << 1u) | ((bits & 0xAAAAAAAAu) >> 1u);
    bits = ((bits & 0x33333333u) << 2u) | ((bits & 0xCCCCCCCCu) >> 2u);
    bits = ((bits & 0x0F0F0F0Fu) << 4u) | ((bits & 0xF0F0F0F0u) >> 4u);
    bits = ((bits & 0x00FF00FFu) << 8u) | ((bits & 0xFF00FF00u) >> 8u);
    return float(bits) * 2.3283064365386963e-10f;
}

glm::vec2 Hammersley(uint32_t i, uint32_t N) {
    return glm::vec2(float(i) / float(N), RadicalInverse_VdC(i));
}

glm::vec3 ImportanceSampleGGX(const glm::vec2& Xi, float roughness) {
    float a = roughness * roughness;
    float phi = 2.0f * glm::pi<float>() * Xi.x;
    float cosTheta = sqrt((1.0f - Xi.y) / (1.0f + (a * a - 1.0f) * Xi.y));
    float sinTheta = sqrt(1.0f - cosTheta * cosTheta);
    return glm::vec3(cos(phi) * sinTheta, sin(phi) * sinTheta, cosTheta);
}

float GeometrySchlickGGX(float NdotV, float roughness) {
    float r = roughness + 1.0f;
    float k = (r * r) / 8.0f;
    float denom = NdotV * (1.0f - k) + k;
    return NdotV / denom;
}

float GeometrySmith(float NdotV, float NdotL, float roughness) {
    float ggx1 = GeometrySchlickGGX(NdotV, roughness);
    float ggx2 = GeometrySchlickGGX(NdotL, roughness);
    return ggx1 * ggx2;
}

std::shared_ptr<GLStudy::Texture2D> GenerateBRDFLUT(unsigned int size) {
    using namespace GLStudy;
    std::vector<float> data(size * size * 2);
    const unsigned int SAMPLE_COUNT = 128u;
    for (unsigned int y = 0; y < size; ++y) {
        float roughness = (float)y / float(size - 1);
        for (unsigned int x = 0; x < size; ++x) {
            float NdotV = (float)x / float(size - 1);
            glm::vec3 V = glm::normalize(glm::vec3(sqrt(1.0f - NdotV * NdotV), 0.0f, NdotV));
            float A = 0.0f;
            float B = 0.0f;
            for (unsigned int i = 0; i < SAMPLE_COUNT; ++i) {
                glm::vec2 Xi = Hammersley(i, SAMPLE_COUNT);
                glm::vec3 H = ImportanceSampleGGX(Xi, roughness);
                glm::vec3 L = glm::normalize(2.0f * glm::dot(V, H) * H - V);
                float NdotL = glm::max(L.z, 0.0f);
                float NdotH = glm::max(H.z, 0.0f);
                float VdotH = glm::max(glm::dot(V, H), 0.0f);
                if (NdotL > 0.0f) {
                    float G = GeometrySmith(V.z, NdotL, roughness);
                    float G_Vis = (G * VdotH) / (NdotH * NdotV + 1e-5f);
                    float Fc = pow(1.0f - VdotH, 5.0f);
                    A += (1.0f - Fc) * G_Vis;
                    B += Fc * G_Vis;
                }
            }
            A /= float(SAMPLE_COUNT);
            B /= float(SAMPLE_COUNT);
            data[(y * size + x) * 2 + 0] = A;
            data[(y * size + x) * 2 + 1] = B;
        }
    }
    auto tex = std::make_shared<Texture2D>();
    tex->LoadFromRawData(reinterpret_cast<unsigned char*>(data.data()), size, size, 2);
    return tex;
}
} // anonymous namespace

namespace GLStudy {
    void Renderer::Init() {
        shader_prog_ = Shader::CreateShaderProgram("Assets/Shaders/pbr_shader.vert", "Assets/Shaders/pbr_shader.frag");

        glUseProgram(shader_prog_);
        view_proj_location_ = glGetUniformLocation(shader_prog_, "u_ViewProjection");
        cam_pos_location_ = glGetUniformLocation(shader_prog_, "u_CamPos");
        num_lights_location_ = glGetUniformLocation(shader_prog_, "u_NumLights");
        model_location_ = glGetUniformLocation(shader_prog_, "u_Model");
        irradiance_location_ = glGetUniformLocation(shader_prog_, "u_IrradianceMap");
        prefilter_location_ = glGetUniformLocation(shader_prog_, "u_PrefilterMap");
        brdf_lut_location_ = glGetUniformLocation(shader_prog_, "u_BrdfLUT");
        use_ibl_location_ = glGetUniformLocation(shader_prog_, "u_UseIBL");
        glUniform1i(irradiance_location_, 4);
        glUniform1i(prefilter_location_, 5);
        glUniform1i(brdf_lut_location_, 6);

        brdf_lut_texture_ = GenerateBRDFLUT(256);
        if (brdf_lut_texture_)
            brdf_lut_texture_->Bind(6);

        struct Vertex {
            glm::vec3 position;
            glm::vec3 normal;
            glm::vec3 tangent;
            glm::vec2 texcoord;
        };

        // Setup triangle buffers once
        static const Vertex tri_vertices[3] = {
            { {-0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f} },
            { { 0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f} },
            { { 0.0f,  0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f, 0.0f}, {0.5f, 1.0f} }
        };
        static const unsigned int tri_indices[3] = {0, 1, 2};
        triangle_vao_ = std::make_unique<VertexArray>();
        triangle_vao_->Bind();
        triangle_vbo_ = std::make_unique<VertexBuffer>(tri_vertices, sizeof(tri_vertices));
        triangle_ibo_ = std::make_unique<IndexBuffer>(tri_indices, 3);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, tangent));
        glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texcoord));
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glEnableVertexAttribArray(2);
        glEnableVertexAttribArray(3);

        triangle_instance_vbo_ = std::make_unique<VertexBuffer>(nullptr, sizeof(InstanceData) * 1000, GL_DYNAMIC_DRAW);
        glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, sizeof(InstanceData), (void*)offsetof(InstanceData, model));
        glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, sizeof(InstanceData), (void*)(offsetof(InstanceData, model) + sizeof(glm::vec4)));
        glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, sizeof(InstanceData), (void*)(offsetof(InstanceData, model) + sizeof(glm::vec4) * 2));
        glVertexAttribPointer(7, 4, GL_FLOAT, GL_FALSE, sizeof(InstanceData), (void*)(offsetof(InstanceData, model) + sizeof(glm::vec4) * 3));
        glVertexAttribPointer(8, 4, GL_FLOAT, GL_FALSE, sizeof(InstanceData), (void*)offsetof(InstanceData, color));
        glEnableVertexAttribArray(4);
        glEnableVertexAttribArray(5);
        glEnableVertexAttribArray(6);
        glEnableVertexAttribArray(7);
        glEnableVertexAttribArray(8);
        glVertexAttribDivisor(4, 1);
        glVertexAttribDivisor(5, 1);
        glVertexAttribDivisor(6, 1);
        glVertexAttribDivisor(7, 1);
        glVertexAttribDivisor(8, 1);
        triangle_vao_->Unbind();

        // Setup cube buffers once with normals/tangents/texcoords
        static const Vertex cube_vertices[] = {
            // Front face
            { {-0.5f, -0.5f,  0.5f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f} },
            { { 0.5f, -0.5f,  0.5f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f} },
            { { 0.5f,  0.5f,  0.5f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 1.0f} },
            { {-0.5f,  0.5f,  0.5f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 1.0f} },

            // Back face
            { {-0.5f, -0.5f, -0.5f}, {0.0f, 0.0f, -1.0f}, {-1.0f, 0.0f, 0.0f}, {1.0f, 0.0f} },
            { {-0.5f,  0.5f, -0.5f}, {0.0f, 0.0f, -1.0f}, {-1.0f, 0.0f, 0.0f}, {1.0f, 1.0f} },
            { { 0.5f,  0.5f, -0.5f}, {0.0f, 0.0f, -1.0f}, {-1.0f, 0.0f, 0.0f}, {0.0f, 1.0f} },
            { { 0.5f, -0.5f, -0.5f}, {0.0f, 0.0f, -1.0f}, {-1.0f, 0.0f, 0.0f}, {0.0f, 0.0f} },

            // Left face
            { {-0.5f, -0.5f, -0.5f}, {-1.0f, 0.0f, 0.0f}, {0.0f, 0.0f,-1.0f}, {0.0f, 0.0f} },
            { {-0.5f, -0.5f,  0.5f}, {-1.0f, 0.0f, 0.0f}, {0.0f, 0.0f,-1.0f}, {1.0f, 0.0f} },
            { {-0.5f,  0.5f,  0.5f}, {-1.0f, 0.0f, 0.0f}, {0.0f, 0.0f,-1.0f}, {1.0f, 1.0f} },
            { {-0.5f,  0.5f, -0.5f}, {-1.0f, 0.0f, 0.0f}, {0.0f, 0.0f,-1.0f}, {0.0f, 1.0f} },

            // Right face
            { { 0.5f, -0.5f,  0.5f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f} },
            { { 0.5f, -0.5f, -0.5f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f} },
            { { 0.5f,  0.5f, -0.5f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f} },
            { { 0.5f,  0.5f,  0.5f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 1.0f} },

            // Bottom face
            { {-0.5f, -0.5f, -0.5f}, {0.0f,-1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f} },
            { { 0.5f, -0.5f, -0.5f}, {0.0f,-1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f} },
            { { 0.5f, -0.5f,  0.5f}, {0.0f,-1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 1.0f} },
            { {-0.5f, -0.5f,  0.5f}, {0.0f,-1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 1.0f} },

            // Top face
            { {-0.5f,  0.5f,  0.5f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f} },
            { { 0.5f,  0.5f,  0.5f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f} },
            { { 0.5f,  0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 1.0f} },
            { {-0.5f,  0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 1.0f} }
        };

        static const unsigned int cube_indices[] = {
            0,1,2, 2,3,0,       // front
            4,5,6, 6,7,4,       // back
            8,9,10, 10,11,8,    // left
            12,13,14, 14,15,12, // right
            16,17,18, 18,19,16, // bottom
            20,21,22, 22,23,20  // top
        };
        cube_vao_ = std::make_unique<VertexArray>();
        cube_vao_->Bind();
        cube_vbo_ = std::make_unique<VertexBuffer>(cube_vertices, sizeof(cube_vertices));
        cube_ibo_ = std::make_unique<IndexBuffer>(cube_indices, 36);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, tangent));
        glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texcoord));
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glEnableVertexAttribArray(2);
        glEnableVertexAttribArray(3);

        cube_instance_vbo_ = std::make_unique<VertexBuffer>(nullptr, sizeof(InstanceData) * 1000, GL_DYNAMIC_DRAW);
        glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, sizeof(InstanceData), (void*)offsetof(InstanceData, model));
        glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, sizeof(InstanceData), (void*)(offsetof(InstanceData, model) + sizeof(glm::vec4)));
        glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, sizeof(InstanceData), (void*)(offsetof(InstanceData, model) + sizeof(glm::vec4) * 2));
        glVertexAttribPointer(7, 4, GL_FLOAT, GL_FALSE, sizeof(InstanceData), (void*)(offsetof(InstanceData, model) + sizeof(glm::vec4) * 3));
        glVertexAttribPointer(8, 4, GL_FLOAT, GL_FALSE, sizeof(InstanceData), (void*)offsetof(InstanceData, color));
        glEnableVertexAttribArray(4);
        glEnableVertexAttribArray(5);
        glEnableVertexAttribArray(6);
        glEnableVertexAttribArray(7);
        glEnableVertexAttribArray(8);
        glVertexAttribDivisor(4, 1);
        glVertexAttribDivisor(5, 1);
        glVertexAttribDivisor(6, 1);
        glVertexAttribDivisor(7, 1);
        glVertexAttribDivisor(8, 1);
        cube_vao_->Unbind();
    }

    void Renderer::DrawTriangle(const glm::mat4& model, const glm::vec4& color) {
        triangle_instances_.push_back({model, color});
    }

    void Renderer::DrawCube(const glm::mat4& model, const glm::vec4& color) {
        cube_instances_.push_back({model, color});
    }

    void Renderer::Flush() {
        glUseProgram(shader_prog_);
        glUniformMatrix4fv(view_proj_location_, 1, GL_FALSE, glm::value_ptr(view_projection_));
        glUniformMatrix4fv(model_location_, 1, GL_FALSE, glm::value_ptr(glm::mat4(1.0f)));
        glUniform3fv(cam_pos_location_, 1, glm::value_ptr(camera_pos_));
        glUniform1i(num_lights_location_, static_cast<int>(lights_.size()));
        glUniform1i(glGetUniformLocation(shader_prog_, "u_UseAlbedoMap"), 0);
        glUniform1i(glGetUniformLocation(shader_prog_, "u_UseNormalMap"), 0);
        glUniform1i(glGetUniformLocation(shader_prog_, "u_UseMetallicMap"), 0);
        glUniform1i(glGetUniformLocation(shader_prog_, "u_UseRoughnessMap"), 0);
        for (size_t i = 0; i < lights_.size() && i < 4; ++i) {
            std::string base = "u_Lights[" + std::to_string(i) + "]";
            glUniform1i(glGetUniformLocation(shader_prog_, (base + ".type").c_str()), static_cast<int>(lights_[i].type));
            glUniform3fv(glGetUniformLocation(shader_prog_, (base + ".position").c_str()), 1, glm::value_ptr(lights_[i].position));
            glUniform3fv(glGetUniformLocation(shader_prog_, (base + ".direction").c_str()), 1, glm::value_ptr(lights_[i].direction));
            glUniform3fv(glGetUniformLocation(shader_prog_, (base + ".color").c_str()), 1, glm::value_ptr(lights_[i].color));
            glUniform1f(glGetUniformLocation(shader_prog_, (base + ".intensity").c_str()), lights_[i].intensity);
            glUniform1f(glGetUniformLocation(shader_prog_, (base + ".range").c_str()), lights_[i].range);
            glUniform1f(glGetUniformLocation(shader_prog_, (base + ".innerCutoff").c_str()), lights_[i].inner_cutoff);
            glUniform1f(glGetUniformLocation(shader_prog_, (base + ".outerCutoff").c_str()), lights_[i].outer_cutoff);
        }

        if (!triangle_instances_.empty()) {
            triangle_vao_->Bind();
            triangle_instance_vbo_->SetData(triangle_instances_.data(), triangle_instances_.size() * sizeof(InstanceData));
            glDrawElementsInstanced(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr, triangle_instances_.size());
            triangle_instances_.clear();
        }

        if (!cube_instances_.empty()) {
            cube_vao_->Bind();
            cube_instance_vbo_->SetData(cube_instances_.data(), cube_instances_.size() * sizeof(InstanceData));
            glDrawElementsInstanced(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr, cube_instances_.size());
            cube_instances_.clear();
        }
    }
}
