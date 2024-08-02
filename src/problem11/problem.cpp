/*
Problem page link:
https://projecteuler.net/problem=11

dax 2024-08-02 17:22:10
*/
#include "problem.h"

unsigned Solution::max_product()
{
	unsigned product{}, temp{};

	for(unsigned r = 0; r < 20; ++r)
		for(unsigned c = 0; c < 20; ++c)
		{
			// horizontal
			if(c < 17)
			{
				temp = grid[r][c] * grid[r][c + 1] * grid[r][c + 2] * grid[r][c + 3];
				product = product < temp ? temp : product;
			}

			// vertical
			if(r < 17)
			{
				temp = grid[r][c] * grid[r + 1][c] * grid[r + 2][c] * grid[r + 3][c];
				product = product < temp ? temp : product;
			}

			// diagonal
			if(c < 17 && r < 17)
			{
				temp = grid[r][c] * grid[r + 1][c + 1] * grid[r + 2][c + 2] * grid[r + 3][c + 3];
				product = product < temp ? temp : product;
			}

			// horizontal
			if(c > 2 && r < 17)
			{
				temp = grid[r][c] * grid[r + 1][c - 1] * grid[r + 2][c - 2] * grid[r + 3][c - 3];
				product = product < temp ? temp : product;
			}
		}

	return product;
}

void Solution::answer()
{
	std::cout << "The answer is: " << max_product() << std::endl;
}
