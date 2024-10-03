#include <prime.h>
#include <cmath>

bool dax::is_prime(unsigned long n)
{
	if(n < 4) return n > 1;

	unsigned long root = std::sqrt(n);

	for(unsigned i = 2; i <= root; ++i)
		if(n % i == 0)
			return false;

	return true;
}

bool dax::is_prime_improved(unsigned long n)
{

	if(n < 4) return n > 1;

	if(n % 2 == 0 || n % 3 == 0) return false;

	unsigned long i = 5;
	unsigned long root = std::sqrt(n);

	for(unsigned long i = 5; i <= root; i += 6)
		if(n % i == 0 || n % (i + 2) == 0) return false;

	return true;

}

std::vector<bool> dax::sieve_of_eratosthenes(unsigned long n)
{
	std::vector<bool> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	unsigned long root = std::sqrt(n);

	for(unsigned long i = 2; i <= root; ++i)
	{
		if(is_prime[i])
		{
			for(unsigned long multiple = i * i; multiple <= n; multiple += i)
				is_prime[multiple] = false;
		}
	}

	return is_prime;
}

std::vector<unsigned long> dax::sieve_of_euler(unsigned long n)
{
	std::vector<bool> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	std::vector<unsigned long> primes;
	primes.reserve(n / std::log(n));

	for(unsigned long i = 2; i <= n; ++i)
	{
		if(is_prime[i]) primes.push_back(i);

		if(i > n / 2) continue;

		for(auto&p : primes)
		{
			auto composite = i * p;

			if(composite > n) break;

			is_prime[composite] = false;

			if(i % p == 0) break;
		}
	}

	return primes;

}

unsigned long dax::euler_phi(unsigned long n)
{
	if(n < 2) return 0;

	auto is_prime = dax::sieve_of_eratosthenes(n);
	if(is_prime[n]) return n - 1;

	unsigned long phi{1};
	unsigned long root = std::sqrt(n);



	for(unsigned long i = 2; i <= n; ++i)
	{
		if(is_prime[i] && n % i == 0)
		{
			unsigned power{};

			while(n % i == 0)
			{
				n /= i;
				++power;
			}

			phi *= (i - 1);

			for(unsigned p = 0; p < power - 1; ++p)
			{
				phi *= i;
			}
		}
	}

	return phi;
}
