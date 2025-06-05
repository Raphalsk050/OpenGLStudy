#include "IndexBuffer.h"

namespace GLStudy {
    IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count, GLenum usage)
        : count_(count)
    {
        glGenBuffers(1, &renderer_id_);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderer_id_);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, usage);
    }

    IndexBuffer::~IndexBuffer()
    {
        glDeleteBuffers(1, &renderer_id_);
    }

    void IndexBuffer::Bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderer_id_);
    }

    void IndexBuffer::Unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
}
