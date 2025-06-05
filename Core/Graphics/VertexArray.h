#pragma once
#include "glad/glad.h"

namespace GLStudy
{
    class VertexArray
    {
    public:
        VertexArray();
        ~VertexArray();
        void Bind() const;
        void Unbind() const;

    private:
        unsigned int renderer_id_ = 0;
    };
} // GLStudy
