
#include <iostream>
#include <vector>
#include "heap.hpp"

int main() {
    bary::Heap<int> heap;
    std::vector<int> values = {15, 5, 20, 7, 30, 1};

    std::cout << "Inserting values: ";
    for (int val : values) {
        std::cout << val << " ";
        heap.insert(val);
    }
    std::cout << std::endl;

    std::cout << "Extracting values from heap (sorted): ";
    while (!heap.is_empty()) {
        std::cout << heap.extract_max() << " ";
    }
    std::cout << std::endl;

    return 0;
}
