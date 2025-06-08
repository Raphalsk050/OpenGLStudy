#pragma once
#include <glad/glad.h>

namespace GLStudy {
class CubemapTexture {
public:
    CubemapTexture() = default;
    ~CubemapTexture();
    bool Create(int size, GLenum internal_format = GL_RGB16F, GLenum format = GL_RGB, GLenum type = GL_FLOAT);
    void Bind(unsigned int slot = 0) const;
    unsigned int GetID() const { return renderer_id_; }
private:
    unsigned int renderer_id_ = 0;
};
}
