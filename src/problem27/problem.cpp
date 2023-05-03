/*
Problem description:
Quadratic primes
Problem 27
Euler discovered the remarkable quadratic formula:
n^2 + n + 41
It turns out that the formula will produce 40 primes for the consecutive integer
values 0<=n<=39. However, when n=40, 40^2 + 40 + 41 = 40(40 + 1) + 41 is
divisible by 41, and certainly when n=41, 41^2 + 41 + 41 is clearly divisible
by 41.

The incredible formula n^2 -79n + 1601
 was discovered, which produces 80 primes for the consecutive values 0<=n<=79
. The product of the coefficients, −79 and 1601, is −126479.

Considering quadratics of the form:

n^2 + an + b, where |a| < 1000 and |b| <= 1000


where |n| is the modulus/absolute value of n
e.g.
|11| = 11 and |-4| = 4
Find the product of the coefficients, a and b, for the quadratic expression that
produces the maximum number of primes for consecutive values of , starting with
0
.
page link:
https://projecteuler.net/problem=26

dax 2023-05-02 14:14:05
*/
#include "problem.h"

unsigned Solution::quadratic_from(unsigned n, int a, int b)
{
	return n * n + a * n + b;
}

int Solution::product_of_coefficients()
{
	unsigned maximum_number_of_primes{};
	int poc{};

	for(int a = -999; a < 1000; ++a)
		for(int b = -1000; b <= 1000; ++b)
		{
			unsigned n = 0;

			while(is_prime(quadratic_from(n, a, b)))
			{
				++n;
			}

			if(n > maximum_number_of_primes)
			{
				maximum_number_of_primes = n;
				poc = a * b;
			}
		}

	return poc;
}

void Solution::answer()
{
	std::cout << "The answer is: " << product_of_coefficients() << std::endl;
}
