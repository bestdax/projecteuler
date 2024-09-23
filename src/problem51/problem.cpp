/*
Problem page link:
https://projecteuler.net/problem=51

dax 2024-09-23 14:26:32
*/
#include "problem.h"
#include <prime.h>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <utils.h>

void Solution::answer()
{
	unsigned limit = 1e6;
	auto is_prime = dax::sieve_of_eratosthenes(limit);

	// 遍历素数
	for(unsigned i = 56003; i <= limit; ++i)
	{
		if(is_prime[i])
		{
			auto ns = std::to_string(i);
			std::unordered_map<char, unsigned> digits_count;

			for(const auto& c : ns)
			{
				++digits_count[c];
			}

			// 遍历每个数字
			for(const auto& [d, count] : digits_count)
			{
				// 用一个set来保存已经发现的素数
				std::unordered_set<unsigned> found_primes;
				found_primes.insert(i);

				// 保证只对有重复的数字进行替换
				if(count > 1)
				{
					for(char c = '0'; c <= '9'; ++c)
					{
						// 跳过本身
						if(d == c) continue;

						std::string copy(ns);
						std::replace(copy.begin(), copy.end(), d, c);

						// 替换后数字不能为0打头，并且得是素数
						if(!copy.starts_with('0') && is_prime[std::stoul(copy)]) found_primes.insert(std::stoul(copy));
					}
				}

				// 找到8个以后就退出
				if(found_primes.size() == 8)
				{
					std::cout << "The answer is: " << i << std::endl;
					return;
				}

			}

		}
	}
}
