// 题目:不修改数组找出重复的数字
// 在一个长度为n + 1的数组里的所有数字都在1到n的范围内，所以数组中至
// 少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
// 数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的
// 输出是重复的数字2或者3。

// 时间:O(nlogn),空间:O(1),不修改数组

#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <vector>

#include "gtest/gtest.h"

size_t BinarySearch(const std::vector<int>& A, int T) {
    size_t L = 0;
    size_t R = A.size() - 1;

    while (L <= R) {
        size_t m = (L + R) / 2;

        if (A[m] < T)
            L = m + 1;

        if (A[m] > T)
            R = m - 1;

        if (A[m] == T)
            return m;
    }
    return -1;
}

TEST(BinarySearchTest, BeginTest) {
    size_t idx = BinarySearch({ 0,1,2,3,4,5,6,7,8,9 }, 0);
    EXPECT_EQ(idx, 0);
}

TEST(BinarySearchTest, MiddleTest) {
    size_t idx = BinarySearch({ 0,1,2,3,4,5,6,7,8,9 }, 4);
    EXPECT_EQ(idx, 4);
}

TEST(BinarySearchTest, EndTest) {
    size_t idx = BinarySearch({ 0,1,2,3,4,5,6,7,8,9 }, 9);
    EXPECT_EQ(idx, 9);
}

TEST(BinarySearchTest, ErrTest) {
    size_t idx = BinarySearch({ 0,1,2,3,4,5,6,7,8,9 }, 10);
    EXPECT_EQ(idx, -1);
}


size_t GetDuplicate(const std::vector<int>& A) {
    size_t L = 1;
    size_t R = A.size() - 1;

    while (L <= R) {
        size_t m = (L + R) / 2;

        int count = 0;
        for (int i = 0; i < A.size(); i++) {
            if (L <= A[i] && A[i] <= m) {
                count++;
            }
        }

        if (L == R) {
            if (count > 1) {
                return L;
            } else {
                break;
            }
        }

        if (count > m - L + 1) {
            R = m;
        } else {
            L = m + 1;
        }
    }

    return -1;
}

TEST(GetDuplicateTest, BeginTest) {
    std::vector<int> v = { 1,1,2,3,4,5,6,7 };

    size_t idx = GetDuplicate(v);
    EXPECT_EQ(v[idx], 1);
}

TEST(GetDuplicateTest, MiddleTest) {
    std::vector<int> v = { 1,2,3,4,4,5,6,7 };

    size_t idx = GetDuplicate(v);
    EXPECT_EQ(v[idx], 4);
}


TEST(GetDuplicateTest, EndTest) {
    std::vector<int> v = { 1,2,3,4,5,6,7,7 };

    size_t idx = GetDuplicate(v);
    EXPECT_EQ(v[idx], 7);
}


int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::FLAGS_gtest_death_test_style = "fast";
    return RUN_ALL_TESTS();
}