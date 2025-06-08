
#ifndef TNT_COMPUTE_TEST_H
#define TNT_COMPUTE_TEST_H

#include <gtest/gtest.h>

#include "private/backend/CommandBufferQueue.h"
#include "private/backend/DriverApi.h"

class ComputeTest : public ::testing::Test {
    static filament::backend::Backend sBackend;

    filament::backend::Driver* driver = nullptr;
    filament::backend::CommandBufferQueue commandBufferQueue;
    std::unique_ptr<filament::backend::DriverApi> commandStream;

protected:
    void SetUp() override;
    void TearDown() override;

    void executeCommands();
    void flushAndWait();
    filament::backend::DriverApi& getDriverApi() { return *commandStream; }
    filament::backend::Driver& getDriver() { return *driver; }

    static filament::backend::Backend getBackend() noexcept { return sBackend; };
    bool isMobile() noexcept { return driver->getShaderModel() == filament::backend::ShaderModel::MOBILE; };

public:
    static void init(filament::backend::Backend backend);

    ComputeTest();
    ~ComputeTest() override;
};

#endif // TNT_COMPUTE_TEST_H
