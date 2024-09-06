/*
Problem description:
Goldbach's other conjecture
Problem 46
It was proposed by Christian Goldbach that every odd composite number can be
written as the sum of a prime and twice a square.

9 = 7 + 2×1^2
15 = 7 + 2×2^2
21 = 3 + 2×3^2
25 = 7 + 2×3^2
27 = 19 + 2×2^2
33 = 31 + 2×1^2

It turns out that the conjecture was false.

What is the smallest odd composite that cannot be written as the sum of a prime
and twice a square?

page link:
https://projecteuler.net/problem=46

dax 2023-05-23 15:43:51
*/
#include "problem.h"
#include "number.h"

bool Solution::is_goldbach_number(unsigned long number)
{
	for(unsigned long i = 2; i < number; ++i)
	{
		if(dax::is_prime(i))
		{
			auto remainder = number - i;

			if(dax::is_even(remainder))
			{
				remainder /= 2;

				if(dax::is_square(remainder)) return true;
			}
		}
	}

	return false;
}

unsigned long Solution::find_first_not_goldbach_number()
{
	unsigned long number = 9;
	while(is_goldbach_number(number))
	{
		while(true)
		{
			number += 2;
			if(!dax::is_prime(number)) break;
		}
	}
	return number;
}

void Solution::answer()
{
	std::cout << "The answer is: " << find_first_not_goldbach_number() << std::endl;
}
