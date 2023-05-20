/*
Problem description:
Circular primes
Problem 35
The number, 197, is called a circular prime because all rotations of the digits:
197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71,
73, 79, and 97.

How many circular primes are there below one million?

page link:
https://projecteuler.net/problem=35

dax 2023-05-19 16:58:55
*/
#include "problem.h"
#include "prime.h"
#include "number.h"

bool Solution::is_circular_prime(unsigned number)
{
    auto len = size(number);

    for(unsigned i = 1; i < len; ++i)
    {
        if (is_prime(number))
        {
            number = rotate(number);
        }
        else
            return false;
    }

    return true;

}

void Solution::answer()
{
    std::cout << "The answer is: " << "" << std::endl;
}
