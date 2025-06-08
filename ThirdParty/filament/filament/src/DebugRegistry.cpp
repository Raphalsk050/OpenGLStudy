
#include "details/DebugRegistry.h"

#include "third_party/filament/libs/math/include/math/vec2.h"
#include "third_party/filament/libs/math/include/math/vec3.h"
#include "third_party/filament/libs/math/include/math/vec4.h"

namespace filament {

using namespace math;

bool DebugRegistry::hasProperty(const char* name) const noexcept {
    return downcast(this)->hasProperty(name);
}

bool DebugRegistry::setProperty(const char* name, bool v) noexcept {
    return downcast(this)->setProperty(name, v);
}

bool DebugRegistry::setProperty(const char* name, int v) noexcept {
    return downcast(this)->setProperty(name, v);
}

bool DebugRegistry::setProperty(const char* name, float v) noexcept {
    return downcast(this)->setProperty(name, v);
}

bool DebugRegistry::setProperty(const char* name, float2 v) noexcept {
    return downcast(this)->setProperty(name, v);
}

bool DebugRegistry::setProperty(const char* name, float3 v) noexcept {
    return downcast(this)->setProperty(name, v);
}

bool DebugRegistry::setProperty(const char* name, float4 v) noexcept {
    return downcast(this)->setProperty(name, v);
}


bool DebugRegistry::getProperty(const char* name, bool* v) const noexcept {
    return downcast(this)->getProperty(name, v);
}

bool DebugRegistry::getProperty(const char* name, int* v) const noexcept {
    return downcast(this)->getProperty(name, v);
}

bool DebugRegistry::getProperty(const char* name, float* v) const noexcept {
    return downcast(this)->getProperty(name, v);
}

bool DebugRegistry::getProperty(const char* name, float2* v) const noexcept {
    return downcast(this)->getProperty(name, v);
}

bool DebugRegistry::getProperty(const char* name, float3* v) const noexcept {
    return downcast(this)->getProperty(name, v);
}

bool DebugRegistry::getProperty(const char* name, float4* v) const noexcept {
    return downcast(this)->getProperty(name, v);
}

void *DebugRegistry::getPropertyAddress(const char *name) {
    return  downcast(this)->getPropertyAddress(name);
}

void const *DebugRegistry::getPropertyAddress(const char *name) const noexcept {
    return  downcast(this)->getPropertyAddress(name);
}

DebugRegistry::DataSource DebugRegistry::getDataSource(const char* name) const noexcept {
    return  downcast(this)->getDataSource(name);
}


} // namespace filament

