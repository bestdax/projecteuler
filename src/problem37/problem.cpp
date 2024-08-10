/*
Problem page link:
https://projecteuler.net/problem=37

dax 2024-08-11 07:24:43
*/
#include "problem.h"
#include "number.h"
#include <string>

bool Solution::is_truncatable_prime(unsigned long p)
{
	if(p < 11) return false;

	auto ps = std::to_string(p);

	while(!ps.empty())
	{
		ps.pop_back();

		if(!ps.empty() && !dax::is_prime(std::stoul(ps)))
		{
			return false;
		}
	}

	ps = std::to_string(p);

	while(!ps.empty())
	{
		ps = ps.substr(1);

		if(!ps.empty() && !dax::is_prime(std::stoul(ps)))
			return false;
	}

	return true;
}

void Solution::answer()
{
	auto primes = dax::sieve_of_Euler(1e6);
	unsigned count{};
	unsigned sum{};

	for(auto p : primes)
	{
		if(is_truncatable_prime(p))
		{
			std::cout << p << std::endl;
			sum += p;

			if(count == 11) break;
		}
	}

	std::cout << "The answer is: " << sum << std::endl;
}
