/*
Problem page link:
https://projecteuler.net/problem=15

dax 2024-08-02 21:59:11
*/
#include "problem.h"

unsigned long Solution::lattice_paths(unsigned long n)
{
	auto size = n + 1;
	std::vector<std::vector<unsigned long>> grid(size, std::vector<unsigned long>(size, 1));

	for(unsigned r = 1; r < size; ++r)
		for(unsigned c = 1; c < size; ++c)
		{
			grid[r][c] = grid[r - 1][c] + grid[r][c-1];
		}

	return grid[n][n];

}

void Solution::answer()
{
	std::cout << "The answer is: " << lattice_paths(20) << std::endl;
}
