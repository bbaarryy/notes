#include <iostream>
#include <vector>
#include "knapsack.hpp"

int main() {
    // Пример данных: предметы с весом и ценностью
    std::vector<bary::Item> items = {
        {10, 60}, 
        {20, 100}, 
        {30, 120}
    };
    int capacity = 50;

    std::cout << "Items available:" << std::endl;
    for (const auto& item : items) {
        std::cout << "  - Weight: " << item.weight << ", Value: " << item.value << std::endl;
    }
    std::cout << "\nKnapsack capacity: " << capacity << std::endl;

    int max_value = bary::knapsack_01(items, capacity);

    std::cout << "\nMaximum value that can be carried: " << max_value << std::endl;
    // Для этих данных оптимально взять предметы {20, 100} и {30, 120},
    // общий вес 50, общая ценность 220.

    return 0;
}