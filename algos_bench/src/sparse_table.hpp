
#pragma once

#include <vector>
#include <cmath>
#include <algorithm>
#include <stdexcept>

namespace bary {

/**
 * @brief Структура данных "Разреженная таблица" для быстрых запросов на отрезке.
 * 
 * Позволяет находить минимум (или выполнять другую идемпотентную операцию)
 * на любом отрезке массива за O(1) после предобработки за O(N log N).
 * 
 * @tparam T Тип хранимых элементов.
 * 
 * @complexity
 * Построение:
 *   - Время: O(N log N)
 *   - Память: O(N log N)
 * Запрос (query):
 *   - Время: O(1)
 */
template <typename T>
class SparseTable {
public:
    // Конструктор, который строит sparse table из вектора
    SparseTable(const std::vector<T>& arr) {
        if (arr.empty()) {
            return;
        }
        n = arr.size();
        int max_log = std::log2(n) + 1;
        st.assign(n, std::vector<T>(max_log));
        log_table.assign(n + 1, 0);

        // Предварительно вычисляем логарифмы для O(1) запросов
        for (int i = 2; i <= n; i++) {
            log_table[i] = log_table[i / 2] + 1;
        }

        // Базовый случай: длина отрезка 2^0 = 1
        for (int i = 0; i < n; i++) {
            st[i][0] = arr[i];
        }

        // Построение таблицы
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; (i + (1 << j)) <= n; i++) {
                st[i][j] = std::min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    // Запрос минимума на отрезке [l, r] (включительно)
    T query(int l, int r) const {
        if (l > r || l < 0 || r >= n) {
            throw std::out_of_range("Query range is out of bounds.");
        }
        int j = log_table[r - l + 1];
        return std::min(st[l][j], st[r - (1 << j) + 1][j]);
    }

private:
    int n = 0;
    std::vector<std::vector<T>> st;
    std::vector<int> log_table;
};

} // namespace bary
