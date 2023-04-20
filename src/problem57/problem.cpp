/*
Problem description:

page link:
https://projecteuler.net/problem=

dax 2023-06-03 07:01:20
*/
#include "problem.h"
#include "longint.h"

unsigned gen_expansion(unsigned n)
{
	lint denominator{2};
	lint numerator{3};
	unsigned count{};

	for(unsigned i = 1; i < n; ++i)
	{
		numerator = numerator  + denominator * 2;
		denominator =  numerator - denominator;
		if(numerator.size() > denominator.size()) ++count;
	}

	return count;
}

void Solution::answer()
{
	auto count = gen_expansion(1000);
	std::cout << "The answer is: " << count << std::endl;
}
