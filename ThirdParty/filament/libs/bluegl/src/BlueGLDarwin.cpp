
#include <dlfcn.h>

namespace bluegl {

static void* library = nullptr;

bool initBinder() {
    const char* library_name = "/System/Library/Frameworks/OpenGL.framework/OpenGL";
    library = dlopen(library_name, RTLD_GLOBAL | RTLD_NOW);
    return library != nullptr;
}

void* loadFunction(const char* name) {
    return dlsym(library, name);
}

void shutdownBinder() {
    dlclose(library);
    library = nullptr;
}

} // namespace bluegl
