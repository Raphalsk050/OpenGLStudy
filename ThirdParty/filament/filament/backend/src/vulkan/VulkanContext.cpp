
#include "VulkanContext.h"

#include "VulkanCommands.h"
#include "VulkanHandles.h"
#include "VulkanMemory.h"
#include "VulkanTexture.h"
#include "VulkanUtility.h"

#include <backend/PixelBufferDescriptor.h>

#include "third_party/filament/libs/utils/include/utils/Panic.h"
#include "third_party/filament/libs/utils/include/utils/FixedCapacityVector.h"

#include <algorithm> // for std::max

using namespace bluevk;

using utils::FixedCapacityVector;


namespace {

} // end anonymous namespace

namespace filament::backend {

VkImage VulkanAttachment::getImage() const {
    return texture ? texture->getVkImage() : VK_NULL_HANDLE;
}

VkFormat VulkanAttachment::getFormat() const {
    return texture ? texture->getVkFormat() : VK_FORMAT_UNDEFINED;
}

VulkanLayout VulkanAttachment::getLayout() const {
    return texture ? texture->getLayout(layer, level) : VulkanLayout::UNDEFINED;
}

VkExtent2D VulkanAttachment::getExtent2D() const {
    assert_invariant(texture);
    return { std::max(1u, texture->width >> level), std::max(1u, texture->height >> level) };
}

VkImageView VulkanAttachment::getImageView() {
    assert_invariant(texture);
    return texture->getAttachmentView(getSubresourceRange());
}

bool VulkanAttachment::isDepth() const {
    return texture->getImageAspect() & VK_IMAGE_ASPECT_DEPTH_BIT;
}

VkImageSubresourceRange VulkanAttachment::getSubresourceRange() const {
    assert_invariant(texture);
    return {
            .aspectMask = texture->getImageAspect(),
            .baseMipLevel = uint32_t(level),
            .levelCount = 1,
            .baseArrayLayer = uint32_t(layer),
            .layerCount = 1,
    };
}

VulkanTimestamps::VulkanTimestamps(VkDevice device) : mDevice(device) {
    // Create a timestamp pool large enough to hold a pair of queries for each timer.
    VkQueryPoolCreateInfo tqpCreateInfo = {
        .sType = VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO,
        .queryType = VK_QUERY_TYPE_TIMESTAMP,
    };  
    std::unique_lock<utils::Mutex> lock(mMutex);
    tqpCreateInfo.queryCount = mUsed.size() * 2;
    VkResult result = vkCreateQueryPool(mDevice, &tqpCreateInfo, VKALLOC, &mPool);
    FILAMENT_CHECK_POSTCONDITION(result == VK_SUCCESS) << "vkCreateQueryPool error.";
    mUsed.reset();
}

std::tuple<uint32_t, uint32_t> VulkanTimestamps::getNextQuery() {
    std::unique_lock<utils::Mutex> lock(mMutex);
    size_t const maxTimers = mUsed.size();
    assert_invariant(mUsed.count() < maxTimers);
    for (size_t timerIndex = 0; timerIndex < maxTimers; ++timerIndex) {
        if (!mUsed.test(timerIndex)) {
            mUsed.set(timerIndex);
	    return std::make_tuple(timerIndex * 2, timerIndex * 2 + 1);
        }
    }
    FVK_LOGE << "More than " << maxTimers << " timers are not supported." << utils::io::endl;
    return std::make_tuple(0, 1);
}

void VulkanTimestamps::clearQuery(uint32_t queryIndex) {
    mUsed.unset(queryIndex / 2);
}

void VulkanTimestamps::beginQuery(VulkanCommandBuffer const* commands,
        VulkanTimerQuery* query) {
    uint32_t const index = query->getStartingQueryIndex();

    auto const cmdbuffer = commands->buffer();
    vkCmdResetQueryPool(cmdbuffer, mPool, index, 2);
    vkCmdWriteTimestamp(cmdbuffer, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, mPool, index);

    // We stash this because getResult might come before the query is actually processed.
    query->setFence(commands->fence);
}

void VulkanTimestamps::endQuery(VulkanCommandBuffer const* commands,
        VulkanTimerQuery const* query) {
    uint32_t const index = query->getStoppingQueryIndex();
    vkCmdWriteTimestamp(commands->buffer(), VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, mPool, index);
}

VulkanTimestamps::QueryResult VulkanTimestamps::getResult(VulkanTimerQuery const* query) {
    uint32_t const index = query->getStartingQueryIndex();
    QueryResult result;
    size_t const dataSize = result.size() * sizeof(uint64_t);
    VkDeviceSize const stride = sizeof(uint64_t) * 2;
    VkResult vkresult =
            vkGetQueryPoolResults(mDevice, mPool, index, 2, dataSize, (void*) result.data(),
                    stride, VK_QUERY_RESULT_64_BIT | VK_QUERY_RESULT_WITH_AVAILABILITY_BIT);
    FILAMENT_CHECK_POSTCONDITION(vkresult == VK_SUCCESS || vkresult == VK_NOT_READY)
            << "vkGetQueryPoolResults error: " << static_cast<int32_t>(vkresult);
    if (vkresult == VK_NOT_READY) {
        return {0, 0, 0, 0};
    }
    return result;
}

VulkanTimestamps::~VulkanTimestamps() {
    vkDestroyQueryPool(mDevice, mPool, VKALLOC);
}

} // namespace filament::backend
