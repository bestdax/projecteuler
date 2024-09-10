/*
Problem page link:
https://projecteuler.net/problem=16

dax 2024-09-10 13:00:35
*/
#include "problem.h"
#include <stringint.h>

void Solution::answer()
{
	std::cout << "The answer is: " << StringInt(2).power(1000).sum_of_digits() << std::endl;
}
