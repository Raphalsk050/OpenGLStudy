#include "Skybox.h"
#include <gtc/type_ptr.hpp>

namespace GLStudy {

static const float skybox_vertices[] = {
    -1.0f,  1.0f, -1.0f,
    -1.0f, -1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,
     1.0f,  1.0f, -1.0f,
    -1.0f,  1.0f, -1.0f,

    -1.0f, -1.0f,  1.0f,
    -1.0f, -1.0f, -1.0f,
    -1.0f,  1.0f, -1.0f,
    -1.0f,  1.0f, -1.0f,
    -1.0f,  1.0f,  1.0f,
    -1.0f, -1.0f,  1.0f,

     1.0f, -1.0f, -1.0f,
     1.0f, -1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,

    -1.0f, -1.0f,  1.0f,
    -1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f, -1.0f,  1.0f,
    -1.0f, -1.0f,  1.0f,

    -1.0f,  1.0f, -1.0f,
     1.0f,  1.0f, -1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
    -1.0f,  1.0f,  1.0f,
    -1.0f,  1.0f, -1.0f,

    -1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f,  1.0f,
     1.0f, -1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f,  1.0f,
     1.0f, -1.0f,  1.0f
};

bool Skybox::Load(const std::array<std::string,6>& faces, bool hdr) {
    vao_ = std::make_unique<VertexArray>();
    vao_->Bind();
    vbo_ = std::make_unique<VertexBuffer>(skybox_vertices, sizeof(skybox_vertices));
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    vao_->Unbind();

    if (!cubemap_.LoadFromFiles(faces, hdr))
        return false;

    shader_prog_ = Shader::CreateShaderProgram("Assets/Shaders/skybox.vert", "Assets/Shaders/skybox.frag");
    view_loc_ = glGetUniformLocation(shader_prog_, "u_View");
    proj_loc_ = glGetUniformLocation(shader_prog_, "u_Projection");
    return shader_prog_ != 0;
}

bool Skybox::Load(const std::string& file, bool hdr) {
    vao_ = std::make_unique<VertexArray>();
    vao_->Bind();
    vbo_ = std::make_unique<VertexBuffer>(skybox_vertices, sizeof(skybox_vertices));
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    vao_->Unbind();

    if (!cubemap_.LoadFromSingleFile(file, hdr))
        return false;

    shader_prog_ = Shader::CreateShaderProgram("Assets/Shaders/skybox.vert", "Assets/Shaders/skybox.frag");
    view_loc_ = glGetUniformLocation(shader_prog_, "u_View");
    proj_loc_ = glGetUniformLocation(shader_prog_, "u_Projection");
    return shader_prog_ != 0;
}

void Skybox::Draw(const glm::mat4& view, const glm::mat4& projection) {
    glDepthFunc(GL_LEQUAL);
    glUseProgram(shader_prog_);
    glm::mat4 view_no_translation = glm::mat4(glm::mat3(view));
    glUniformMatrix4fv(view_loc_, 1, GL_FALSE, glm::value_ptr(view_no_translation));
    glUniformMatrix4fv(proj_loc_, 1, GL_FALSE, glm::value_ptr(projection));
    cubemap_.Bind(0);
    vao_->Bind();
    glDrawArrays(GL_TRIANGLES, 0, 36);
    vao_->Unbind();
    glDepthFunc(GL_LESS);
}

} // namespace GLStudy
