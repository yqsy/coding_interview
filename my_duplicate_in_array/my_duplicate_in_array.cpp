// 题目:找出数组中重复的数字

// 时间:O(n),空间:O(n),辅助空间

#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <unordered_set>

#include "gtest/gtest.h"


std::vector<int> FindDuplicateInArray(const std::vector<int>& A) {
    std::unordered_set<int> hash;
    std::vector<int> v;
    for (const auto& n : A) {
        auto rtn = hash.insert(n);
        if (!rtn.second)
            v.push_back(n);
    }
    return v;
}

TEST(FindDuplicateInArrayTest, Mini) {
    auto v = FindDuplicateInArray({ 2, 1, 3, 1, 4 });
    
    EXPECT_EQ(v.size(), 1);
    EXPECT_EQ(v[0], 1);
}

TEST(FindDuplicateInArrayTest, Max) {
    auto v = FindDuplicateInArray({ 2, 4, 3, 1, 4 });

    EXPECT_EQ(v.size(), 1);
    EXPECT_EQ(v[0], 4);
}

TEST(FindDuplicateInArrayTest, Multi) {
    auto v = FindDuplicateInArray({ 2, 4, 2, 1, 4 });

    EXPECT_EQ(v.size(), 2);
    EXPECT_EQ(v[0], 2);
    EXPECT_EQ(v[1], 4);
}

TEST(FindDuplicateInArrayTest, NoDuplicate) {
    auto v = FindDuplicateInArray({ 2, 1, 3, 0, 4 });

    EXPECT_EQ(v.size(), 0);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::FLAGS_gtest_death_test_style = "fast";
    return RUN_ALL_TESTS();
}