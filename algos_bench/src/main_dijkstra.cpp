
#include <iostream>
#include <vector>
#include <limits>
#include "dijkstra.hpp"

// Для удобства определим тип графа
using Graph = std::vector<std::vector<std::pair<int, int>>>;

int main() {
    // Создадим граф, как в тесте
    // 0 --4-- 1
    // | \   / |
    // 1  8 2  7
    // |   \ / |
    // 2 --3-- 3
    int num_vertices = 4;
    Graph graph(num_vertices);
    graph[0].push_back({1, 4});
    graph[0].push_back({2, 1});
    graph[1].push_back({0, 4});
    graph[1].push_back({2, 8});
    graph[1].push_back({3, 7});
    graph[2].push_back({0, 1});
    graph[2].push_back({1, 8});
    graph[2].push_back({3, 3});
    graph[3].push_back({1, 7});
    graph[3].push_back({2, 3});

    int start_node = 0;
    std::vector<int> distances = bary::dijkstra(graph, start_node);

    std::cout << "Shortest distances from node " << start_node << ":" << std::endl;
    for (int i = 0; i < distances.size(); ++i) {
        std::cout << "To node " << i << ": ";
        if (distances[i] == std::numeric_limits<int>::max()) {
            std::cout << "unreachable" << std::endl;
        } else {
            std::cout << distances[i] << std::endl;
        }
    }

    return 0;
}
