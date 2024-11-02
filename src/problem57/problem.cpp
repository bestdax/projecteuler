/*
Problem page link:
https://projecteuler.net/problem=57

dax 2024-09-24 14:26:47
*/
#include "problem.h"
#include <bigint.h>
#include <stringint.h>
#include <vector>
#include <iomanip>

void Solution::answer()
{
	std::vector<BigUInt> numerators(1003);
	numerators[0] = 0;
	numerators[1] = 1;
	numerators[2] = 1;
	std::vector<BigUInt> denominators(1003);
	denominators[0] = 1;
	denominators[1] = 0;
	denominators[2] = 1;

	uint count{};

	for(uint i = 3; i < 1003; ++i)
	{
		numerators[i] = 2 * numerators[i - 1] + numerators[i - 2];
		denominators[i] = 2 *  denominators[i - 1] + denominators[i - 2];

		if(numerators[i].length() > denominators[i].length()) ++count;
	}

	std::cout << "The answer is: " << count << std::endl;
}
