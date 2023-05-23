/*
Problem description:
Pandigital prime
Problem 41
We shall say that an n-digit number is pandigital if it makes use of all the
digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is
also prime.

What is the largest n-digit pandigital prime that exists?
page link:
https://projecteuler.net/problem=41

dax 2023-05-23 09:52:05
*/
#include "problem.h"
#include "number.h"
#include <algorithm>
#include <string>

bool Solution::is_pandigital_prime(unsigned number)
{
	return is_n_pandigital(number) && is_prime(number);
}

// this solution takes too long time
unsigned Solution::max_pandigital_prime()
{
	for(unsigned i = 987654321; i > 1; i -= 2)
	{
		if(is_pandigital_prime(i))
		{
			std::cout << "max: " << i << std::endl;
			return i;
		}

		if(i % 1000 == 1) std::cout << "computing: " << i << std::endl;
	}
	return 0;
}

// second try
unsigned Solution::max_pandigital_prime2()
{
	unsigned max{};
	std::string digits = "123456789";

	while(digits.length() > 1)
	{
		if(!std::next_permutation(digits.begin(), digits.end()))
		{
			std::sort(digits.begin(), digits.end());
			digits.pop_back();
		}

		unsigned number = std::stoi(digits);

		if(is_prime(number) && number > max) max = number;
	}

	return max;
}


void Solution::answer()
{
	std::cout << "The answer is: " << max_pandigital_prime2() << std::endl;
}
