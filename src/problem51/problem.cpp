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

ulong Solution::replace_with_index(ulong number, uint index, uint digit)
{
	auto digits = get_digits(number);

	if(index < digits.size()) digits[index] = digit;

	return digits_to_number(digits);
}

ulong Solution::replace_with_position(ulong number, uvec position_list,
                                      uint digit)
{
	uint len = size(number);

	for(auto it = position_list.begin(); it != position_list.end(); ++it)
	{
		if(*it == 1)
		{
			auto size_diff = len - size(number);
			number = replace_with_index(number, it - position_list.begin() - size_diff, digit);
		}
	}

	return number;
}

position_lists_type Solution::gen_position_lists(ulong number)
{
	position_lists_type positions;
	auto digits = get_digits(number);

	for(auto d : digits)
	{
		uvec position(size(number), 0);

		for(auto it = digits.begin(); it != digits.end(); ++it)
		{
			if(d == *it) position[it - digits.begin()] = 1;
		}

		positions.push_back(position);
	}

	return positions;
}

ulvec Solution::replace(ulong number)
{
	auto len = size(number);
	ulvec numbers;

	for(uint i = 0; i < 10; ++i)
	{
		auto pos_lists = gen_position_lists(len);

		for(auto row : pos_lists)
		{
			for(auto d : row)
				std::cout << d << '\t';

			std::cout << std::endl;
		}

		for(auto pos : pos_lists)
		{
			auto n = replace_with_position(number, pos, i);

			if(size(n) == len && is_prime(n))
				numbers.push_back(replace_with_position(number, pos, i));
		}
	}

	std::sort(numbers.begin(), numbers.end());
	auto last = std::unique(numbers.begin(), numbers.end());
	numbers.erase(last);
	return numbers;
}


void Solution::answer()
{
	ulong start = 10000;
	ulvec numbers;

	while(true)
	{
		numbers = replace(start);

		if(numbers.size() == 8) break;

		++start;
	}

	std::cout << "The answer is: " << numbers.front() << std::endl;
}
