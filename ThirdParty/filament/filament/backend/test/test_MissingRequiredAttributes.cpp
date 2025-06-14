
#include "BackendTest.h"

#include "ShaderGenerator.h"
#include "TrianglePrimitive.h"

namespace {

////////////////////////////////////////////////////////////////////////////////////////////////////
// Shaders
////////////////////////////////////////////////////////////////////////////////////////////////////

std::string vertex (R"(#version 450 core

layout(location = 0) in vec4 mesh_position;

// these attributes won't be set in the renderable
layout(location = 5) in uvec4 mesh_bone_indices;
layout(location = 6) in vec4 mesh_bone_weights;

layout(location = 0) out uvec4 indices;
layout(location = 1) out vec4 weights;

void main() {
    gl_Position = vec4(mesh_position.xy, 0.0, 1.0);

    // for a valid test, we must read from the attributes, otherwise they're optimized away
    indices = mesh_bone_indices;
    weights = mesh_bone_weights;
}
)");

std::string fragment (R"(#version 450 core

layout(location = 0) out vec4 fragColor;

void main() {
    fragColor = vec4(1.0);
}

)");

}

namespace test {

using namespace filament;
using namespace filament::backend;

TEST_F(BackendTest, MissingRequiredAttributes) {
    // The test is executed within this block scope to force destructors to run before
    // executeCommands().
    {
        // Create a platform-specific SwapChain and make it current.
        auto swapChain = createSwapChain();
        getDriverApi().makeCurrent(swapChain, swapChain);

        // Create a program.
        ShaderGenerator shaderGen(vertex, fragment, sBackend, sIsMobilePlatform);
        Program p = shaderGen.getProgram(getDriverApi());
        auto program = getDriverApi().createProgram(std::move(p));

        auto defaultRenderTarget = getDriverApi().createDefaultRenderTarget(0);

        TrianglePrimitive triangle(getDriverApi());

        RenderPassParams params = {};
        fullViewport(params);
        params.flags.clear = TargetBufferFlags::COLOR;
        params.clearColor = {0.f, 1.f, 0.f, 1.f};
        params.flags.discardStart = TargetBufferFlags::ALL;
        params.flags.discardEnd = TargetBufferFlags::NONE;

        PipelineState state;
        state.program = program;
        state.rasterState.colorWrite = true;
        state.rasterState.depthWrite = false;
        state.rasterState.depthFunc = RasterState::DepthFunc::A;
        state.rasterState.culling = CullingMode::NONE;

        getDriverApi().startCapture(0);

        getDriverApi().makeCurrent(swapChain, swapChain);
        getDriverApi().beginFrame(0, 0, 0);

        // Render a triangle.
        getDriverApi().beginRenderPass(defaultRenderTarget, params);
        getDriverApi().draw(state, triangle.getRenderPrimitive(), 0, 3, 1);
        getDriverApi().endRenderPass();

        getDriverApi().flush();
        getDriverApi().commit(swapChain);
        getDriverApi().endFrame(0);

        getDriverApi().stopCapture(0);

        getDriverApi().destroyProgram(program);
        getDriverApi().destroySwapChain(swapChain);
        getDriverApi().destroyRenderTarget(defaultRenderTarget);
    }

    executeCommands();
}

} // namespace test
