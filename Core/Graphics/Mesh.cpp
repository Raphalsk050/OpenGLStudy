#include "Mesh.h"
#include <gtc/type_ptr.hpp>

namespace GLStudy {

Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices,
           std::shared_ptr<Texture2D> albedo, std::shared_ptr<Texture2D> normal,
           std::shared_ptr<Texture2D> metallic, std::shared_ptr<Texture2D> roughness)
    : albedo_(std::move(albedo)), normal_(std::move(normal)),
      metallic_(std::move(metallic)), roughness_(std::move(roughness)) {
    vao_ = std::make_unique<VertexArray>();
    vao_->Bind();
    vbo_ = std::make_unique<VertexBuffer>(vertices.data(), vertices.size() * sizeof(Vertex));
    ibo_ = std::make_unique<IndexBuffer>(indices.data(), indices.size());
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, tangent));
    glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texcoord));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glEnableVertexAttribArray(3);
    vao_->Unbind();
    index_count_ = indices.size();
}

void Mesh::Draw(unsigned int shader) const {
    if (albedo_) {
        glUniform1i(glGetUniformLocation(shader, "u_UseAlbedoMap"), 1);
        glUniform1i(glGetUniformLocation(shader, "u_AlbedoMap"), 0);
        albedo_->Bind(0);
    } else {
        glUniform1i(glGetUniformLocation(shader, "u_UseAlbedoMap"), 0);
    }
    if (normal_) {
        glUniform1i(glGetUniformLocation(shader, "u_UseNormalMap"), 1);
        glUniform1i(glGetUniformLocation(shader, "u_NormalMap"), 1);
        normal_->Bind(1);
    } else {
        glUniform1i(glGetUniformLocation(shader, "u_UseNormalMap"), 0);
    }
    if (metallic_) {
        glUniform1i(glGetUniformLocation(shader, "u_UseMetallicMap"), 1);
        glUniform1i(glGetUniformLocation(shader, "u_MetallicMap"), 2);
        metallic_->Bind(2);
    } else {
        glUniform1i(glGetUniformLocation(shader, "u_UseMetallicMap"), 0);
    }
    if (roughness_) {
        glUniform1i(glGetUniformLocation(shader, "u_UseRoughnessMap"), 1);
        glUniform1i(glGetUniformLocation(shader, "u_RoughnessMap"), 3);
        roughness_->Bind(3);
    } else {
        glUniform1i(glGetUniformLocation(shader, "u_UseRoughnessMap"), 0);
    }
    vao_->Bind();
    glDrawElements(GL_TRIANGLES, index_count_, GL_UNSIGNED_INT, nullptr);
    vao_->Unbind();
    if (albedo_)
        albedo_->Unbind();
    if (normal_)
        normal_->Unbind();
    if (metallic_)
        metallic_->Unbind();
    if (roughness_)
        roughness_->Unbind();
}

}
