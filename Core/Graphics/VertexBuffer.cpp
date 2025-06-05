#include "VertexBuffer.h"

namespace GLStudy {
    VertexBuffer::VertexBuffer(const void* data, unsigned int size, GLenum usage)
    {
        glGenBuffers(1, &renderer_id_);
        glBindBuffer(GL_ARRAY_BUFFER, renderer_id_);
        glBufferData(GL_ARRAY_BUFFER, size, data, usage);
    }

    VertexBuffer::~VertexBuffer()
    {
        glDeleteBuffers(1, &renderer_id_);
    }

    void VertexBuffer::Bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, renderer_id_);
    }

    void VertexBuffer::Unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void VertexBuffer::SetData(const void* data, unsigned int size) const
    {
        glBindBuffer(GL_ARRAY_BUFFER, renderer_id_);
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
    }
} // GLStudy
