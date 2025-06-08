
#ifndef TNT_FILAMENT_FILAMENTAPI_H
#define TNT_FILAMENT_FILAMENTAPI_H

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/PrivateImplementation.h"

#include <stddef.h>

namespace filament {

class UTILS_PUBLIC FilamentAPI {
protected:
    // disallow creation on the stack
    FilamentAPI() noexcept = default;
    ~FilamentAPI() = default;

public:
    // disallow copy and assignment
    FilamentAPI(FilamentAPI const&) = delete;
    FilamentAPI(FilamentAPI&&) = delete;
    FilamentAPI& operator=(FilamentAPI const&) = delete;
    FilamentAPI& operator=(FilamentAPI&&) = delete;

    // allow placement-new allocation, don't use "noexcept", to avoid compiler null check
    static void *operator new     (size_t, void* p) { return p; }

    // prevent heap allocation
    static void *operator new     (size_t) = delete;
    static void *operator new[]   (size_t) = delete;
};

template<typename T>
using BuilderBase = utils::PrivateImplementation<T>;

} // namespace filament

#endif // TNT_FILAMENT_FILAMENTAPI_H
