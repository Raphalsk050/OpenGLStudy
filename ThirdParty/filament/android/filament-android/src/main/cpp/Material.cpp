
#include <jni.h>

#include <filament/Material.h>

#include "common/NioUtils.h"
#include "common/CallbackUtils.h"

using namespace filament;

extern "C" JNIEXPORT jlong JNICALL
Java_com_google_android_filament_Material_nBuilderBuild(JNIEnv *env, jclass,
        jlong nativeEngine, jobject buffer_, jint size, jint shBandCount) {
    Engine* engine = (Engine*) nativeEngine;
    AutoBuffer buffer(env, buffer_, size);
    auto builder = Material::Builder();
    if (shBandCount) {
        builder.sphericalHarmonicsBandCount(shBandCount);
    }
    Material* material = builder
            .package(buffer.getData(), buffer.getSize())
            .build(*engine);

    return (jlong) material;
}

extern "C" JNIEXPORT jlong JNICALL
Java_com_google_android_filament_Material_nGetDefaultInstance(JNIEnv*, jclass,
        jlong nativeMaterial) {
    Material const* material = (Material const*) nativeMaterial;
    return (jlong) material->getDefaultInstance();
}

extern "C" JNIEXPORT jlong JNICALL
Java_com_google_android_filament_Material_nCreateInstance(JNIEnv*, jclass,
        jlong nativeMaterial) {
    Material* material = (Material*) nativeMaterial;
    return (jlong) material->createInstance();
}

