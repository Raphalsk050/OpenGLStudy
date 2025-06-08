
#ifndef TNT_FILAMENT_BACKEND_COMPILERTHREADPOOL_H
#define TNT_FILAMENT_BACKEND_COMPILERTHREADPOOL_H

#include <backend/DriverEnums.h>

#include "third_party/filament/libs/utils/include/utils/Invocable.h"
#include "third_party/filament/libs/utils/include/utils/Mutex.h"
#include "third_party/filament/libs/utils/include/utils/Condition.h"

#include <array>
#include <deque>
#include <memory>
#include <thread>
#include <utility>
#include <vector>

namespace filament::backend {

struct ProgramToken {
    virtual ~ProgramToken();
};

using program_token_t = std::shared_ptr<ProgramToken>;

class Platform;

class CompilerThreadPool {
public:
    CompilerThreadPool() noexcept;
    ~CompilerThreadPool() noexcept;
    using Job = utils::Invocable<void()>;
    using ThreadSetup = utils::Invocable<void()>;
    using ThreadCleanup = utils::Invocable<void()>;
    void init(uint32_t threadCount,
            ThreadSetup&& threadSetup, ThreadCleanup&& threadCleanup) noexcept;
    void terminate() noexcept;
    void queue(CompilerPriorityQueue priorityQueue, program_token_t const& token, Job&& job);
    Job dequeue(program_token_t const& token);

private:
    using Queue = std::deque<std::pair<program_token_t, Job>>;
    std::vector<std::thread> mCompilerThreads;
    bool mExitRequested{ false };
    utils::Mutex mQueueLock;
    utils::Condition mQueueCondition;
    std::array<Queue, 2> mQueues;
    // lock must be held for methods below
    std::pair<Queue&, Queue::iterator> find(program_token_t const& token);
};

} // namespace filament::backend

#endif  // TNT_FILAMENT_BACKEND_COMPILERTHREADPOOL_H

