#include <benchmark/benchmark.h>
#include <vector>
#include <cstdlib>
#include "knapsack.hpp"

// Функция для генерации случайного набора предметов
static std::vector<bary::Item> random_items(int n) {
    std::vector<bary::Item> items;
    items.reserve(n);
    for (int i = 0; i < n; ++i) {
        items.push_back({
            .weight = 1 + (rand() % 100), // Вес от 1 до 100
            .value = 1 + (rand() % 1000) // Ценность от 1 до 1000
        });
    }
    return items;
}

static void BM_Knapsack(benchmark::State& state) {
    int num_items = state.range(0);
    auto items = random_items(num_items);
    // Вместимость рюкзака, пропорциональная количеству предметов
    int capacity = num_items * 20;

    for (auto _ : state) {
        int result = bary::knapsack_01(items, capacity);
        benchmark::DoNotOptimize(result);
    }
    // Сложность O(N*W), где N - кол-во предметов, W - вместимость
    state.SetComplexityN(num_items);
}

BENCHMARK(BM_Knapsack)
    ->RangeMultiplier(2)
    ->Range(8, 512) // От 8 до 512 предметов
    ->Complexity(benchmark::oNSquared); // Приближенно, т.к. W растет с N

BENCHMARK_MAIN();