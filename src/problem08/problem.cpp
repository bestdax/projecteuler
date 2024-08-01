/*
Problem page link:
https://projecteuler.net/problem=8

dax 2024-08-01 08:17:55
*/
#include "problem.h"

unsigned long Solution::largest_product_of_adjacent_digits(unsigned n)
{
	unsigned long product{};

	int last_start = 1000 - n;

	for(int i = 0; i < last_start; ++i)
	{
		unsigned long temp{1};

		for(int j = 0; j < n; ++j)
		{

			temp *= (long_number[i + j] - 48);
			if(!temp) break;


		}

		product = product > temp ? product : temp;
	}

	return product;
}

void Solution::answer()
{
	std::cout << "The answer is: " << largest_product_of_adjacent_digits(13) << std::endl;
}
