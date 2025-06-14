
#include "VulkanSwapChain.h"
#include "VulkanTexture.h"

#include "third_party/filament/libs/utils/include/utils/FixedCapacityVector.h"
#include "third_party/filament/libs/utils/include/utils/Panic.h"

using namespace bluevk;
using namespace utils;

namespace filament::backend {

VulkanSwapChain::VulkanSwapChain(VulkanPlatform* platform, VulkanContext const& context,
        VmaAllocator allocator, VulkanCommands* commands, VulkanStagePool& stagePool,
        void* nativeWindow, uint64_t flags, VkExtent2D extent)
    : VulkanResource(VulkanResourceType::SWAP_CHAIN),
      mPlatform(platform),
      mCommands(commands),
      mAllocator(allocator),
      mStagePool(stagePool),
      mHeadless(extent.width != 0 && extent.height != 0 && !nativeWindow),
      mFlushAndWaitOnResize(platform->getCustomization().flushAndWaitOnWindowResize),
      mTransitionSwapChainImageLayoutForPresent(
            platform->getCustomization().transitionSwapChainImageLayoutForPresent),
      mAcquired(false),
      mIsFirstRenderPass(true) {
    swapChain = mPlatform->createSwapChain(nativeWindow, flags, extent);
    FILAMENT_CHECK_POSTCONDITION(swapChain) << "Unable to create swapchain";

    update();
}

VulkanSwapChain::~VulkanSwapChain() {
    // Must wait for the inflight command buffers to finish since they might contain the images
    // we're about to destroy.
    mCommands->flush();
    mCommands->wait();

    mPlatform->destroy(swapChain);
}

void VulkanSwapChain::update() {
    mColors.clear();

    auto const bundle = mPlatform->getSwapChainBundle(swapChain);
    mColors.reserve(bundle.colors.size());
    VkDevice const device = mPlatform->getDevice();

    for (auto const color: bundle.colors) {
        mColors.push_back(std::make_unique<VulkanTexture>(device, mAllocator, mCommands, color,
                bundle.colorFormat, 1, bundle.extent.width, bundle.extent.height,

    mExtent = bundle.extent;
}

void VulkanSwapChain::present() {
    if (!mHeadless && mTransitionSwapChainImageLayoutForPresent) {
        VkCommandBuffer const cmdbuf = mCommands->get().buffer();
        VkImageSubresourceRange const subresources{
                .aspectMask = VK_IMAGE_ASPECT_COLOR_BIT,
                .baseMipLevel = 0,
                .levelCount = 1,
                .baseArrayLayer = 0,
                .layerCount = 1,
        };
        mColors[mCurrentSwapIndex]->transitionLayout(cmdbuf, subresources, VulkanLayout::PRESENT);
    }

    mCommands->flush();
    
    // call the image ready wait function
    if (mExplicitImageReadyWait != nullptr) {
        mExplicitImageReadyWait(swapChain);
    }

    // We only present if it is not headless. No-op for headless.
    if (!mHeadless) {
        VkSemaphore const finishedDrawing = mCommands->acquireFinishedSignal();
        VkResult const result = mPlatform->present(swapChain, mCurrentSwapIndex, finishedDrawing);
        FILAMENT_CHECK_POSTCONDITION(result == VK_SUCCESS || result == VK_SUBOPTIMAL_KHR ||
                result == VK_ERROR_OUT_OF_DATE_KHR)
                << "Cannot present in swapchain.";
    }

    // We presented the last acquired buffer.
    mAcquired = false;
    mIsFirstRenderPass = true;
}

void VulkanSwapChain::acquire(bool& resized) {
    // It's ok to call acquire multiple times due to it being linked to Driver::makeCurrent().
    if (mAcquired) {
        return;
    }

    // Check if the swapchain should be resized.
    if ((resized = mPlatform->hasResized(swapChain))) {
        if (mFlushAndWaitOnResize) {
            mCommands->flush();
            mCommands->wait();
        }
        mPlatform->recreate(swapChain);
        update();
    }

    VulkanPlatform::ImageSyncData imageSyncData;
    VkResult const result = mPlatform->acquire(swapChain, &imageSyncData);
    mCurrentSwapIndex = imageSyncData.imageIndex;
    mExplicitImageReadyWait = imageSyncData.explicitImageReadyWait;
    FILAMENT_CHECK_POSTCONDITION(result == VK_SUCCESS || result == VK_SUBOPTIMAL_KHR) 
        << "Cannot acquire in swapchain.";
    if (imageSyncData.imageReadySemaphore != VK_NULL_HANDLE) {
        mCommands->injectDependency(imageSyncData.imageReadySemaphore);
    }
    mAcquired = true;
}

}// namespace filament::backend
