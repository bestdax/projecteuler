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

unsigned long Solution::path_number(unsigned grid_size)
{
	unsigned long paths{};

	for(unsigned x = 0; x < grid_size; ++x)
		for(unsigned y = 0; y < grid_size; ++y)
			continue;

	return paths;
}





void Solution::answer()
{
	std::cout << "The answer is: " << path_number(20) << std::endl;
}
