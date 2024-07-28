/*
Problem page link:
https://projecteuler.net/problem=2

dax 2024-07-28 08:55:39
*/
#include "problem.h"

unsigned long Solution::next_fib()
{
	long next = first + second;
	first = second;
	second = next;
	return next;
}

unsigned long Solution::sum_of_even_fibs(unsigned long cap)
{
	if(cap == 1) return 0;

	unsigned long sum{2};

	while(next_fib() <= cap)
	{
		if(second % 2 == 0)
		{
			sum +=  second;
		}
	}

	return sum;
}

void Solution::answer()
{
	std::cout << "The answer is: " << sum_of_even_fibs(4'000'000) << std::endl;
}
