#include <benchmark/benchmark.h>

#include <vector>
#include <cstdlib>
#include <ctime>

#include "lcs.hpp"

static std::vector<int> random_vector(int n) {
    std::vector<int> v(n);
    for (int& x : v) x = rand() % 1000;
    return v;
}

static void BM_LCS(benchmark::State& state) {
    int n = state.range(0);
    auto a = random_vector(n);
    auto b = random_vector(n);
    for (auto _ : state) {
        auto result = bary::longest_common_subsequence(a, b);
        benchmark::DoNotOptimize(result);
    }
    // Сообщаем бенчмарку, что входной размер = n
    state.SetComplexityN(n);
}

// Генерация тестов для разных размеров
BENCHMARK(BM_LCS)
    ->RangeMultiplier(2)
    ->Range(10, 200) // от 10 до 200
    ->Complexity();  // оцениваем асимптотику

BENCHMARK_MAIN();
