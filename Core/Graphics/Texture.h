#pragma once
#include <string>
#include "glad/glad.h"

namespace GLStudy {
class Texture {
public:
    static GLuint LoadTexture2D(const std::string& path);
};
}
