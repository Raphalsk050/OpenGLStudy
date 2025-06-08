
#ifndef TNT_PLATFORMRUNNER_H
#define TNT_PLATFORMRUNNER_H

#include <stdint.h>
#include <stddef.h>

namespace test {

constexpr uint32_t const WINDOW_WIDTH = 512;
constexpr uint32_t const WINDOW_HEIGHT = 512;

// To avoid a dependency on filabridge, the Backend enum is replicated here.
enum class Backend : uint8_t {
    OPENGL = 1,
    VULKAN = 2,
    METAL = 3,
    NOOP = 4,
};

struct NativeView {
    void* ptr = nullptr;
    size_t width = 0, height = 0;
};

NativeView getNativeView();

void initTests(Backend backend, bool isMobile, int& argc, char* argv[]);

int runTests();

Backend parseArgumentsForBackend(int argc, char* argv[]);

}

#endif
