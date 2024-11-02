/*
Problem page link:
https://projecteuler.net/problem=12

dax 2024-09-10 09:46:17
*/
#include "problem.h"
#include <cmath>

uint Solution::count_divisors(ulong n)
{
	ulong root = std::sqrt(n);
	uint count{};

	for(ulong i = 1; i <= root; ++i)
	{
		if(n % i == 0) count += 2;
	}

	if(root * root == n) --count;

	return count;
}

ulong Solution::triangle_number(uint n)
{
	return n * (n + 1) / 2;
}

void Solution::answer()
{
	uint count{1};
	uint n{1}, triangle{1};

	while(count <= 500)
	{
		triangle = triangle_number(n);
		count = count_divisors(triangle);
		++n;
	}

	std::cout << "The answer is: " << triangle << std::endl;
}
