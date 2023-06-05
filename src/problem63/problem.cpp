/*
Problem description:

page link:
https://projecteuler.net/problem=63

dax 2023-06-05 16:04:44
*/
#include "problem.h"
#include <cmath>
#include "longint.h"

void Solution::answer()
{
	unsigned count = 0;
	// the number should be less than 10, since 10^2 is a 3-digit number
	{
		for(int i = 1; i < 10; ++i)
		{
			unsigned n = 1;

			while(lint(i).power(n).size() == n)
			{
				++count;
				lint number = lint(i).power(n);
				++n;
			}
		}
	}
	std::cout << "The answer is: " << count << std::endl;
}
