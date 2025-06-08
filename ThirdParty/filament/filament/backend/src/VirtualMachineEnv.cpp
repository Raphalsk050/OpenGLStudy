
#include "private/backend/VirtualMachineEnv.h"

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/debug.h"

#include <jni.h>

namespace filament {

JavaVM* VirtualMachineEnv::sVirtualMachine = nullptr;

UTILS_PUBLIC
UTILS_NOINLINE
UTILS_PUBLIC
jint VirtualMachineEnv::JNI_OnLoad(JavaVM* vm) noexcept {
    JNIEnv* env = nullptr;
    if (UTILS_UNLIKELY(vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK)) {
        // this should not happen
        return -1;
    }
    sVirtualMachine = vm;
    return JNI_VERSION_1_6;
}

UTILS_NOINLINE
void VirtualMachineEnv::handleException(JNIEnv* const env) noexcept {
    if (UTILS_UNLIKELY(env->ExceptionCheck())) {
        env->ExceptionDescribe();
        env->ExceptionClear();
    }
}

UTILS_NOINLINE
JNIEnv* VirtualMachineEnv::getEnvironmentSlow() noexcept {
#if defined(__ANDROID__)
    mVirtualMachine->AttachCurrentThread(&mJniEnv, nullptr);
#else
    mVirtualMachine->AttachCurrentThread(reinterpret_cast<void**>(&mJniEnv), nullptr);
#endif
    assert_invariant(mJniEnv);
    return mJniEnv;
}

} // namespace filament

