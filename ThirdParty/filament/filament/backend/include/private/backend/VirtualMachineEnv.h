
#ifndef TNT_FILAMENT_DRIVER_ANDROID_VIRTUAL_MACHINE_ENV_H
#define TNT_FILAMENT_DRIVER_ANDROID_VIRTUAL_MACHINE_ENV_H

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/debug.h"

#include <jni.h>

namespace filament {

class VirtualMachineEnv {
public:
    static jint JNI_OnLoad(JavaVM* vm) noexcept;

    static VirtualMachineEnv& get() noexcept {
        // declaring this thread local, will ensure it's destroyed with the calling thread
        static thread_local VirtualMachineEnv instance;
        return instance;
    }

    static JNIEnv* getThreadEnvironment() noexcept {
        JNIEnv* env;
        assert_invariant(sVirtualMachine);
        if (sVirtualMachine->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
            return nullptr; // this should not happen
        }
        return env;
    }

    inline JNIEnv* getEnvironment() noexcept {
        assert_invariant(mVirtualMachine);
        JNIEnv* env = mJniEnv;
        if (UTILS_UNLIKELY(!env)) {
            return getEnvironmentSlow();
        }
        return env;
    }

    static void handleException(JNIEnv* env) noexcept;

private:
    VirtualMachineEnv() noexcept : mVirtualMachine(sVirtualMachine) {
        // We're not initializing the JVM here -- but we could -- because most of the time
        // we don't need the jvm. Instead we do the initialization on first use. This means we could get
        // a nasty slow down the very first time, but we'll live with it for now.
    }

    ~VirtualMachineEnv() {
        if (mVirtualMachine) {
            mVirtualMachine->DetachCurrentThread();
        }
    }

    JNIEnv* getEnvironmentSlow() noexcept;
    static JavaVM* sVirtualMachine;
    JNIEnv* mJniEnv = nullptr;
    JavaVM* mVirtualMachine = nullptr;
};

} // namespace filament

#endif // TNT_FILAMENT_DRIVER_ANDROID_VIRTUAL_MACHINE_ENV_H
