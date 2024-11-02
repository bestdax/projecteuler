/*
Problem page link:
https://projecteuler.net/problem=70

dax 2024-10-05 08:51:07
*/
#include "problem.h"
#include <prime.h>
#include <numutils.h>
#include <utility>

void Solution::answer()
{
	std::pair<ulong, ulong> min_totient{1, 0};
	auto phi_vec = dax::sieve_of_euler_phi(1e7);

	for(int i = 2; i < 1e7; ++i)
	{
		auto phi = phi_vec[i];
		if(dax::is_permutation(phi, i) && i * min_totient.second < phi * min_totient.first)
		{
			min_totient.first = i;
			min_totient.second = phi;
		}
	}

	print("The answer is:", min_totient.first);
}
