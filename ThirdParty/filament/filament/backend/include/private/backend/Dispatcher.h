
#ifndef TNT_FILAMENT_BACKEND_PRIVATE_DISPATCHER_H
#define TNT_FILAMENT_BACKEND_PRIVATE_DISPATCHER_H

#include <stdint.h>

namespace filament::backend {

class Driver;
class CommandBase;

class Dispatcher {
public:
    using Execute = void (*)(Driver& driver, CommandBase* self, intptr_t* next);
#define DECL_DRIVER_API_SYNCHRONOUS(RetType, methodName, paramsDecl, params)
#define DECL_DRIVER_API(methodName, paramsDecl, params)                     Execute methodName##_;
#define DECL_DRIVER_API_RETURN(RetType, methodName, paramsDecl, params)     Execute methodName##_;

#include "DriverAPI.inc"
};

} // namespace filament::backend

#endif //TNT_FILAMENT_BACKEND_PRIVATE_DISPATCHER_H
