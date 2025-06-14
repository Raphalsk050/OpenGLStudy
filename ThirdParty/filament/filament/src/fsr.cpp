
#include "fsr.h"

#include "third_party/filament/libs/math/include/math/vec4.h"

#include <math.h>
#include <stdint.h>
#include <stdlib.h>

namespace filament {

using namespace math;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-function"
#pragma clang diagnostic ignored "-Wignored-qualifiers"

#define A_CPU  1
#include "materials/fsr/ffx_a.h"
#define FSR_EASU_F 1
#define FSR_RCAS_F 1
#include "materials/fsr/ffx_fsr1.h"

#pragma clang diagnostic pop

void FSR_ScalingSetup(FSRUniforms* outUniforms, FSRScalingConfig config) noexcept {
    // FsrEasu API claims it needs the left-top offset, however that's not true with OpenGL,
    // in which case it uses the left-bottom offset.

    auto yoffset = config.input.bottom;
    if (config.backend == backend::Backend::METAL ||
        config.backend == backend::Backend::VULKAN) {
        yoffset = config.inputHeight - (config.input.bottom + config.input.height);
    }

    FsrEasuConOffset( outUniforms->EasuCon0.v, outUniforms->EasuCon1.v,
                outUniforms->EasuCon2.v, outUniforms->EasuCon3.v,
            // Viewport size (top left aligned) in the input image which is to be scaled.
            config.input.width, config.input.height,
            // The size of the input image.
            config.inputWidth, config.inputHeight,
            // The output resolution.
            config.outputWidth, config.outputHeight,
            // Input image offset
            config.input.left, yoffset);
}

void FSR_SharpeningSetup(FSRUniforms* outUniforms, FSRSharpeningConfig config) noexcept {
    FsrRcasCon(outUniforms->RcasCon.v, config.sharpness);
}

} // namespace filament


