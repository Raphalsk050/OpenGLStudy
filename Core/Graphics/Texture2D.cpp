#include "Texture2D.h"
#include <stb_image.h>

namespace GLStudy {
    Texture2D::~Texture2D() {
        if (renderer_id_)
            glDeleteTextures(1, &renderer_id_);
    }

    bool Texture2D::LoadFromFile(const std::string& path, bool srgb) {
        stbi_set_flip_vertically_on_load(1);
        unsigned char* data = stbi_load(path.c_str(), &width_, &height_, &channels_, 0);
        if (!data)
            return false;
        GLenum internal_format = srgb ? GL_SRGB8_ALPHA8 : GL_RGBA8;
        GLenum format = channels_ == 3 ? GL_RGB : GL_RGBA;
        glGenTextures(1, &renderer_id_);
        glBindTexture(GL_TEXTURE_2D, renderer_id_);
        glTexImage2D(GL_TEXTURE_2D, 0, internal_format, width_, height_, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        stbi_image_free(data);
        return true;
    }

    void Texture2D::Bind(unsigned int slot) const {
        glActiveTexture(GL_TEXTURE0 + slot);
        glBindTexture(GL_TEXTURE_2D, renderer_id_);
    }
}
