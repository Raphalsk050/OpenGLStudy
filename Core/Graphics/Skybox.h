#pragma once
#include "CubemapTexture.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "Core/Shader/Shader.h"
#include <memory>
#include <glm.hpp>

namespace GLStudy {
class Skybox {
public:
    Skybox() = default;
    bool Load(const std::array<std::string,6>& faces, bool hdr = false);
    bool Load(const std::string& file, bool hdr = false);
    bool LoadIBL(const std::string& irradianceKtx, const std::string& prefilterKtx);
    void Draw(const glm::mat4& view, const glm::mat4& projection);
    void Bind(unsigned int slot = 0) const;
    void BindIrradiance(unsigned int slot) const;
    void BindPrefilter(unsigned int slot) const;
private:
    CubemapTexture cubemap_;
    CubemapTexture irradiance_;
    CubemapTexture prefilter_;
    std::unique_ptr<VertexArray> vao_;
    std::unique_ptr<VertexBuffer> vbo_;
    unsigned int shader_prog_ = 0;
    int view_loc_ = -1;
    int proj_loc_ = -1;
};
}
