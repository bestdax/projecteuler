/*
Problem page link:
https://projecteuler.net/problem=20

dax 2024-09-11 11:11:59
*/
#include "problem.h"
#include <stringint.h>

void Solution::answer()
{
	std::cout << "The answer is: " << StringInt(100).factorial().sum_of_digits() << std::endl;
}
