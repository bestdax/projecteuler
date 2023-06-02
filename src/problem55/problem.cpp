/*
Problem description:

page link:
https://projecteuler.net/problem=

dax 2023-06-02 16:39:46
*/
#include "problem.h"
#include <algorithm>

bool Solution::is_lychrel(lint number)
{
	for(unsigned i = 0; i < 50; ++i)
	{
		lint reversed_number = number.reverse();
		lint new_number = number + reversed_number;

		if(new_number.is_palindrome()) return false;
		else number = new_number;
	}

	return true;
}
void Solution::answer()
{
	unsigned count{};

	for(lint i = 0; i < 10000; ++i)
	{
		if(is_lychrel(i)) ++count;
	}

	std::cout << "The answer is: " << count << std::endl;
}
