/*
Problem description:
Longest Collatz sequence
Problem 14
The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been
proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
page link:
https://projecteuler.net/problem=14
dax 2023/04/23 21:40:15
*/
#include "problem.h"

unsigned Solution::collatz_count(unsigned long start_number)
{
	unsigned count = 0;

	while(true)
	{
		if(start_number < 1) return count;
		else
		{
			count++;

			if(start_number == 1) break;

			start_number = start_number % 2 == 0 ? start_number / 2 : 3 * start_number + 1;
		}
	}

	return count;
}

unsigned long Solution::longest_chain_within(unsigned long range)
{
	unsigned max_count = 0;
	unsigned long the_number;

	for(unsigned long i = 1; i < range; ++i)
	{
		auto count = collatz_count(i);

		if(count > max_count)
		{
			max_count = count;
			the_number = i;
		}
	}

	return the_number;
}



void Solution::answer()
{
	std::cout << "The answer is: " << longest_chain_within(1'000'000) << std::endl;
}
