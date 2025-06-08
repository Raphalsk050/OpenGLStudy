
#ifndef TNT_FILAMENT_BACKEND_VULKANMEMORY_H
#define TNT_FILAMENT_BACKEND_VULKANMEMORY_H

#include <bluevk/BlueVK.h> // must be included before vk_mem_alloc

#ifndef VMA_STATIC_VULKAN_FUNCTIONS
#define VMA_STATIC_VULKAN_FUNCTIONS 0
#endif

#ifndef VMA_DYNAMIC_VULKAN_FUNCTIONS
#define VMA_DYNAMIC_VULKAN_FUNCTIONS 1
#endif

#pragma clang diagnostic ignored "-Wc++98-compat-extra-semi"

#include "third_party/vulkan_memory_allocator/include/vk_mem_alloc.h"

VK_DEFINE_HANDLE(VmaAllocator)
VK_DEFINE_HANDLE(VmaAllocation)
VK_DEFINE_HANDLE(VmaPool)

#endif // TNT_FILAMENT_BACKEND_VULKANMEMORY_H
