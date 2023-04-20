/*
Problem page link:
https://projecteuler.net/problem=65

dax 2023-06-09 13:26:43
*/
#include "problem.h"

void Solution::gen_factors(lint n)
{
	factors.push_back(2);

	while(n > factors.size())
	{
		if(factors.size() % 3 == 2)
		{
			factors.push_back((factors.size() / 3 + 1) * 2);
		}
		else factors.push_back(1);
	}
}

void Solution::gen_convergents()
{
	auto it = factors.rbegin();
	conv_lower = 1;
	conv_upper = *it;

	for(it = it + 1; it < factors.rend(); ++it)
	{
		auto temp = conv_lower;
		conv_lower = conv_upper;
		conv_upper = temp;
		conv_upper = conv_lower * (*it) + conv_upper;
	}
}
void Solution::answer()
{
	gen_factors(10);
	gen_convergents();


	std::cout << "The answer is: " << conv_upper.digit_sum() << std::endl;
}
