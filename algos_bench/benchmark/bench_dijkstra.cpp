
#include <benchmark/benchmark.h>
#include "dijkstra.hpp"
#include <vector>
#include <random>

using Graph = std::vector<std::vector<std::pair<int, int>>>;

// Утилита для генерации случайного графа
static Graph generate_random_graph(int num_vertices, int num_edges) {
    Graph graph(num_vertices);
    if (num_vertices == 0) {
        return graph;
    }

    std::mt19937 gen(123); // Фиксированный seed для воспроизводимости
    std::uniform_int_distribution<> vertex_dist(0, num_vertices - 1);
    std::uniform_int_distribution<> weight_dist(1, 100);

    // Гарантируем связность графа, создав путь, проходящий через все вершины
    for (int i = 0; i < num_vertices - 1; ++i) {
        int weight = weight_dist(gen);
        graph[i].push_back({i + 1, weight});
        graph[i + 1].push_back({i, weight}); // Для неориентированного графа
    }
    int edges_count = num_vertices - 1;

    // Добавляем оставшиеся рёбра случайным образом
    while (edges_count < num_edges && num_vertices > 1) {
        int u = vertex_dist(gen);
        int v = vertex_dist(gen);
        if (u != v) {
            int weight = weight_dist(gen);
            graph[u].push_back({v, weight});
            graph[v].push_back({u, weight});
            edges_count++;
        }
    }
    return graph;
}

static void BM_Dijkstra(benchmark::State& state) {
    int num_vertices = state.range(0);
    // Создаем разреженный граф, где количество рёбер пропорционально количеству вершин
    int num_edges = num_vertices * 4;
    auto graph = generate_random_graph(num_vertices, num_edges);
    int start_node = 0;

    for (auto _ : state) {
        auto result = bary::dijkstra(graph, start_node);
        benchmark::DoNotOptimize(result);
    }
    // Сложность O((E+V)logV). Так как E ~ V, это примерно O(V log V).
    state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_Dijkstra)
    ->RangeMultiplier(2)
    ->Range(64, 8 << 7) // от 64 до 1024 вершин
    ->Complexity();

BENCHMARK_MAIN();
