#pragma once
#include <string>
#include "glad/glad.h"

namespace GLStudy {
class Texture2D {
public:
    Texture2D() = default;
    explicit Texture2D(const std::string& path);
    Texture2D(const unsigned char* data, int size);
    ~Texture2D();
    bool LoadFromFile(const std::string& path);
    bool LoadFromMemory(const unsigned char* data, int size);
    bool LoadFromRawData(const unsigned char* data, int width, int height, int channels);
    void Bind(unsigned int slot = 0) const;
    void Unbind() const;
    int GetWidth() const { return width_; }
    int GetHeight() const { return height_; }
private:
    unsigned int renderer_id_ = 0;
    int width_ = 0;
    int height_ = 0;
    int channels_ = 0;
};
}
