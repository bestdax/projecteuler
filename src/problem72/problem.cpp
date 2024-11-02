/*
Problem page link:
https://projecteuler.net/problem=72

dax 2024-10-05 16:25:40
*/
#include "problem.h"
#include <prime.h>
#include <numeric>

void Solution::answer()
{
	auto phi_vec = dax::sieve_of_euler_phi(1e6);
	ulong sum = std::accumulate(phi_vec.begin(), phi_vec.end(), 0UL);
	print("The answer is:", sum);
}
