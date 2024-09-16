#pragma once
#include <iostream>
#include <prime.h>

class Solution
{
	private:
		std::vector<bool> is_prime;
	public:
		Solution();
		bool is_truncatable_prime(unsigned n);
		void answer();

};
