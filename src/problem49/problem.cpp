/*
Problem description:
Prime permutations
Problem 49
The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases
by 3330, is unusual in two ways: (i) each of the three terms are prime, and,
(ii) each of the 4-digit numbers are permutations of one another.

There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes,
exhibiting this property, but there is one other 4-digit increasing sequence.

What 12-digit number do you form by concatenating the three terms in this
sequence?

page link:
https://projecteuler.net/problem=49

dax 2023-05-24 11:19:26
*/
#include "problem.h"
#include "number.h"
#include <algorithm>

std::vector<unsigned long> Solution::prime_permutations(unsigned long n)
{
	auto digits = dax::get_digits(n);
	std::vector<unsigned long> numbers{n};

	while(std::next_permutation(digits.begin(), digits.end()))
	{
		if(dax::is_prime(dax::digits_to_number(digits)))
			numbers.push_back(dax::digits_to_number(digits));
	}

	std::sort(numbers.begin(), numbers.end());
	return numbers;
}

std::vector<unsigned long> Solution::pick_arithmetic_sequence(std::vector<unsigned long> numbers)
{
	std::vector<unsigned long> sequence{};

	for(auto first = numbers.begin(); first != numbers.end() - 1; ++first)
		for(auto second = first + 1; second != numbers.end(); ++second)
		{
			auto difference = *second - *first;
			auto third_number = *second + difference;
			auto it = std::find(numbers.begin(), numbers.end(), third_number);

			if(it != numbers.end())
			{
				sequence.push_back(*first);
				sequence.push_back(*second);
				sequence.push_back(third_number);
				return sequence;
			}
		}

	return sequence;
}


void Solution::answer()
{
	std::cout << "The answer is: ";

	for(unsigned i = 1000; i < 10000; ++i)
	{
		if(dax::is_prime(i))
		{
			auto numbers = prime_permutations(i);
			auto sequence = pick_arithmetic_sequence(numbers);

			if(!std::empty(sequence) && sequence[0] != 1487)
			{
				auto number = dax::concatenate(sequence);
				std::cout << number << std::endl;
				return;
			}
		}
	}
}
