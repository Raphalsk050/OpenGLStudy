#include "Mesh.h"
#include <gtc/type_ptr.hpp>

namespace GLStudy {

Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices, std::shared_ptr<Texture2D> texture)
    : texture_(std::move(texture)) {
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
    if (texture_) {
        glUniform1i(glGetUniformLocation(shader, "u_UseTexture"), 1);
        glUniform1i(glGetUniformLocation(shader, "u_AlbedoMap"), 0);
        texture_->Bind(0);
    } else {
        glUniform1i(glGetUniformLocation(shader, "u_UseTexture"), 0);
    }
    vao_->Bind();
    glDrawElements(GL_TRIANGLES, index_count_, GL_UNSIGNED_INT, nullptr);
    vao_->Unbind();
    if (texture_)
        texture_->Unbind();
}

}
