
#include "DFG.h"

#include "details/Engine.h"
#include "details/Texture.h"

namespace filament {

const uint16_t DFG::DFG_LUT[] = {
#include "third_party/filament/filament/generated/data/dfg.inc"
};

void DFG::init(FEngine& engine) noexcept {
    constexpr size_t fp16Count = DFG_LUT_SIZE * DFG_LUT_SIZE * 3;
    constexpr size_t byteCount = fp16Count * sizeof(uint16_t);

    static_assert(sizeof(DFG_LUT) == byteCount, "DFG_LUT_SIZE doesn't match size of the DFG LUT");

    Texture* lut = Texture::Builder()
            .width(DFG_LUT_SIZE)
            .height(DFG_LUT_SIZE)
            .format(backend::TextureFormat::RGB16F)
            .build(engine);

    Texture::PixelBufferDescriptor buffer(DFG_LUT, byteCount,
            Texture::Format::RGB, Texture::Type::HALF);

    lut->setImage(engine, 0, std::move(buffer));

    mLUT = downcast(lut);
}

void DFG::terminate(FEngine& engine) noexcept {
    if (mLUT) {
        engine.destroy(mLUT);
    }
}

} // namespace filament
