/*
Problem page link:
https://projecteuler.net/problem=34

dax 2024-08-11 05:33:47
*/
#include "problem.h"

unsigned long Solution::factorial(unsigned n)
{
	unsigned long f{1};

	while(n)
	{
		f *= n--;
	}

	return f;
}

void Solution::answer()
{

	unsigned long curious_number_sum{};
	for(int i = 3; i < 1e6; ++i)
	{
		unsigned long digit_factorial_sum{};
		auto temp = i;

		while(temp)
		{
			digit_factorial_sum += factorial(temp % 10);
			temp /= 10;
		}

		if(digit_factorial_sum == i)
			curious_number_sum += i;

	}

	std::cout << "The answer is: " << curious_number_sum << std::endl;
}
