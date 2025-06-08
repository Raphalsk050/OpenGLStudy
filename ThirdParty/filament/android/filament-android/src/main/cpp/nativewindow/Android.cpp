
#include <jni.h>

#include <android/native_window_jni.h>

extern "C" {

void* getNativeWindow(JNIEnv* env, jclass, jobject surface) {
    return ANativeWindow_fromSurface(env, surface);
}

jlong createNativeSurface(jint width, jint height) {
    return 0;
}

void destroyNativeSurface(jlong surface) {
}

}
