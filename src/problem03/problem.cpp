/*
Problem description:
Largest prime factor
Problem 3
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
page link:
https://projecteuler.net/problem=3

dax 2023-04-21 12:52:04

*/

#include "problem.h"

bool Solution::is_prime(long number)
{
	if(number < 2) return false;

	int root = std::round(std::sqrt(number));

	for(int i = 2; i <= root; i++)
	{
		if(number % i == 0) return false;
	}

	return true;
}

std::vector<int> Solution::prime_factors(long number)
{
	std::vector<int> pf{};

	if(number < 2) return pf;

	for(int i = 2; i <= number; ++i)
	{
		if(is_prime(i) && number % i == 0)
		{
			pf.push_back(i);
			number /= i;
			i = 2;
		}
	}

	return pf;
}

int Solution::largest_prime_factor(long number)
{
	auto pf = prime_factors(number);
	return *(pf.end() - 1);
}

void Solution::answer()
{
	std::cout << "The answer is: " << largest_prime_factor(600'851'475'143) << std::endl;
}
