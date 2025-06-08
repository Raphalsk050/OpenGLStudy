
#include "CompilerThreadPool.h"

#include "third_party/filament/libs/utils/include/utils/Systrace.h"

#include <memory>

namespace filament::backend {

using namespace utils;

ProgramToken::~ProgramToken() = default;

CompilerThreadPool::CompilerThreadPool() noexcept = default;

CompilerThreadPool::~CompilerThreadPool() noexcept {
    assert_invariant(mCompilerThreads.empty());
    assert_invariant(mQueues[0].empty());
    assert_invariant(mQueues[1].empty());
}

void CompilerThreadPool::init(uint32_t threadCount,
        ThreadSetup&& threadSetup, ThreadCleanup&& threadCleanup) noexcept {
    auto setup = std::make_shared<ThreadSetup>(std::move(threadSetup));
    auto cleanup = std::make_shared<ThreadCleanup>(std::move(threadCleanup));

    for (size_t i = 0; i < threadCount; i++) {
        mCompilerThreads.emplace_back([this, setup, cleanup]() {
            SYSTRACE_CONTEXT();

            (*setup)();

            // process jobs from the queue until we're asked to exit
            while (!mExitRequested) {
                std::unique_lock lock(mQueueLock);
                mQueueCondition.wait(lock, [this]() {
                    return  mExitRequested ||
                            (!std::all_of( std::begin(mQueues), std::end(mQueues),
                                    [](auto&& q) { return q.empty(); }));
                });

                SYSTRACE_VALUE32("CompilerThreadPool Jobs",
                        mQueues[0].size() + mQueues[1].size());

                if (UTILS_LIKELY(!mExitRequested)) {
                    Job job;
                    // use the first queue that's not empty
                    auto& queue = [this]() -> auto& {
                        for (auto& q: mQueues) {
                            if (!q.empty()) {
                                return q;
                            }
                        }
                        return mQueues[0]; // we should never end-up here.
                    }();
                    assert_invariant(!queue.empty());
                    std::swap(job, queue.front().second);
                    queue.pop_front();

                    // execute the job without holding any locks
                    lock.unlock();
                    job();
                }
            }

            (*cleanup)();
        });

    }
}

auto CompilerThreadPool::find(program_token_t const& token) -> std::pair<Queue&, Queue::iterator> {
    for (auto&& q: mQueues) {
        auto pos = std::find_if(q.begin(), q.end(), [&token](auto&& item) {
            return item.first == token;
        });
        if (pos != q.end()) {
            return { q, pos };
        }
    }
    // this can happen if the program is being processed right now
    return { mQueues[0], mQueues[0].end() };
}

auto CompilerThreadPool::dequeue(program_token_t const& token) -> Job {
    std::unique_lock const lock(mQueueLock);
    Job job;
    auto&& [q, pos] = find(token);
    if (pos != q.end()) {
        std::swap(job, pos->second);
        q.erase(pos);
    }
    return job;
}

void CompilerThreadPool::queue(CompilerPriorityQueue priorityQueue,
        program_token_t const& token, Job&& job) {
    std::unique_lock const lock(mQueueLock);
    mQueues[size_t(priorityQueue)].emplace_back(token, std::move(job));
    mQueueCondition.notify_one();
}

void CompilerThreadPool::terminate() noexcept {
    std::unique_lock lock(mQueueLock);
    mExitRequested = true;
    mQueueCondition.notify_all();
    lock.unlock();

    for (auto& thread: mCompilerThreads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
    mCompilerThreads.clear();

    // Clear all the queues, dropping the remaining jobs. This relies on the jobs being cancelable.
    for (auto&& q : mQueues) {
        q.clear();
    }
}

} // namespace filament::backend
