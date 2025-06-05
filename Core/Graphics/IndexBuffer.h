#pragma once
#include "glad/glad.h"

namespace GLStudy {
    class IndexBuffer {
    public:
        IndexBuffer(const unsigned int* data, unsigned int count, GLenum usage = GL_STATIC_DRAW);
        ~IndexBuffer();

        void Bind() const;
        void Unbind() const;
        unsigned int GetCount() const { return count_; }
    private:
        unsigned int renderer_id_ = 0;
        unsigned int count_ = 0;
    };
}
