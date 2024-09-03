/*
Problem page link:
https://projecteuler.net/problem=65

dax 2024-09-03 12:04:30
*/
#include "problem.h"

void Solution::answer()
{
	std::vector<bint> numerators{0, 1};
	std::vector<bint> denominators{1, 0};
	std::vector<unsigned> coeffients{2};

	for(int i = 0; i < 100; ++i)
	{
		bint numerator = numerators.back() * coeffients.back() + (*(numerators.end() - 2));
		bint denominator = denominators.back() * coeffients.back() + (*(denominators.end() - 2));
		numerators.push_back(numerator);
		denominators.push_back(denominator);

		if(coeffients.size() % 3 == 1 || coeffients.size() % 3 == 0) coeffients.push_back(1);
		else
			coeffients.push_back((coeffients.size() / 3 + 1) * 2);
	}

	std::cout << "The answer is: " << numerators.back().digtal_sum() << std::endl;
}
