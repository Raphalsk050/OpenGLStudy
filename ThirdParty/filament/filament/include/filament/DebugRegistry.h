
//! \file

#ifndef TNT_FILAMENT_DEBUGREGISTRY_H
#define TNT_FILAMENT_DEBUGREGISTRY_H

#include <filament/FilamentAPI.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"

#include "third_party/filament/libs/math/include/math/mathfwd.h"

#include <stddef.h>

namespace filament {

class UTILS_PUBLIC DebugRegistry : public FilamentAPI {
public:

    bool hasProperty(const char* UTILS_NONNULL name) const noexcept;

    void* UTILS_NULLABLE getPropertyAddress(const char* UTILS_NONNULL name);

    void const* UTILS_NULLABLE getPropertyAddress(const char* UTILS_NONNULL name) const noexcept;

    template<typename T>
    inline T* UTILS_NULLABLE getPropertyAddress(const char* UTILS_NONNULL name) {
        return static_cast<T*>(getPropertyAddress(name));
    }

    template<typename T>
    inline T const* UTILS_NULLABLE getPropertyAddress(const char* UTILS_NONNULL name) const noexcept {
        return static_cast<T*>(getPropertyAddress(name));
    }

    template<typename T>
    inline bool getPropertyAddress(const char* UTILS_NONNULL name,
            T* UTILS_NULLABLE* UTILS_NONNULL p) {
        *p = getPropertyAddress<T>(name);
        return *p != nullptr;
    }

    template<typename T>
    inline bool getPropertyAddress(const char* UTILS_NONNULL name,
            T* const UTILS_NULLABLE* UTILS_NONNULL p) const noexcept {
        *p = getPropertyAddress<T>(name);
        return *p != nullptr;
    }
    bool setProperty(const char* UTILS_NONNULL name, bool v) noexcept;
    bool setProperty(const char* UTILS_NONNULL name, int v) noexcept;
    bool setProperty(const char* UTILS_NONNULL name, float v) noexcept;
    bool setProperty(const char* UTILS_NONNULL name, math::float2 v) noexcept;
    bool setProperty(const char* UTILS_NONNULL name, math::float3 v) noexcept;
    bool setProperty(const char* UTILS_NONNULL name, math::float4 v) noexcept;
    bool getProperty(const char* UTILS_NONNULL name, bool* UTILS_NONNULL v) const noexcept;
    bool getProperty(const char* UTILS_NONNULL name, int* UTILS_NONNULL v) const noexcept;
    bool getProperty(const char* UTILS_NONNULL name, float* UTILS_NONNULL v) const noexcept;
    bool getProperty(const char* UTILS_NONNULL name, math::float2* UTILS_NONNULL v) const noexcept;
    bool getProperty(const char* UTILS_NONNULL name, math::float3* UTILS_NONNULL v) const noexcept;
    bool getProperty(const char* UTILS_NONNULL name, math::float4* UTILS_NONNULL v) const noexcept;
