/*
Problem description:
Highly divisible triangular number
Problem 12
The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be
1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

Let us list the factors of the first seven triangle numbers:

 1: 1
 3: 1,3
 6: 1,2,3,6
10: 1,2,5,10
15: 1,3,5,15
21: 1,3,7,21
28: 1,2,4,7,14,28
We can see that 28 is the first triangle number to have over five divisors.

What is the value of the first triangle number to have over five hundred divisors?
page link:
https://projecteuler.net/problem=12

dax 2023-04-23 17:12:45
*/
#include "problem.h"

unsigned long Solution::nth_triangle_number(unsigned n)
{
	unsigned long ntn{};

	for(unsigned i{1}; i <= n; ++i)
		ntn += i;

	return ntn;
}
unsigned Solution::number_of_divisors(unsigned long n)
{
	unsigned count = 0;
	unsigned root = std::round(std::sqrt(n));

	for(unsigned i{1}; i <= root; ++i)
		if(n % i == 0) count += 2;

	if(root * root == n) count--;

	return count;
}

unsigned long Solution::triangle_number_with_over_n_divisors(unsigned n)
{
	unsigned nth{1};

	while(true)
	{
		unsigned long triangle_number = nth_triangle_number(nth);
		unsigned nod = number_of_divisors(triangle_number);

		if(nod > n) return  triangle_number;
		else nth++;
	}
}

void Solution::answer()
{
	std::cout << "The answer is: " << triangle_number_with_over_n_divisors(500) << std::endl;
}
