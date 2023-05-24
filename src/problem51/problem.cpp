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

unsigned long Solution::replace(unsigned long number, unsigned index, unsigned digit)
{
	auto digits = get_digits(number);

	if(index < digits.size()) digits[index] = digit;

	std::cout << digits_to_number(digits) << std::endl;
	return digits_to_number(digits);
}

unsigned long Solution::replace_with_position_list(unsigned long number, std::vector<unsigned> position_list,
        unsigned digit)
{
	for(auto it = position_list.begin(); it != position_list.end(); ++it)
	{
		if(*it == 1)
		{
			number = replace(number, it - position_list.begin(), digit);
		}
	}

	return number;
}

std::vector<unsigned long> Solution::replace_with_same_digits(unsigned long prime_number)
{
	std::vector<unsigned long> primes{prime_number};
	auto digits = get_digits(prime_number);

	// n refers to how many digits will be replaced
	for(unsigned n = 1; n < digits.size(); ++n)
	{
		// create a copy of digits
		auto changed_digits = digits;
		// create a list, position with 0 keeps unchanged, 1 to be replaced
		std::vector<unsigned> positions;

		for(unsigned i = 0; i < digits.size(); ++i)
		{
			unsigned p = i < digits.size() - n ? 0 : 1;
			positions.push_back(p);
		}

		// d referes to the digit to replace
		for(unsigned d = 0; d < 10; ++d)
		{
			do
			{
				for(auto p : positions) std::cout << p << '\t';

				std::cout << "n = " << n << std::endl;

				for(auto it = positions.begin(); it != positions.end(); ++it)
				{
					if(*it == 1)
					{
						if(changed_digits[it - positions.begin()] == d) break;

						changed_digits[it - positions.begin()] = d;
					}
				}

				auto number = digits_to_number(changed_digits);

				if(is_prime(number)) primes.push_back(number);
			}
			while(std::next_permutation(positions.begin(), positions.end()));
		}
	}

	return primes;
}
void Solution::answer()
{
	std::cout << "The answer is: " << "" << std::endl;
}
