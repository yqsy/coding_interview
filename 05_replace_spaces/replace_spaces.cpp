// 题目:替换空格
// 时间:O(n),空间:O(1)

#include <algorithm>
#include <stdlib.h>
#include <iostream>


#include "gtest/gtest.h"

// 时间:O(n2)
std::string MyReplaceAll(std::string str, 
    const std::string& from, const std::string& to) {
    size_t pos = 0;
    while ((pos = str.find(from, pos)) != std::string::npos) {
        str.replace(pos, from.length(), to);
        pos += to.length();
    }
    return str;
}

std::string ReplaceBlank(const char* str, const char* to) {


    return "";
}


int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::FLAGS_gtest_death_test_style = "fast";
    return RUN_ALL_TESTS();
}