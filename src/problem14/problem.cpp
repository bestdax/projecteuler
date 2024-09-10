/*
Problem page link:
https://projecteuler.net/problem=14

dax 2024-09-10 12:03:08
*/
#include "problem.h"

unsigned Solution::collatz_length(unsigned long n)
{
	unsigned l{1};

	while(n != 1)
	{
		if(n % 2 == 0) n /= 2;
		else n = 3 * n + 1;

		++l;
	}

	return l;
}

void Solution::answer()
{
	unsigned max_length {};
	unsigned number{};
	for(unsigned i = 1; i < 1e6; ++i)
	{
		auto l = collatz_length(i);
		if(l > max_length)
		{
			max_length = l;
			number = i;
		}
	}
	std::cout << "The answer is: " << number << std::endl;
}
