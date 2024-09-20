/*
Problem page link:
https://projecteuler.net/problem=50

dax 2024-09-20 11:32:42
*/
#include "problem.h"
#include <prime.h>
#include <numeric>

void Solution::answer()
{
	unsigned limit = 1e6;
	auto primes = dax::sieve_of_euler(limit);
	unsigned long sum{};
	unsigned max_length{};

	// 计算出最大的长度
	for(auto &p : primes)
	{
		if(sum + p <= limit)
		{
			sum += p;
			++max_length;
		}
		else break;
	}

	if(dax::is_prime_improved(sum))
	{
		std::cout << "The answer is: " << sum << std::endl;
		return;
	}

	while(true)
	{

		// 将长度缩短1后在primes数组中从头开始求和；
		sum = std::accumulate(primes.begin(), primes.begin() + --max_length, 0);

		for(int i = 1; i <= limit; ++i)
		{
			// 加上新滑进窗口的数，减去移出窗口的数
			sum += (primes[i + max_length - 1] - primes[i - 1]);

			if(sum > limit) break;

			if(dax::is_prime_improved(sum))
			{
				std::cout << "The answer is: " << sum << std::endl;
				return;
			}

		}
	}

}
