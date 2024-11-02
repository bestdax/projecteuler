/*
Problem page link:
https://projecteuler.net/problem=15

dax 2024-09-10 12:23:27
*/
#include "problem.h"
#include <vector>

ulong Solution::paths_in_grid(uint n)
{
	std::vector<std::vector<ulong>> grid(n + 1, std::vector<ulong>(n + 1, 1));

	for(uint row = 1; row <= n; ++row)
		for(uint col = 1; col <= n; ++col)
		{
			grid[row][col] = grid[row - 1] [col] + grid[row][col - 1];
		}

	return grid[n][n];
}

void Solution::answer()
{
	std::cout << "The answer is: " << paths_in_grid(20) << std::endl;
}
