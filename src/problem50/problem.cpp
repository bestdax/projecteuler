/*
Problem page link:
https://projecteuler.net/problem=50

dax 2024-08-12 22:29:19
*/
#include "problem.h"
#include "number.h"

void Solution::answer()
{
	unsigned long limit = 1e6;
	auto primes = dax::sieve_of_Euler(limit);
	unsigned long sum{};
	unsigned max_length = {};
	auto it = primes.begin();

	// 首先计算最大可能的长度
	while(sum < limit)
	{
		sum += *it;
		++it;
		++max_length;
	}

	// 因为从2开始的最大长度的和是超过上限的，所以可能的长度要从最大长度减去1开始
	auto length = max_length - 1;

	while(length)
	{
		// 从右到左滑动求和
		it = primes.begin() + max_length - length;

		// 如果和小于上限并且是素数，则找到结果，否则向左滑动
		for(unsigned i = 0; i < max_length - length; ++i)
		{

			auto temp_sum = std::accumulate(it, it + length, 0);

			if(temp_sum < limit && dax::is_prime(temp_sum))
			{
				sum = temp_sum;
				std::cout << "The answer is: " << sum << std::endl;
				return;
			}

			--it;
		}

		// 如果在一个长度内不能结束就将长度缩减1
		--length;
	}

}
