/*
Problem page link:
https://projecteuler.net/problem=49

dax 2024-08-12 21:54:43
*/
#include <algorithm>
#include <string>
#include "problem.h"
#include "number.h"

void Solution::answer()
{
	for(unsigned i = 1000; i < 1e4; ++i)
	{
		if(dax::is_prime(i))
		{
			auto sn = std::to_string(i);

			while(std::next_permutation(sn.begin(), sn.end()))
			{
				auto middle = std::stoul(sn);

				if(dax::is_prime(middle))
				{
					auto diff = middle - i;
					auto third = middle + diff;

					if(dax::is_prime(third) &&
					        std::is_permutation(sn.begin(), sn.end(), std::to_string(third).begin())
					        && third < 1e4
					        && i != 1487)
						std::cout << i << middle << third << std::endl;
				}
			}
		}
	}

	std::cout << "The answer is: " << "" << std::endl;
}
