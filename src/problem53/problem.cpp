/*
Problem page link:
https://projecteuler.net/problem=53

dax 2024-08-14 16:57:49
*/
#include "problem.h"
#include <array>

void Solution::answer()
{
	std::array<std::array<unsigned, 101>, 101> matrix;
	unsigned count{};

	for(unsigned n = 1; n < 101; ++n)
		for(unsigned r = 1; r <= n; ++r)
		{
			if(r == 1) matrix[n][r] = n;
			else if(n == r) matrix[n][r] = 1;
			else matrix[n][r] = matrix[n - 1][r - 1] + matrix[n - 1][r];

			if(matrix[n][r] > 1e6)  ++count;
		}

	std::cout << "The answer is: " << count << std::endl;
}
