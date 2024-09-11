/*
Problem page link:
https://projecteuler.net/problem=21

dax 2024-09-11 11:39:05
*/
#include "problem.h"
#include <cmath>

unsigned long  Solution::sum_of_proper_divisors(unsigned long n)
{
	unsigned long sum{};
	unsigned long root = std::sqrt(n);

	for(unsigned long i = 2; i <= root; ++i)
	{
		if(n % i == 0) sum += i + n / i;

	}

	if(root * root == n) sum -= root;

	return ++sum;
}

void Solution::answer()
{
	unsigned long sum{};

	for(unsigned long a = 2; a < 1e4; ++a)
	{
		auto b = sum_of_proper_divisors(a);

		if(sum_of_proper_divisors(b) == a && a != b && b < 1e4)
			sum += a;
	}

	std::cout << "The answer is: " << sum << std::endl;
}
