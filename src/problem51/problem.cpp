/*
Problem description:
Prime digit replacements
Problem 51
By replacing the 1st digit of the 2-digit number *3, it turns out that six of
the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.

By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit
number is the first example having seven primes among the ten generated numbers,
yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993.
Consequently 56003, being the first member of this family, is the smallest prime
with this property.

Find the smallest prime which, by replacing part of the number (not necessarily
adjacent digits) with the same digit, is part of an eight prime value family.

page link:
https://projecteuler.net/problem=51

dax 2023-05-24 15:40:55
*/
#include "problem.h"
#include "number.h"
#include <algorithm>

ulong Solution::replace(ulong number, uint old_digit, uint new_digit)
{
	auto digits = get_digits(number);

	for(auto &d : digits)
	{
		if(d == old_digit) d = new_digit;
	}

	return digits_to_number(digits);
}

ulong Solution::find_prime_family(uint n)
{
	ulong start = 10;

	while(true)
	{
		auto digits = get_unique_digits(start);

		for(auto old_digit : digits)
		{
			ulvec family_members{};

			for(uint new_digit = 0; new_digit < 10; ++new_digit)
			{
				auto after = replace(start, old_digit, new_digit);

				if(size(after) != size(start)) continue;

				if(is_prime(after) && std::find(family_members.begin(), family_members.end(), after) == family_members.end())
					family_members.push_back(after);
			}

			if(family_members.size() == n)
			{
				for(auto member : family_members)
					std::cout << member << '\t';

				std::cout << std::endl;
				return *std::min_element(family_members.begin(), family_members.end());
			}
		}

		++start;
	}
}



void Solution::answer()
{
	std::cout << "The answer is: " << find_prime_family(8) << std::endl;
}
