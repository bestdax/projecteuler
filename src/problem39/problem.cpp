/*
Problem description:
Integer right triangles
Problem 39
If p is the perimeter of a right angle triangle with integral length sides,
{a,b,c}, there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p ≤ 1000, is the number of solutions maximised?

page link:
https://projecteuler.net/problem=39

dax 2023-05-22 14:53:07
*/
#include "problem.h"

unsigned Solution::number_of_right_triangles(unsigned p)
{
	unsigned number {};

	for(unsigned a = 1; a < p; ++a)
		for(unsigned b = a; b <= p - a; ++ b)
			if(a * a + b * b == (p - a - b) * (p - a - b)) ++number;

	return number;
}

unsigned Solution::perimeter_with_maximum_solutions()
{
	unsigned p{}, number{}, n{};

	for(unsigned i = 4; i <= 1000; ++i)
	{
		if((n = number_of_right_triangles(i)) > number)
		{
			number = n;
			p = i;
		}
	}

	return p;
}

void Solution::answer()
{
	std::cout << "The answer is: " << perimeter_with_maximum_solutions() << std::endl;
}
