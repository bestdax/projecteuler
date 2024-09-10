/*
Problem page link:
https://projecteuler.net/problem=13

dax 2024-09-10 10:15:03
*/
#include "problem.h"
#include <stringint.h>

void Solution::answer()
{
	StringInt result;
	for(auto& sn: string_numbers)
	{
		result = result + sn;
	}
	std::cout << "The answer is: " << result.to_string().substr(0, 10) << std::endl;
}
