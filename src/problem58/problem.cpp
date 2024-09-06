/*
Problem description:

page link:
https://projecteuler.net/problem=58

dax 2023-06-03 07:54:20
*/
#include "problem.h"
#include "number.h"


unsigned Solution::traverse_matrix()
{
	float prime_ratio = 1;
	unsigned nth_layer = 1;
	unsigned side_length = 1;
	unsigned long number = 1;
	unsigned diagonal_count = 1;
	unsigned diagonal_prime_count = 0;

	while(prime_ratio > 0.1)
	{
		++nth_layer;
		side_length = nth_layer * 2 - 1;

		diagonal_count += 4;

		for(unsigned i = 0; i < 4; ++i)
		{
			number += 2 * (nth_layer - 1);

			if(dax::is_prime(number)) ++diagonal_prime_count;
		}

		prime_ratio = static_cast<float>(diagonal_prime_count) / diagonal_count;

	}
	return side_length;
}

void Solution::answer()
{
	std::cout << "The answer is: " << traverse_matrix() << std::endl;
}
