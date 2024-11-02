/*
Problem page link:
https://projecteuler.net/problem=60

dax 2024-09-26 12:49:33
*/
#include "problem.h"
#include <prime.h>
#include <numutils.h>
#include <numeric>
#include <utils.h>

bool Solution::is_prime_pair(ulong a, ulong b)
{
	return dax::is_prime_improved(dax::concatenate(a, b)) && dax::is_prime_improved(dax::concatenate(b, a));
}

// 使用宽度优先策略(因为是要查找5个的最小值)
void Solution::find_groups(ulong start_node)
{
	std::queue<std::set<ulong>> queue;

	queue.push({start_node});

	while(not queue.empty())
	{
		auto node = queue.front();
		queue.pop();

		auto last_elem = *node.rbegin();

		// 在当前节点对应的可连接素数中搜索
		for(auto& p : group_map[last_elem])
			if(p > last_elem) // 比当前组最后一个元素大
			{
				// 确认是否可以添加到当前组中
				bool valid = true;

				for(auto& elem : node)
				{
					if(!group_map[elem].contains(p))
					{
						valid = false;
						break;
					}
				}

				if(valid)
				{
					// 如果可以添加，复制一份，并添加当前素数后压入队列中
					auto copy(node);
					copy.insert(p);
					queue.push(copy);

					// 判定是否找到目标
					if(copy.size() == target_len)
					{
						auto sum = std::accumulate(copy.begin(), copy.end(), 0UL);

						if(sum < min)
						{
							min = sum;
							target = copy;
						}
					}
				}

			}

	}
}

void Solution::answer()
{

	for(auto&prime : primes)
	{
		find_groups(prime);

		if(prime > min) break;
	}

	print(target);

	std::cout << "The answer is: " << min << std::endl;
}
