/*
Problem page link:
https://projecteuler.net/problem=12

dax 2024-09-10 09:46:17
*/
#include "problem.h"
#include <cmath>

unsigned Solution::count_divisors(unsigned long n)
{
	unsigned long root = std::sqrt(n);
	unsigned count{};

	for(unsigned long i = 1; i <= root; ++i)
	{
		if(n % i == 0) count += 2;
	}

	if(root * root == n) --count;

	return count;
}

unsigned long Solution::triangle_number(unsigned n)
{
	return n * (n + 1) / 2;
}

void Solution::answer()
{
	unsigned count{1};
	unsigned n{1}, triangle{1};

	while(count <= 500)
	{
		triangle = triangle_number(n);
		count = count_divisors(triangle);
		++n;
	}

	std::cout << "The answer is: " << triangle << std::endl;
}
