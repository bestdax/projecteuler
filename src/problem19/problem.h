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

		Date(unsigned year, Month month, unsigned day): year(year), month(month), day(day)
		{
			weekday = calculate_weekday();
		};

		Date(unsigned year, unsigned month, unsigned day): year(year), month(Month(month - 1)), day(day) {};

		unsigned year;
		Month month;
		unsigned day;
		Weekday weekday;
		static unsigned days_of_month(Date other);
		static bool is_leap_year(unsigned y);
		void next_day();
		unsigned nth_day_of_the_year();
		Weekday calculate_weekday();
		unsigned days_from_19000101();

		bool operator!=(Date other);

		bool operator<(Date other);
		bool operator=(Date other);
		bool operator<=(Date other);
};

std::ostream& operator<<(std::ostream& os, Date date);

class Solution
{
	public:
		void answer();

};
