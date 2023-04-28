#pragma once
#include <iostream>
#include <vector>

class Solution
{
public:
	bool is_leap(unsigned year);
	unsigned days_in_the_year(unsigned year);
	unsigned nth_day_of_the_year(unsigned year, unsigned month, unsigned day);
	unsigned how_many_days_from_19000101(unsigned year, unsigned month, unsigned day);
	unsigned which_day(unsigned year, unsigned month, unsigned day);
	unsigned sundays_in_the_first_of_the_month_in_20th();
	void answer();

};
