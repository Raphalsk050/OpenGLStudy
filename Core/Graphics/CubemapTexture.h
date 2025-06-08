#pragma once
#include <array>
#include <string>
#include "glad/glad.h"

namespace GLStudy {
class CubemapTexture {
public:
    CubemapTexture() = default;
    ~CubemapTexture();
    bool LoadFromFiles(const std::array<std::string,6>& faces, bool hdr = false);
    void Bind(unsigned int slot = 0) const;
private:
    unsigned int renderer_id_ = 0;
};
}
