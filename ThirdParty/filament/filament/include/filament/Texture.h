
//! \file

#ifndef TNT_FILAMENT_TEXTURE_H
#define TNT_FILAMENT_TEXTURE_H

#include <filament/FilamentAPI.h>

#include <backend/DriverEnums.h>
#include <backend/PixelBufferDescriptor.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include <utility>

#include <stddef.h>
#include <stdint.h>

namespace filament {

class FTexture;

class Engine;
class Stream;

class UTILS_PUBLIC Texture : public FilamentAPI {
    struct BuilderDetails;

public:
    static constexpr const size_t BASE_LEVEL = 0;

    //! Face offsets for all faces of a cubemap
    struct FaceOffsets;

    using PixelBufferDescriptor = backend::PixelBufferDescriptor;    //!< Geometry of a pixel buffer
    using Sampler = backend::SamplerType;                            //!< Type of sampler
    using InternalFormat = backend::TextureFormat;                   //!< Internal texel format
    using CubemapFace = backend::TextureCubemapFace;                 //!< Cube map faces
    using Format = backend::PixelDataFormat;                         //!< Pixel color format
    using Type = backend::PixelDataType;                             //!< Pixel data format
    using CompressedType = backend::CompressedPixelDataType;         //!< Compressed pixel data format
    using Usage = backend::TextureUsage;                             //!< Usage affects texel layout
    using Swizzle = backend::TextureSwizzle;                         //!< Texture swizzle

    static bool isProtectedTexturesSupported(Engine& engine) noexcept;

    struct PrefilterOptions {
        uint16_t sampleCount = 8;   //!< sample count used for filtering
        bool mirror = true;         //!< whether the environment must be mirrored
    private:
        UTILS_UNUSED uintptr_t reserved[3] = {};
    };


    //! Use Builder to construct a Texture object instance
    class Builder : public BuilderBase<BuilderDetails> {
        friend struct BuilderDetails;
    public:
        Builder() noexcept;
        Builder(Builder const& rhs) noexcept;
        Builder(Builder&& rhs) noexcept;
        ~Builder() noexcept;
        Builder& operator=(Builder const& rhs) noexcept;
        Builder& operator=(Builder&& rhs) noexcept;

        Builder& width(uint32_t width) noexcept;

        Builder& height(uint32_t height) noexcept;

        Builder& depth(uint32_t depth) noexcept;

        Builder& levels(uint8_t levels) noexcept;

        Builder& sampler(Sampler target) noexcept;

        Builder& format(InternalFormat format) noexcept;

        Builder& usage(Usage usage) noexcept;

        Builder& swizzle(Swizzle r, Swizzle g, Swizzle b, Swizzle a) noexcept;

        Texture* UTILS_NONNULL build(Engine& engine);

        Builder& import(intptr_t id) noexcept;

    private:
        friend class FTexture;
    };

    size_t getWidth(size_t level = BASE_LEVEL) const noexcept;

    size_t getHeight(size_t level = BASE_LEVEL) const noexcept;

    size_t getDepth(size_t level = BASE_LEVEL) const noexcept;

    size_t getLevels() const noexcept;

    Sampler getTarget() const noexcept;

    InternalFormat getFormat() const noexcept;

    void setImage(Engine& engine, size_t level,
            uint32_t xoffset, uint32_t yoffset, uint32_t zoffset,
            uint32_t width, uint32_t height, uint32_t depth,
            PixelBufferDescriptor&& buffer) const;

    inline void setImage(Engine& engine, size_t level, PixelBufferDescriptor&& buffer) const {
        setImage(engine, level, 0, 0, 0,
            uint32_t(getWidth(level)), uint32_t(getHeight(level)), 1, std::move(buffer));
    }

    inline void setImage(Engine& engine, size_t level,
            uint32_t xoffset, uint32_t yoffset, uint32_t width, uint32_t height,
            PixelBufferDescriptor&& buffer) const {
        setImage(engine, level, xoffset, yoffset, 0, width, height, 1, std::move(buffer));
    }

    UTILS_DEPRECATED
    void setImage(Engine& engine, size_t level,
            PixelBufferDescriptor&& buffer, const FaceOffsets& faceOffsets) const;


    void setExternalImage(Engine& engine, void* UTILS_NONNULL image) noexcept;

    void setExternalImage(Engine& engine, void* UTILS_NONNULL image, size_t plane) noexcept;

    void setExternalStream(Engine& engine, Stream* UTILS_NULLABLE stream) noexcept;

    void generateMipmaps(Engine& engine) const noexcept;

    void generatePrefilterMipmap(Engine& engine,
            PixelBufferDescriptor&& buffer, const FaceOffsets& faceOffsets,
            PrefilterOptions const* UTILS_NULLABLE options = nullptr);


