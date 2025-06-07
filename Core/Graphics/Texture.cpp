#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <iostream>

namespace GLStudy {
Texture2D::Texture2D(const std::string& path) {
    LoadFromFile(path);
}

bool Texture2D::LoadFromFile(const std::string& path) {
    if(renderer_id_ != 0) {
        glDeleteTextures(1, &renderer_id_);
        renderer_id_ = 0;
    }
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(path.c_str(), &width_, &height_, &channels_, 0);
    if(!data) {
        std::cerr << "Failed to load texture: " << path << std::endl;
        return false;
    }
    GLenum format = GL_RGB;
    if(channels_ == 4) format = GL_RGBA;
    else if(channels_ == 3) format = GL_RGB;
    else if(channels_ == 1) format = GL_RED;

    glGenTextures(1, &renderer_id_);
    glBindTexture(GL_TEXTURE_2D, renderer_id_);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, format, width_, height_, 0, format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);
    return true;
}

Texture2D::~Texture2D() {
    if(renderer_id_)
        glDeleteTextures(1, &renderer_id_);
}

void Texture2D::Bind(unsigned int slot) const {
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, renderer_id_);
}

void Texture2D::Unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}
}
