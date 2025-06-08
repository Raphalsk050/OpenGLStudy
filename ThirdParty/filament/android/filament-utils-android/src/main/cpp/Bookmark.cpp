
#include <jni.h>

#include <camutils/Bookmark.h>

using namespace filament::camutils;
using namespace filament::math;

extern "C" JNIEXPORT void Java_com_google_android_filament_utils_Bookmark_nDestroyBookmark(JNIEnv*, jclass, jlong nativeBookmark) {
    Bookmark<float>* bookmark = (Bookmark<float>*) nativeBookmark;
    delete bookmark;
}
