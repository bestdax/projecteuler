/*
Problem description:
Smallest multiple

Problem 5
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
page link:
https://projecteuler.net/problem=5

dax 2023-04-23 12:28:57
*/
#include "problem.h"

unsigned long Solution::lcm_of_range(unsigned range)
{
	long lcm{1};

	for(unsigned i = 1; i <= range; ++i)
	{
		lcm = std::lcm(lcm, i);
	}

	return lcm;
}
unsigned long Solution::lcm_of_range2(unsigned range)
{
	long ret{1};

	for(unsigned i = 1; i <= range; ++i)
	{
		ret = lcm(ret, i);
	}

	return ret;
}

unsigned long Solution::lcm(unsigned a, unsigned b)
{
	auto pf_a = dax::prime_factors(a);
	auto pf_b = dax::prime_factors(b);

	for(auto item : pf_a)
	{
		auto it = std::find(pf_b.begin(), pf_b.end(), item);

		if(it != pf_b.end()) pf_b.erase(it);
	}

	unsigned long ret{1};
	ret = std::accumulate(pf_a.begin(), pf_a.end(), ret, [](int x, int y)
	{
		return x * y;
	});
	ret = std::accumulate(pf_b.begin(), pf_b.end(), ret, [](int x, int y)
	{
		return x * y;
	});
	std::cout << ret;
	return ret;
}

void Solution::answer()
{
	std::cout << "The answer is: " << lcm_of_range2(20) << std::endl;
}
