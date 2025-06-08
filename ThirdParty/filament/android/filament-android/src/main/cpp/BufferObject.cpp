
#include <jni.h>

#include <functional>
#include <stdlib.h>
#include <string.h>

#include <filament/BufferObject.h>

#include <backend/BufferDescriptor.h>

#include "common/CallbackUtils.h"
#include "common/NioUtils.h"

using namespace filament;
using namespace backend;

extern "C" JNIEXPORT jlong JNICALL
Java_com_google_android_filament_BufferObject_nCreateBuilder(JNIEnv *env, jclass type) {
    return (jlong) new BufferObject::Builder();
}

extern "C" JNIEXPORT void JNICALL
Java_com_google_android_filament_BufferObject_nDestroyBuilder(JNIEnv *env, jclass type,
        jlong nativeBuilder) {
    BufferObject::Builder* builder = (BufferObject::Builder *) nativeBuilder;
    delete builder;
}

extern "C" JNIEXPORT void JNICALL
Java_com_google_android_filament_BufferObject_nBuilderSize(JNIEnv *env, jclass type,
        jlong nativeBuilder, jint byteCount) {
    BufferObject::Builder* builder = (BufferObject::Builder *) nativeBuilder;
    builder->size((uint32_t) byteCount);
}

extern "C" JNIEXPORT void JNICALL
Java_com_google_android_filament_BufferObject_nBuilderBindingType(JNIEnv *env, jclass type,
        jlong nativeBuilder, jint bindingType) {
    using BindingType = BufferObject::BindingType;
    BufferObject::Builder* builder = (BufferObject::Builder *) nativeBuilder;
    BindingType types[] = {BindingType::VERTEX};
    builder->bindingType(types[bindingType]);
}

extern "C" JNIEXPORT jlong JNICALL
Java_com_google_android_filament_BufferObject_nBuilderBuild(JNIEnv *env, jclass type,
        jlong nativeBuilder, jlong nativeEngine) {
    BufferObject::Builder* builder = (BufferObject::Builder *) nativeBuilder;
    Engine *engine = (Engine *) nativeEngine;
    return (jlong) builder->build(*engine);
}

extern "C" JNIEXPORT jint JNICALL
Java_com_google_android_filament_BufferObject_nGetByteCount(JNIEnv *env, jclass type,
        jlong nativeBufferObject) {
    BufferObject *bufferObject = (BufferObject *) nativeBufferObject;
    return (jint) bufferObject->getByteCount();
}

extern "C" JNIEXPORT int JNICALL
Java_com_google_android_filament_BufferObject_nSetBuffer(JNIEnv *env, jclass type,
        jlong nativeBufferObject, jlong nativeEngine, jobject buffer, int remaining,
        jint destOffsetInBytes, jint count,
        jobject handler, jobject runnable) {
    BufferObject *bufferObject = (BufferObject *) nativeBufferObject;
    Engine *engine = (Engine *) nativeEngine;

    AutoBuffer nioBuffer(env, buffer, count);
    void* data = nioBuffer.getData();
    size_t sizeInBytes = nioBuffer.getSize();
    if (sizeInBytes > (remaining << nioBuffer.getShift())) {
        // BufferOverflowException
        return -1;
    }

    auto* callback = JniBufferCallback::make(engine, env, handler, runnable, std::move(nioBuffer));

    BufferDescriptor desc(data, sizeInBytes,
            callback->getHandler(), &JniBufferCallback::postToJavaAndDestroy, callback);

    bufferObject->setBuffer(*engine, std::move(desc), (uint32_t) destOffsetInBytes);

    return 0;
}
