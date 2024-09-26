/*
Problem page link:
https://projecteuler.net/problem=58

dax 2024-09-24 15:53:55
*/
#include "problem.h"
#include <prime.h>

void Solution::answer()
{
	unsigned prime_count = 0;
	unsigned diagonal_count = 1;

	unsigned side = 1;
	unsigned long diagonal{1};

	do
	{
		side += 2;

		for(unsigned i = 0; i < 4; ++i)
		{
			diagonal += side - 1;

			++diagonal_count;

			if(dax::is_prime_improved(diagonal)) ++prime_count;

		}
	}
	while(prime_count * 10 >= diagonal_count);

	std::cout << "The answer is: " << side << std::endl;
}
