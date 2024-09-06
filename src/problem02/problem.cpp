/*
Problem page link:
https://projecteuler.net/problem=2

dax 2024-09-07 05:53:48
*/
#include "problem.h"

unsigned Solution::sum_of_even_fibonacci(unsigned limit)
{
	unsigned a = 1, b = 2, sum = 0;

	while(b <= limit)
	{
		if(b % 2 == 0) sum += b;

		auto temp = a + b;
		a = b;
		b = temp;
	}

	return sum;
}

void Solution::answer()
{
	auto sum = sum_of_even_fibonacci(4'000'000);
	std::cout << "The answer is: " << sum << std::endl;
}
