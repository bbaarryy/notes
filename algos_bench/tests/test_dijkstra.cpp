#include <gtest/gtest.h>
#include "dijkstra.hpp"
#include <vector>
#include <limits>

using Graph = std::vector<std::vector<std::pair<int, int>>>;

TEST(DijkstraTest, SimpleGraph) {
    // Граф:
    // 0 --4-- 1
    // | \   / |
    // 1  8 2  7
    // |   \ / |
    // 2 --3-- 3
    Graph graph(4);
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

    auto distances = bary::dijkstra(graph, 0);
    std::vector<int> expected = {0, 4, 1, 4};
    EXPECT_EQ(distances, expected);
}

TEST(DijkstraTest, LinearGraph) {
    // 0 --1--> 1 --2--> 2 --3--> 3
    Graph graph(4);
    graph[0].push_back({1, 1});
    graph[1].push_back({2, 2});
    graph[2].push_back({3, 3});

    auto distances = bary::dijkstra(graph, 0);
    std::vector<int> expected = {0, 1, 3, 6};
    EXPECT_EQ(distances, expected);
}

TEST(DijkstraTest, DisconnectedGraph) {
    Graph graph(5);
    // Компонента 1: 0-1-2
    graph[0].push_back({1, 10});
    graph[1].push_back({0, 10});
    graph[1].push_back({2, 10});
    graph[2].push_back({1, 10});
    // Компонента 2: 3-4
    graph[3].push_back({4, 5});
    graph[4].push_back({3, 5});

    auto distances = bary::dijkstra(graph, 0);
    const int INF = std::numeric_limits<int>::max();
    std::vector<int> expected = {0, 10, 20, INF, INF};
    EXPECT_EQ(distances, expected);
}

TEST(DijkstraTest, NoEdges) {
    Graph graph(3);
    auto distances = bary::dijkstra(graph, 0);
    const int INF = std::numeric_limits<int>::max();
    std::vector<int> expected = {0, INF, INF};
    EXPECT_EQ(distances, expected);
}

TEST(DijkstraTest, EmptyGraph) {
    Graph graph(0);
    auto distances = bary::dijkstra(graph, 0);
    EXPECT_TRUE(distances.empty());
}