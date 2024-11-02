/*
Problem page link:
https://projecteuler.net/problem=32

dax 2024-09-14 12:55:07
*/
#include "problem.h"
#include <algorithm>
#include <unordered_set>
#include <numeric>
#include <vector>

void Solution::answer()
{
    uint total_sum = 0;
    std::string digits = "123456789";
    std::unordered_set<uint> unique_products;
    
    // 可能的分割模式：{乘数1长度, 乘数2长度, 积的长度}
    std::vector<std::vector<uint>> split_patterns = {
        {1, 4, 4},  // 1位乘数 和 4位乘数 得到 4位乘积
        {2, 3, 4}   // 2位乘数 和 3位乘数 得到 4位乘积
    };

    do {
        for (const auto& pattern : split_patterns)
        {
            uint pos = 0;
            std::vector<uint> numbers;

            // 根据分割模式提取乘数和积
            for (uint i = 0; i < pattern.size(); ++i)
            {
                // 提取对应长度的数字片段并转换为无符号整数
                numbers.push_back(std::stoul(digits.substr(pos, pattern[i])));
                pos += pattern[i];
            }

            // 检查乘法条件是否成立
            if (numbers[0] * numbers[1] == numbers[2])
            {
                unique_products.insert(numbers[2]); // 只保存唯一的积
            }
        }

    } while (std::next_permutation(digits.begin(), digits.end()));

    // 计算所有唯一积的总和
    total_sum = std::accumulate(unique_products.begin(), unique_products.end(), 0);

    std::cout << "The answer is: " << total_sum << std::endl;
}

