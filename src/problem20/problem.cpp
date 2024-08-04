/*
Problem page link:
https://projecteuler.net/problem=20

dax 2024-08-04 16:06:40
*/
#include "problem.h"

void Solution::answer()
{
	char carry{};

	for(unsigned i = 2; i <= 100; ++i)
	{
		for(auto& d : result)
		{
			d *= i;

			if(carry) d += carry;

			carry = 0;

			carry = d / 10;
			d %= 10;
		}

		if(carry)
		{
			while(carry)
			{
				result.push_back(carry % 10);
				carry /= 10;
			}
		}
	}

	std::cout << "The answer is: " << std::accumulate(result.begin(), result.end(), 0) << std::endl;
}
