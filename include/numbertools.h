#pragma once
#include <vector>
#include <cmath>

namespace dax
{
bool is_prime(unsigned long);
bool is_prime_improved(unsigned long);
std::vector<bool> sieve_of_eratosthenes(unsigned long);
std::vector<bool> sieve_of_euler(unsigned long);
}