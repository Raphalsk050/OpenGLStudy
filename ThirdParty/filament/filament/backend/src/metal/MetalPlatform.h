
#ifndef TNT_FILAMENT_BACKEND_PRIVATE_METALPLATFORM_H
#define TNT_FILAMENT_BACKEND_PRIVATE_METALPLATFORM_H

#include <backend/DriverEnums.h>
#include <backend/Platform.h>

#import <Metal/Metal.h>

namespace filament::backend {

class MetalPlatform final : public Platform {
public:
    ~MetalPlatform() override;

    Driver* createDriver(void* sharedContext, const Platform::DriverConfig& driverConfig) noexcept override;
    int getOSVersion() const noexcept override { return 0; }

    virtual id<MTLDevice> createDevice() noexcept;

    virtual id<MTLCommandQueue> createCommandQueue(id<MTLDevice> device) noexcept;

    id<MTLCommandBuffer> createAndEnqueueCommandBuffer() noexcept;

private:
    id<MTLCommandQueue> mCommandQueue = nil;

};

} // namespace filament::backend

#endif // TNT_FILAMENT_BACKEND_PRIVATE_METALPLATFORM_H
