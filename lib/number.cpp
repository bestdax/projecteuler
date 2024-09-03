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

	prime_factors.push_back(n);

	return prime_factors;
}

std::vector<unsigned> dax::get_unique_prime_factors(unsigned long n)
{
	auto prime_factors = dax::get_prime_factors(n);
	auto last = std::unique(prime_factors.begin(), prime_factors.end());
	prime_factors.erase(last, prime_factors.end());
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
	auto root = std::floor(std::sqrt(n));
	unsigned long sum_of_proper_factors{};

	for(unsigned long i = 2; i <= root; ++i)
	{
		// 如果是方根的号就只加一个
		if(n % i == 0) sum_of_proper_factors += (i + (i * i != n ? n / i : 0));
	}

	++sum_of_proper_factors;

	return sum_of_proper_factors > n;
}

// 全数字
bool dax::is_pandigital(unsigned n)
{
	std::string pandigits = "123456789";
	auto ns = std::to_string(n);
	std::sort(ns.begin(), ns.end());
	return ns == pandigits.substr(0, ns.size());
}

// 三角数
bool dax::is_triangle(unsigned long n)
{
	unsigned long m = (std::sqrt(8 * n + 1) - 1) / 2;
	return m * (m + 1) / 2 == n;
}

// 五角形数
bool dax::is_pentagonal(unsigned long n)
{
	unsigned long m = (std::sqrt(24 * n + 1) + 1) / 6;
	return m * (3 * m - 1) / 2 == n;
}

// 平方
bool dax::is_square(unsigned long n)
{
	auto root = std::floor(std::sqrt(n));
	return root * root == n;
}

// 回文数
bool dax::is_palindrome(unsigned long n)
{
	std::string ns = std::to_string(n);
	auto l = ns.begin();
	auto r = 	ns.end() - 1;

	while(l < r)
	{
		if(*l != *r) return false;

		++l, --r;

	}

	return true;
}

unsigned dax::number_of_digits(unsigned long n)
{
	unsigned l{};

	while(n > 0)
	{
		++l;
		n /= 10;
	}

	return l;
}
