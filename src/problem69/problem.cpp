/*
Problem page link:
https://projecteuler.net/problem=69

dax 2024-10-03 00:48:18
*/
#include "problem.h"
#include <prime.h>
#include <utility>

void Solution::answer()
{
	std::pair<unsigned, unsigned> max_totient{0, 1};
	auto phi_vec = dax::sieve_of_euler_phi(1e6);

	for(unsigned i = 2; i <= 1e6; ++i)
	{
		auto phi = phi_vec[i];

		if(i * max_totient.second > phi * max_totient.first)
		{
			max_totient.first = i;
			max_totient.second = phi;
		}
	}

	print("The answer is:", max_totient.first);
}
