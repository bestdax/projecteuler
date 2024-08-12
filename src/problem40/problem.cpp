/*
Problem page link:
https://projecteuler.net/problem=40

dax 2024-08-12 10:38:51
*/
#include "problem.h"
#include <cmath>

unsigned Solution::nth_digit(unsigned long n)
{
	// 如果小于10，直接返回原来的数字即可
	if(n < 10) return n;

	unsigned level{};

	// 循环减去 9 x 1，90 x 2， 900 x 3 ...
	while(n > 9 * std::pow(10, level) * (level + 1))
	{
		n -= 9 * std::pow(10, level) * (level + 1);
		++level;
	}

	// 余下的位数除以数字的宽度，再加上前面所有的数就求出了当前的数字
	unsigned long number = long(std::pow(10, level)) + n / (level + 1);

	// 将求得的数字转化为字符串，取出对应的数字位
	// 注意，如果是10的话，最后应该是余1，这个应该对应的是第一位，所以要将位次前移1位
	return std::to_string(number)[n % (level + 1) - 1] - 48;
}

void Solution::answer()
{
	std::cout << "The answer is: " << nth_digit(1) * nth_digit(10) * nth_digit(100)* nth_digit(1000)* nth_digit(
	              10000)* nth_digit(100000)* nth_digit(1000000) << std::endl;
}
