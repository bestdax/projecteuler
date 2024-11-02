/*
Problem page link:
https://projecteuler.net/problem=11

dax 2024-09-10 08:48:37
*/
#include "problem.h"

void Solution::answer()
{
	ulong max_product{1};

	for(uint col = 0; col < 20; ++col)
		for(uint row = 0; row < 20; ++row)
		{
			if(col < 17 && row < 17)
			{
				auto product_h = matrix[row][col] * matrix[row][col + 1] * matrix[row][col + 2] * matrix[row][col + 3];
				auto product_v = matrix[row][col] * matrix[row + 1][col] * matrix[row + 2][col] * matrix[row + 3][col];
				auto product_d = matrix[row][col] * matrix[row + 1][col + 1] * matrix[row + 2][col + 2] * matrix[row + 3][col + 3];

				for(auto &p :
				        {
				            product_h, product_v, product_d
				        })
					max_product = p > max_product ? p : max_product;
			};

			if(col > 2 && row < 17)
			{
				auto product_ad = matrix[row][col] * matrix[row + 1][col - 1] * matrix[row + 2][col - 2] * matrix[row + 3][col - 3];
				max_product = product_ad > max_product ? product_ad : max_product;
			}

		}

	std::cout << "The answer is: " << max_product << std::endl;
}
