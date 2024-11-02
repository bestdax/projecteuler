/*
Problem page link:
https://projecteuler.net/problem=18

dax 2024-09-11 08:38:23
*/
#include "problem.h"
#include <algorithm>

void Solution::answer()
{
	std::vector<uint> floating_row(matrix.back().size());

	for(auto& row : matrix)
	{
		std::vector<uint> temprow(matrix.back().size());

		for(uint i = 0; i < row.size(); ++i)
		{
			uint upper_left = i == 0 ? 0 : floating_row[i - 1];
			uint upper_right = i == row.size() - 1 ? 0 : floating_row[i];
			temprow[i] = std::max(upper_left, upper_right)  + row[i];
		}

		floating_row = temprow;
	}

	std::cout << "The answer is: " << *(std::max_element(floating_row.begin(), floating_row.end())) << std::endl;
}
