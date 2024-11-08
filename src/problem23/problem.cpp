/*
Problem page link:
https://projecteuler.net/problem=23

dax 2024-09-11 14:54:18
*/
#include "problem.h"
#include <cmath>

Solution::Solution(): is_abundant(28124, false)
{
	for(int i = 0; i < 28124; ++i)
	{
		if(_is_abundant(i)) is_abundant[i] = true;
	}
}

bool Solution::_is_abundant(uint n)
{
	if(n < 2) return false;

	uint sum{};
	uint root = std::sqrt(n);

	for(uint i = 2; i <= root; ++i)
	{
		if(n % i == 0) sum += i + n / i;
	}

	if(root * root == n) sum -= root;

	return ++sum > n;

}

bool Solution::is_sum_of_two_abundants(uint n)
{
	if(n < 24) return false;
	else
	{
		auto middle = n / 2;

		for(ulong i = 12; i <= middle; ++i)
		{
			if(is_abundant[i] && is_abundant[n - i])return true;
		}

		return false;
	}
}

void Solution::answer()
{
	ulong sum{};

	for(ulong i = 1; i <= 28123; ++i)
	{
		if(!is_sum_of_two_abundants(i)) sum += i;
	}

	std::cout << "The answer is: " << sum << std::endl;
}
