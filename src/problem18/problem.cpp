/*
Problem page link:
https://projecteuler.net/problem=18

dax 2024-08-03 08:56:37
*/
#include "problem.h"

unsigned Solution::path_sum()
{

	std::vector<unsigned> float_row(15, 0);

	for(unsigned r = 1; r < 15; ++r)
		for(unsigned c = 0; c <= r; ++c)
		{
			if(c == 0) number_triangle[r][c] += number_triangle[r - 1][c];
			else if(c == r) number_triangle[r][c] += number_triangle[r - 1][c - 1];
			else number_triangle[r][c] += std::max(number_triangle[r - 1][c - 1], number_triangle[r - 1][c]);
		}

	return *std::max_element(number_triangle[14].begin(), number_triangle[14].end());
}

void Solution::answer()
{
	std::cout << "The answer is: " << path_sum() << std::endl;
}
