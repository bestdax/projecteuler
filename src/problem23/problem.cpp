/*
Problem page link:
https://projecteuler.net/problem=23

dax 2024-08-07 11:04:36
*/
#include "problem.h"

bool Solution::is_sum_of_two_abundants(unsigned long n)
{
	if(n < 24) return false;
	else
	{
		for(unsigned long i = 12; n - i >= 12; ++i)
		{
			if(dax::is_abundant(i) && dax::is_abundant(n - i))return true;
		}

		return false;
	}
}

void Solution::answer()
{
	unsigned long sum{};

	for(unsigned long i = 1; i <= 28123; ++i)
	{
		if(!is_sum_of_two_abundants(i)) sum += i;
	}

	std::cout << "The answer is: " << sum << std::endl;
}
