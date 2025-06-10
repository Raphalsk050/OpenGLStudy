#include "CubemapTexture.h"
#include <stb_image.h>
#include <zlib.h>
#include <tinyexr.h>
#include <glm.hpp>
#include <gtc/constants.hpp>
#include <iostream>
#include <vector>
#include <cstring>

namespace GLStudy {
CubemapTexture::~CubemapTexture() {
    if (renderer_id_) {
        glDeleteTextures(1, &renderer_id_);
    }
}

bool CubemapTexture::LoadFromFiles(const std::array<std::string,6>& faces, bool hdr) {
    if (renderer_id_ != 0) {
        glDeleteTextures(1, &renderer_id_);
    }
    glGenTextures(1, &renderer_id_);
    glBindTexture(GL_TEXTURE_CUBE_MAP, renderer_id_);
    stbi_set_flip_vertically_on_load(false);
    for (unsigned int i = 0; i < faces.size(); ++i) {
        int width, height, channels;
        if (hdr) {
            int from_exr = 0;
            float* data = stbi_loadf(faces[i].c_str(), &width, &height, &channels, 0);
            if (!data) {
                const char* err = nullptr;
                int ret = LoadEXR(&data, &width, &height, faces[i].c_str(), &err);
                if (ret != TINYEXR_SUCCESS) {
                    if(err) {
                        std::cerr << "Failed to load EXR cubemap face: " << err << std::endl;
                        FreeEXRErrorMessage(err);
                    } else {
                        std::cerr << "Failed to load EXR cubemap face: " << faces[i] << std::endl;
                    }
                    return false;
                }
                channels = 4;
                from_exr = 1;
            }
            GLenum format = channels == 4 ? GL_RGBA : (channels == 3 ? GL_RGB : GL_RED);
            GLenum internal = channels == 4 ? GL_RGBA16F : GL_RGB16F;
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, internal, width, height, 0, format, GL_FLOAT, data);
            if(from_exr)
                free(data);
            else
                stbi_image_free(data);
        } else {
            unsigned char* data = stbi_load(faces[i].c_str(), &width, &height, &channels, 0);
            if (!data) {
                std::cerr << "Failed to load cubemap face: " << faces[i] << std::endl;
                return false;
            }
            GLenum format = channels == 4 ? GL_RGBA : (channels == 3 ? GL_RGB : GL_RED);
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
            stbi_image_free(data);
        }
    }
    glGenerateMipmap(GL_TEXTURE_CUBE_MAP);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    return true;
}

