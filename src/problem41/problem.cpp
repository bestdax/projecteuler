/*
Problem page link:
https://projecteuler.net/problem=41

dax 2024-08-12 11:48:52
*/
#include "problem.h"
#include "number.h"

void Solution::answer()
{
	std::string pandigits = "987654321";
	{
		while(true)
		{
			if(dax::is_prime(std::stoul(pandigits)))
			{
				std::cout << pandigits << std::endl;
				break;
			}

			if(!std::prev_permutation(pandigits.begin(), pandigits.end()))
			{
				pandigits = pandigits.substr(1);
			}
		}
	}
}
