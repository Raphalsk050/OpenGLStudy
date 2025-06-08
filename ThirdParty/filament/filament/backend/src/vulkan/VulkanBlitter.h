
#ifndef TNT_FILAMENT_BACKEND_VULKANBLITTER_H
#define TNT_FILAMENT_BACKEND_VULKANBLITTER_H

#include "VulkanCommands.h"
#include "VulkanContext.h"

#include "third_party/filament/libs/utils/include/utils/compiler.h"

namespace filament::backend {

class VulkanBuffer;
class VulkanFboCache;
class VulkanPipelineCache;
class VulkanSamplerCache;

struct VulkanProgram;

class VulkanBlitter {
public:
    VulkanBlitter(VkPhysicalDevice physicalDevice, VulkanCommands* commands) noexcept;

    void blit(VkFilter filter,
            VulkanAttachment dst, const VkOffset3D* dstRectPair,
            VulkanAttachment src, const VkOffset3D* srcRectPair);

    void resolve(VulkanAttachment dst, VulkanAttachment src);

    void terminate() noexcept;

private:
    UTILS_UNUSED VkPhysicalDevice mPhysicalDevice;
    VulkanCommands* mCommands;
};

} // namespace filament::backend

#endif // TNT_FILAMENT_BACKEND_VULKANBLITTER_H
