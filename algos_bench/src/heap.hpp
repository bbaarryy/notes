
#pragma once

#include <vector>
#include <stdexcept>
#include <algorithm>

namespace bary {

/**
 * @brief Реализация бинарной max-кучи (max-heap).
 * 
 * @tparam T Тип хранимых элементов. Должен поддерживать оператор '<'.
 * 
 * @complexity
 *   - `insert`: O(log N)
 *   - `extract_max`: O(log N)
 *   - `get_max`: O(1)
 *   - Память: O(N)
 */
template <typename T>
class Heap {
public:
    void insert(const T& value) {
        data.push_back(value);
        sift_up(data.size() - 1);
    }

    T extract_max() {
        if (is_empty()) {
            throw std::out_of_range("Heap is empty");
        }
        T max_value = data[0];
        data[0] = data.back();
        data.pop_back();
        if (!is_empty()) {
            sift_down(0);
        }
        return max_value;
    }

    const T& get_max() const {
        if (is_empty()) {
            throw std::out_of_range("Heap is empty");
        }
        return data[0];
    }

    bool is_empty() const {
        return data.empty();
    }

    size_t size() const {
        return data.size();
    }

private:
    std::vector<T> data;

    void sift_up(size_t index) {
        if (index == 0) return;
        size_t parent_index = (index - 1) / 2;
        if (data[parent_index] < data[index]) {
            std::swap(data[parent_index], data[index]);
            sift_up(parent_index);
        }
    }

    void sift_down(size_t index) {
        size_t left_child = 2 * index + 1;
        size_t right_child = 2 * index + 2;
        size_t largest = index;

        if (left_child < data.size() && data[largest] < data[left_child]) {
            largest = left_child;
        }
        if (right_child < data.size() && data[largest] < data[right_child]) {
            largest = right_child;
        }

        if (largest != index) {
            std::swap(data[index], data[largest]);
            sift_down(largest);
        }
    }
};

} // namespace bary
