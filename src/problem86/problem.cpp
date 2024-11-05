/*
Problem page link:
https://projecteuler.net/problem=86

dax 2024-11-04 12:38:56
*/
#include "problem.h"
#include <numutils.h>

void Solution::answer()
{
	uint M = 0;
	uint count = 0;
	uint target = 1e6;

	// 不断增加M，直到找到满足目标计数的最小M
	while(count < target)
	{
		M++;

		for(uint a = 1; a <= M; ++a)
			for(uint b = a; b <= M; ++b)
			{
				// 检查最短路径 (a + b, M) 的平方和是否为完全平方数
				// 因为有a <= b <= M，所以根据题意算最短路径只需要计算(a+b, M)这一种即可。
				if(dax::is_square((a + b) * (a + b) + M * M))
				{
					count++;
				}
			}
	}

	print("The answer is:", M);
}
