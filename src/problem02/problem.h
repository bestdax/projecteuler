#pragma once
#include <iostream>

class Solution
{
	public:
		unsigned long next_fib();
		unsigned long sum_of_even_fibs(unsigned long cap);
		void answer();
	private:
		unsigned long first{1};
		unsigned long second{2};

};
