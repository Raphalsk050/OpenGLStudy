
#ifndef TNT_UTILS_BENCHMARK_PEROFRMANCECOUNTERS_H
#define TNT_UTILS_BENCHMARK_PEROFRMANCECOUNTERS_H

#include <benchmark/benchmark.h>

#include "third_party/filament/libs/utils/include/utils/Profiler.h"

class PerformanceCounters {
    benchmark::State& state;
    utils::Profiler profiler;
    utils::Profiler::Counters counters{};

public:
    explicit PerformanceCounters(benchmark::State& state)
            : state(state) {
        profiler.resetEvents(utils::Profiler::EV_CPU_CYCLES | utils::Profiler::EV_BPU_MISSES);
        profiler.start();
    }
    ~PerformanceCounters() {
        profiler.stop();
        counters = profiler.readCounters();
        if (profiler.isValid()) {
            state.counters.insert({
                    { "C",   { (double)counters.getCpuCycles(),    benchmark::Counter::kAvgIterations }},
                    { "I",   { (double)counters.getInstructions(), benchmark::Counter::kAvgIterations }},
                    { "BPU", { (double)counters.getBranchMisses(), benchmark::Counter::kAvgIterations }},
                    { "CPI", { (double)counters.getCPI(),          benchmark::Counter::kAvgThreads }},
            });
        }
    }
};

#endif //TNT_UTILS_BENCHMARK_PEROFRMANCECOUNTERS_H
