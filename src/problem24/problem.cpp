/*
Problem description:
Lexicographic permutations
Problem 24
A permutation is an ordered arrangement of objects. For example, 3124 is one
possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are
listed numerically or alphabetically, we call it lexicographic order. The
lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5,
6, 7, 8 and 9?

page link:
https://projecteuler.net/problem=24

dax 2023-04-30 09:15:15
*/
#include "problem.h"


std::string Solution::nth_permutation(std::string collection, unsigned n)
{
	unsigned count{};
	std::string target;

	do
	{
		++count;
		target = collection;
	}
	while(count < n && std::next_permutation(collection.begin(), collection.end()));

	return target;
}

bool Solution::next_permutation()
{
	auto pivot = collection.end() - 2;

	while(pivot >= collection.begin() && (*pivot >= *(pivot + 1)))
	{
		--pivot;
	}

	if(pivot < collection.begin()) return false;
	else
	{
		auto lg = pivot + 1;

		while(lg < collection.end() && *lg > *pivot) ++lg;

		std::swap(*pivot, *(lg - 1));
		std::reverse(pivot + 1, collection.end());
		return true;
	}
}

std::string Solution::get_colllection()
{
	return collection;
}

void Solution::set_string(std::string col)
{
	collection = col;
}
void Solution::answer()
{
	std::cout << "The answer is: " << nth_permutation("0123456789", 1'000'000) << std::endl;
	set_string("0123456789");
	for(unsigned i{1}; i < 1'000'000; ++i) next_permutation();
	std::cout << "The answer is: " << get_colllection() << std::endl;
}
