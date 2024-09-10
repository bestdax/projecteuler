/*
Problem page link:
https://projecteuler.net/problem=15

dax 2024-09-10 12:23:27
*/
#include "problem.h"
#include <vector>

unsigned long Solution::paths_in_grid(unsigned n)
{
	std::vector<std::vector<unsigned long>> grid(n + 1, std::vector<unsigned long>(n + 1, 1));

	for(unsigned row = 1; row <= n; ++row)
		for(unsigned col = 1; col <= n; ++col)
		{
			grid[row][col] = grid[row - 1] [col] + grid[row][col - 1];
		}

	return grid[n][n];
}

void Solution::answer()
{
	std::cout << "The answer is: " << paths_in_grid(20) << std::endl;
}
