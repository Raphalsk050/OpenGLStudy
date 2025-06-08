
#include "PlatformRunner.h"

#include <getopt.h>

#include <iostream>
#include <string>

namespace test {

Backend parseArgumentsForBackend(int argc, char* argv[]) {
    Backend backend = Backend::OPENGL;
    // The first colon in OPTSTR turns on silent error reporting. This is important, as the
    // arguments may also contain gtest parameters we don't know about.
    static constexpr const char* OPTSTR = ":a:";
    static const struct option OPTIONS[] = {
            { "api", required_argument, nullptr, 'a' },
            { nullptr, 0, nullptr, 0 }  // termination of the option list
    };

    int opt;
    int optionIndex = 0;

    while ((opt = getopt_long(argc, argv, OPTSTR, OPTIONS, &optionIndex)) >= 0) {
        std::string arg(optarg ? optarg : "");
        switch (opt) {
            case 'a':
                if (arg == "opengl") {
                    backend = Backend::OPENGL;
                } else if (arg == "vulkan") {
                    backend = Backend::VULKAN;
                } else if (arg == "metal") {
                    backend = Backend::METAL;
                } else {
                    std::cerr << "Unrecognized target API. Must be 'opengl'|'vulkan'|'metal'."
                              << std::endl
                              << "Defaulting to OpenGL."
                              << std::endl;
                }
                break;
        }
    }

    return backend;
}

} // namespace test
