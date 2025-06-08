
#include <jni.h>

#include <filament-iblprefilter/IBLPrefilterContext.h>

#include <filament/Engine.h>
#include <filament/Texture.h>

using namespace filament;

extern "C" JNIEXPORT jlong JNICALL
Java_com_google_android_filament_utils_IBLPrefilterContext_nCreate(JNIEnv* env, jclass,
        jlong nativeEngine) {
    Engine* engine = (Engine*) nativeEngine;
    return (jlong) new IBLPrefilterContext(*engine);
}

extern "C" JNIEXPORT void JNICALL
Java_com_google_android_filament_utils_IBLPrefilterContext_nDestroy(JNIEnv*, jclass, jlong native) {
    IBLPrefilterContext* context = (IBLPrefilterContext*) native;
    delete context;
}

extern "C" JNIEXPORT long JNICALL
Java_com_google_android_filament_utils_IBLPrefilterContext_nCreateEquirectHelper(JNIEnv* env, jclass, jlong nativeContext) {
    IBLPrefilterContext* context = (IBLPrefilterContext*) nativeContext;
    return (long) new IBLPrefilterContext::EquirectangularToCubemap(*context);
}

extern "C" JNIEXPORT long JNICALL
Java_com_google_android_filament_utils_IBLPrefilterContext_nEquirectHelperRun(JNIEnv* env, jclass, jlong nativeHelper, long nativeEquirect) {
    auto helper = (IBLPrefilterContext::EquirectangularToCubemap*) nativeHelper;
    auto texture = (filament::Texture*) nativeEquirect;
    auto result = (*helper)(texture);
    return (long) result;
}

extern "C" JNIEXPORT void JNICALL
Java_com_google_android_filament_utils_IBLPrefilterContext_nDestroyEquirectHelper(JNIEnv* env, jclass, jlong nativeObject) {
    delete (IBLPrefilterContext::EquirectangularToCubemap*) nativeObject;
}

extern "C" JNIEXPORT long JNICALL
Java_com_google_android_filament_utils_IBLPrefilterContext_nCreateSpecularFilter(JNIEnv* env, jclass, jlong nativeContext) {
    IBLPrefilterContext* context = (IBLPrefilterContext*) nativeContext;
    return (long) new IBLPrefilterContext::SpecularFilter(*context);
}

extern "C" JNIEXPORT long JNICALL
Java_com_google_android_filament_utils_IBLPrefilterContext_nSpecularFilterRun(JNIEnv* env, jclass, jlong nativeHelper, long nativeSkybox) {
    auto helper = (IBLPrefilterContext::SpecularFilter*) nativeHelper;
    auto texture = (filament::Texture*) nativeSkybox;
    auto result = (*helper)(texture);
    return (long) result;
}

extern "C" JNIEXPORT void JNICALL
Java_com_google_android_filament_utils_IBLPrefilterContext_nDestroySpecularFilter(JNIEnv* env, jclass, jlong nativeObject) {
    delete (IBLPrefilterContext::SpecularFilter*) nativeObject;
}
