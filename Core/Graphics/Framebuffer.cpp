#include "Framebuffer.h"

namespace GLStudy {

Framebuffer::Framebuffer() {
    glGenFramebuffers(1, &id_);
}

Framebuffer::~Framebuffer() {
    if (id_) glDeleteFramebuffers(1, &id_);
}

void Framebuffer::Bind() const {
    glBindFramebuffer(GL_FRAMEBUFFER, id_);
}

void Framebuffer::Unbind() const {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void Framebuffer::AttachCubemapFace(unsigned int cubemap, GLenum face, int level) {
    Bind();
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, face, cubemap, level);
}

void Framebuffer::AttachTexture2D(unsigned int texture) {
    Bind();
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);
}

}