bool CubemapTexture::LoadFromSingleFile(const std::string& file, bool hdr) {
    if (renderer_id_ != 0) {
        glDeleteTextures(1, &renderer_id_);
    }

    int width, height, channels;
    stbi_set_flip_vertically_on_load(false);
    float* data_f = nullptr;
    unsigned char* data = nullptr;
    bool exr_loaded = false;
    if (hdr) {
        data_f = stbi_loadf(file.c_str(), &width, &height, &channels, 0);
        if (!data_f) {
            const char* err = nullptr;
            int ret = LoadEXR(&data_f, &width, &height, file.c_str(), &err);
            if (ret != TINYEXR_SUCCESS) {
                if(err) {
                    std::cerr << "Failed to load EXR cubemap: " << err << std::endl;
                    FreeEXRErrorMessage(err);
                } else {
                    std::cerr << "Failed to load HDR cubemap: " << file << std::endl;
                }
                return false;
            }
            channels = 4;
            exr_loaded = true;
        }
    } else {
        data = stbi_load(file.c_str(), &width, &height, &channels, 0);
        if (!data) {
            std::cerr << "Failed to load cubemap image: " << file << std::endl;
            return false;
        }
    }

    enum class Layout { HorizontalStrip, VerticalStrip, HorizontalCross, VerticalCross, Equirectangular };
    Layout layout;
    int face_size = 0;
    if (width == height * 6) {
        layout = Layout::HorizontalStrip;
        face_size = height;
    } else if (height == width * 6) {
        layout = Layout::VerticalStrip;
        face_size = width;
    } else if (width * 3 == height * 4) {
        layout = Layout::HorizontalCross;
        face_size = width / 4;
    } else if (height * 3 == width * 4) {
        layout = Layout::VerticalCross;
        face_size = height / 4;
    } else if (width == height * 2) {
        layout = Layout::Equirectangular;
        face_size = height;
    } else {
        std::cerr << "Unsupported cubemap layout: " << file << std::endl;
        if (hdr)
            exr_loaded ? free(data_f) : stbi_image_free(data_f);
        else
            stbi_image_free(data);
        return false;
    }

    glGenTextures(1, &renderer_id_);
    glBindTexture(GL_TEXTURE_CUBE_MAP, renderer_id_);
    GLenum format = channels == 4 ? GL_RGBA : (channels == 3 ? GL_RGB : GL_RED);
    GLenum internal = channels == 4 && hdr ? GL_RGBA16F : (hdr ? GL_RGB16F : format);
    GLenum type = hdr ? GL_FLOAT : GL_UNSIGNED_BYTE;

    auto copy_face = [&](int face, int x_off, int y_off) {
        int pixel_size = hdr ? sizeof(float) : sizeof(unsigned char);
        std::vector<unsigned char> buffer(face_size * face_size * channels * pixel_size);
        for (int row = 0; row < face_size; ++row) {
            const void* src;
            if (hdr)
                src = data_f + ((y_off + row) * width + x_off) * channels;
            else
                src = data + ((y_off + row) * width + x_off) * channels;
            memcpy(buffer.data() + row * face_size * channels * pixel_size, src, face_size * channels * pixel_size);
        }
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + face, 0,
                     internal, face_size, face_size, 0,
                     format, type, buffer.data());
    };

    auto copy_from_equirect = [&](int face) {
        int pixel_size = hdr ? sizeof(float) : sizeof(unsigned char);
        std::vector<unsigned char> buffer(face_size * face_size * channels * pixel_size);
        for (int y = 0; y < face_size; ++y) {
            for (int x = 0; x < face_size; ++x) {
                float u = 2.0f * (x + 0.5f) / face_size - 1.0f;
                float v = 2.0f * (y + 0.5f) / face_size - 1.0f;
                glm::vec3 dir;
                switch (face) {
                case 0: dir = glm::normalize(glm::vec3(1.0f, v, -u)); break;  // +X
                case 1: dir = glm::normalize(glm::vec3(-1.0f, v, u)); break; // -X
                case 2: dir = glm::normalize(glm::vec3(u, -1.0f, v)); break; // -Y
                case 3: dir = glm::normalize(glm::vec3(u, 1.0f, -v)); break; // +Y
                case 4: dir = glm::normalize(glm::vec3(u, v, 1.0f)); break;  // +Z
                default: dir = glm::normalize(glm::vec3(-u, v, -1.0f)); break; // -Z
                }
                float phi = atan2f(dir.z, dir.x);
                float theta = asinf(dir.y);
                float uf = (phi + glm::pi<float>()) / (2.0f * glm::pi<float>());
                float vf = (theta + glm::half_pi<float>()) / glm::pi<float>();
                int src_x = glm::clamp(int(uf * (width - 1)), 0, width - 1);
                int src_y = glm::clamp(int(vf * (height - 1)), 0, height - 1);
                size_t dst_idx = (y * face_size + x) * channels * pixel_size;
                size_t src_idx = (src_y * width + src_x) * channels * pixel_size;
                if (hdr) {
                    memcpy(buffer.data() + dst_idx, reinterpret_cast<unsigned char*>(data_f) + src_idx, channels * pixel_size);
                } else {
                    memcpy(buffer.data() + dst_idx, data + src_idx, channels * pixel_size);
                }
            }
        }
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + face, 0,
                     internal, face_size, face_size, 0,
                     format, type, buffer.data());
    };

    switch (layout) {
    case Layout::HorizontalStrip:
        for (int i = 0; i < 6; ++i)
            copy_face(i, face_size * i, 0);
        break;
    case Layout::VerticalStrip:
        for (int i = 0; i < 6; ++i)
            copy_face(i, 0, face_size * i);
        break;
    case Layout::HorizontalCross:
        copy_face(0, 2 * face_size, face_size); // +X
        copy_face(1, 0, face_size);             // -X
        copy_face(2, face_size, 0);             // +Y
        copy_face(3, face_size, 2 * face_size); // -Y
        copy_face(4, face_size, face_size);     // +Z
        copy_face(5, 3 * face_size, face_size); // -Z
        break;
    case Layout::VerticalCross:
        copy_face(0, face_size, face_size);     // +X
        copy_face(1, face_size, 3 * face_size); // -X
        copy_face(2, face_size, 0);             // +Y
        copy_face(3, face_size, 2 * face_size); // -Y
        copy_face(4, 0, face_size);             // +Z
        copy_face(5, 2 * face_size, face_size); // -Z
        break;
    case Layout::Equirectangular:
        for (int i = 0; i < 6; ++i)
            copy_from_equirect(i);
        break;
    }

    if (hdr)
        exr_loaded ? free(data_f) : stbi_image_free(data_f);
    else
        stbi_image_free(data);

    glGenerateMipmap(GL_TEXTURE_CUBE_MAP);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    return true;
}

void CubemapTexture::Bind(unsigned int slot) const {
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_CUBE_MAP, renderer_id_);
}
} // namespace GLStudy
