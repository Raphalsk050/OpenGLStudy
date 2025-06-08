#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#define TINYEXR_IMPLEMENTATION
#include <tinyexr.h>
#include <iostream>

namespace GLStudy {
Texture2D::Texture2D(const std::string& path) {
    LoadFromFile(path);
}

Texture2D::Texture2D(const unsigned char* data, int size) {
    LoadFromMemory(data, size);
}

bool Texture2D::LoadFromFile(const std::string& path) {
    if(renderer_id_ != 0) {
        glDeleteTextures(1, &renderer_id_);
        renderer_id_ = 0;
    }
    stbi_set_flip_vertically_on_load(true);
    std::string ext = path.substr(path.find_last_of('.') + 1);
    for (auto& c : ext) c = static_cast<char>(tolower(c));
    if (ext == "hdr") {
        float* data = stbi_loadf(path.c_str(), &width_, &height_, &channels_, 0);
        if(!data) {
            std::cerr << "Failed to load HDR texture: " << path << std::endl;
            return false;
        }
        GLenum format = channels_ == 4 ? GL_RGBA : GL_RGB;
        glGenTextures(1, &renderer_id_);
        glBindTexture(GL_TEXTURE_2D, renderer_id_);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, width_, height_, 0, format, GL_FLOAT, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        stbi_image_free(data);
        return true;
    } else if (ext == "exr") {
        float* out; int w, h; const char* err = nullptr;
        int ret = LoadEXR(&out, &w, &h, path.c_str(), &err);
        if (ret != TINYEXR_SUCCESS) {
            if (err) {
                std::cerr << "Failed to load EXR texture: " << err << std::endl;
                FreeEXRErrorMessage(err);
            }
            return false;
        }
        width_ = w; height_ = h; channels_ = 4;
        GLenum format = GL_RGBA;
        glGenTextures(1, &renderer_id_);
        glBindTexture(GL_TEXTURE_2D, renderer_id_);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, width_, height_, 0, format, GL_FLOAT, out);
        glGenerateMipmap(GL_TEXTURE_2D);
        free(out);
        return true;
    } else {
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
}

bool Texture2D::LoadFromMemory(const unsigned char* data, int size) {
    if(renderer_id_ != 0) {
        glDeleteTextures(1, &renderer_id_);
        renderer_id_ = 0;
    }
    stbi_set_flip_vertically_on_load(true);
    unsigned char* pixels = stbi_load_from_memory(data, size, &width_, &height_, &channels_, 0);
    if(!pixels) {
        std::cerr << "Failed to load texture from memory" << std::endl;
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
    glTexImage2D(GL_TEXTURE_2D, 0, format, width_, height_, 0, format, GL_UNSIGNED_BYTE, pixels);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(pixels);
    return true;
}

bool Texture2D::LoadFromRawData(const unsigned char* data, int width, int height, int channels) {
    if(renderer_id_ != 0) {
        glDeleteTextures(1, &renderer_id_);
        renderer_id_ = 0;
    }
    width_ = width;
    height_ = height;
    channels_ = channels;
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
