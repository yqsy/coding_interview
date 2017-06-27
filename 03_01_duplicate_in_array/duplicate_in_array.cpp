// ��Ŀ:�ҳ��������ظ�������
// ��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�
// Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡����磬������볤��Ϊ7������{2, 3, 1, 0, 2, 5, 3}��
// ��ô��Ӧ��������ظ�������2����3��

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

// �ظ�����������������С������
TEST(FindDuplicateInArrayTest, DuplicateMiniNumber) {
    int numbers[] = { 2, 1, 3, 1, 4 };
    int duplicate = 0;
    FindDuplicateInArray(numbers, _countof(numbers), &duplicate);

    EXPECT_EQ(duplicate, 1);
}

// �ظ�����������������������
TEST(FindDuplicateInArrayTest, DuplicateMaxNumber) {
    int numbers[] = { 2, 4, 3, 1, 4 };
    int duplicate = 0;
    FindDuplicateInArray(numbers, _countof(numbers), &duplicate);

    EXPECT_EQ(duplicate, 4);
}

// �����д��ڶ���ظ�������
TEST(FindDuplicateInArrayTest, DuplicateMultiNumber) {
    int numbers[] = { 2, 4, 2, 1, 4 };
    int duplicate = 0;
    FindDuplicateInArray(numbers, _countof(numbers), &duplicate);

    int duplications[] = { 2, 4 };
    bool finded = std::find(std::begin(duplications),
        std::end(duplications), duplicate) != std::end(duplications);
    EXPECT_EQ(finded, true);
}

// û���ظ�������
TEST(FindDuplicateInArrayTest, NoDuplicateNumber) {
    int numbers[] = { 2, 1, 3, 0, 4 };
    int duplicate = 0;
    
    bool finded = FindDuplicateInArray(numbers, _countof(numbers), &duplicate);

    EXPECT_EQ(finded, false);
}

// ��Ч������
TEST(FindDuplicateInArrayTest, legalInput) {
    int* numbers = nullptr;
    int duplicate = 0;

    bool finded = FindDuplicateInArray(numbers, 0, &duplicate);

    EXPECT_EQ(finded, false);
}

// ���ֳ�����Χ
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