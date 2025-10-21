#include <gtest/gtest.h>
#include "lcs.hpp"

TEST(LcsTest, EmptySequences) {
  // ... existing code
  std::vector<int> a, b;
  EXPECT_TRUE(bary::longest_common_subsequence(a, b).empty());
}

TEST(LcsTest, OneEmptySequence) {
  // ... existing code
  std::vector<int> a = {1, 2, 3}, b;
  EXPECT_TRUE(bary::longest_common_subsequence(a, b).empty());
}

TEST(LcsTest, FullMatch) {
  // ... existing code
  std::vector<int> a = {1, 2, 3}, b = {1, 2, 3};
  EXPECT_EQ(bary::longest_common_subsequence(a, b), (std::vector<int>{1, 2, 3}));
}

TEST(LcsTest, PartialMatch) {
  // ... existing code
  std::vector<int> a = {1, 2, 3, 4, 5, 6};
  std::vector<int> b = {2, 4, 6, 8, 10, 12};
  EXPECT_EQ(bary::longest_common_subsequence(a, b), (std::vector<int>{2, 4, 6}));
}

TEST(LcsTest, NoCommonElements) {
  // ... existing code
  std::vector<int> a = {1, 2, 3};
  std::vector<int> b = {4, 5, 6};
  EXPECT_TRUE(bary::longest_common_subsequence(a, b).empty());
}

TEST(LcsTest, Interleaved) {
  // ... existing code
  std::vector<int> a = {1, 3, 5, 7, 9};
  std::vector<int> b = {3, 7, 10};
  EXPECT_EQ(bary::longest_common_subsequence(a, b), (std::vector<int>{3, 7}));
}

TEST(LcsTest, LongSequences) {
    std::vector<int> a, b, expected;
    for (int i = 0; i < 200; ++i) {
        a.push_back(i);
        b.push_back(-1); // Вставляем "мусорный" элемент
        b.push_back(i);
        expected.push_back(i);
    }
    EXPECT_EQ(bary::longest_common_subsequence(a, b), expected);
}

TEST(LcsTest, OneIsSubsequence) {
    std::vector<char> a = {'a', 'b', 'c', 'd', 'e'};
    std::vector<char> b;
    for (int i = 0; i < 26; ++i) {
        b.push_back('a' + i);
    }
    EXPECT_EQ(bary::longest_common_subsequence(a, b), a);
}

TEST(LcsTest, LongReversed) {
    std::vector<int> a, b;
    for (int i = 0; i < 100; ++i) {
        a.push_back(i);
        b.push_back(99 - i);
    }
    // LCS для последовательности и её реверса - это один элемент (центральный, если нечетная длина, или любой, если четная)
    // Наш алгоритм найдет последний возможный, то есть a[0] == b[99]
    auto lcs = bary::longest_common_subsequence(a, b);
    EXPECT_EQ(lcs.size(), 1);
}
