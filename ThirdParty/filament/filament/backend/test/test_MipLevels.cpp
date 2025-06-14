
#include "BackendTest.h"

#include "ShaderGenerator.h"
#include "TrianglePrimitive.h"
#include "BackendTestUtils.h"

#include "private/backend/SamplerGroup.h"

namespace {

////////////////////////////////////////////////////////////////////////////////////////////////////
// Shaders
////////////////////////////////////////////////////////////////////////////////////////////////////

std::string vertex (R"(#version 450 core

layout(location = 0) in vec4 mesh_position;
layout(location = 0) out vec2 uv;

void main() {
    gl_Position = vec4(mesh_position.xy, 0.0, 1.0);
    uv = (mesh_position.xy * 0.5 + 0.5);
}
)");

std::string fragment (R"(#version 450 core

layout(location = 0) out vec4 fragColor;
layout(location = 0) in vec2 uv;

layout(location = 0, set = 1) uniform sampler2D backend_test_sib_tex;

void main() {
    fragColor = textureLod(backend_test_sib_tex, uv, 1);
}
)");

std::string whiteFragment (R"(#version 450 core

layout(location = 0) out vec4 fragColor;
layout(location = 0) in vec2 uv;

layout(location = 0, set = 1) uniform sampler2D backend_test_sib_tex;

void main() {
    fragColor = vec4(1.0);
}
)");

}

namespace test {

using namespace filament;
using namespace filament::backend;

TEST_F(BackendTest, SetMinMaxLevel) {
    auto& api = getDriverApi();
    api.startCapture(0);

    // The test is executed within this block scope to force destructors to run before
    // executeCommands().
    {
        // Create a SwapChain and make it current.
        auto swapChain = createSwapChain();
        api.makeCurrent(swapChain, swapChain);

        // Create a program that draws only white.
        Handle<HwProgram> whiteProgram;
        {
            ShaderGenerator shaderGen(vertex, whiteFragment, sBackend, sIsMobilePlatform);
            Program p = shaderGen.getProgram(api);
            Program::Sampler sampler{utils::CString("backend_test_sib_tex"), 0};
            p.setSamplerGroup(0, ShaderStageFlags::FRAGMENT, &sampler, 1);
            whiteProgram = api.createProgram(std::move(p));
        }

        // Create a program that samples a texture.
        Handle<HwProgram> textureProgram;
        {
            SamplerInterfaceBlock sib = filament::SamplerInterfaceBlock::Builder()
                    .name("backend_test_sib")
                    .stageFlags(backend::ShaderStageFlags::FRAGMENT)
                    .add( {{"tex", SamplerType::SAMPLER_2D, SamplerFormat::FLOAT, Precision::HIGH }} )
                    .build();
            ShaderGenerator shaderGen(vertex, fragment, sBackend, sIsMobilePlatform, &sib);
            Program p = shaderGen.getProgram(api);
            Program::Sampler sampler{utils::CString("backend_test_sib_tex"), 0};
            p.setSamplerGroup(0, ShaderStageFlags::FRAGMENT, &sampler, 1);
            textureProgram = api.createProgram(std::move(p));
        }

        // Create a texture that has 4 mip levels. Each level is a different color.
        // Level 0: 128x128 (red)
        // Level 1:   64x64 (green)
        // Level 2:   32x32 (blue)
        // Level 3:   16x16 (yellow)
        const size_t kTextureSize = 128;
        const size_t kMipLevels = 4;
        Handle<HwTexture> texture = api.createTexture(SamplerType::SAMPLER_2D, kMipLevels,
                TextureFormat::RGBA8, 1, kTextureSize, kTextureSize, 1,
                TextureUsage::SAMPLEABLE | TextureUsage::COLOR_ATTACHMENT | TextureUsage::UPLOADABLE);

        // Create image data.
        auto pixelFormat = PixelDataFormat::RGBA;
        auto pixelType = PixelDataType::UBYTE;
        size_t components; int bpp;
        getPixelInfo(pixelFormat, pixelType, components, bpp);
        uint32_t colors[] = {
        };
        for (int l = 0; l < kMipLevels; l++) {
            size_t mipSize = kTextureSize >> l;
            auto* buffer = (uint8_t*)calloc(1, mipSize * mipSize * bpp);
            fillCheckerboard<uint32_t>(buffer, mipSize, mipSize, 1, colors[l]);
            PixelBufferDescriptor descriptor(
                    buffer, mipSize * mipSize * bpp, pixelFormat, pixelType, 1, 0, 0,
                    mipSize, [](void* buffer, size_t size, void* user) { free(buffer); },
                    nullptr);
            api.update3DImage(
                    texture, l, 0, 0, 0, mipSize, mipSize, 1, std::move(descriptor));
        }

        TrianglePrimitive triangle(api);

        api.beginFrame(0, 0, 0);

        // We set the base mip to 1, and the max mip to 3
        // Level 0: 128x128 (red)
        // Level 1:   64x64 (green)             <-- base
        // Level 2:   32x32 (blue)              <--- white triangle rendered
        // Level 3:   16x16 (yellow)            <-- max
        api.setMinMaxLevels(texture, 1, 3);

        // Render a white triangle into level 2.
        // We specify mip level 2, because minMaxLevels has no effect when rendering into a texture.
        Handle<HwRenderTarget> renderTarget = api.createRenderTarget(
                TargetBufferFlags::COLOR, 32, 32, 1, 0,
