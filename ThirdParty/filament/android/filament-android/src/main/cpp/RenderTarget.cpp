
#include <jni.h>

#include <functional>
#include <stdlib.h>
#include <string.h>

#include <filament/RenderTarget.h>

using namespace filament;
using namespace backend;

extern "C" JNIEXPORT jlong JNICALL
Java_com_google_android_filament_RenderTarget_nCreateBuilder(JNIEnv *env, jclass type) {
    return (jlong) new RenderTarget::Builder();
}

extern "C" JNIEXPORT void JNICALL
Java_com_google_android_filament_RenderTarget_nDestroyBuilder(JNIEnv *env, jclass type,
        jlong nativeBuilder) {
    RenderTarget::Builder* builder = (RenderTarget::Builder*) nativeBuilder;
    delete builder;
}

extern "C" JNIEXPORT void JNICALL
Java_com_google_android_filament_RenderTarget_nBuilderTexture(JNIEnv *env, jclass type,
        jlong nativeBuilder, jint attachment, jlong nativeTexture) {
    RenderTarget::Builder* builder = (RenderTarget::Builder*) nativeBuilder;
    Texture* texture = (Texture*) nativeTexture;
    builder->texture(RenderTarget::AttachmentPoint(attachment), texture);
}

extern "C" JNIEXPORT void JNICALL
Java_com_google_android_filament_RenderTarget_nBuilderMipLevel(JNIEnv *env, jclass type,
        jlong nativeBuilder, jint attachment, jint level) {
    RenderTarget::Builder* builder = (RenderTarget::Builder*) nativeBuilder;
    builder->mipLevel(RenderTarget::AttachmentPoint(attachment), level);
}

extern "C" JNIEXPORT void JNICALL
Java_com_google_android_filament_RenderTarget_nBuilderFace(JNIEnv *env, jclass type,
        jlong nativeBuilder, jint attachment, jint face) {
    RenderTarget::Builder* builder = (RenderTarget::Builder*) nativeBuilder;
    RenderTarget::CubemapFace cubeface = (RenderTarget::CubemapFace) face;
    builder->face(RenderTarget::AttachmentPoint(attachment), cubeface);
}

extern "C" JNIEXPORT void JNICALL
Java_com_google_android_filament_RenderTarget_nBuilderLayer(JNIEnv *env, jclass type,
        jlong nativeBuilder, jint attachment, jint layer) {
    RenderTarget::Builder* builder = (RenderTarget::Builder*) nativeBuilder;
    builder->layer(RenderTarget::AttachmentPoint(attachment), layer);
}

extern "C" JNIEXPORT jlong JNICALL
Java_com_google_android_filament_RenderTarget_nBuilderBuild(JNIEnv *env, jclass type,
        jlong nativeBuilder, jlong nativeEngine) {
    RenderTarget::Builder* builder = (RenderTarget::Builder*) nativeBuilder;
    Engine *engine = (Engine *) nativeEngine;
    return (jlong) builder->build(*engine);
}

extern "C" JNIEXPORT jint JNICALL
Java_com_google_android_filament_RenderTarget_nGetMipLevel(JNIEnv *env, jclass type,
        jlong nativeTarget, jint attachment) {
    RenderTarget* target = (RenderTarget*) nativeTarget;
    return (jint) target->getMipLevel(RenderTarget::AttachmentPoint(attachment));
}

extern "C" JNIEXPORT jint JNICALL
Java_com_google_android_filament_RenderTarget_nGetFace(JNIEnv *env, jclass type,
        long nativeTarget, int attachment) {
    RenderTarget* target = (RenderTarget*) nativeTarget;
    return (jint) target->getFace(RenderTarget::AttachmentPoint(attachment));
}

extern "C" JNIEXPORT jint JNICALL
Java_com_google_android_filament_RenderTarget_nGetLayer(JNIEnv *env, jclass type,
        long nativeTarget, int attachment) {
    RenderTarget* target = (RenderTarget*) nativeTarget;
    return (jint) target->getLayer(RenderTarget::AttachmentPoint(attachment));
}
