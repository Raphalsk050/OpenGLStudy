
#ifndef TNT_SHADERGENERATOR_H
#define TNT_SHADERGENERATOR_H

#include "PlatformRunner.h"

#include "private/filament/SamplerInterfaceBlock.h"
#include "private/backend/DriverApi.h"
#include "backend/Program.h"

#include <string>

namespace test {

class ShaderGenerator {

public:

    static void init();
    static void shutdown();

    ShaderGenerator(std::string vertex, std::string fragment, Backend backend, bool isMobile,
            const filament::SamplerInterfaceBlock* sib = nullptr) noexcept;

    ShaderGenerator(const ShaderGenerator& rhs) = delete;
    ShaderGenerator& operator=(const ShaderGenerator& rhs) = delete;

    filament::backend::Program getProgram(filament::backend::DriverApi&) noexcept;

private:
    using ShaderStage = filament::backend::ShaderStage;

    using Blob = std::vector<char>;
    static Blob transpileShader(ShaderStage stage, std::string shader, Backend backend,
            bool isMobile, const filament::SamplerInterfaceBlock* sib = nullptr) noexcept;

    Backend mBackend;

    Blob mVertexBlob;
    Blob mFragmentBlob;
    std::string mCompiledVertexShader;
    std::string mCompiledFragmentShader;
    filament::backend::ShaderLanguage mShaderLanguage;

};

} // namespace test

#endif
