#include <iostream>
#include <vector>
#include <string>

#include "lcs.hpp"

int main() {
    std::vector<int> x = {1, 2, 3, 4, 5};
    std::vector<int> y = {2, 4, 5, 6};

    auto lcs_int = bary::longest_common_subsequence(x, y);
    for (int v : lcs_int) std::cout << v << " ";
    std::cout << "\n";

    std::vector<std::string> s1 = {"a", "b", "c", "d"};
    std::vector<std::string> s2 = {"b", "d", "e"};

    auto lcs_str = bary::longest_common_subsequence(s1, s2);
    for (auto& v : lcs_str) std::cout << v << " ";
    std::cout << "\n";

    return 0;
}
