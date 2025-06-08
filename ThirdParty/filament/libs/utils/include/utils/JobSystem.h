
#ifndef TNT_UTILS_JOBSYSTEM_H
#define TNT_UTILS_JOBSYSTEM_H

#include "third_party/filament/libs/utils/include/utils/Allocator.h"
#include "third_party/filament/libs/utils/include/utils/architecture.h"
#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/Condition.h"
#include "third_party/filament/libs/utils/include/utils/Log.h"
#include "third_party/filament/libs/utils/include/utils/memalign.h"
#include "third_party/filament/libs/utils/include/utils/Mutex.h"
#include "third_party/filament/libs/utils/include/utils/Slice.h"
#include "third_party/filament/libs/utils/include/utils/ostream.h"
#include "third_party/filament/libs/utils/include/utils/WorkStealingDequeue.h"

#include "robin_map/include/tsl/robin_map.h"

#include <atomic>
#include <functional>
#include <mutex>
#include <type_traits>
#include <thread>
#include <vector>

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

namespace utils {

class JobSystem {
    static constexpr size_t MAX_JOB_COUNT = 16384;
    static_assert(MAX_JOB_COUNT <= 0x7FFE, "MAX_JOB_COUNT must be <= 0x7FFE");
    using WorkQueue = WorkStealingDequeue<uint16_t, MAX_JOB_COUNT>;

public:
    class Job;

    using JobFunc = void(*)(void*, JobSystem&, Job*);

    class alignas(CACHELINE_SIZE) Job {
    public:

    // creates an empty (no-op) job with an optional parent
    Job* createJob(Job* parent = nullptr) noexcept {
        return create(parent, nullptr);
    }

    // creates a job from a KNOWN method pointer w/ object passed by pointer
    // the caller must ensure the object will outlive the Job
    template<typename T, void(T::*method)(JobSystem&, Job*)>
    Job* createJob(Job* parent, T* data) noexcept {
        Job* job = create(parent, +[](void* storage, JobSystem& js, Job* job) {
            T* const that = static_cast<T*>(reinterpret_cast<void**>(storage)[0]);
            (that->*method)(js, job);
        });
        if (job) {
            job->storage[0] = data;
        }
        return job;
    }

    // creates a job from a KNOWN method pointer w/ object passed by value
    template<typename T, void(T::*method)(JobSystem&, Job*)>
    Job* createJob(Job* parent, T data) noexcept {
        static_assert(sizeof(data) <= sizeof(Job::storage), "user data too large");
        Job* job = create(parent, [](void* storage, JobSystem& js, Job* job) {
            T* const that = static_cast<T*>(storage);
            (that->*method)(js, job);
            that->~T();
        });
        if (job) {
            new(job->storage) T(std::move(data));
        }
        return job;
    }

    // creates a job from a functor passed by value
    template<typename T>
    Job* createJob(Job* parent, T functor) noexcept {
        static_assert(sizeof(functor) <= sizeof(Job::storage), "functor too large");
        Job* job = create(parent, [](void* storage, JobSystem& js, Job* job){
            T* const that = static_cast<T*>(storage);
            that->operator()(js, job);
            that->~T();
        });
        if (job) {
            new(job->storage) T(std::move(functor));
        }
        return job;
    }


    void cancel(Job*& job) noexcept;

    static Job* retain(Job* job) noexcept;

    void release(Job*& job) noexcept;
    void release(Job*&& job) noexcept {
        Job* p = job;
        release(p);
    }

    void run(Job*& job) noexcept;
    void run(Job*&& job) noexcept { // allows run(createJob(...));
        Job* p = job;
        run(p);
    }

    void signal() noexcept;

    Job* runAndRetain(Job* job) noexcept;

    void waitAndRelease(Job*& job) noexcept;

    void runAndWait(Job*& job) noexcept;
    void runAndWait(Job*&& job) noexcept { // allows runAndWait(createJob(...));
        Job* p = job;
        runAndWait(p);
    }

    // for debugging
    friend utils::io::ostream& operator << (utils::io::ostream& out, JobSystem const& js);


    // utility functions...

    // set the name of the current thread (on OSes that support it)
    static void setThreadName(const char* threadName) noexcept;

    enum class Priority {
        NORMAL,
        DISPLAY,
        URGENT_DISPLAY,
        BACKGROUND
    };

    static void setThreadPriority(Priority priority) noexcept;
    static void setThreadAffinityById(size_t id) noexcept;

