/*
Problem page link:
https://projecteuler.net/problem=21

dax 2024-08-04 16:42:00
*/
#include "problem.h"

std::vector<unsigned long> Solution::proper_factors(unsigned long n)
{
	std::vector<unsigned long> factors;
	auto half = n / 2;

	for(unsigned long i = 1; i <= half; ++i)
	{
		if(n % i == 0) factors.push_back(i);
	}

	return factors;
}

bool Solution::is_amicable(unsigned long n)
{
	auto factors = proper_factors(n);
	auto sum_of_factors = std::accumulate(factors.begin(), factors.end(), 0);
	factors = proper_factors(sum_of_factors);

	if(std::accumulate(factors.begin(), factors.end(), 0) == n && sum_of_factors != n)
	{

		amicables.push_back(n);

		amicables.push_back(sum_of_factors);

		return true;
	}

	else return false;
}

void Solution::answer()
{
	for(unsigned long i = 2; i < 1'0000; ++i)
	{
		auto it = std::find(amicables.begin(), amicables.end(), i);

		if(it == amicables.end()) is_amicable(i);
	}

	std::cout << "The answer is: " << std::accumulate(amicables.begin(), amicables.end(), 0UL) << std::endl;
}
