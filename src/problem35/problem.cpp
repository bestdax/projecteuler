/*
Problem page link:
https://projecteuler.net/problem=35

dax 2024-08-11 05:49:11
*/
#include "problem.h"
#include <fstream>

void Solution::answer()
{
	auto primes = dax::sieve_of_Euler(1e6);
	unsigned count = primes.size();

	for(auto p : primes)
	{
		auto sp = std::to_string(p);

		while(true)
		{

			sp = sp.back() + sp.substr(0, sp.size() - 1);
			auto permutated_p = std::stoul(sp);

			if(permutated_p == p) break;

			// 用搜索的方法比较慢，还是直接判断素数快
			// auto it = std::find(primes.begin(), primes.end(), permutated_p);

			// if(it == primes.end())
			if(!dax::is_prime(permutated_p))
			{
				--count;
				break;
			}
		}

	}

	std::cout << "The answer is: " << count << std::endl;
}
