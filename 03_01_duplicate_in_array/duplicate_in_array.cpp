// 题目:找出数组中重复的数字
// 在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。

#include <algorithm>
#include <stdlib.h>
#include <iostream>

#include "gtest/gtest.h"

// [0]
// {2, 3, 1, 0, 2, 5 ,3}
// {1, 3, 2, 0, 2, 5, 3}
// {3, 1, 2, 0, 2, 5, 3}
// {0, 1, 2, 3, 2, 5, 3}

// [1]
// {0, 1, 2, 3, 2, 5, 3}

// [2]
// {0, 1, 2, 3, 2, 5, 3}

// [3]
// {0, 1, 2, 3, 2, 5, 3}

// [4]
// if [4] == array[[4]]
//    *duplicate = array[4]

bool FindDuplicateInArray(int array[], int len, int* duplicate) {
    if (array == nullptr || len <= 0)
        return false;

    for (int i = 0; i < len; i++) {
        if (array[i] < 0 || array[i] > len - 1) {
            return false;
        }
    }

    for (int i = 0; i < len; i++) {
        while (array[i] != i) {
            if (array[i] == array[array[i]]) {
                *duplicate = array[i];
                return true;
            }
            std::swap(array[i], array[array[i]]);
        }
    }
    return false;
}

// 重复的数字是数组中最小的数字
TEST(FindDuplicateInArrayTest, DuplicateMiniNumber) {
    int numbers[] = { 2, 1, 3, 1, 4 };
    int duplicate = 0;
    FindDuplicateInArray(numbers, _countof(numbers), &duplicate);

    EXPECT_EQ(duplicate, 1);
}

// 重复的数字是数组中最大的数字
TEST(FindDuplicateInArrayTest, DuplicateMaxNumber) {
    int numbers[] = { 2, 4, 3, 1, 4 };
    int duplicate = 0;
    FindDuplicateInArray(numbers, _countof(numbers), &duplicate);

    EXPECT_EQ(duplicate, 4);
}

// 数组中存在多个重复的数字
TEST(FindDuplicateInArrayTest, DuplicateMultiNumber) {
    int numbers[] = { 2, 4, 2, 1, 4 };
    int duplicate = 0;
    FindDuplicateInArray(numbers, _countof(numbers), &duplicate);

    int duplications[] = { 2, 4 };
    bool finded = std::find(std::begin(duplications),
        std::end(duplications), duplicate) != std::end(duplications);
    EXPECT_EQ(finded, true);
}

// 没有重复的数字
TEST(FindDuplicateInArrayTest, NoDuplicateNumber) {
    int numbers[] = { 2, 1, 3, 0, 4 };
    int duplicate = 0;
    
    bool finded = FindDuplicateInArray(numbers, _countof(numbers), &duplicate);

    EXPECT_EQ(finded, false);
}

// 无效的输入
TEST(FindDuplicateInArrayTest, legalInput) {
    int* numbers = nullptr;
    int duplicate = 0;

    bool finded = FindDuplicateInArray(numbers, 0, &duplicate);

    EXPECT_EQ(finded, false);
}

// 数字超出范围
TEST(FindDuplicateInArrayTest, OutRange) {
    int numbers[] = { 2, 1, 3, 0, 5 };
    int duplicate = 0;

    bool finded = FindDuplicateInArray(numbers, _countof(numbers), &duplicate);

    EXPECT_EQ(finded, false);
}


int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::FLAGS_gtest_death_test_style = "fast";
    return RUN_ALL_TESTS();
}