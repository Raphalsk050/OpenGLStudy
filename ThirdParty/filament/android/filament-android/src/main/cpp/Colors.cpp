
#include <jni.h>

#include <filament/Color.h>

using namespace filament;

extern "C" JNIEXPORT void JNICALL
Java_com_google_android_filament_Colors_nCct(JNIEnv *env, jclass,
        jfloat temperature, jfloatArray color_) {
    const LinearColor cct = Color::cct(temperature);
    jfloat *color = env->GetFloatArrayElements(color_, NULL);
    color[0] = cct.r;
    color[1] = cct.g;
    color[2] = cct.b;
    env->ReleaseFloatArrayElements(color_, color, 0);
}

extern "C" JNIEXPORT void JNICALL
Java_com_google_android_filament_Colors_nIlluminantD(JNIEnv *env, jclass,
        jfloat temperature, jfloatArray color_) {
    const LinearColor illuminantD = Color::illuminantD(temperature);
    jfloat *color = env->GetFloatArrayElements(color_, NULL);
    color[0] = illuminantD.r;
    color[1] = illuminantD.g;
    color[2] = illuminantD.b;
    env->ReleaseFloatArrayElements(color_, color, 0);
}
