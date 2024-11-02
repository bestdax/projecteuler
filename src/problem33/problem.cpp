/*
Problem page link:
https://projecteuler.net/problem=33

dax 2024-09-14 14:30:04
*/
#include "problem.h"
#include <numeric>

void Solution::answer()
{
    uint numerator_product = 1;
    uint denominator_product = 1;

    for (int numerator = 10; numerator < 99; ++numerator) {
        for (int denominator = numerator + 1; denominator < 100; ++denominator) {

            // 拆分分子和分母的个位与十位
            int num_units = numerator % 10;
            int num_tens = numerator / 10;
            int denom_units = denominator % 10;
            int denom_tens = denominator / 10;

            // 排除无效情况：分子的个位和十位等于分母的个位和十位
            if (num_units == denom_units || num_tens == denom_tens) continue;

            // 检查是否可以简化分数，且保持值不变
            if (num_units != 0 && denom_units != 0) {
                // 检查分子的个位与分母的十位
                if (num_units == denom_tens && num_tens * denominator == denom_units * numerator) {
                    numerator_product *= num_tens;
                    denominator_product *= denom_units;
                }

                // 检查分子的十位与分母的个位
                if (num_tens == denom_units && num_units * denominator == denom_tens * numerator) {
                    numerator_product *= num_units;
                    denominator_product *= denom_tens;
                }
            }
        }
    }

    // 输出最终结果
    std::cout << "The answer is: " << denominator_product / std::gcd(denominator_product, numerator_product) << std::endl;
}