extern "C" JNIEXPORT jlong JNICALL
Java_com_google_android_filament_Material_nCreateInstanceWithName(JNIEnv* env, jclass,
        jlong nativeMaterial, jstring name_) {
    Material* material = (Material*) nativeMaterial;
    const char *name = env->GetStringUTFChars(name_, 0);
    jlong instance = (jlong) material->createInstance(name);
    env->ReleaseStringUTFChars(name_, name);
    return instance;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_google_android_filament_Material_nGetName(JNIEnv* env, jclass, jlong nativeMaterial) {
    Material* material = (Material*) nativeMaterial;
    return env->NewStringUTF(material->getName());
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_google_android_filament_Material_nGetShading(JNIEnv*, jclass,
        jlong nativeMaterial) {
    Material* material = (Material*) nativeMaterial;
    return (jint) material->getShading();
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_google_android_filament_Material_nGetInterpolation(JNIEnv*, jclass,
        jlong nativeMaterial) {
    Material* material = (Material*) nativeMaterial;
    return (jint) material->getInterpolation();
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_google_android_filament_Material_nGetBlendingMode(JNIEnv*, jclass,
        jlong nativeMaterial) {
    Material* material = (Material*) nativeMaterial;
    return (jint) material->getBlendingMode();
}


extern "C"
JNIEXPORT jint JNICALL
Java_com_google_android_filament_Material_nGetRefractionMode(JNIEnv*, jclass,
        jlong nativeMaterial) {
    Material* material = (Material*) nativeMaterial;
    return (jint)material->getRefractionMode();
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_google_android_filament_Material_nGetRefractionType(JNIEnv*, jclass,
        jlong nativeMaterial) {
    Material* material = (Material*) nativeMaterial;
    return (jint) material->getRefractionType();
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_google_android_filament_Material_nGetReflectionMode(JNIEnv*, jclass,
        jlong nativeMaterial) {
    Material* material = (Material*) nativeMaterial;
    return (jint) material->getReflectionMode();
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_google_android_filament_Material_nGetFeatureLevel(JNIEnv*, jclass,
        jlong nativeMaterial) {
    Material* material = (Material*) nativeMaterial;
    return (jint) material->getFeatureLevel();
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_google_android_filament_Material_nGetVertexDomain(JNIEnv*, jclass,
        jlong nativeMaterial) {
    Material* material = (Material*) nativeMaterial;
    return (jint) material->getVertexDomain();
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_google_android_filament_Material_nGetCullingMode(JNIEnv*, jclass,
        jlong nativeMaterial) {
    Material* material = (Material*) nativeMaterial;
    return (jint) material->getCullingMode();
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_google_android_filament_Material_nIsColorWriteEnabled(JNIEnv*, jclass,
        jlong nativeMaterial) {
    Material* material = (Material*) nativeMaterial;
    return (jboolean) material->isColorWriteEnabled();
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_google_android_filament_Material_nIsDepthWriteEnabled(JNIEnv*, jclass,
        jlong nativeMaterial) {
    Material* material = (Material*) nativeMaterial;
    return (jboolean) material->isDepthWriteEnabled();
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_google_android_filament_Material_nIsDepthCullingEnabled(JNIEnv*, jclass,
        jlong nativeMaterial) {
    Material* material = (Material*) nativeMaterial;
    return (jboolean) material->isDepthCullingEnabled();
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_google_android_filament_Material_nIsDoubleSided(JNIEnv*, jclass,
        jlong nativeMaterial) {
    Material* material = (Material*) nativeMaterial;
    return (jboolean) material->isDoubleSided();
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_google_android_filament_Material_nIsAlphaToCoverageEnabled(JNIEnv*, jclass,
        jlong nativeMaterial) {
    Material* material = (Material*) nativeMaterial;
    return (jboolean) material->isAlphaToCoverageEnabled();
}

extern "C"
JNIEXPORT jfloat JNICALL
Java_com_google_android_filament_Material_nGetMaskThreshold(JNIEnv*, jclass,
        jlong nativeMaterial) {
    Material* material = (Material*) nativeMaterial;
    return material->getMaskThreshold();
}

extern "C"
JNIEXPORT jfloat JNICALL
Java_com_google_android_filament_Material_nGetSpecularAntiAliasingVariance(JNIEnv*, jclass,
        jlong nativeMaterial) {
    Material* material = (Material*) nativeMaterial;
    return material->getSpecularAntiAliasingVariance();
}

extern "C"
JNIEXPORT jfloat JNICALL
Java_com_google_android_filament_Material_nGetSpecularAntiAliasingThreshold(JNIEnv*, jclass,
        jlong nativeMaterial) {
    Material* material = (Material*) nativeMaterial;
    return material->getSpecularAntiAliasingThreshold();
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_google_android_filament_Material_nGetParameterCount(JNIEnv*, jclass,
        jlong nativeMaterial) {
    Material* material = (Material*) nativeMaterial;
    return (jint) material->getParameterCount();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_google_android_filament_Material_nGetParameters(JNIEnv* env, jclass,
        jlong nativeMaterial, jobject parameters, jint count) {
    Material* material = (Material*) nativeMaterial;

    Material::ParameterInfo* info = new Material::ParameterInfo[count];
    size_t received = material->getParameters(info, (size_t) count);
    assert(received == count);

    jclass parameterClass = env->FindClass("com/google/android/filament/Material$Parameter");
    parameterClass = (jclass) env->NewLocalRef(parameterClass);

    jmethodID parameterAdd = env->GetStaticMethodID(parameterClass, "add",
            "(Ljava/util/List;Ljava/lang/String;III)V");

    jfieldID parameterSamplerOffset = env->GetStaticFieldID(parameterClass,
            "SAMPLER_OFFSET", "I");

    jfieldID parameterSubpassOffset = env->GetStaticFieldID(parameterClass,
            "SUBPASS_OFFSET", "I");

    jint offset = env->GetStaticIntField(parameterClass, parameterSamplerOffset);
    jint subpassOffset = env->GetStaticIntField(parameterClass, parameterSubpassOffset);
    for (size_t i = 0; i < received; i++) {
        jint type;
        if (info[i].isSampler) {
            type = (jint) info[i].samplerType + offset;
        } else if (info[i].isSubpass) {
            type = subpassOffset;
        } else {
            type = (jint) info[i].type;
        }

        env->CallStaticVoidMethod(
                parameterClass, parameterAdd,
                parameters, env->NewStringUTF(info[i].name), type, (jint) info[i].precision,
                (jint) info[i].count);
    }

    env->DeleteLocalRef(parameterClass);

    delete[] info;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_google_android_filament_Material_nGetRequiredAttributes(JNIEnv*, jclass,
        jlong nativeMaterial) {
    Material* material = (Material*) nativeMaterial;
    return material->getRequiredAttributes().getValue();
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_google_android_filament_Material_nHasParameter(JNIEnv* env, jclass,
        jlong nativeMaterial, jstring name_) {
    Material* material = (Material*) nativeMaterial;
    const char* name = env->GetStringUTFChars(name_, 0);
    bool hasParameter = material->hasParameter(name);
    env->ReleaseStringUTFChars(name_, name);
    return (jboolean) hasParameter;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_google_android_filament_Material_nCompile(JNIEnv *env, jclass clazz,
        jlong nativeMaterial, jint priority, jint variants, jobject handler, jobject runnable) {
    Material* material = (Material*) nativeMaterial;
    JniCallback* jniCallback = JniCallback::make(env, handler, runnable);
    material->compile(
            (Material::CompilerPriorityQueue) priority,
            (UserVariantFilterBit) variants,
            jniCallback->getHandler(), [jniCallback](Material*){
                JniCallback::postToJavaAndDestroy(jniCallback);
            });
}
