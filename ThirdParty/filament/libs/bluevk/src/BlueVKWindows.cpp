

#include <windows.h>

namespace bluevk {

static const char* VKLIBRARY_PATH = "vulkan-1.dll";

static HMODULE library = nullptr;

bool loadLibrary() {
    library = LoadLibraryA(VKLIBRARY_PATH);
    return library != nullptr;
}

void* getInstanceProcAddr() {
    return GetProcAddress(library, "vkGetInstanceProcAddr");
}

} // namespace bluevk
