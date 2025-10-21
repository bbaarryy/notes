#include <benchmark/benchmark.h>
#include "sparse_table.hpp"
#include <vector>
#include <random>

// Утилита для генерации случайных данных
static std::vector<int> generate_data(int n) {
    std::vector<int> data(n);
    std::mt19937 gen(123); // Фиксированный seed для воспроизводимости
    std::uniform_int_distribution<> dis(1, 1000000);
    for (auto& val : data) {
        val = dis(gen);
    }
    return data;
}

// Бенчмарк для построения Sparse Table
static void BM_SparseTableCreation(benchmark::State& state) {
    int n = state.range(0);
    auto data = generate_data(n);

    for (auto _ : state) {
        bary::SparseTable<int> st(data);
        benchmark::DoNotOptimize(st);
    }
    state.SetComplexityN(n);
}

// Бенчмарк для запросов на минимальное значение в диапазоне
static void BM_SparseTableQuery(benchmark::State& state) {
    int n = state.range(0);
    auto data = generate_data(n);
    bary::SparseTable<int> st(data);

    // Генерируем случайные диапазоны для запросов
    std::mt19937 gen(456);
    std::uniform_int_distribution<> dis(0, n - 1);
    
    for (auto _ : state) {
        state.PauseTiming(); // Приостанавливаем таймер для генерации диапазона
        int l = dis(gen);
        int r = dis(gen);
        if (l > r) std::swap(l, r);
        state.ResumeTiming(); // Возобновляем таймер перед запросом

        int result = st.query(l, r);
        benchmark::DoNotOptimize(result);
    }
    state.SetComplexityN(n);
}

// Ожидаемая сложность O(N log N)
BENCHMARK(BM_SparseTableCreation)
    ->RangeMultiplier(2)
    ->Range(8, 8<<10)
    ->Complexity(benchmark::oNLogN);

// Ожидаемая сложность O(1)
BENCHMARK(BM_SparseTableQuery)
    ->RangeMultiplier(2)
    ->Range(8, 8<<10)
    ->Complexity(benchmark::o1);

BENCHMARK_MAIN();
