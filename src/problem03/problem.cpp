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
#include "number.h"


int Solution::largest_prime_factor(long number)
{
	auto pf = dax::prime_factors(number);
	return *(pf.end() - 1);
}

void Solution::answer()
{
	std::cout << "The answer is: " << largest_prime_factor(600'851'475'143) << std::endl;
}
