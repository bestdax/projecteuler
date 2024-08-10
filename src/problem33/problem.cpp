/*
Problem page link:
https://projecteuler.net/problem=33

dax 2024-08-10 17:34:04
*/
#include "problem.h"

void Solution::answer()
{
	unsigned numerator_product = 1;
	unsigned denominator_product = 1;

	for(int i = 11; i < 99; ++ i)
	{
		int tens_of_i = i / 10;
		int ones_of_i = i % 10;

		if(ones_of_i == 0) continue;

		for(int j = 1; j < 10; ++j)
		{
			int p = j * 10 + tens_of_i;

			if(p <= i) continue;

			int q = ones_of_i * 10 + j;

			if(q <= i) continue;

			if(i * j == p * ones_of_i)
			{
				std::cout << i << '/' <<  p << '\t' << ones_of_i << '/' << j << std::endl;
				numerator_product *= ones_of_i;
				denominator_product *= j;

			}

			if(i * j == q * tens_of_i)
			{
				std::cout << i << '/' <<  q << '\t' << tens_of_i << '/' << j << std::endl;
				numerator_product *= tens_of_i;
				denominator_product *= j;
			}
		}
	}

	std::cout << "The answer is: " << denominator_product / numerator_product << std::endl;
}
