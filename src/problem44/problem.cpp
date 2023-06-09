/*
Problem description:
Pentagon numbers
Problem 44
Pentagonal numbers are generated by the formula, Pn=n(3n−1)/2. The first ten
pentagonal numbers are:

1, 5, 12, 22, 35, 51, 70, 92, 117, 145, ...

It can be seen that P4 + P7 = 22 + 70 = 92 = P8. However, their difference, 70 −
22 = 48, is not pentagonal.

Find the pair of pentagonal numbers, Pj and Pk, for which their sum and
difference are pentagonal and D = |Pk − Pj| is minimised; what is the value of
D?

page link:
https://projecteuler.net/problem=44

dax 2023-05-23 14:09:49
*/
#include "problem.h"
#include "number.h"

Solution::Solution()
{
	pentagonal_numbers = {1, 5};
}

void Solution::find_next_pentagonal_number()
{
	unsigned n = pentagonal_numbers.size() + 1;
	unsigned long pn = (3 * n * n - n) / 2;
	pentagonal_numbers.push_back(pn);
}

unsigned long Solution::find_pairs_difference()
{
	while(true)
	{
		for(auto first = pentagonal_numbers.begin(); first != pentagonal_numbers.end() - 1; ++first)
		{
			auto second = pentagonal_numbers.end() - 1;

			if(is_pentagonal_number(*second - *first) && is_pentagonal_number(*first + *second))
			{
				std::cout << *first << '\t' << *second << std::endl;
				return *second - *first;
			}
		}

		find_next_pentagonal_number();
	}
}
void Solution::answer()
{
	std::cout << "The answer is: " << find_pairs_difference() << std::endl;
}
