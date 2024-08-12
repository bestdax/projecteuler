/*
Problem page link:
https://projecteuler.net/problem=47

dax 2024-08-12 16:23:22
*/
#include "problem.h"
#include "number.h"

void Solution::answer()
{

	for(unsigned long n = 2; n < 1e6; ++n)
	{
		if(dax::get_unique_prime_factors(n).size() != 4) continue;

		if(dax::get_unique_prime_factors(n + 1).size() != 4) continue;

		if(dax::get_unique_prime_factors(n + 2).size() != 4) continue;

		if(dax::get_unique_prime_factors(n + 3).size() != 4) continue;

		std::cout << "The answer is: " << n << std::endl;
		break;
	}

}
