
#include "gtest/gtest.h"
#include "heap.hpp"
#include <vector>
#include <algorithm>

TEST(HeapTest, BasicInsertAndExtract) {
    bary::Heap<int> heap;
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);

    ASSERT_EQ(heap.size(), 3);
    EXPECT_EQ(heap.get_max(), 20);
    EXPECT_EQ(heap.extract_max(), 20);
    EXPECT_EQ(heap.get_max(), 10);
    EXPECT_EQ(heap.extract_max(), 10);
    EXPECT_EQ(heap.get_max(), 5);
    EXPECT_EQ(heap.extract_max(), 5);
    ASSERT_TRUE(heap.is_empty());
}

TEST(HeapTest, SortProperty) {
    bary::Heap<int> heap;
    std::vector<int> values = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    for (int val : values) {
        heap.insert(val);
    }

    std::sort(values.rbegin(), values.rend()); // Сортируем в обратном порядке для сравнения

    for (int sorted_val : values) {
        EXPECT_EQ(heap.extract_max(), sorted_val);
    }
    ASSERT_TRUE(heap.is_empty());
}

TEST(HeapTest, EmptyHeap) {
    bary::Heap<int> heap;
    ASSERT_TRUE(heap.is_empty());
    EXPECT_THROW(heap.get_max(), std::out_of_range);
    EXPECT_THROW(heap.extract_max(), std::out_of_range);
}
