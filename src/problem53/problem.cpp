/*
Problem description:
Combinatoric selections
Problem 53
There are exactly ten ways of selecting three from five, 12345:

123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

In combinatorics, we use the notation, C(5, 3) = 10.
.

In general,C(n, r) = n! / (r! * (n - r)!) , where r <= n, n! = n x (n - 1) x ...
x 1 , , and 0! = 1.

It is not until n = 23, that a value exceeds one-million: C(23, 10) 1144066 .

How many, not necessarily distinct, values of C(n, r) for 1 <= n <= 100, are
greater than one-million?

page link:
https://projecteuler.net/problem=53

dax 2023-05-26 13:54:37
*/
#include "problem.h"

void Solution::answer()
{
	unsigned count{};

	for(unsigned n = 0; n <= 100; ++n)
		for(unsigned r = 0; r <= n; ++r)
		{
			if(n == r) combination_matrix[n][r] = 1;
			else if(r == 1) combination_matrix[n][r] = n;
			else
			{
				combination_matrix[n][r] = combination_matrix[n - 1][r] * n / (n - r);
			}

			if(combination_matrix[n][r] > 1000000) ++count;
		}

	std::cout << "The answer is: " << count << std::endl;
}
