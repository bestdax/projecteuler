/*
Problem description:
Lattice paths
Problem 15
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6
routes to the bottom right corner.


How many such routes are there through a 20×20 grid?
page link:
https://projecteuler.net/problem=15
dax 2023/04/23 21:40:15
*/
#include "problem.h"

unsigned long Solution::factorial(unsigned n)
{
	unsigned long f{1};
	LargeNumber a{"1"};
	LargeNumber b{"11"};

	for(unsigned i = 1; i <= n; ++i)
	{
		f *= i;
	}

	return f;
}
unsigned long Solution::path_number(unsigned grid_size)
{
	unsigned long paths{1};
	grid_size = 4;

	for(unsigned i = grid_size + 1; i <= grid_size * 2; i += 2) paths *= i;

	paths /= factorial(grid_size / 2);
	paths *= std::pow(2, grid_size / 2);
	return paths;
}





void Solution::answer()
{
	std::cout << "The answer is: " << path_number(20) << std::endl;
}
