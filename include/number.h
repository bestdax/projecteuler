#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <string>
#include <algorithm>

namespace dax
{
std::vector<unsigned> get_prime_factors(unsigned long n);
unsigned long gcd(unsigned long a, unsigned long b);
unsigned long lcm(unsigned long a, unsigned long b);
bool is_prime(unsigned long n);
bool is_abundant(unsigned long n);
std::vector<bool> sieve_of_Eratosthenes(unsigned long limit);
std::vector<unsigned long> sieve_of_Euler(unsigned long limit);
bool is_pandigital(unsigned n);
};
