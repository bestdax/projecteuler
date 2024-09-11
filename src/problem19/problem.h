#pragma once
#include <iostream>
#include <map>

class Solution
{
	private:
		std::map<unsigned, unsigned> days_of_month =
		{
			{1, 31},
			{3, 31},
			{5, 31},
			{7, 31},
			{8, 31},
			{10, 31},
			{12, 31},
			{4, 30},
			{6, 30},
			{9, 30},
			{11, 30},
			{2, 28}
		};
	public:
		bool is_leap_year(int y);
		void answer();

};
