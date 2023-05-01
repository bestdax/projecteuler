/*
Problem description:
1000-digit Fibonacci number
Problem 25
The Fibonacci sequence is defined by the recurrence relation:

Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
Hence the first 12 terms will be:

F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144
The 12th term, F12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
page link:
https://projecteuler.net/problem=25

dax 2023-05-01 18:11:22
*/
#include "problem.h"

unsigned Solution::fabonacci()
{
	lint fab;
	lint a{1};
	lint b{1};
	unsigned index{2};

	while(fab.size() != 1000)
	{
		index += 1;
		fab = a+b;
		a = b;
		b = fab;
	}

	return index;
}
void Solution::answer()
{
	std::cout << "The answer is: " << fabonacci() << std::endl;
}
