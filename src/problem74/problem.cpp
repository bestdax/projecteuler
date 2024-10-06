/*
Problem page link:
https://projecteuler.net/problem=74

dax 2024-10-06 14:17:25
*/
#include "problem.h"
#include <numutils.h>
#include <vector>
#include <algorithm>

Solution::Solution()
{
	digit_factorials.resize(10);

	for(int i = 0; i < 10; ++i)
		digit_factorials[i] = dax::factorial(i);
}

// 计算数字各个位数的阶乘和
unsigned long Solution::factorial_sum_of_digits(unsigned long n)
{
	unsigned long sum = 0;

	while(n > 0)
	{
		sum += digit_factorials[n % 10];
		n /= 10;
	}

	return sum;
}

void Solution::answer()
{

	unsigned count{};

	std::vector<int> chain_cache(1e6, -1);

	chain_cache[0] = 1;

	const int target_chain_length = 60;
	int result_count = 0;

	// 遍历1到1e6的所有数字
	for(unsigned long i = 1; i < 1e6; ++i)
	{
		std::vector<unsigned long> visited_chain; // 记录当前链条访问过的数字
		visited_chain.reserve(60);
		unsigned long current = i;
		int chain_length = 0;

		// 生成链条，直到出现循环或缓存命中
		while(std::find(visited_chain.begin(), visited_chain.end(), current) == visited_chain.end() &&
		        chain_cache[current] == -1)
		{
			visited_chain.push_back(current); // 记录当前数字及其在链条中的位置
			current = factorial_sum_of_digits(current); // 计算下一个数字
			++chain_length;
		}

		// 如果当前数字命中了缓存，更新链长度
		if(chain_cache[current] != -1)
		{
			chain_length += chain_cache[current]; // 累加缓存中的链长度
		}

		// 更新缓存链长度
		for(auto num : visited_chain)
		{
			if(chain_cache[num] == -1)
				chain_cache[num] = chain_length--; // 更新缓存：当前链条长度减去该数字的出现位置
		}

		// 检查链条长度是否为60
		if(chain_cache[i] == target_chain_length)
		{
			++result_count;
		}
	}

	std::cout << "The answer is: " << result_count << std::endl; // 输出结果}
}
