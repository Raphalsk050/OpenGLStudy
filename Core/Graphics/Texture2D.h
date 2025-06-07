#pragma once
#include <string>
#include "glad/glad.h"

namespace GLStudy {
class Texture2D {
public:
    Texture2D();
    bool LoadFromFile(const std::string& path);
    void Bind(unsigned int slot = 0) const;
private:
    unsigned int id_;
    int width_;
    int height_;
    int channels_;
};
}
