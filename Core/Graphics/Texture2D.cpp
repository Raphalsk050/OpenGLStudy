#define STB_IMAGE_IMPLEMENTATION
#include "Texture2D.h"
#include "stb_image.h"

namespace GLStudy {
Texture2D::Texture2D(const std::string& path, bool flip_vertically) {
    stbi_set_flip_vertically_on_load(flip_vertically);
    int w, h, ch;
    unsigned char* data = stbi_load(path.c_str(), &w, &h, &ch, 0);
    if (data) {
        GLenum format = ch == 4 ? GL_RGBA : GL_RGB;
        glGenTextures(1, &id_);
        glBindTexture(GL_TEXTURE_2D, id_);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexImage2D(GL_TEXTURE_2D, 0, format, w, h, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        stbi_image_free(data);
    }
}

Texture2D::~Texture2D() {
    if (id_) glDeleteTextures(1, &id_);
}

void Texture2D::Bind(unsigned int slot) const {
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, id_);
}
}
