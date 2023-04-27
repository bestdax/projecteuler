/*
Problem description:
Power digit sum
Problem 16
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?
page link:
https://projecteuler.net/problem=16

dax 2023-04-27 14:05:10
*/
#include "problem.h"

lint Solution::power_digit_sum()
{
	return lint(2).power(1000).digit_sum();
}

void Solution::answer()
{
	std::cout << "The answer is: " << power_digit_sum() << std::endl;
}
