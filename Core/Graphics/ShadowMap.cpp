#include "ShadowMap.h"
#include <gtc/type_ptr.hpp>

namespace GLStudy {
    void ShadowMap::Init(unsigned int width, unsigned int height) {
        width_ = width; height_ = height;
        glGenFramebuffers(1, &fbo_);
        glGenTextures(1, &depth_map_);
        glBindTexture(GL_TEXTURE_2D, depth_map_);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, width_, height_, 0,
                     GL_DEPTH_COMPONENT, GL_FLOAT, nullptr);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
        float borderColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
        glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);

        glBindFramebuffer(GL_FRAMEBUFFER, fbo_);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depth_map_, 0);
        glDrawBuffer(GL_NONE);
        glReadBuffer(GL_NONE);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    ShadowMap::~ShadowMap() {
        if(depth_map_) glDeleteTextures(1, &depth_map_);
        if(fbo_) glDeleteFramebuffers(1, &fbo_);
    }

    void ShadowMap::BindFramebuffer() const {
        glViewport(0, 0, width_, height_);
        glBindFramebuffer(GL_FRAMEBUFFER, fbo_);
        glClear(GL_DEPTH_BUFFER_BIT);
    }

    void ShadowMap::UnbindFramebuffer() const {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }
}
