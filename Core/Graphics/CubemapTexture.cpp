#include "CubemapTexture.h"

namespace GLStudy {

bool CubemapTexture::Create(int size, GLenum internal_format, GLenum format, GLenum type) {
    if (renderer_id_) glDeleteTextures(1, &renderer_id_);
    glGenTextures(1, &renderer_id_);
    glBindTexture(GL_TEXTURE_CUBE_MAP, renderer_id_);
    for (unsigned int i = 0; i < 6; ++i)
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, internal_format, size, size, 0, format, type, nullptr);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    return true;
}

CubemapTexture::~CubemapTexture() {
    if (renderer_id_) glDeleteTextures(1, &renderer_id_);
}

void CubemapTexture::Bind(unsigned int slot) const {
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_CUBE_MAP, renderer_id_);
}

}
