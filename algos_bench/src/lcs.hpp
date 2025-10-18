#pragma once

#include <vector>
#include <algorithm>

#include "lcs.hpp"

namespace bary
{
    /**
     * @brief Находит наибольшую общую подпоследовательность (LCS) для двух последовательностей.
     * 
     * Алгоритм использует динамическое программирование для построения таблицы,
     * хранящей длины LCS для всех префиксов исходных последовательностей.
     * 
     * @tparam T Тип элементов в последовательностях.
     * @param a Первая последовательность.
     * @param b Вторая последовательность.
     * @return std::vector<T> Наибольшая общая подпоследовательность.
     * 
     * @complexity
     * Время: O(N * M), где N и M - длины последовательностей a и b.
     * Память: O(N * M) для хранения таблицы DP.
     */
    template <typename T>
    std::vector<T> longest_common_subsequence(const std::vector<T> &a, const std::vector<T> &b)
    {        size_t n = a.size(), m = b.size();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

        // Построение таблицы DP
        for (size_t i = 1; i <= n; ++i)
        {
            for (size_t j = 1; j <= m; ++j)
            {
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // Восстановление LCS
        std::vector<T> lcs;
        size_t i = n, j = m;
        while (i > 0 && j > 0)
        {
            if (a[i - 1] == b[j - 1])
            {
                lcs.push_back(a[i - 1]);
                --i;
                --j;
            }
            else if (dp[i - 1][j] >= dp[i][j - 1])
            {
                --i;
            }
            else
            {
                --j;
            }
        }
        std::reverse(lcs.begin(), lcs.end());
        return lcs;
    }
}