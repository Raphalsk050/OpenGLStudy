load("@build_bazel_rules_android//android:rules.bzl", "android_library")
load(
    "//third_party/filament:filament.bzl",
    "filament_linkopts",
)

package(
    default_applicable_licenses = ["//third_party/filament:license"],
    default_visibility = ["//third_party/arcore/java/com/google/ar/sceneform:sceneform_dependees"],
    features = [
        "-use_header_modules",  # Incompatible with -std=c++14.
    ],
)

licenses(["unencumbered"])

android_library(
    name = "filament_android",
    srcs = [],
    exports = [
        ":filament-android-jni",
        "//third_party/filament/android:filament_android_no_jni",
    ],
)
