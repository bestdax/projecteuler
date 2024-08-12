/*
Problem page link:
https://projecteuler.net/problem=48

dax 2024-08-12 16:53:51
*/
#include "problem.h"

std::vector<short> Solution::self_power(unsigned n)
{
	std::vector<short> result;
	unsigned digits = 10;
	auto m = n;

	while(m)
	{
		result.push_back(m % 10);
		m /= 10;
	}

	unsigned carry{};

	if(result.size() > digits)
		result.erase(result.begin() + 10, result.end());

	for(unsigned i = 1; i < n; ++i)
	{
		for(auto& digit : result)
		{
			digit *= n;
			digit += carry;
			carry = digit / 10;
			digit %= 10;
		}

		while(carry)
		{
			result.push_back(carry % 10);
			carry /= 10;
		}
	}

	if(result.size() > 10) result.erase(result.begin() + 10, result.end());

	return result;
}

void Solution::print_self_power(std::vector<short> vc)
{
	for(auto it = vc.rbegin(); it != vc.rend(); ++it)
	{
		std::cout << *it;
	}

	std::cout << std::endl;
}

std::vector<short> Solution::sum_of_self_powers(unsigned n)
{
	std::vector<short> result;

	for(unsigned i = 1; i <= n; ++i)
	{
		auto power = self_power(i);

		unsigned carry{};

		for(auto itr = result.begin(), itp = power.begin(); itr != result.end(); ++itr, ++itp)
		{
			*itp += *itr;
			*itp += carry;
			carry = *itp / 10;
			*itp %= 10;
		}

		auto pp = power.begin() + result.size();

		while(carry)
		{
			*pp += carry;
			carry = *pp / 10;
			*pp %= 10;
		}

		result = power;

		if(result.size()  > 10)
			result.erase(result.begin() + 10, result.end());
	}

	return result;
}

void Solution::answer()
{
	print_self_power(sum_of_self_powers(1000));
	std::cout << "The answer is: " << "" << std::endl;
}
