
#include <jni.h>

#include "third_party/filament/libs/math/include/math/mat3.h"
#include "third_party/filament/libs/math/include/math/quat.h"

using namespace filament::math;

extern "C" JNIEXPORT void JNICALL
Java_com_google_android_filament_MathUtils_nPackTangentFrame(JNIEnv *env, jclass,
        jfloat tangentX, jfloat tangentY, jfloat tangentZ,
        jfloat bitangentX, jfloat bitangentY, jfloat bitangentZ,
        jfloat normalX, jfloat normalY, jfloat normalZ,
        jfloatArray quaternion_, jint offset) {

    float3 tangent{tangentX, tangentY, tangentZ};
    float3 bitangent{bitangentX, bitangentY, bitangentZ};
    float3 normal{normalX, normalY, normalZ};
    quatf q = mat3f::packTangentFrame({tangent, bitangent, normal});

    env->SetFloatArrayRegion(quaternion_, offset, 4,
             reinterpret_cast<jfloat*>(&q));
}
