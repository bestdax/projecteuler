/*
Problem page link:
https://projecteuler.net/problem=68

dax 2024-10-02 23:09:07
*/
#include "problem.h"
#include <numeric>
#include <vector>
#include <algorithm>

void Solution::answer()
{
	// 一共10个数，因为需要求解的是数字是16位，所以可以肯定10是在外圈
	// 前面5个数字为内圈，后面5个为外圈，试试1-5为内圈的情况能不能找到答案。
	// 内圈和为15， 外圈和为40，则第一支的和应该为(15 x 2 + 40) / 5 = 14
	std::vector<short> five_gon_ring(10);
	std::iota(five_gon_ring.begin(), five_gon_ring.end(), 1);

	do
	{
		std::string result;

		for(unsigned i = 0; i < 5; ++i)
		{
			auto sum = five_gon_ring[i] + five_gon_ring[i + 5] + (i == 4 ? five_gon_ring[0] : five_gon_ring[i + 1]);

			if(sum != 14) break;

			if(i == 4)
			{
				// 找到答案时的数组为[3,5,2,4,1,6,7,8,9,10]，即最终答案按时针方向输出为6531031914842725

				std::string result;
				int outer_index = 5;
				int inner_index1 = 1;
				int inner_index2 = 0;

				for(int j = 0; j < 5; ++j)
				{
					result += std::to_string(five_gon_ring[outer_index]) + std::to_string(five_gon_ring[inner_index1]) + std::to_string(
					              five_gon_ring[inner_index2]);
					--outer_index;
					--inner_index1;
					--inner_index2;

					if(outer_index < 5) outer_index = 9;

					if(inner_index1 < 0) inner_index1 = 4;

					if(inner_index2 < 0) inner_index2 = 4;
				}

				print("The answer is:", result);

				return;
			}

		}
	}
	while(std::next_permutation(five_gon_ring.begin(), five_gon_ring.begin() + 5));
}
