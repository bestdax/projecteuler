#pragma once
#include <iostream>
#include <unordered_map>
#include <string>

enum class Month
{
	January, February, March, April, May, June, July, August, September, October, November, December
};
std::ostream& operator<<(std::ostream& os, Month month);

enum class Weekday
{
	Sunday, Monday, Tuesday, Thursday, Wednesday, Friday, Saturday
};

std::ostream& operator<<(std::ostream& os, Weekday weekday);
class Date
{
	public:
		Date(): year(1900), month(Month::January), day(1), weekday(Weekday::Monday) {};

		unsigned year;
		Month month;
		unsigned day;
		Weekday weekday;
		unsigned days_of_month(Date d);
		bool is_leap_year();
		void next_day();

		bool operator!=(Date other);
};

class Solution
{
	public:
		unsigned nth_day_of_the_year(Date);
		void answer();

};
