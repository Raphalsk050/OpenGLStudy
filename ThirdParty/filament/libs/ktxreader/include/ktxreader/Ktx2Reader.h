
#ifndef KTXREADER_KTX2READER_H
#define KTXREADER_KTX2READER_H

#include <cstdint>
#include <cstddef>

#include <filament/Texture.h>

#include "third_party/filament/libs/utils/include/utils/FixedCapacityVector.h"

namespace filament {
    class Engine;
}

namespace basist {
    class ktx2_transcoder;
}

namespace ktxreader {

class Ktx2Reader {
    public:
        using Engine = filament::Engine;
        using Texture = filament::Texture;
        enum class TransferFunction { LINEAR, sRGB };

        enum class Result {
            SUCCESS,
            COMPRESSED_TRANSCODE_FAILURE,
            UNCOMPRESSED_TRANSCODE_FAILURE,
            FORMAT_UNSUPPORTED,
            FORMAT_ALREADY_REQUESTED,
        };

        Ktx2Reader(Engine& engine, bool quiet = false);
        ~Ktx2Reader();

        Result requestFormat(Texture::InternalFormat format) noexcept;

        void unrequestFormat(Texture::InternalFormat format) noexcept;

        Texture* load(const void* data, size_t size, TransferFunction transfer);

        class Async {
        public:
            Texture* getTexture() const noexcept;

            Result doTranscoding();

            void uploadImages();

        protected:
            Async() noexcept = default;
            virtual ~Async();

        public:
            Async(Async const&) = delete;
            Async(Async&&) = delete;
            Async& operator=(Async const&) = delete;
            Async& operator=(Async&&) = delete;

            friend class Ktx2Reader;
        };

        Async* asyncCreate(const void* data, size_t size, TransferFunction transfer);

        void asyncDestroy(Async** async);

    private:
        Ktx2Reader(const Ktx2Reader&) = delete;
        Ktx2Reader& operator=(const Ktx2Reader&) = delete;
        Ktx2Reader(Ktx2Reader&& that) noexcept = delete;
        Ktx2Reader& operator=(Ktx2Reader&& that) noexcept = delete;

        Texture* createTexture(basist::ktx2_transcoder* transcoder, const void* data,
                size_t size, TransferFunction transfer);

        Engine& mEngine;
        basist::ktx2_transcoder* const mTranscoder;
        utils::FixedCapacityVector<Texture::InternalFormat> mRequestedFormats;
        bool mQuiet;
};

} // namespace ktxreader

#endif
