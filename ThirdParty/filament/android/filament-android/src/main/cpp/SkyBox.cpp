
#include <jni.h>

#include <filament/Skybox.h>

#include "third_party/filament/libs/math/include/math/vec4.h"

using namespace filament;

extern "C" JNIEXPORT jlong JNICALL
Java_com_google_android_filament_Skybox_nCreateBuilder(JNIEnv *env, jclass type) {
    return (jlong) new Skybox::Builder{};
}

extern "C" JNIEXPORT void JNICALL
Java_com_google_android_filament_Skybox_nDestroyBuilder(JNIEnv *env, jclass type,
        jlong nativeSkyBoxBuilder) {
    Skybox::Builder *builder = (Skybox::Builder *) nativeSkyBoxBuilder;
    delete builder;
}

extern "C" JNIEXPORT void JNICALL
Java_com_google_android_filament_Skybox_nBuilderEnvironment(JNIEnv *env, jclass type,
        jlong nativeSkyBoxBuilder, jlong nativeTexture) {
    Skybox::Builder *builder = (Skybox::Builder *) nativeSkyBoxBuilder;
    Texture *texture = (Texture *) nativeTexture;
    builder->environment(texture);
}

extern "C" JNIEXPORT void JNICALL
Java_com_google_android_filament_Skybox_nBuilderShowSun(JNIEnv *env, jclass type,
        jlong nativeSkyBoxBuilder, jboolean show) {
    Skybox::Builder *builder = (Skybox::Builder *) nativeSkyBoxBuilder;
    builder->showSun(show);
}

extern "C" JNIEXPORT void JNICALL
Java_com_google_android_filament_Skybox_nBuilderIntensity(JNIEnv *env, jclass clazz,
        jlong nativeSkyBoxBuilder, jfloat intensity) {
    Skybox::Builder *builder = (Skybox::Builder *) nativeSkyBoxBuilder;
    builder->intensity(intensity);
}

extern "C" JNIEXPORT void JNICALL
Java_com_google_android_filament_Skybox_nBuilderColor(JNIEnv *,  jclass,
        jlong nativeSkyBoxBuilder, jfloat r, jfloat g, jfloat b, jfloat a) {
    Skybox::Builder *builder = (Skybox::Builder *) nativeSkyBoxBuilder;
    builder->color({r, g, b, a});
}

extern "C" JNIEXPORT jlong JNICALL
Java_com_google_android_filament_Skybox_nBuilderBuild(JNIEnv *env, jclass type,
        jlong nativeSkyBoxBuilder, jlong nativeEngine) {
    Skybox::Builder *builder = (Skybox::Builder *) nativeSkyBoxBuilder;
    Engine *engine = (Engine *) nativeEngine;
    return (jlong) builder->build(*engine);
}

extern "C" JNIEXPORT void JNICALL
Java_com_google_android_filament_Skybox_nSetLayerMask(JNIEnv *env, jclass type, jlong nativeSkybox,
        jint select, jint value) {
    Skybox *skybox = (Skybox *) nativeSkybox;
    skybox->setLayerMask((uint8_t) select, (uint8_t) value);
}

extern "C" JNIEXPORT jint JNICALL
Java_com_google_android_filament_Skybox_nGetLayerMask(JNIEnv *env, jclass type,
        jlong nativeSkybox) {
    Skybox *skybox = (Skybox *) nativeSkybox;
    return static_cast<jint>(skybox->getLayerMask());
}

extern "C" JNIEXPORT jfloat JNICALL
Java_com_google_android_filament_Skybox_nGetIntensity(JNIEnv *env, jclass clazz,
        jlong nativeSkybox) {
    Skybox *skybox = (Skybox *) nativeSkybox;
    return static_cast<jint>(skybox->getIntensity());
}

extern "C" JNIEXPORT void JNICALL
Java_com_google_android_filament_Skybox_nSetColor(JNIEnv *, jclass,
        jlong nativeSkybox, jfloat r, jfloat g, jfloat b, jfloat a) {
    Skybox *skybox = (Skybox *) nativeSkybox;
    skybox->setColor({r, g, b, a});
}

extern "C" JNIEXPORT jlong JNICALL
Java_com_google_android_filament_Skybox_nGetTexture(JNIEnv* env, jclass,
        jlong nativeSkybox) {
    Skybox *skybox = (Skybox *) nativeSkybox;
    Texture const *tex = skybox->getTexture();
    return (jlong) tex;
}
