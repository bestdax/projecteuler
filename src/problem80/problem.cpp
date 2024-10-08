/*
Problem page link:
https://projecteuler.net/problem=80

dax 2024-10-08 21:50:40
*/
#include "problem.h"
#include <bigint.h>

void Solution::answer()
{
	BigUInt sum;

	for(BigUInt i(1); i <= 100; ++i)
	{
		auto root = i.sqrt();

		if(root * root != i)
		{
			sum += (i * BigUInt(10).power(198)).sqrt().digital_sum();
		}
	}

	print("The answer is:", sum);
}
