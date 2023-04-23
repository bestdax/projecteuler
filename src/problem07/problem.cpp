/*
Problem description:
10001st prime
Problem 7
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
page link:
https://projecteuler.net/problem=7

dax 2023-04-23 14:25:53
*/
#include "problem.h"
long Solution::nth_prime(int n)
{
	if(n == 1) return 2;
	else if(n == 2) return 3;
	else
	{
		int i = 5;
		int count = 2;

		while(true)
		{
			if(is_prime(i))
			{
				count++;

				if(count == n) return i;
			}

			i += 2;
		}
	}
}

void Solution::answer()
{
	std::cout << "The answer is: " << nth_prime(10001) << std::endl;
}
