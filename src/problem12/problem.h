#pragma once
#include <iostream>

class Solution
{
	public:
		void next_triangle();
		unsigned count_factors(unsigned long n);

		void answer();

	private:
		unsigned triangle{};
		unsigned nth{};

};
