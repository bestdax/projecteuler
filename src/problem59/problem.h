#pragma once
#include <utils.h>

class Solution
{
	private:
		std::string ciphered;
		std::string pass = "aaa";
	public:
		void read_text();
		std::string decript(std::string pass);
		bool next_pass();
		bool find_the_in_text(std::string text);
		ulong ascii_sum(std::string text);
		void answer();

};
