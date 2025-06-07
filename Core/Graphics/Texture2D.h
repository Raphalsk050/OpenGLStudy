#pragma once
#include <string>
#include "glad/glad.h"

namespace GLStudy {
class Texture2D {
public:
    Texture2D(const std::string& path, bool flip_vertically = true);
    ~Texture2D();
    void Bind(unsigned int slot = 0) const;
    unsigned int GetID() const { return id_; }
private:
    unsigned int id_ = 0;
};
}
