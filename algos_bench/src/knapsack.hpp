
#pragma once

#include <vector>
#include <algorithm>

namespace bary
{
    // Структура для представления предмета
    struct Item {
        int weight;
        int value;
    };

    /**
     * @brief Решает задачу о рюкзаке 0-1.
     * 
     * Дано множество предметов, каждый из которых имеет вес и ценность.
     * Необходимо определить набор предметов, который можно унести в рюкзаке
     * с ограниченной вместимостью, чтобы их суммарная ценность была максимальной.
     * 
     * @param items Вектор предметов (вес и ценность).
     * @param capacity Вместимость рюкзака.
     * @return int Максимальная суммарная ценность.
     * 
     * @complexity
     * Время: O(N * W), где N - количество предметов, W - вместимость рюкзака.
     * Память: O(N * W) для хранения таблицы DP.
     */
    int knapsack_01(const std::vector<Item>& items, int capacity) {
        if (capacity < 0) {
            return 0;
        }
        
        size_t n = items.size();
        // dp[w] будет хранить максимальную ценность для рюкзака вместимостью w
        std::vector<int> dp(capacity + 1, 0);

        // Идем по каждому предмету
        for (size_t i = 0; i < n; ++i) {
            // Идем по всем возможным вместимостям рюкзака в обратном порядке
            // Обратный порядок нужен, чтобы не использовать один и тот же предмет дважды в одной итерации
            for (int w = capacity; w >= items[i].weight; --w) {
                // Выбираем: либо не брать предмет (dp[w] остается прежним),
                // либо взять его (dp[w - items[i].weight] + items[i].value)
                dp[w] = std::max(dp[w], dp[w - items[i].weight] + items[i].value);
            }
        }

        return dp[capacity];
    }
}
