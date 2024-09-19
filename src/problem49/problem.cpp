/*
Problem page link:
https://projecteuler.net/problem=49

dax 2024-09-19 14:55:17
*/
#include "problem.h"
#include <prime.h>
#include <algorithm>
#include <string>

bool has_same_digits(unsigned n, unsigned m)
{
	auto sn = std::to_string(n);
	auto sm = std::to_string(m);
	std::sort(sn.begin(), sn.end());
	std::sort(sm.begin(), sm.end());
	return sn == sm;
}

void Solution::answer()
{
	auto is_prime = dax::sieve_of_eratosthenes(1e4);

	for(unsigned i = 1001; i < 1e4; ++i)
	{
		if(i == 1487) continue;

		if(is_prime[i])
			for(unsigned j = i + 1; j < 1e4; ++j)
			{
				if(is_prime[j] && has_same_digits(i, j))
				{
					auto k = j + j - i;

					if(k < 1e4 && is_prime[k] && has_same_digits(i, k))
						std::cout << "The answer is: " << i << j << k << std::endl;
				}
			}
	}

}
