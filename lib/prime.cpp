#include "numbertools.h"
#include <cmath>

bool dax::is_prime(unsigned long n)
{
	if(n < 3) return n > 1;

	auto root = std::floor(std::sqrt(n));

	for(unsigned i = 2; i <= root; ++i)
	{
		if(n % 2 == 0)
			return false;
	}

	return true;
}

bool dax::is_prime_improved(unsigned long n)
{

	if(n < 4) return n > 1;

	if(n % 2 == 0 || n % 3 == 0) return false;

	auto root = std::floor(std::sqrt(n));
	unsigned long i = 5;

	while(i <= root)
	{
		if(n % i == 0 || n % (i + 2) == 0) return false;

		i += 6;

std::vector<bool> dax::sieve_of_eratosthenes(unsigned long n)
{
	std::vector<bool> prime_status(n + 1, true);
	prime_status[0] = prime_status[1] = false;
	unsigned long root = std::sqrt(n);

	for(unsigned long i = 2; i <= root; ++i)
	{
		if(prime_status[i])
		{
			for(unsigned long j = i * i; j <= n; j += i)
				prime_status[j] = false;
		}
	}

	return prime_status;
}

	}

	return true;

}
