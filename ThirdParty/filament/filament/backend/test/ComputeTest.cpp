
#include "ComputeTest.h"
#include "PlatformRunner.h"

#include <backend/Platform.h>
#include <private/backend/PlatformFactory.h>


#include "private/backend/CommandBufferQueue.h"
#include "private/backend/DriverApi.h"

using namespace filament;
using namespace filament::backend;

int main(int argc, char* argv[]) {
    auto backend = (Backend)test::parseArgumentsForBackend(argc, argv);
    ComputeTest::init(backend);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// ------------------------------------------------------------------------------------------------

static constexpr size_t CONFIG_MIN_COMMAND_BUFFERS_SIZE = 1 * 1024 * 1024;
static constexpr size_t CONFIG_COMMAND_BUFFERS_SIZE     = 3 * CONFIG_MIN_COMMAND_BUFFERS_SIZE;

Backend ComputeTest::sBackend = Backend::NOOP;

void ComputeTest::init(Backend backend) {
    sBackend = backend;
}

ComputeTest::ComputeTest()
    : commandBufferQueue(CONFIG_MIN_COMMAND_BUFFERS_SIZE, CONFIG_COMMAND_BUFFERS_SIZE,
