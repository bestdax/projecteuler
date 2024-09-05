/*
Problem page link:
https://projecteuler.net/problem=68

dax 2024-09-05 13:28:57
*/
#include "problem.h"

Solution::Solution()
{
	numbers.resize(10);
	std::iota(numbers.begin(), numbers.end(), 1);
}

/*
因为是16位的，所以可以判定10在外圈；
和的算法是内圈和x2 + 外圈和 然后除以5
测试一下12345在内圈的情况下能不能找到答案
*
*/
void Solution::answer()
{
	std::vector<short> inner(numbers.begin(), numbers.begin() + 5);
	std::vector<short> outer(numbers.begin() + 5, numbers.end());
	auto sum = std::accumulate(inner.begin(), inner.end(), 0) * 2;
	sum += std::accumulate(outer.begin(), outer.end(), 0);
	sum /= 5;

	do
	{
		bool found = true;

		for(int i = 0; i < inner.size(); ++i)
		{
			if(i != inner.size() - 1)
			{
				if(inner[i] + inner[i + 1] + outer[i] != sum)
				{
					found = false;
					break;
				}
			}
			else
			{
				if(inner[i] + inner[0] + outer[i] != sum)
				{
					found = false;
					break;
				}
			}
		}

		if(found) break;
	}
	while(std::next_permutation(inner.begin(), inner.end()));

	std::string result;

	for(int i = inner.size() - 1; i > 0; --i)
	{
		if(i < inner.size() - 1)
		{
			result += std::to_string(outer[i]);
			result += std::to_string(inner[i + 1]);
			result += std::to_string(inner[i]);
		}
		else
		{
			result += std::to_string(outer[i]);
			result += std::to_string(inner[0]);
			result += std::to_string(inner[i]);
		}
	}

	result = std::to_string(outer[0]) + std::to_string(inner[1]) + std::to_string(inner[0]) + result;

	std::cout << "The answer is: " << result << std::endl;
}
