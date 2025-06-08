

#include "BackendTest.h"
#include "PlatformRunner.h"

#include <array>
#include <iostream>

namespace test {

test::NativeView getNativeView() {
    return {
            .ptr = nullptr,
            .width = WINDOW_WIDTH,
            .height = WINDOW_HEIGHT,
    };
}

}// namespace test

namespace {

std::array<test::Backend, 2> const VALID_BACKENDS{
        test::Backend::OPENGL,
        test::Backend::VULKAN,
};

}// namespace

int main(int argc, char* argv[]) {
    auto backend = test::parseArgumentsForBackend(argc, argv);

    if (!std::any_of(VALID_BACKENDS.begin(), VALID_BACKENDS.end(),
                [backend](test::Backend validBackend) { return backend == validBackend; })) {
        std::cerr << "Specified an invalid backend. Only GL and Vulkan are available" << std::endl;
        return 1;
    }

    test::initTests(backend, false, argc, argv);
    return test::runTests();
}
