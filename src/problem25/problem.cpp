/*
Problem page link:
https://projecteuler.net/problem=25

dax 2024-08-08 16:19:29
*/
#include "problem.h"

void Solution::next_fib()
{
	++nth;

	if(nth > 2)
	{
		temp = fibb;
		auto ita = fiba.begin();
		auto itb = fibb.begin();
		char carry{};

		while(ita != fiba.end())
		{
			// 遍历fiba和fibb，相应的位置相加后的值赋给fibb
			*itb += *ita;
			// 加上进位
			*itb += carry;
			// 重新计算是否有进位
			carry = *itb / 10;
			// 将数字与10取模后赋给b的相应数位
			*itb = *itb % 10;
			++itb;
			++ita;
		}

		// 如果有进位，fibb已经到最后一位的话增加一位，否则相应的加上进位的数字，注意有循环进位的可能
		if(carry)
		{
			if(itb != fibb.end())
			{
				while(itb != fibb.end())
				{
					*itb += carry;
					carry = *itb / 10;

					if(!carry) break;

					++itb;
				}
			}
			else fibb.push_back(carry);
		}

		fiba = temp;
	}
}

std::string Solution::fib()
{
	std::string number;

	for(auto it = fibb.rbegin(); it != fibb.rend(); ++it)
	{
		number += std::to_string(*it);
	}

	return number;
}

void Solution::answer()
{
	while(fibb.size() != 1000)
		next_fib();

	std::cout << "The answer is: " << nth << std::endl;
}
