#include "number.h"
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