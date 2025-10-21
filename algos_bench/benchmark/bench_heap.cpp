
#include <benchmark/benchmark.h>
#include "heap.hpp"
#include <vector>
#include <random>

static void BM_HeapInsert(benchmark::State& state) {
    std::vector<int> values;
    std::mt19937 gen(123); // Фиксированный seed для воспроизводимости
    std::uniform_int_distribution<> dis(1, 1000000);
    for (int i = 0; i < state.range(0); ++i) {
        values.push_back(dis(gen));
    }

    for (auto _ : state) {
        bary::Heap<int> heap;
        for (int val : values) {
            heap.insert(val);
        }
        benchmark::ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}

static void BM_HeapExtract(benchmark::State& state) {
    std::vector<int> values;
    std::mt19937 gen(123);
    std::uniform_int_distribution<> dis(1, 1000000);
    for (int i = 0; i < state.range(0); ++i) {
        values.push_back(dis(gen));
    }

    for (auto _ : state) {
        state.PauseTiming();
        bary::Heap<int> heap;
        for (int val : values) {
            heap.insert(val);
        }
        state.ResumeTiming();

        while (!heap.is_empty()) {
            heap.extract_max();
        }
        benchmark::ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_HeapInsert)->Range(8, 8<<10)->Complexity();
BENCHMARK(BM_HeapExtract)->Range(8, 8<<10)->Complexity();

BENCHMARK_MAIN();
