#include <gtest/gtest.h>
#include "knapsack.hpp"

using namespace bary;

TEST(KnapsackTest, EmptyItems) {
    std::vector<Item> items = {};
    EXPECT_EQ(knapsack_01(items, 100), 0);
}

TEST(KnapsackTest, ZeroCapacity) {
    std::vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};
    EXPECT_EQ(knapsack_01(items, 0), 0);
}

TEST(KnapsackTest, BasicCase) {
    std::vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};
    int capacity = 50;
    // Оптимально взять предметы с весом 20 и 30 (ценность 100 + 120 = 220)
    EXPECT_EQ(knapsack_01(items, capacity), 220);
}

TEST(KnapsackTest, AllItemsFit) {
    std::vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};
    int capacity = 60;
    // Все предметы помещаются, общая ценность 60 + 100 + 120 = 280
    EXPECT_EQ(knapsack_01(items, capacity), 280);
}

TEST(KnapsackTest, NoItemsFit) {
    std::vector<Item> items = {{10, 60}, {20, 100}};
    int capacity = 5;
    EXPECT_EQ(knapsack_01(items, capacity), 0);
}

TEST(KnapsackTest, ComplexCase) {
    std::vector<Item> items = {
        {5, 10}, {4, 40}, {6, 30}, {3, 50}
    };
    int capacity = 10;
    // Оптимально взять предметы {4, 40} и {3, 50}. Вес 7, ценность 90.
    EXPECT_EQ(knapsack_01(items, capacity), 90);
}
