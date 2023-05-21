#pragma once
#include <iostream>
#include "number.h"

class Solution
{
public:
	unsigned long truncate_from_right(unsigned long number);
	unsigned long truncate_from_left(unsigned long number);
	bool is_truncatable_prime(unsigned long number);
	unsigned long sum_of_truncatable_primes();
	void answer();

};
