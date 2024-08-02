/*
Problem page link:
https://projecteuler.net/problem=16

dax 2024-08-02 23:24:09
*/
#include "problem.h"

void Solution::answer()
{
	char carry{};

	for(int i = 1; i < 1000; ++i)
	{
		// 计算数字的长度
		auto size = digits.size();

		for(int j = 0; j < size; ++j)
		{
			// 对每个数字乘以２
			digits[j] *= 2;

			// 如果有进位就加上进位
			if(carry) digits[j] += carry;

			// 最后计算进位的值，以及余下的单个数字
			carry = digits[j] / 10;
			digits[j] %= 10;
		}

		// 一轮结束后，如果最后有进位，则增加一个数位
		if(carry)
		{
			digits.push_back(carry);
			carry = 0;
		}
	}

	unsigned digits_sum{};

	for(auto d : digits)
		digits_sum += d;

	std::cout << "The answer is: " << digits_sum << std::endl;
}
