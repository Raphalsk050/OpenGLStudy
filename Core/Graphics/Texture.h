#pragma once
#include <string>
#include "glad/glad.h"
#include <assimp/texture.h>

namespace GLStudy {
class Texture {
public:
    static GLuint LoadTexture2D(const std::string& path);
    static GLuint LoadTextureFromAssimp(const aiTexture* tex);
};
}
