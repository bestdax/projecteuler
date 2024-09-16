/*
Problem page link:
https://projecteuler.net/problem=34

dax 2024-09-16 09:12:37
*/
#include "problem.h"
#include <numutils.h>
#include <vector>

void Solution::answer()
{
	unsigned long sum{};

	std::vector<unsigned> factorials(10);

	for(int i = 0; i < 10; ++i)
	{
		factorials[i] = dax::factorial(i);
	}

	unsigned limit = 7 * factorials[9];

	for(unsigned long i = 3; i <= limit; ++i)
	{
		unsigned long n = i;
		unsigned digital_factorial_sum {};

		while(n)
		{
			digital_factorial_sum += factorials[n % 10];
			n /= 10;
		}

		if(digital_factorial_sum == i) sum += i;

	}

	std::cout << "The answer is: " << sum << std::endl;
}
