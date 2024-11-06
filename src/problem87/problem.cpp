/*
Problem page link:
https://projecteuler.net/problem=87

dax 2024-11-05 13:58:59
*/
#include "problem.h"
#include <vector>
#include <prime.h>
#include <unordered_set>

void Solution::answer()
{
	uint limit = 5e7;

	auto primes = dax::sieve_of_euler(limit);

	std::vector<uint> power2;
	std::vector<uint> power3;
	std::vector<uint> power4;

	for(const auto& p : primes)
	{
		if(p * p < limit) power2.push_back(p * p);
		else break;

		if(p * p * p < limit) power3.push_back(p * p * p);

		if(p * p * p * p < limit) power4.push_back(p * p * p * p);
	}

	std::unordered_set<uint> unique_sum;

	for(const auto& p2 : power2)
		for(const auto& p3 : power3)
			for(const auto& p4 : power4)
			{
				auto sum = p2 + p3 + p4;

				if(sum < limit) unique_sum.insert(sum);
			}

	std::cout << "The answer is: " << unique_sum.size() << std::endl;
}
