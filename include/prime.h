#pragma once
#include <vector>
#include <utils.h>
#include <cmath>

namespace dax
{
	bool is_prime(ulong);
	bool is_prime_improved(ulong);
	std::vector<bool> sieve_of_eratosthenes(ulong);
	std::vector<ulong> sieve_of_euler(ulong);
	ulong euler_phi(ulong);
	std::vector<ulong> sieve_of_euler_phi(ulong);
}
