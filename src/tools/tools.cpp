#include "tools.h"

bool is_prime(long number)
{
	if(number < 2) return false;

	int root = std::round(std::sqrt(number));

	for(int i = 2; i <= root; i++)
	{
		if(number % i == 0) return false;
	}

	return true;
}

std::vector<int> prime_factors(long number)
{
	std::vector<int> pf{};

	if(number < 2) return pf;

	for(int i = 2; i <= number; ++i)
	{
		if(is_prime(i) && number % i == 0)
		{
			pf.push_back(i);
			number /= i;
			i = 1;
		}
	}

	return pf;
}
