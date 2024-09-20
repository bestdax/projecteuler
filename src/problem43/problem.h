#pragma once
#include <vector>
#include <string>

class Solution
{
	private:
		std::vector<unsigned> divisors{2, 3, 5, 7, 11, 13, 17};
		std::string pandigit = "1023456789";
		std::vector<bool> used_digits;
		unsigned long sum_of_pandigit{};
	public:

		Solution(): used_digits(10, false) {};

		void build_pandigit(std::string current_number, unsigned depth);
		void answer();
		void answer2();

};
