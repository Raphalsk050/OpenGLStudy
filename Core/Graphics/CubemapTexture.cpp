#include "CubemapTexture.h"
#include <stb_image.h>
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
            float* data = stbi_loadf(faces[i].c_str(), &width, &height, &channels, 0);
            if (!data) {
                std::cerr << "Failed to load HDR cubemap face: " << faces[i] << std::endl;
                return false;
            }
            GLenum format = channels == 4 ? GL_RGBA : (channels == 3 ? GL_RGB : GL_RED);
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB16F, width, height, 0, format, GL_FLOAT, data);
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
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
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
    if (hdr) {
        data_f = stbi_loadf(file.c_str(), &width, &height, &channels, 0);
        if (!data_f) {
            std::cerr << "Failed to load HDR cubemap: " << file << std::endl;
            return false;
        }
    } else {
        data = stbi_load(file.c_str(), &width, &height, &channels, 0);
        if (!data) {
            std::cerr << "Failed to load cubemap image: " << file << std::endl;
            return false;
        }
    }

    enum class Layout { HorizontalStrip, VerticalStrip, HorizontalCross, VerticalCross };
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
    } else {
        std::cerr << "Unsupported cubemap layout: " << file << std::endl;
        if (hdr)
            stbi_image_free(data_f);
        else
            stbi_image_free(data);
        return false;
    }

    glGenTextures(1, &renderer_id_);
    glBindTexture(GL_TEXTURE_CUBE_MAP, renderer_id_);
    GLenum format = channels == 4 ? GL_RGBA : (channels == 3 ? GL_RGB : GL_RED);
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
                     hdr ? GL_RGB16F : format, face_size, face_size, 0,
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
    }

    if (hdr)
        stbi_image_free(data_f);
    else
        stbi_image_free(data);

    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
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
