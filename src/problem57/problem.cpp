/*
Problem page link:
https://projecteuler.net/problem=57

dax 2024-08-26 09:02:14
*/
#include "problem.h"

void Solution::answer()
{
	std::vector<bint> numberators{0, 1};
	std::vector<bint> denominators{1, 0};
	unsigned count{};

	for(int i = 0; i < 1000; ++i)
	{
		int a = i == 0 ? 1 : 2;
		bint tempn(numberators[i + 1] * a + numberators[i]) ;
		numberators.push_back(tempn);
		bint tempd(denominators[i + 1] * a + denominators[i]);
		denominators.push_back(tempd);

		if(tempn.number_of_digits() > tempd.number_of_digits()) ++count;
	}

	std::cout << "The answer is: " << count << std::endl;
}
