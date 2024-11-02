/*
Problem page link:
https://projecteuler.net/problem=6

dax 2024-09-09 15:51:28
*/
#include "problem.h"

ulong Solution::sum_square_difference(uint n)
{
	ulong sum = n * (n + 1) / 2;
	ulong square_of_sum = sum * sum;

	ulong sum_of_square{};

	for(uint i = 1; i <= n; ++i)
		sum_of_square += i * i;

	return square_of_sum - sum_of_square;
}

void Solution::answer()
{
	std::cout << "The answer is: " << sum_square_difference(100) << std::endl;
}
