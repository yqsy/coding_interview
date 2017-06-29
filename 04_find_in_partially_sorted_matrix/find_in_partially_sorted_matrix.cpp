// 题目:二维数组中的查找
// 时间:O(?),空间O(n)

#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <vector>

#include "gtest/gtest.h"

bool FindInPartiallySortedMatrix(const std::vector<std::vector<int>>& v, int T) {
    if (v.size() < 1 || T <= 0)
        return false;

    if (v[0].size() < 1)
        return false;

    size_t row_idx = 0;
    size_t column_idx = v[0].size() - 1;

    while (row_idx < v.size() && column_idx >= 0) {
        const std::vector<int>& row = v[row_idx];

        if (T == row[column_idx])
            return true;

        if (T < row[column_idx])
            --column_idx;

        if (T > row[column_idx])
            ++row_idx;
    }
    return false;
}

TEST(FindInPartiallySortedMatrixTest, FINDED) {
    std::vector<std::vector<int>> v{
        { 1, 2, 8, 9 },
        { 2, 4, 9, 12 },
        { 4, 7, 10, 13 },
        { 6, 8, 11, 15 }
    };

    EXPECT_EQ(FindInPartiallySortedMatrix(v, 7), true);
}


TEST(FindInPartiallySortedMatrixTest, UNFINDED) {
    std::vector<std::vector<int>> v{
        { 1, 2, 8, 9 },
        { 2, 4, 9, 12 },
        { 4, 7, 10, 13 },
        { 6, 8, 11, 15 }
    };

    EXPECT_EQ(FindInPartiallySortedMatrix(v, 16), false);
}

TEST(FindInPartiallySortedMatrixTest, TWOUNFINDED) {
    std::vector<std::vector<int>> v{
        { 1, 2}
    };

    EXPECT_EQ(FindInPartiallySortedMatrix(v, 3), false);
}

TEST(FindInPartiallySortedMatrixTest, TWOFINDED) {
    std::vector<std::vector<int>> v{
        { 1, 2 }
    };

    EXPECT_EQ(FindInPartiallySortedMatrix(v, 1), true);
}

TEST(FindInPartiallySortedMatrixTest, ZERO) {
    std::vector<std::vector<int>> v{
        {}
    };

    EXPECT_EQ(FindInPartiallySortedMatrix(v, 1), false);
}


int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::FLAGS_gtest_death_test_style = "fast";
    return RUN_ALL_TESTS();
}