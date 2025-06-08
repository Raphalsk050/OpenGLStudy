#include "CubemapTexture.h"
#include <stb_image.h>
#include <iostream>

namespace GLStudy {
CubemapTexture::~CubemapTexture() {
    if (renderer_id_) {
        glDeleteTextures(1, &renderer_id_);
    }
}

bool CubemapTexture::LoadFromFiles(const std::array<std::string,6>& faces, bool hdr) {
    if (renderer_id_ != 0) {
        glDeleteTextures(1, &renderer_id_);
    }
    glGenTextures(1, &renderer_id_);
    glBindTexture(GL_TEXTURE_CUBE_MAP, renderer_id_);
    stbi_set_flip_vertically_on_load(false);
    for (unsigned int i = 0; i < faces.size(); ++i) {
        int width, height, channels;
        if (hdr) {
            float* data = stbi_loadf(faces[i].c_str(), &width, &height, &channels, 0);
            if (!data) {
                std::cerr << "Failed to load HDR cubemap face: " << faces[i] << std::endl;
                return false;
            }
            GLenum format = channels == 4 ? GL_RGBA : (channels == 3 ? GL_RGB : GL_RED);
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB16F, width, height, 0, format, GL_FLOAT, data);
            stbi_image_free(data);
        } else {
            unsigned char* data = stbi_load(faces[i].c_str(), &width, &height, &channels, 0);
            if (!data) {
                std::cerr << "Failed to load cubemap face: " << faces[i] << std::endl;
                return false;
            }
            GLenum format = channels == 4 ? GL_RGBA : (channels == 3 ? GL_RGB : GL_RED);
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
            stbi_image_free(data);
        }
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    return true;
}

void CubemapTexture::Bind(unsigned int slot) const {
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_CUBE_MAP, renderer_id_);
}
} // namespace GLStudy
