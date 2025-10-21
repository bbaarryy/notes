
#pragma once

#include <vector>
#include <queue>
#include <limits>
#include <utility>

namespace bary {

/**
 * @brief Находит кратчайшие пути от одной вершины до всех остальных в графе с неотрицательными весами рёбер.
 *
 * Алгоритм использует приоритетную очередь для эффективного выбора вершины с наименьшим
 * текущим расстоянием для исследования на каждом шаге.
 *
 * @param graph Граф, представленный списками смежности. `graph[i]` содержит вектор пар `{сосед, вес_ребра}`.
 * @param start_node Начальная вершина для поиска путей.
 * @return std::vector<int> Вектор, где i-й элемент содержит кратчайшее расстояние от `start_node` до вершины `i`.
 *                          Если вершина недостижима, расстояние будет `std::numeric_limits<int>::max()`.
 *
 * @complexity
 * Время: O((E + V) * log V), где V - количество вершин, E - количество рёбер.
 * Память: O(V + E) для хранения графа, расстояний и приоритетной очереди.
 */
std::vector<int> dijkstra(const std::vector<std::vector<std::pair<int, int>>>& graph, int start_node) {
    if (graph.empty() || start_node < 0 || start_node >= graph.size()) {
        return {};
    }

    int num_vertices = graph.size();
    std::vector<int> distances(num_vertices, std::numeric_limits<int>::max());
    distances[start_node] = 0;

    // Приоритетная очередь для хранения {расстояние, вершина}.
    // Используем std::greater для создания min-priority-queue.
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push({0, start_node});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        // Если мы нашли более короткий путь к этой вершине ранее, пропускаем.
        if (d > distances[u]) {
            continue;
        }

        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (distances[u] != std::numeric_limits<int>::max() && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                pq.push({distances[v], v});
            }
        }
    }

    return distances;
}

} // namespace bary
