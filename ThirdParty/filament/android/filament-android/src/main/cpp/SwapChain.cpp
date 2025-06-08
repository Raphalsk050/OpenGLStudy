
#include <jni.h>

#include <filament/Engine.h>
#include <filament/SwapChain.h>

#include "common/CallbackUtils.h"

using namespace filament;

extern "C" JNIEXPORT void JNICALL
Java_com_google_android_filament_SwapChain_nSetFrameCompletedCallback(JNIEnv* env, jclass,
        jlong nativeSwapChain, jobject handler, jobject runnable) {
    SwapChain* swapChain = (SwapChain*) nativeSwapChain;
    auto* callback = JniCallback::make(env, handler, runnable);
    swapChain->setFrameCompletedCallback(nullptr, [callback](SwapChain* swapChain) {
        JniCallback::postToJavaAndDestroy(callback);
    });
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_google_android_filament_SwapChain_nIsSRGBSwapChainSupported(
        JNIEnv *, jclass, jlong nativeEngine) {
    Engine* engine = (Engine*) nativeEngine;
    return (jboolean)SwapChain::isSRGBSwapChainSupported(*engine);
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_google_android_filament_SwapChain_nIsProtectedContentSupported(
        JNIEnv *, jclass, jlong nativeEngine) {
    Engine* engine = (Engine*) nativeEngine;
    return (jboolean)SwapChain::isProtectedContentSupported(*engine);
}
