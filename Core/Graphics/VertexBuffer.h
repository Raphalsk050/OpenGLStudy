#pragma once
#include "glad/glad.h"

namespace GLStudy
{
    class VertexBuffer
    {
    public:
        VertexBuffer(const void* data, unsigned int size, GLenum usage = GL_STATIC_DRAW);
        ~VertexBuffer();
        void Bind() const;
        void Unbind() const;

    private:
        unsigned int renderer_id_ = 0;
    };
} // GLStudy
