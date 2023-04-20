/*
Problem description:
Double-base palindromes
Problem 36
The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in
base 10 and base 2.

(Please note that the palindromic number, in either base, may not include
leading zeros.)

page link:
https://projecteuler.net/problem=36

dax 2023-05-20 17:13:17
*/
#include "problem.h"
#include <bitset>
#include "number.h"

bool Solution::is_double_base_palindrome(unsigned number)
{
	if(dax::is_palindrome(number))
	{
		auto bit_string = std::bitset<32>(number).to_string();
		auto begin = bit_string.begin();

		while(*begin == '0') ++begin;

		auto end = bit_string.end() - 1;

		while(end > begin)
		{
			if(*begin != *end) return false;
			else
			{
				++begin;
				--end;
			}
		}

		return true;
	}
	else return false;
}

unsigned long Solution::sum_of_double_base_palindrome(unsigned cap)
{
	unsigned long sum{};

	for(unsigned i = 0; i < cap; ++i)
	{
		if(is_double_base_palindrome(i)) sum += i;
	}

	return sum;
}

void Solution::answer()
{
	std::cout << "The answer is: " << sum_of_double_base_palindrome(1'000'000) << std::endl;
}
