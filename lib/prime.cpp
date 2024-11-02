#include <prime.h>
#include <cmath>
#include <utils.h>

bool dax::is_prime(ulong n)
{
	if(n < 4) return n > 1;

	ulong root = std::sqrt(n);

	for(unsigned i = 2; i <= root; ++i)
		if(n % i == 0)
			return false;

	return true;
}

bool dax::is_prime_improved(ulong n)
{

	if(n < 4) return n > 1;

	if(n % 2 == 0 || n % 3 == 0) return false;

	ulong i = 5;
	ulong root = std::sqrt(n);

	for(ulong i = 5; i <= root; i += 6)
		if(n % i == 0 || n % (i + 2) == 0) return false;

	return true;

}

std::vector<bool> dax::sieve_of_eratosthenes(ulong n)
{
	std::vector<bool> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	ulong root = std::sqrt(n);

	for(ulong i = 2; i <= root; ++i)
	{
		if(is_prime[i])
		{
			for(ulong multiple = i * i; multiple <= n; multiple += i)
				is_prime[multiple] = false;
		}
	}

	return is_prime;
}

std::vector<ulong> dax::sieve_of_euler(ulong n)
{
	std::vector<bool> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	std::vector<ulong> primes;
	primes.reserve(n / std::log(n));

	for(ulong i = 2; i <= n; ++i)
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

ulong dax::euler_phi(ulong n)
{
	if(n < 2) return 0;

	auto is_prime = dax::sieve_of_eratosthenes(n);

	if(is_prime[n]) return n - 1;

	ulong phi{1};
	ulong root = std::sqrt(n);

	for(ulong i = 2; i <= n; ++i)
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

std::vector<ulong> dax::sieve_of_euler_phi(ulong limit)
{

	std::vector<bool> is_prime(limit + 1, true);
	is_prime[0] = is_prime[1] = false;
	std::vector<ulong> primes;
	primes.reserve(limit / std::log(limit));
	std::vector<ulong> phi_vec(limit + 1);

	for(ulong i = 2; i <= limit; ++i)
	{
		if(is_prime[i])
		{
			primes.push_back(i);
			phi_vec[i] = i - 1;
		}

		if(i > limit / 2) continue;

		for(auto&p : primes)
		{
			auto composite = i * p;

			if(composite > limit) break;

			is_prime[composite] = false;

			if(i % p == 0)
			{
				phi_vec[composite] = phi_vec[i] * p;
				break;
			}

			phi_vec[composite] = phi_vec[i] * phi_vec[p];

		}
	}

	return phi_vec;

}