    size_t getParallelSplitCount() const noexcept {
        return mParallelSplitCount;
    }

    size_t getThreadCount() const { return mThreadCount; }

private:
    // this is just to avoid using std::default_random_engine, since we're in a public header.
    class default_random_engine {
        static constexpr uint32_t m = 0x7fffffffu;
        uint32_t mState; // must be 0 < seed < 0x7fffffff
    public:
        inline constexpr explicit default_random_engine(uint32_t seed = 1u) noexcept
                : mState(((seed % m) == 0u) ? 1u : seed % m) {
        }
        inline uint32_t operator()() noexcept {
            return mState = uint32_t((uint64_t(mState) * 48271u) % m);
        }
    };

    struct alignas(CACHELINE_SIZE) ThreadState {    // this causes 40-bytes padding
        // make sure storage is cache-line aligned
        WorkQueue workQueue;

        // these are not accessed by the worker threads
        alignas(CACHELINE_SIZE)         // this causes 56-bytes padding
        JobSystem* js;                  // this is in fact const and always initialized
        std::thread thread;             // unused for adopted threads
        default_random_engine rndGen;
    };

    static_assert(sizeof(ThreadState) % CACHELINE_SIZE == 0,
            "ThreadState doesn't align to a cache line");

    ThreadState& getState() noexcept;

    static void incRef(Job const* job) noexcept;
    void decRef(Job const* job) noexcept;

    Job* allocateJob() noexcept;
    JobSystem::ThreadState* getStateToStealFrom(JobSystem::ThreadState& state) noexcept;
    static bool hasJobCompleted(Job const* job) noexcept;

    void requestExit() noexcept;
    bool exitRequested() const noexcept;
    bool hasActiveJobs() const noexcept;

    void loop(ThreadState* state) noexcept;
    bool execute(JobSystem::ThreadState& state) noexcept;
    Job* steal(JobSystem::ThreadState& state) noexcept;
    void finish(Job* job) noexcept;

    void put(WorkQueue& workQueue, Job* job) noexcept;
    Job* pop(WorkQueue& workQueue) noexcept;
    Job* steal(WorkQueue& workQueue) noexcept;

    void wait(std::unique_lock<Mutex>& lock, Job* job = nullptr) noexcept;
    void wake(size_t hint) noexcept;
    void wakeAll() noexcept;

    // these have thread contention, keep them together
    utils::Mutex mWaiterLock;
    utils::Condition mWaiterCondition;

    std::atomic<int32_t> mActiveJobs = { 0 };
    utils::Arena<utils::ThreadSafeObjectPoolAllocator<Job>, LockingPolicy::NoLock> mJobPool;

    template <typename T>
    using aligned_vector = std::vector<T, utils::STLAlignedAllocator<T>>;

    // These are essentially const, make sure they're on a different cache-lines than the
    // read-write atomics.
    // We can't use "alignas(CACHELINE_SIZE)" because the standard allocator can't make this
    // guarantee.
    char padding[CACHELINE_SIZE];

    alignas(16) // at least we align to half (or quarter) cache-line
    aligned_vector<ThreadState> mThreadStates;          // actual data is stored offline
    std::atomic<bool> mExitRequested = { false };       // this one is almost never written
    std::atomic<uint16_t> mAdoptedThreads = { 0 };      // this one is almost never written
    Job* const mJobStorageBase;                         // Base for conversion to indices
    uint16_t mThreadCount = 0;                          // total # of threads in the pool
    uint8_t mParallelSplitCount = 0;                    // # of split allowable in parallel_for
    Job* mRootJob = nullptr;

