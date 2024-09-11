/*
Problem page link:
https://projecteuler.net/problem=19

dax 2024-09-11 10:12:31
*/
#include "problem.h"

bool Solution::is_leap_year(int y)
{
	return y % 400 == 0 || y % 4 == 0 && y % 100 != 0;
}

void Solution::answer()
{
	unsigned weekday = 1;

	unsigned year = 1900;
	unsigned count{};

	while(year <= 2000)
	{
		for(int m = 1; m <= 12; ++m)
		{
			if(m == 12) ++year;

			if(is_leap_year(year) && m == 2) weekday += 29;
			else weekday += days_of_month[m];

			weekday %= 7;

			if(year > 1900 && weekday == 0) ++count;
		}
	}

	std::cout << "The answer is: " << count << std::endl;
}
