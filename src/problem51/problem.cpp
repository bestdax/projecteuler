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

void Solution::answer()
{
	unsigned limit = 1e6;
	auto is_prime = dax::sieve_of_eratosthenes(limit);

	// 遍历素数
	for(unsigned i = 56003; i <= limit; ++i)
	{
		if(is_prime[i])
		{
			unsigned count = 0;
			// 转换为字符串以便后续处理
			auto ns = std::to_string(i);

			// 遍历每个数字
			for(unsigned j = 0; j < ns.size() - 1; ++j)
			{
				auto it = std::find(ns.begin() + j + 1, ns.end(), ns[j]);
				// 用searched_digits记录哪些数字查找过了以免重复查找
				std::unordered_set<char> searched_digits;

				// 如果发现重复数字并且没有搜索过将数字添加到已搜索数字set里面
				if(it != ns.end() && !searched_digits.contains(ns[j]))
				{
					searched_digits.insert(ns[j]);

					for(auto & c : std::string("0123456789"))
					{
						std::string copy(ns);
						std::replace(copy.begin(), copy.end(), ns[j], c);

						// 替换后数字不能为0打头，并且得是素数
						if(!copy.starts_with('0') && is_prime[std::stoul(copy)]) ++count;

						if(count == 8)
						{
							std::cout << "The answer is: " << i << std::endl;
							return;
						}

					}

					count = 0;
				}
			}
		}
	}
}
