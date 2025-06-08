
#ifndef TNT_FILAMENT_BACKEND_PRIVATE_DRIVER_H
#define TNT_FILAMENT_BACKEND_PRIVATE_DRIVER_H

#include <backend/CallbackHandler.h>
#include <backend/DriverApiForward.h>
#include <backend/DriverEnums.h>
#include <backend/Handle.h>
#include <backend/PipelineState.h>
#include <backend/TargetBufferInfo.h>

#include "third_party/filament/libs/utils/include/utils/CString.h"
#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include <functional>

#include <stddef.h>
#include <stdint.h>

// Command debugging off. debugging virtuals are not called.
// This is automatically enabled in DEBUG builds.
#define FILAMENT_DEBUG_COMMANDS_NONE         0x0
// Command debugging enabled. No logging by default.
#define FILAMENT_DEBUG_COMMANDS_ENABLE       0x1
// Command debugging enabled. Every command logged to slog.d
#define FILAMENT_DEBUG_COMMANDS_LOG          0x2
// Command debugging enabled. Every command logged to systrace
#define FILAMENT_DEBUG_COMMANDS_SYSTRACE     0x4

#define FILAMENT_DEBUG_COMMANDS              FILAMENT_DEBUG_COMMANDS_NONE

namespace filament::backend {

class BufferDescriptor;
class CallbackHandler;
class PixelBufferDescriptor;
class Program;

template<typename T>
class ConcreteDispatcher;
class Dispatcher;
class CommandStream;

class Driver {
public:
    virtual ~Driver() noexcept;

    static size_t getElementTypeSize(ElementType type) noexcept;

    // called from the main thread (NOT the render-thread) at various intervals, this
    // is where the driver can execute user callbacks.
    virtual void purge() noexcept = 0;

    virtual ShaderModel getShaderModel() const noexcept = 0;

    // Returns the dispatcher. This is only called once during initialization of the CommandStream,
    // so it doesn't matter that it's virtual.
    virtual Dispatcher getDispatcher() const noexcept = 0;

    // called from CommandStream::execute on the render-thread
    // the fn function will execute a batch of driver commands
    // this gives the driver a chance to wrap their execution in a meaningful manner
    // the default implementation simply calls fn
    virtual void execute(std::function<void(void)> const& fn);

    // This is called on debug build, or when enabled manually on the backend thread side.
    virtual void debugCommandBegin(CommandStream* cmds,
            bool synchronous, const char* methodName) noexcept = 0;

    virtual void debugCommandEnd(CommandStream* cmds,
            bool synchronous, const char* methodName) noexcept = 0;


#define DECL_DRIVER_API(methodName, paramsDecl, params) \
    void methodName(paramsDecl) {}

#define DECL_DRIVER_API_SYNCHRONOUS(RetType, methodName, paramsDecl, params) \
    virtual RetType methodName(paramsDecl) = 0;

#define DECL_DRIVER_API_RETURN(RetType, methodName, paramsDecl, params) \
    virtual RetType methodName##S() noexcept = 0; \
    void methodName##R(RetType, paramsDecl) {}

#include "private/backend/DriverAPI.inc"
};

} // namespace filament::backend

#endif // TNT_FILAMENT_BACKEND_PRIVATE_DRIVER_H