    utils::Mutex mThreadMapLock; // this should have very little contention
    tsl::robin_map<std::thread::id, ThreadState *> mThreadMap;
};

// -------------------------------------------------------------------------------------------------
// Utility functions built on top of JobSystem

namespace jobs {

// These are convenience C++11 style job creation methods that support lambdas
//
// IMPORTANT: these are less efficient to call and may perform heap allocation
//            depending on the capture and parameters
//
template<typename CALLABLE, typename ... ARGS>
JobSystem::Job* createJob(JobSystem& js, JobSystem::Job* parent,
        CALLABLE&& func, ARGS&&... args) noexcept {
    struct Data {
        std::function<void()> f;
        // Renaming the method below could cause an Arrested Development.
        void gob(JobSystem&, JobSystem::Job*) noexcept { f(); }
    } user{ std::bind(std::forward<CALLABLE>(func),
            std::forward<ARGS>(args)...) };
    return js.createJob<Data, &Data::gob>(parent, std::move(user));
}

template<typename CALLABLE, typename T, typename ... ARGS,
        typename = typename std::enable_if<
                std::is_member_function_pointer<typename std::remove_reference<CALLABLE>::type>::value
        >::type
>
JobSystem::Job* createJob(JobSystem& js, JobSystem::Job* parent,
        CALLABLE&& func, T&& o, ARGS&&... args) noexcept {
    struct Data {
        std::function<void()> f;
        // Renaming the method below could cause an Arrested Development.
        void gob(JobSystem&, JobSystem::Job*) noexcept { f(); }
    } user{ std::bind(std::forward<CALLABLE>(func), std::forward<T>(o),
            std::forward<ARGS>(args)...) };
    return js.createJob<Data, &Data::gob>(parent, std::move(user));
}


namespace details {

template<typename S, typename F>
struct ParallelForJobData {
    using SplitterType = S;
    using Functor = F;
    using JobData = ParallelForJobData;
    using size_type = uint32_t;

    ParallelForJobData(size_type start, size_type count, uint8_t splits,
            Functor functor,
            const SplitterType& splitter) noexcept
            : start(start), count(count),
              functor(std::move(functor)),
              splits(splits),
              splitter(splitter) {
    }

    void parallelWithJobs(JobSystem& js, JobSystem::Job* parent) noexcept {
        assert(parent);

        // this branch is often miss-predicted (it both sides happen 50% of the calls)
right_side:
        if (splitter.split(splits, count)) {
            const size_type lc = count / 2;
            JobData ld(start, lc, splits + uint8_t(1), functor, splitter);
            JobSystem::Job* l = js.createJob<JobData, &JobData::parallelWithJobs>(parent, std::move(ld));
            if (UTILS_UNLIKELY(l == nullptr)) {
                // couldn't create a job, just pretend we're done splitting
                goto execute;
            }

            // start the left side before attempting the right side, so we parallelize in case
            // of job creation failure -- rare, but still.
            js.run(l);

            // don't spawn a job for the right side, just reuse us -- spawning jobs is more
            // costly than we'd like.
            start += lc;
            count -= lc;
            ++splits;
            goto right_side;

        } else {
execute:
            // we're done splitting, do the real work here!
            functor(start, count);
        }
    }

private:
    size_type start;            // 4
    size_type count;            // 4
    Functor functor;            // ?
    uint8_t splits;             // 1
    SplitterType splitter;      // 1
};

} // namespace details


// parallel jobs with start/count indices
template<typename S, typename F>
JobSystem::Job* parallel_for(JobSystem& js, JobSystem::Job* parent,
        uint32_t start, uint32_t count, F functor, const S& splitter) noexcept {
    using JobData = details::ParallelForJobData<S, F>;
    JobData jobData(start, count, 0, std::move(functor), splitter);
    return js.createJob<JobData, &JobData::parallelWithJobs>(parent, std::move(jobData));
}

// parallel jobs with pointer/count
template<typename T, typename S, typename F>
JobSystem::Job* parallel_for(JobSystem& js, JobSystem::Job* parent,
        T* data, uint32_t count, F functor, const S& splitter) noexcept {
    auto user = [data, f = std::move(functor)](uint32_t s, uint32_t c) {
        f(data + s, c);
    };
    using JobData = details::ParallelForJobData<S, decltype(user)>;
    JobData jobData(0, count, 0, std::move(user), splitter);
    return js.createJob<JobData, &JobData::parallelWithJobs>(parent, std::move(jobData));
}

// parallel jobs on a Slice<>
template<typename T, typename S, typename F>
JobSystem::Job* parallel_for(JobSystem& js, JobSystem::Job* parent,
        utils::Slice<T> slice, F functor, const S& splitter) noexcept {
    return parallel_for(js, parent, slice.data(), slice.size(), functor, splitter);
}


template <size_t COUNT, size_t MAX_SPLITS = 12>
class CountSplitter {
public:
    bool split(size_t splits, size_t count) const noexcept {
        return (splits < MAX_SPLITS && count >= COUNT * 2);
    }
};

} // namespace jobs
} // namespace utils

#endif // TNT_UTILS_JOBSYSTEM_H
