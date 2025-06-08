
#include <jni.h>

extern "C" {
jlong createNativeSurface(jint width, jint height);
void destroyNativeSurface(jlong surface);
};

extern "C" JNIEXPORT jlong JNICALL
Java_com_google_android_filament_NativeSurface_nCreateSurface(JNIEnv*, jclass,
        jint width, jint height) {
    return createNativeSurface(width, height);
}


extern "C" JNIEXPORT void JNICALL
Java_com_google_android_filament_NativeSurface_nDestroySurface(JNIEnv*, jclass, jlong surface){
    destroyNativeSurface(surface);
}