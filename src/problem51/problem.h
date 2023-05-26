#pragma once
#include <iostream>
#include <vector>
typedef unsigned long ulong;
typedef std::vector<unsigned long> ulvec;
typedef std::vector<unsigned> uvec;
typedef unsigned uint;
typedef std::vector<uvec> position_lists_type;
class Solution
{
public:
	ulong replace(ulong number, uint old_digit, uint new_digit);
	ulong find_prime_family(uint n);

	void answer();

};
