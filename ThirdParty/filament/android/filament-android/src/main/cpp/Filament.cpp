
#include <jni.h>

#include "private/backend/VirtualMachineEnv.h"

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    JNIEnv* env;
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return -1;
    }

    // This must be called when the library is loaded. We need this to get a reference to the
    // global VM
    ::filament::VirtualMachineEnv::JNI_OnLoad(vm);

    return JNI_VERSION_1_6;
}
