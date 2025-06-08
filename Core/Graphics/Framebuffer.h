#pragma once
#include <glad/glad.h>

namespace GLStudy {
class Framebuffer {
public:
    Framebuffer();
    ~Framebuffer();
    void Bind() const;
    void Unbind() const;
    void AttachCubemapFace(unsigned int cubemap, GLenum face, int level = 0);
    void AttachTexture2D(unsigned int texture);
private:
    unsigned int id_ = 0;
};
}
