#include "VertexArray.h"

namespace GLStudy {
    VertexArray::VertexArray()
    {
        glGenVertexArrays(1, &renderer_id_);
    }

    VertexArray::~VertexArray()
    {
        glDeleteVertexArrays(1, &renderer_id_);
    }

    void VertexArray::Bind() const
    {
        glBindVertexArray(renderer_id_);
    }

    void VertexArray::Unbind() const
    {
        glBindVertexArray(0);
    }
} // GLStudy
