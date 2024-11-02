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
	uint limit = 1e6;
	auto primes = dax::sieve_of_euler(limit);
	ulong sum{};
	uint max_length{};

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

// 滑动窗口解法
void Solution::answer2()
{
	uint limit = 1e6;
	auto primes = dax::sieve_of_euler(limit);
	uint max_length{};
	uint max_sum{};

	// 外层循环控制窗口的起点
	for(int i = 0; i < primes.size(); ++i)
	{
		// 如何剩余素数的个数已经少于max_length，退出循环
		if(primes.size() - i < max_length) break;

		uint current_sum = 0;

		// 内层循环控制窗口的结束位置
		for(int j = i; j < primes.size(); ++j)
		{
			current_sum += primes[j];

			// 如果和超过limit就停止循环
			if(current_sum > limit) break;

			// 如果是新的长度并且和是质数就更新最大长度及其和
			if(j - i + 1 > max_length && dax::is_prime_improved(current_sum))
			{
				max_length = j - i + 1;
				max_sum = current_sum;
			}
		}
	}

	std::cout << "The answer is: " << max_sum << std::endl;
}
