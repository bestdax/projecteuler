/*
Problem page link:
https://projecteuler.net/problem=10

dax 2024-08-01 10:08:40
*/
#include "problem.h"
#include <numeric>
#include <ctime>

unsigned long Solution::sum_of_primes(unsigned long limit)
{
	unsigned long sum{};
	auto begin = clock();
	auto primes_status = dax::sieve_of_Eratosthenes(limit);

	for(unsigned long i = 0; i < limit + 1; ++i)
	{
		if(primes_status[i]) sum += i;
	}

	auto end = clock();
	std::cout << "Eratosthenes time: " << end - begin << std::endl;

	begin = clock();
	auto primes = dax::sieve_of_Euler(limit);

	// 不能直接写0，直接定零会让初始值为int类型，这样就会溢出
	sum = std::accumulate(primes.begin(), primes.end(), 0ULL);
	std::cout << "Euler time: " << clock() - begin << std::endl;

	return sum;
}

void Solution::answer()
{
	std::cout << "The answer is: " << sum_of_primes(2e6) << std::endl;
}
