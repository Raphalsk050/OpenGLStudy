#pragma once
#include "glad/glad.h"
#include <glm.hpp>

namespace GLStudy {
    class ShadowMap {
    public:
        ShadowMap() = default;
        ~ShadowMap();

        void Init(unsigned int width = 1024, unsigned int height = 1024);
        void BindFramebuffer() const;
        void UnbindFramebuffer() const;

        GLuint GetDepthMap() const { return depth_map_; }
        void SetLightSpaceMatrix(const glm::mat4& mat) { light_space_matrix_ = mat; }
        const glm::mat4& GetLightSpaceMatrix() const { return light_space_matrix_; }
    private:
        GLuint fbo_ = 0;
        GLuint depth_map_ = 0;
        unsigned int width_ = 1024;
        unsigned int height_ = 1024;
        glm::mat4 light_space_matrix_{1.0f};
    };
}
