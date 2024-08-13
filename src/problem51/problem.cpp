/*
Problem page link:
https://projecteuler.net/problem=51

dax 2024-08-13 08:25:07
*/
#include "problem.h"

std::vector<unsigned long> Solution::replace_digit_and_get_primes(unsigned long n)
{
	auto ns = std::to_string(n);
	std::vector<unsigned long > results;
	unsigned max_length{};

	// 复制一份数字字符串，并去除重复数字
	std::string uniquens(ns);
	std::sort(uniquens.begin(), uniquens.end());
	auto last = std::unique(uniquens.begin(), uniquens.end());
	uniquens.erase(last, uniquens.end());

	std::string alldigits("0123456789");

	for(auto c : uniquens)
	{
		std::vector<unsigned long> temp{};

		for(auto d : alldigits)
		{
			if(c != d)
			{
				std::string nscopy(ns);
				std::replace(nscopy.begin(), nscopy.end(), c, d);

				if(!nscopy.starts_with('0'))
				{
					auto number = std::stoul(nscopy);

					if(dax::is_prime(number))
						temp.push_back(number);
				}
			}
		}

		if(temp.size() > max_length)
		{
			max_length = temp.size();
			results = temp;
		}

	}

	std::sort(results.begin(), results.end());
	auto last_it = std::unique(results.begin(), results.end());
	results.erase(last_it, results.end());

	return results;

}

void Solution::answer()
{
	auto primes = dax::sieve_of_Euler(1e6);

	for(auto p : primes)
	{
		auto families = replace_digit_and_get_primes(p);

		if(families.size() == 7)
		{
			std::cout << "The answer is: " << p << std::endl;

			for(auto item : families) std::cout << item << '\t';

			break;
		}

	}

}
