/*
Problem page link:
https://projecteuler.net/problem=14

dax 2024-08-02 21:27:05
*/
#include "problem.h"
#include <sys/types.h>

unsigned Solution::count_terms_of_collaz_seq(unsigned long n)
{
	unsigned count = 1;

	while(n != 1)
	{
		if(n % 2 == 0) n /= 2;
		else
			n = 3 * n + 1;

		++count;
	}

	return count;
}

void Solution::answer()
{
	unsigned max = 1;
	unsigned start_number{};

	for(unsigned i = 1; i < 1e6; ++i)
	{
		auto count = count_terms_of_collaz_seq(i);

		if(count > max)
		{
			max = count;
			start_number = i;
		}
	}

	std::cout << "The answer is: " << start_number << ' ' << max << std::endl;
}
