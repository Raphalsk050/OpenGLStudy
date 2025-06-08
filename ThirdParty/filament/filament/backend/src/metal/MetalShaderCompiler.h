
#ifndef TNT_FILAMENT_BACKEND_METAL_METALSHADERCOMPILER_H
#define TNT_FILAMENT_BACKEND_METAL_METALSHADERCOMPILER_H

#include "CompilerThreadPool.h"

#include "CallbackManager.h"

#include <backend/CallbackHandler.h>
#include <backend/Program.h>

#include "third_party/filament/libs/utils/include/utils/CString.h"

#include <Metal/Metal.h>

#include <array>
#include <memory>
#include <tuple>
#include <variant>

namespace filament::backend {

class MetalDriver;

class MetalShaderCompiler {
    struct MetalProgramToken;

public:
    enum class Mode {
        SYNCHRONOUS,    // synchronous shader compilation
        ASYNCHRONOUS    // asynchronous shader compilation
    };

    class MetalFunctionBundle {
    public:
        using Raster = std::tuple<id<MTLFunction>, id<MTLFunction>>;
        using Compute = id<MTLFunction>;
        using Error = std::tuple<NSString*, NSString*>; // error message, Program name
        struct None {};

        MetalFunctionBundle() : mPrograms{None{}} {}

        explicit operator bool() const { return isValid(); }

        bool isValid() const noexcept {
            return std::holds_alternative<Raster>(mPrograms) ||
                std::holds_alternative<Compute>(mPrograms);
        }

        void validate() const;

        Raster getRasterFunctions() const {
            assert_invariant(std::holds_alternative<Raster>(mPrograms));
            return std::get<Raster>(mPrograms);
        }

        Compute getComputeFunction() const {
            assert_invariant(std::holds_alternative<Compute>(mPrograms));
            return std::get<Compute>(mPrograms);
        }

        static MetalFunctionBundle none() {
            return MetalFunctionBundle(None{});
        }

        static MetalFunctionBundle raster(id<MTLFunction> fragment, id<MTLFunction> vertex) {
            assert_invariant(fragment && vertex);
            assert_invariant(fragment.functionType == MTLFunctionTypeFragment);
            assert_invariant(vertex.functionType == MTLFunctionTypeVertex);
            return MetalFunctionBundle(Raster{fragment, vertex});
        }

        static MetalFunctionBundle compute(id<MTLFunction> compute) {
            assert_invariant(compute);
            assert_invariant(compute.functionType == MTLFunctionTypeKernel);
            return MetalFunctionBundle(Compute{compute});
        }

        static MetalFunctionBundle error(NSString* errorMessage, NSString* programName) {
            return MetalFunctionBundle(Error{errorMessage, programName});
        }

    private:
        MetalFunctionBundle(None&& t) : mPrograms(std::move(t)) {}
        MetalFunctionBundle(Raster&& t) : mPrograms(std::move(t)) {}
        MetalFunctionBundle(Compute&& t) : mPrograms(std::move(t)) {}
        MetalFunctionBundle(Error&& t) : mPrograms(std::move(t)) {}

        std::variant<Raster, Compute, None, Error> mPrograms;
    };

    using program_token_t = std::shared_ptr<MetalProgramToken>;

    explicit MetalShaderCompiler(id<MTLDevice> device, MetalDriver& driver, Mode mode);

    MetalShaderCompiler(MetalShaderCompiler const& rhs) = delete;
    MetalShaderCompiler(MetalShaderCompiler&& rhs) = delete;
    MetalShaderCompiler& operator=(MetalShaderCompiler const& rhs) = delete;
    MetalShaderCompiler& operator=(MetalShaderCompiler&& rhs) = delete;

    void init() noexcept;
    void terminate() noexcept;

    bool isParallelShaderCompileSupported() const noexcept;

    // Creates a program, either synchronously or asynchronously, depending on the Mode
    // MetalShaderCompiler was constructed with.
    program_token_t createProgram(utils::CString const& name, Program&& program);

    // Returns the functions, blocking if necessary. The Token is destroyed and becomes invalid.
    MetalFunctionBundle getProgram(program_token_t& token);

    void notifyWhenAllProgramsAreReady(
            CallbackHandler* handler, CallbackHandler::Callback callback, void* user);

private:
    static MetalFunctionBundle compileProgram(const Program& program, id<MTLDevice> device);

    CompilerThreadPool mCompilerThreadPool;
    id<MTLDevice> mDevice;
    CallbackManager mCallbackManager;
    Mode mMode;
};

} // namespace filament::backend

#endif  // TNT_FILAMENT_BACKEND_METAL_METALSHADERCOMPILER_H
