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
	}

	return true;

}
