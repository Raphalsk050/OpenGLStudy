
#include <bluevk/BlueVK.h> // must be included before vk_mem_alloc

#pragma clang diagnostic push

// Needed because not all clang versions have the warning -Wdeprecated-copy.
#pragma clang diagnostic ignored "-Wunknown-warning-option"

#pragma clang diagnostic ignored "-Wdeprecated-copy"
#pragma clang diagnostic ignored "-Wimplicit-fallthrough"
#pragma clang diagnostic ignored "-Wmissing-field-initializers"
#pragma clang diagnostic ignored "-Wundef"
#pragma clang diagnostic ignored "-Wunused-private-field"
#pragma clang diagnostic ignored "-Wunused-variable"
#pragma clang diagnostic ignored "-Wweak-vtables"
#pragma clang diagnostic ignored "-Wnullability-completeness"
#pragma clang diagnostic ignored "-Wextra-semi"
#pragma clang diagnostic ignored "-Wc++98-compat-extra-semi"

static const PFN_vkGetInstanceProcAddr& vkGetInstanceProcAddr = bluevk::vkGetInstanceProcAddr;
static const PFN_vkGetDeviceProcAddr& vkGetDeviceProcAddr = bluevk::vkGetDeviceProcAddr;

#define VMA_STATIC_VULKAN_FUNCTIONS 0
#define VMA_IMPLEMENTATION
#include "third_party/vulkan_memory_allocator/include/vk_mem_alloc.h"
#pragma clang diagnostic pop
