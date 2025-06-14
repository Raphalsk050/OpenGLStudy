
#include "details/DebugRegistry.h"

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/Invocable.h"
#include "third_party/filament/libs/utils/include/utils/Panic.h"

#include "third_party/filament/libs/math/include/math/vec2.h"
#include "third_party/filament/libs/math/include/math/vec3.h"
#include "third_party/filament/libs/math/include/math/vec4.h"

#include <functional>
#include <string_view>
#include <utility>

#ifndef NDEBUG
#   define DEBUG_PROPERTIES_WRITABLE true
#else
#   define DEBUG_PROPERTIES_WRITABLE false
#endif

using namespace filament::math;
using namespace utils;

namespace filament {

FDebugRegistry::FDebugRegistry() noexcept = default;

auto FDebugRegistry::getPropertyInfo(const char* name) noexcept -> PropertyInfo {
    std::string_view const key{ name };
    auto& propertyMap = mPropertyMap;
    if (propertyMap.find(key) == propertyMap.end()) {
        return { nullptr, {} };
    }
    return propertyMap[key];
}

UTILS_NOINLINE
void* FDebugRegistry::getPropertyAddress(const char* name) {
    auto info = getPropertyInfo(name);
    ASSERT_PRECONDITION_NON_FATAL(!info.second,
            "don't use DebugRegistry::getPropertyAddress() when a callback is set. "
            "Use setProperty() instead.");
    return info.first;
}

UTILS_NOINLINE
void const* FDebugRegistry::getPropertyAddress(const char* name) const noexcept {
    auto info = const_cast<FDebugRegistry*>(this)->getPropertyInfo(name);
    return info.first;
}

void FDebugRegistry::registerProperty(std::string_view name, void* p, Type,
        std::function<void()> fn) noexcept {
    auto& propertyMap = mPropertyMap;
    if (propertyMap.find(name) == propertyMap.end()) {
        propertyMap[name] = { p, std::move(fn) };
    }
}

bool FDebugRegistry::hasProperty(const char* name) const noexcept {
    return getPropertyAddress(name) != nullptr;
}

template<typename T>
bool FDebugRegistry::setProperty(const char* name, T v) noexcept {
    if constexpr (DEBUG_PROPERTIES_WRITABLE) {
        auto info = getPropertyInfo(name);
        T* const addr = static_cast<T*>(info.first);
        if (addr) {
            auto old = *addr;
            *addr = v;
            if (info.second && old != v) {
                info.second();
            }
            return true;
        }
    }
    return false;
}

template bool FDebugRegistry::setProperty<bool>(const char* name, bool v) noexcept;
template bool FDebugRegistry::setProperty<int>(const char* name, int v) noexcept;
template bool FDebugRegistry::setProperty<float>(const char* name, float v) noexcept;
template bool FDebugRegistry::setProperty<float2>(const char* name, float2 v) noexcept;
template bool FDebugRegistry::setProperty<float3>(const char* name, float3 v) noexcept;
template bool FDebugRegistry::setProperty<float4>(const char* name, float4 v) noexcept;

template<typename T>
bool FDebugRegistry::getProperty(const char* name, T* p) const noexcept {
    T const* const addr = static_cast<T const*>(getPropertyAddress(name));
    if (addr) {
        *p = *addr;
        return true;
    }
    return false;
}

template bool FDebugRegistry::getProperty<bool>(const char* name, bool* v) const noexcept;
template bool FDebugRegistry::getProperty<int>(const char* name, int* v) const noexcept;
template bool FDebugRegistry::getProperty<float>(const char* name, float* v) const noexcept;
template bool FDebugRegistry::getProperty<float2>(const char* name, float2* v) const noexcept;
template bool FDebugRegistry::getProperty<float3>(const char* name, float3* v) const noexcept;
template bool FDebugRegistry::getProperty<float4>(const char* name, float4* v) const noexcept;

void FDebugRegistry::registerDataSource(std::string_view name,
        void const* data, size_t count) noexcept {
    auto& dataSourceMap = mDataSourceMap;
    if (dataSourceMap.find(name) == dataSourceMap.end()) {
        dataSourceMap[name] = { data, count };
    }
}

void FDebugRegistry::registerDataSource(std::string_view name,
        utils::Invocable<DataSource()>&& creator) noexcept {
    mDataSourceCreatorMap[name] = std::move(creator);
}

DebugRegistry::DataSource FDebugRegistry::getDataSource(const char* name) const noexcept {
    std::string_view const key{ name };
    auto& dataSourceMap = mDataSourceMap;
    auto const& it = dataSourceMap.find(key);
    if (UTILS_UNLIKELY(it == dataSourceMap.end())) {
        auto& dataSourceCreatorMap = mDataSourceCreatorMap;
        auto const& pos = dataSourceCreatorMap.find(key);
        if (pos == dataSourceCreatorMap.end()) {
            return { nullptr, 0u };
        }
        DataSource dataSource{ pos->second() };
        dataSourceMap[key] = dataSource;
        dataSourceCreatorMap.erase(pos);
        return dataSource;
    }
    return it->second;
}

} // namespace filament
