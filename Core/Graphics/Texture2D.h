#pragma once
#include <string>
#include "glad/glad.h"

namespace GLStudy {
    class Texture2D {
    public:
        Texture2D() = default;
        ~Texture2D();
        bool LoadFromFile(const std::string& path, bool srgb = false);
        void Bind(unsigned int slot = 0) const;
    private:
        unsigned int renderer_id_ = 0;
        int width_ = 0, height_ = 0, channels_ = 0;
    };
}
