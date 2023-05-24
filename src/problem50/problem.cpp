/*
Problem description:
Consecutive prime sum
Problem 50
The prime 41, can be written as the sum of six consecutive primes:

41 = 2 + 3 + 5 + 7 + 11 + 13
This is the longest sum of consecutive primes that adds to a prime below
one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime,
contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most
consecutive primes?

page link:
https://projecteuler.net/problem=50

dax 2023-05-24 13:53:23
*/
#include "problem.h"
#include "number.h"
#include <numeric>

std::vector<unsigned long> Solution::gen_prime_list(unsigned long cap)
{
	std::vector<unsigned long> primes;

	for(unsigned long i = 2; i < cap; ++i)
		if(is_prime(i)) primes.push_back(i);

	return primes;
}
unsigned long Solution::consequtive_prime_sum(unsigned long cap)
{
	auto primes = gen_prime_list(cap);
	auto size = primes.size();
	unsigned long target{};

	for(unsigned len = 2; len < size; ++len)
	{
		if(std::accumulate(primes.begin(), primes.begin() + len, 0) > cap) break;

		for(auto it = primes.begin(); it != primes.end() - len; ++it)
		{
			auto sum = std::accumulate(it, it + len, 0);

			if(sum > cap) break;

			if(is_prime(sum))
				target = sum;
		}
	}

	return target;
}

void Solution::answer()
{
	std::cout << "The answer is: " << consequtive_prime_sum(1'000'000) << std::endl;
}
