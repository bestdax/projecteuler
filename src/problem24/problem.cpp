/*
Problem page link:
https://projecteuler.net/problem=24

dax 2024-09-11 15:54:50
*/
#include "problem.h"
#include <algorithm>
#include <timer.h>

bool Solution::next_permutation()
{
	auto p = combination.rbegin();

	// 找到递减的点
	while(p + 1 != combination.rend() && *(p + 1) >= *p)
	{
		++p;
	}

	// 如果已经到最左边则返回false
	if(p == combination.rend()) return false;

	// 从p(包含p)的右边找一个比p+1大的值
	auto r = combination.rbegin();

	while(*r <= *(p + 1)) ++r;

	std::swap(*(p + 1), *r);

	// 将右边部分从小到大排列
	std::reverse(combination.rbegin(), p + 1);

	return true;
}

void Solution::answer()
{
	for(int i = 0; i < 1e6; ++i)
		next_permutation();

	std::cout << "The answer is: ";
	print(combination, "");
}
