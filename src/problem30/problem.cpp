/*
Problem page link:
https://projecteuler.net/problem=30

dax 2024-09-14 11:18:04
*/
#include "problem.h"

Solution::Solution(): digital_powers(10)
{
	for(int i = 0; i < 10; ++i)
	{
		digital_powers[i] = i*i*i*i*i;
	}
}

uint Solution::digital_power_sum(uint n)
{
	uint sum{};

	while(n)
	{
		sum += digital_powers[n % 10];
		n /= 10;
	}

	return sum;
}

void Solution::answer()
{

	uint sum{};

	for(uint i = 2; i < 1e6; ++i)
	{
		if(i == digital_power_sum(i))
			sum += i;
	}

	std::cout << "The answer is: " << sum << std::endl;
}
