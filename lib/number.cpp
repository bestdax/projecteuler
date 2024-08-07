#include "number.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <cmath>

bool dax::is_prime(unsigned long n)
{
	if(n < 2) return false;

	auto r = std::floor(std::sqrt(n));

	for(int i = 2; i <= r; ++i) if(n % i == 0) return false;

	return true;
}

std::vector<unsigned> dax::get_prime_factors(unsigned long n)
{
	std::vector<unsigned>prime_factors;

	while(! dax::is_prime(n))
	{
		for(unsigned i = 2; i <= n; ++i)
		{
			if(dax::is_prime(i) && n % i == 0)
			{
				prime_factors.push_back(i);
				n = n / i;
				break;
			}
		}
	}

	return prime_factors;
}

unsigned long dax::gcd(unsigned long a, unsigned long b)
{

	if(a < b)
	{
		auto temp = a;
		a = b;
		b = temp;
	}

	while(b != 0)
	{
		auto temp = b;
		b = a % b;
		a = temp;
	}

	return a;
}

unsigned long dax::lcm(unsigned long a, unsigned long b)
{
	return a * b / dax::gcd(a, b);
}

// 埃氏筛法
std::vector<bool> dax::sieve_of_Eratosthenes(unsigned long limit)
{
	std::vector<bool> prime_status(limit + 1, true);
	prime_status[0] = prime_status[1] = false;

	for(unsigned long i = 2; i <= limit; ++i)
	{
		unsigned times =  2;
		unsigned long product = times * i;

		while(product <= limit)
		{
			prime_status[product] = false;
			product = i * ++times;
		}
	}

	return prime_status;
}

// 欧拉筛法
std::vector<unsigned long> dax::sieve_of_Euler(unsigned long limit)
{
	std::vector<bool> prime_status(limit + 1, true);
	prime_status[0] = prime_status[1] = false;
	std::vector<unsigned long> primes{};

	auto half = limit / 2;

	for(unsigned long i = 2; i <= half; ++i)
	{
		// 如果是素数推进列表
		if(prime_status[i])
		{
			primes.push_back(i);
		}

		for(auto p : primes)
		{
			auto q = p * i;

			if(q < limit + 1)
				prime_status[q] = false;
			else
				break;

			if(i % p == 0) break;
		}

	}

	for(unsigned long i = half; i < limit + 1; ++i)
	{
		if(prime_status[i]) primes.push_back(i);
	}

	return primes;
}

// 富余数
bool dax::is_abundant(unsigned long n)
{
	auto half = n / 2;
	unsigned long sum_of_proper_factors{};

	for(unsigned long i = 1; i <= half; ++i)
	{
		if(n % i == 0) sum_of_proper_factors += i;
	}

	return sum_of_proper_factors > n;
}
