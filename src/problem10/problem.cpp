/*
Problem description:
Summation of primes
Problem 10
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
page link:
https://projecteuler.net/problem=10

dax 2023-04-23 16:41:30
*/
#include "problem.h"
unsigned long Solution::summation_of_primes(int cap)
{
	unsigned long sum{};
	for(unsigned i = 2; i < cap; ++i)
	{
		if(dax::is_prime(i)) sum += i;
	}
	return sum;
}

void Solution::answer()
{
	std::cout << "The answer is: " << summation_of_primes(2'000'000) << std::endl;
}
