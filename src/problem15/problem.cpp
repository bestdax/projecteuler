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

lint Solution::path_number(unsigned grid_size)
{
	lint l = 1;

	for(lint i = grid_size + 1; i <= grid_size * 2; ++i) l *= i;

	return l / lint(grid_size).factorial();
}


void Solution::answer()
{
	std::cout << "The answer is: " << path_number(20) << std::endl;
}
