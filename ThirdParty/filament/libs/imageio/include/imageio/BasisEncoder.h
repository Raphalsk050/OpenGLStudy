
#ifndef IMAGE_BASISENCODER_H_
#define IMAGE_BASISENCODER_H_

#include <stddef.h>
#include <stdint.h>
#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include <image/LinearImage.h>

namespace image {

struct BasisEncoderBuilderImpl;
struct BasisEncoderImpl;

class UTILS_PUBLIC BasisEncoder {
public:
    enum class IntermediateFormat {
        UASTC,
        ETC1S,
    };

    class Builder {
    public:
        Builder(size_t mipCount, size_t layerCount) noexcept;

        ~Builder() noexcept;
        Builder(Builder&& that) noexcept;
        Builder& operator=(Builder&& that) noexcept;

        Builder& linear(bool enabled) noexcept;

        Builder& cubemap(bool enabled) noexcept;

        Builder& intermediateFormat(IntermediateFormat format) noexcept;

        Builder& grayscale(bool enabled) noexcept;

        Builder& normals(bool enabled) noexcept;

        Builder& jobs(size_t count) noexcept;

        Builder& quiet(bool enabled) noexcept;

        Builder& miplevel(size_t mipIndex, size_t layerIndex, const LinearImage& image) noexcept;

        BasisEncoder* build();

    private:
        BasisEncoderBuilderImpl* mImpl;
        Builder(const Builder&) = delete;
        Builder& operator=(const Builder&) = delete;
    };

    ~BasisEncoder() noexcept;
    BasisEncoder(BasisEncoder&& that) noexcept;
    BasisEncoder& operator=(BasisEncoder&& that) noexcept;

    bool encode();

    size_t getKtx2ByteCount() const noexcept;

    uint8_t const* getKtx2Data() const noexcept;

private:
    BasisEncoder(BasisEncoderImpl*) noexcept;
    BasisEncoder(const BasisEncoder&) = delete;
    BasisEncoder& operator=(const BasisEncoder&) = delete;
    BasisEncoderImpl* mImpl;
    friend struct BasisEncoderBuilderImpl;
};

} // namespace image

#endif // IMAGE_BASISENCODER_H_
