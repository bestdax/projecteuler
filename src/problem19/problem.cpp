/*
Problem description:
Counting Sundays
Problem 19
You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

page link:
https://projecteuler.net/problem=19

dax 2023-04-28 08:46:36
*/
#include "problem.h"

bool Solution::is_leap(unsigned year)
{
	return year % 400 == 0 || (year % 100 && year % 4 == 0);
}

unsigned Solution::days_in_the_year(unsigned year)
{
	return is_leap(year) ? 366 : 365;
}

unsigned Solution::nth_day_of_the_year(unsigned year, unsigned month, unsigned day)
{
	unsigned count {0};

	for(unsigned m = 1; m < month; ++m)
	{
		if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) count += 31;
		else if(m == 2) count += is_leap(year) ? 29 : 28;
		else count += 30;
	}

	count += day;
	return count;
}

unsigned Solution::how_many_days_from_19000101(unsigned year, unsigned month, unsigned day)
{
	unsigned count{};

	for(unsigned y = 1900; y < year; ++y)
	{
		count += days_in_the_year(y);
	}

	count += nth_day_of_the_year(year, month, day);
	return count;
}

unsigned Solution::which_day(unsigned year, unsigned month, unsigned day)
{
	unsigned days_count_from_19000101 = how_many_days_from_19000101(year, month, day);
	return days_count_from_19000101 % 7;
}

unsigned Solution::sundays_in_the_first_of_the_month_in_20th()
{
	unsigned sundays{};

	for(unsigned year = 1901; year <= 2000; ++year)
	{
		for(unsigned month = 1; month <= 12; ++month)
		{
			if(which_day(year, month, 1) == 0)
			{
				sundays += 1;
			}
		}
	}

	return sundays;
}

void Solution::answer()
{
	std::cout << "The answer is: " << sundays_in_the_first_of_the_month_in_20th() << std::endl;
}
