/*
Problem page link:
https://projecteuler.net/problem=19

dax 2024-08-03 18:06:12
*/
#include "problem.h"

std::ostream& operator<<(std::ostream& os, Month month)
{
	std::unordered_map<Month, std::string> month_names
	{
		{Month::January, "January"},
		{Month::February, "February"},
		{Month::March, "March"},
		{Month::April, "April"},
		{Month::May, "May"},
		{Month::June, "June"},
		{Month::July, "July"},
		{Month::August, "August"},
		{Month::September, "September"},
		{Month::October, "October"},
		{Month::November, "November"},
		{Month::December, "December"}
	};
	auto it = month_names.find(month);

	if(it != month_names.end())
		os << it->second;
	else
		os << "Unknown Month Name";

	return os;
}

std::ostream& operator<<(std::ostream& os, Weekday weekday)
{
	std::unordered_map<Weekday, std::string> weekday_names
	{
		{Weekday::Sunday, "Sunday"},
		{Weekday::Monday, "Monday"},
		{Weekday::Tuesday, "Tuesday"},
		{Weekday::Thursday, "Thursday"},
		{Weekday::Wednesday, "Wednesday"},
		{Weekday::Friday, "Friday"},
		{Weekday::Saturday, "Saturday"},
	};
	auto it = weekday_names.find(weekday);

	if(it != weekday_names.end())
		os << it->second;
	else
		os << "Unknown Weekday Name";

	return os;
}

bool Date::is_leap_year()
{
	return year % 400 == 0 ||  year % 100 != 0 && year % 4 == 0;
}

unsigned Date::days_of_month(Date d)
{
	unsigned days{};
	auto m = d.month;

	switch(m)
	{
	case Month::January:
		days = 31;
		break;

	case Month::February:
		if(is_leap_year())
			days = 29;
		else days = 28;

		break;

	case Month::March:
		days = 31;
		break;

	case Month::April:
		days = 30;
		break;

	case Month::May:
		days = 31;
		break;

	case Month::June:
		days = 30;
		break;

	case Month::July:
		days = 31;
		break;

	case Month::August:
		days = 31;
		break;

	case Month::September:
		days = 30;
		break;

	case Month::October:
		days = 31;
		break;

	case Month::November:
		days = 30;
		break;

	case Month::December:
		days = 31;
		break;
	}

	return days;
}

// unsigned Solution::nth_day_of_the_year(Date d)
// {
// 	unsigned days{};
// 	for(unsigned m=(Month::January); m < d.month; ++m)
// 	{
// 	}
// }
//
void Date::next_day()
{
	if(month == Month::December && day == 31)
	{
		++year;
		month = Month::January;
		day = 1;
	}
	else if((month == Month::January || month == Month::March || month == Month::May || month == Month::July ||
	         month == Month::August || month == Month::October) && day == 31)
	{
		month = Month(unsigned(month) + 1);
		day = 1;
	}
	else if((month == Month::April || month == Month::June || month == Month::September || month == Month::November) &&
	        day == 30)
	{
		month = Month(unsigned(month) + 1);
		day = 1;
	}
	else if(month == Month::February && (is_leap_year() && day == 29 || !is_leap_year() && day == 28))
	{
		month = Month(unsigned(month) + 1);
		day = 1;
	}
	else ++day;

	weekday = Weekday((unsigned(weekday) + 1) % 7);
}

bool Date::operator!=(Date other)
{
	return year != other.year || month != other.month || day != other.day;
}

void Solution::answer()
{
	unsigned count{};
	Date date;

	while(date.year != 2000 || date.month != Month::December || date.day != 31)
	{
		if(date.day == 1 && date.weekday == Weekday::Sunday)
		{
			++count;
			std::cout << date.year << '\t' << date.month << '\t' << date.day << '\t' << date.weekday << std::endl;
		}

		date.next_day();
	}

	std::cout << "The answer is: " << count << std::endl;
}
