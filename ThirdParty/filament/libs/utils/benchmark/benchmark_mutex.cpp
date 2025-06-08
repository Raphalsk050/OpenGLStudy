
#include "PerformanceCounters.h"

#include "third_party/filament/libs/utils/include/utils/Allocator.h"
#include "third_party/filament/libs/utils/include/utils/Mutex.h"

#include <benchmark/benchmark.h>

using namespace utils;

static void BM_std_mutex(benchmark::State& state) {
    static std::mutex l;
    PerformanceCounters pc(state);
    for (auto _ : state) {
        l.lock();
        l.unlock();
    }
}

static void BM_utils_mutex(benchmark::State& state) {
    static Mutex l;
    PerformanceCounters pc(state);
    for (auto _ : state) {
        l.lock();
        l.unlock();
    }
}

BENCHMARK(BM_std_mutex)
    ->Threads(1)
    ->Threads(2)
    ->Threads(8)
    ->ThreadPerCpu();

BENCHMARK(BM_utils_mutex)
    ->Threads(1)
    ->Threads(2)
    ->Threads(8)
    ->ThreadPerCpu();
