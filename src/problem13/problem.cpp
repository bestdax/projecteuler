/*
Problem page link:
https://projecteuler.net/problem=13

dax 2024-08-02 18:31:02
*/
#include "problem.h"

std::string Solution::first_ten_digits_of_sum()
{
	std::string sum{};
	int carry{};
	int digit_sum{};
	int digit{};

	for(int i = 49; i >= 0; --i)
	{
		digit_sum = carry;
		carry = 0;

		for(auto ns : numbers)
		{
			digit_sum += (ns[i] - 48);
		}

		digit = digit_sum % 10;
		carry = digit_sum - digit;
		sum.insert(sum.begin(), char(digit + 48));
	}

	sum = std::to_string(carry) + sum;
	return sum.substr(0, 10);
}

void Solution::answer()
{
	std::cout << "The answer is: " << first_ten_digits_of_sum() << std::endl;
}
