
#ifndef TNT_FILAMENT_BACKEND_CALLBACKHANDLER_H
#define TNT_FILAMENT_BACKEND_CALLBACKHANDLER_H

namespace filament::backend {

class CallbackHandler {
public:
    using Callback = void(*)(void* user);

    virtual void post(void* user, Callback callback) = 0;

protected:
    virtual ~CallbackHandler() = default;
};

} // namespace filament::backend

#endif // TNT_FILAMENT_BACKEND_CALLBACKHANDLER_H
