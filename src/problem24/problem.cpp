/*
Problem page link:
https://projecteuler.net/problem=24

dax 2024-08-07 14:56:58
可以将数列分成两个部分，在要发生变化的时候，发生变化的部位的左边是从小到大排列的，而右边是从大到小排列的
比如：
0123469875
我们从最右边开始搜索，找到一个点其左边的数比自身小，在这个例子中是9的位置
做一个小遍历，从5到9，找到一个比6大的数，这里是7，将6与7互换
然后将9到最右边按从小到大的顺序排序变成5689
处理完成后数列变成：
0123475689

所以算法可以写：
从数列右边开始遍历(逆序遍历)，找到一个位置p，其左边(p+1)的值比自身小
从数列的rbegin开始遍历到p，找到一个数字比(p+1)大，并交换两个数
将rbegin到p的数字按左小右大的顺序排列

sort函数的范围前闭后开的
functional库里面有很多定义好的functor
*/
#include "problem.h"

void Solution::next_permutation()
{

	while(p != digits.rend() - 1)
	{
		if(*p > *(p + 1))
		{
			for(auto it = digits.rbegin(); it <= p; ++it)
			{
				if(*it > *(p + 1))
				{
					std::swap(*it, *(p + 1));
					std::sort(digits.rbegin(), p + 1, std::greater<short>());
					p = digits.rbegin();
					return;
				}
			}
		}

		++p;

		if(p == digits.rend() - 1)
		{
			std::sort(digits.begin(), digits.end());
			p = digits.rbegin();
			break;
		}
	}

}

void Solution::print()
{
	for(auto i : digits)
		std::cout << i;

	std::cout << std::endl;
}

void Solution::answer()
{
	for(int i = 0; i < 1e6; ++i)
		next_permutation();

	std::cout << "The answer is: " ;
	print();
	std::cout << std::endl;
}
