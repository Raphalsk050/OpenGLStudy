
#ifndef TNT_FILAMENT_BACKEND_VULKANSWAPCHAIN_H
#define TNT_FILAMENT_BACKEND_VULKANSWAPCHAIN_H

#include "DriverBase.h"

#include "VulkanCommands.h"
#include "VulkanContext.h"
#include "VulkanResources.h"

#include <backend/platforms/VulkanPlatform.h>

#include <bluevk/BlueVK.h>
#include "third_party/filament/libs/utils/include/utils/FixedCapacityVector.h"

#include <memory>

using namespace bluevk;

namespace filament::backend {

struct VulkanHeadlessSwapChain;
struct VulkanSurfaceSwapChain;

// A wrapper around the platform implementation of swapchain.
struct VulkanSwapChain : public HwSwapChain, VulkanResource {
    VulkanSwapChain(VulkanPlatform* platform, VulkanContext const& context, VmaAllocator allocator,
            VulkanCommands* commands, VulkanStagePool& stagePool,
            void* nativeWindow, uint64_t flags, VkExtent2D extent = {0, 0});

    ~VulkanSwapChain();

    void present();

    void acquire(bool& reized);

    inline VulkanTexture* getCurrentColor() const noexcept {
        uint32_t const imageIndex = mCurrentSwapIndex;
        FILAMENT_CHECK_PRECONDITION(
            imageIndex != VulkanPlatform::ImageSyncData::INVALID_IMAGE_INDEX);
        return mColors[imageIndex].get();
    }

    inline VulkanTexture* getDepth() const noexcept {
        return mDepth.get();
    }

    inline bool isFirstRenderPass() const noexcept {
        return mIsFirstRenderPass;
    }

    inline void markFirstRenderPass() noexcept {
        mIsFirstRenderPass = false;
    }

    inline VkExtent2D getExtent() noexcept {
        return mExtent;
    }

private:
	static constexpr int IMAGE_READY_SEMAPHORE_COUNT = FVK_MAX_COMMAND_BUFFERS;

    void update();

    VulkanPlatform* mPlatform;
    VulkanCommands* mCommands;
    VmaAllocator mAllocator;
    VulkanStagePool& mStagePool;
    bool const mHeadless;
    bool const mFlushAndWaitOnResize;
    bool const mTransitionSwapChainImageLayoutForPresent;

    // We create VulkanTextures based on VkImages. VulkanTexture has facilities for doing layout
    // transitions, which are useful here.
    utils::FixedCapacityVector<std::unique_ptr<VulkanTexture>> mColors;
    std::unique_ptr<VulkanTexture> mDepth;
    VkExtent2D mExtent;
    uint32_t mCurrentSwapIndex;
    std::function<void(Platform::SwapChain* handle)> mExplicitImageReadyWait = nullptr;
    bool mAcquired;
    bool mIsFirstRenderPass;
};


}// namespace filament::backend

#endif// TNT_FILAMENT_BACKEND_VULKANSWAPCHAIN_H
