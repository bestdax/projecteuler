#include <vector>
#include <algorithm>
#include <numeric>

namespace dax
{
std::vector<unsigned> get_prime_factors(unsigned long n);
unsigned long gcd(unsigned long a, unsigned long b);
unsigned long lcm(unsigned long a, unsigned long b);
bool is_prime(unsigned long n);
};
