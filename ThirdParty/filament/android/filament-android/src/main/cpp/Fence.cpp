
#include <jni.h>

#include <filament/Fence.h>

using namespace filament;

extern "C" JNIEXPORT jint JNICALL
Java_com_google_android_filament_Fence_nWait(JNIEnv *env, jclass type, jlong nativeFence, jint mode,
        jlong timeoutNanoSeconds) {
    Fence *fence = (Fence *) nativeFence;
    return (jint) fence->wait((Fence::Mode) mode, (uint64_t) timeoutNanoSeconds);
}

extern "C" JNIEXPORT jint JNICALL
Java_com_google_android_filament_Fence_nWaitAndDestroy(JNIEnv *env, jclass type, jlong nativeFence,
        jint mode) {
    Fence *fence = (Fence *) nativeFence;
    return (jint) Fence::waitAndDestroy(fence, (Fence::Mode) mode);
}

