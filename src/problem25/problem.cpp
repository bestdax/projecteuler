/*
Problem page link:
https://projecteuler.net/problem=25

dax 2024-09-12 08:03:09
*/
#include "problem.h"

void Solution::next_fibonacci()
{
	auto temp = a + b;
	a = b;
	b = temp;
	++rank;
}

void Solution::answer()
{
	while(b.length() != 1000)
		next_fibonacci();

	std::cout << "The answer is: " << rank << std::endl;
}
