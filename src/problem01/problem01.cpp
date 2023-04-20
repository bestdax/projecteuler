/*
Multiples of 3 or 5

Problem 1
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these
multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.
https://projecteuler.net/problem=1

dax 2023/04/20 12:14:30
*/

#include "problem01.h"

long Solution::sum_of_multiples(int cap)
{
	long sum{};

	for(int i{1}; i < cap; ++i)
	{
		if(i % 3 == 0 || i % 5 == 0) sum += i;
	}
	return sum;
}
