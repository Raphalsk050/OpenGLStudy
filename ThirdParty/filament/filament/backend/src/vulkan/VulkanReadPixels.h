
#ifndef TNT_FILAMENT_BACKEND_VULKANREADPIXELS_H
#define TNT_FILAMENT_BACKEND_VULKANREADPIXELS_H

#include "private/backend/Driver.h"

#include <bluevk/BlueVK.h>
#include "third_party/filament/libs/math/include/math/vec4.h"

#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>

namespace filament::backend {

struct VulkanRenderTarget;

class VulkanReadPixels {
public:
    // A helper class that runs tasks on a separate thread.
    class TaskHandler {
    public:
        using WorkloadFunc = std::function<void()>;
        using OnCompleteFunc = std::function<void()>;
        using Task = std::pair<WorkloadFunc, OnCompleteFunc>;

        TaskHandler();

        // In addition to the workload that the handler will call, client must also provide an
        // oncomplete function that the handler will call either when the workload completes or when
        // the handler is shutdown (so that we can clean-up even when the task was not carried out).
        void post(WorkloadFunc&& workload, OnCompleteFunc&& oncomplete);

        // This will block until all of the tasks are done.
        void drain();

        // This will quit without running the workloads, but oncomplete callbacks will still be
        // called.
        void shutdown();

    private:
        void loop();

        bool mShouldStop;
        std::condition_variable mHasTaskCondition;
        std::mutex mTaskQueueMutex;
        std::queue<Task> mTaskQueue;
        std::thread mThread;
    };

    using OnReadCompleteFunction = std::function<void(PixelBufferDescriptor&&)>;
    using SelecteMemoryFunction = std::function<uint32_t(uint32_t, VkFlags)>;

    explicit VulkanReadPixels(VkDevice device);

    void terminate() noexcept;

    void run(VulkanRenderTarget* srcTarget, uint32_t x, uint32_t y, uint32_t width, uint32_t height,
            uint32_t graphicsQueueFamilyIndex, PixelBufferDescriptor&& pbd,
            SelecteMemoryFunction const& selectMemoryFunc,
            OnReadCompleteFunction const& readCompleteFunc);

    // This method will block until all of the in-flight requests are complete.
    void runUntilComplete() noexcept;

private:
    VkDevice mDevice = VK_NULL_HANDLE;
    VkCommandPool mCommandPool = VK_NULL_HANDLE;
    std::unique_ptr<TaskHandler> mTaskHandler;
};

}// namespace filament::backend

#endif// TNT_FILAMENT_BACKEND_VULKANREADPIXELS_H
