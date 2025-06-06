#include "Renderer.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include <gtc/type_ptr.hpp>
#include <string>

namespace GLStudy {
    void Renderer::Init() {
        shader_prog_ = Shader::CreateShaderProgram("Assets/Shaders/pbr_shader.vert", "Assets/Shaders/pbr_shader.frag");

        glUseProgram(shader_prog_);
        view_proj_location_ = glGetUniformLocation(shader_prog_, "u_ViewProjection");
        cam_pos_location_ = glGetUniformLocation(shader_prog_, "u_CamPos");
        num_lights_location_ = glGetUniformLocation(shader_prog_, "u_NumLights");

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
        glUniform3fv(cam_pos_location_, 1, glm::value_ptr(camera_pos_));
        glUniform1i(num_lights_location_, static_cast<int>(lights_.size()));
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
