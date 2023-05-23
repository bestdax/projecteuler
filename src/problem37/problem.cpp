/*
Problem description:
Truncatable primes
Problem 37
The number 3797 has an interesting property. Being prime itself, it is possible
to continuously remove digits from left to right, and remain prime at each
stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797,
379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to
right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.

page link:
https://projecteuler.net/problem=37

dax 2023-05-21 10:30:21
*/
#include "problem.h"
#include <cmath>
#include "number.h"
#include "number.h"

unsigned long Solution::truncate_from_left(unsigned long number)
{
	unsigned len{};
	auto temp = number;

	while(temp != 0)
	{
		++len;
		temp /= 10;
	}

	return number % static_cast<unsigned long>(std::pow(10, len - 1));
}

unsigned long Solution::truncate_from_right(unsigned long number)
{
	return number / 10;
}

bool Solution::is_truncatable_prime(unsigned long number)
{
	if(number < 10) return false;

	if(is_prime(number))
	{
		auto part_from_left = truncate_from_left(number);
		auto part_from_right = truncate_from_right(number);

		while(part_from_left != 0 && part_from_right != 0)
		{
			if(!is_prime(part_from_right) || !is_prime(part_from_left)) return false;

			part_from_left = truncate_from_left(part_from_left);
			part_from_right = truncate_from_right(part_from_right);
		}

		return true;
	}
	else return false;
}

unsigned long Solution::sum_of_truncatable_primes()
{
	unsigned count{}, i{};
	unsigned long sum{};

	while(count < 11)
	{
		if(is_truncatable_prime(i))
		{
			sum += i;
			++count;
		}

		++i;
	}

	return sum;
}

void Solution::answer()
{
	std::cout << "The answer is: " << sum_of_truncatable_primes() << std::endl;
}
