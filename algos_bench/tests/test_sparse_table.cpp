
#include <gtest/gtest.h>
#include "sparse_table.hpp"
#include <vector>
#include <algorithm>

TEST(SparseTableTest, BasicQueries) {
    std::vector<int> data = {2, 5, 1, 8, 4, 9, 3, 7};
    bary::SparseTable<int> st(data);

    EXPECT_EQ(st.query(0, 7), 1);
    EXPECT_EQ(st.query(2, 5), 1);
    EXPECT_EQ(st.query(4, 6), 3);
    EXPECT_EQ(st.query(3, 3), 8);
    EXPECT_EQ(st.query(0, 2), 1);
}

TEST(SparseTableTest, EdgeCases) {
    std::vector<int> data = {10};
    bary::SparseTable<int> st(data);
    EXPECT_EQ(st.query(0, 0), 10);

    std::vector<int> data2 = {5, 5, 5, 5};
    bary::SparseTable<int> st2(data2);
    EXPECT_EQ(st2.query(0, 3), 5);
    EXPECT_EQ(st2.query(1, 2), 5);
}

TEST(SparseTableTest, ThrowsOnInvalidRange) {
    std::vector<int> data = {1, 2, 3};
    bary::SparseTable<int> st(data);

    EXPECT_THROW(st.query(-1, 1), std::out_of_range);
    EXPECT_THROW(st.query(0, 3), std::out_of_range);
    EXPECT_THROW(st.query(2, 1), std::out_of_range);
}

TEST(SparseTableTest, EmptyInput) {
    std::vector<int> data = {};
    bary::SparseTable<int> st(data);
    // Просто проверяем, что конструктор не падает
    SUCCEED();
}
