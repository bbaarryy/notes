
#include <iostream>
#include <vector>
#include "sparse_table.hpp"

int main() {
    std::vector<int> data = {2, 5, 1, 8, 4, 9, 3, 7};
    
    try {
        bary::SparseTable<int> st(data);

        std::cout << "Data: ";
        for(int x : data) std::cout << x << " ";
        std::cout << std::endl;

        std::cout << "Min in [0, 7]: " << st.query(0, 7) << " (Expected: 1)" << std::endl;
        std::cout << "Min in [2, 5]: " << st.query(2, 5) << " (Expected: 1)" << std::endl;
        std::cout << "Min in [4, 6]: " << st.query(4, 6) << " (Expected: 3)" << std::endl;
        std::cout << "Min in [3, 3]: " << st.query(3, 3) << " (Expected: 8)" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
