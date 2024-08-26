/*
Problem page link:
https://projecteuler.net/problem=58

dax 2024-08-26 13:48:06
*/
#include "problem.h"
#include "bint.h"
#include "number.h"

void Solution::answer()
{
	unsigned long side_length = 1;
	unsigned long total_numbers = 1;
	unsigned long total_diagonal_numbers = 1;
	unsigned long total_diagonal_primes = 0;

	do
	{
		side_length += 2;
		total_diagonal_numbers += 4;

		for(int i = 1; i <= 4; ++i)
		{
			unsigned long dia = total_numbers + (side_length - 1) * i;

			if(dax::is_prime(dia)) ++total_diagonal_primes;
		}

		total_numbers += side_length * 4 - 4;

		std::cout <<side_length << '\t' <<  total_diagonal_primes * 100 / total_diagonal_numbers << std::endl;

	}
	while(total_diagonal_primes * 10 > total_diagonal_numbers);

	std::cout << "The answer is: " << side_length << std::endl;
}
