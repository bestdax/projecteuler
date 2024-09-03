/*
Problem page link:
https://projecteuler.net/problem=63

dax 2024-09-03 08:50:20
*/
#include "problem.h"

void Solution::answer()
{

	unsigned count{};

	// 数字只可能是10以内的数字，因为10^2就已经是3位数了
	for(bint i = 1; i < 10; ++i)
	{

		unsigned exponent{1};

		while(i.power(exponent).number_of_digits() == exponent)
		{
			++count;
			++exponent;
		}
	}

	std::cout << "The answer is: " << count << std::endl;
}
