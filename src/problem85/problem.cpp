/*
Problem page link:
https://projecteuler.net/problem=85

dax 2024-11-03 13:33:21
*/
#include "problem.h"
#include <cmath>
#include <limits>

void Solution::answer()
{
	uint target = 2e6; // 目标矩形数量为200万
	uint limit = std::sqrt(std::sqrt(target * 4)); // 计算限制，以减少计算次数
	uint closest = std::numeric_limits<uint>::max(); // 用于存储最接近的矩形数量
	uint area = 0; // 存储最终结果的面积

	for(uint m = 1; m <= limit + 10; ++m) // 迭代所有可能的行数m
	{
		auto temp = target * 4 / m / (m + 1);
		uint n = std::sqrt(temp); // 对应行数m，估计列数n的初始值

		// 计算m x n网格的矩形总数
		auto rectangle_count = m * (m + 1) * n * (n - 1) / 4;

		if(rectangle_count > target) // 如果矩形数量超过目标值
		{
			auto second_count = m * (m + 1) * (n - 1) * (n - 2) / 4;

			// 判断是否减少列数n可以得到更接近的矩形数量
			if(rectangle_count - target > target - second_count) --n;
		}
		else // 如果矩形数量小于或等于目标值
		{
			auto second_count = m * (m + 1) * n * (n + 1) / 4;

			// 判断是否增加列数n可以得到更接近的矩形数量
			if(target - rectangle_count > second_count - target) ++n;
		}

		// 如果当前m x n网格的矩形数量更接近目标值，更新结果
		if(m * (m + 1) * n * (n + 1) / 4 < closest)
			area = m * n; // 更新面积为当前的m * n
	}

	print("The answer is:", area); // 输出结果
}
