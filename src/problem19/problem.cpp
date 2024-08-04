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

bool Date::is_leap_year(unsigned y)
{
	return y % 400 == 0 ||  y % 100 != 0 && y % 4 == 0;
}

unsigned Date::days_of_month(Date other)
{
	unsigned days{};
	auto m = other.month;

	switch(m)
	{
	case Month::January:
		days = 31;
		break;

	case Month::February:
		if(is_leap_year(other.year))
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

unsigned Date::nth_day_of_the_year()
{
	unsigned days{};

	for(unsigned m = 0; m < unsigned(month); ++m)
	{
		days += days_of_month(Date(year, Month(m), 1));
	}

	return days + day;
}

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
	else if(month == Month::February && (is_leap_year(year) && day == 29 || !is_leap_year(year) && day == 28))
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

unsigned Date::days_from_19000101()
{
	unsigned days{};

	for(unsigned y = 1900; y < year; ++y)
	{
		if(is_leap_year(y)) days += 366;
		else days += 365;

	}

	return days + nth_day_of_the_year();
}

Weekday Date::calculate_weekday()
{
	return Weekday((days_from_19000101()) % 7);
}

bool Date::operator<(Date other)
{
	if(year > other.year) return false;
	else if(year < other.year) return true;
	else
	{
		if(month < other.month) return true;
		else if(month > other.month) return false;
		else return day < other.day;
	}
}

bool Date::operator=(Date other)
{
	return year == other.year && month == other.month && day == other.day;
}

bool Date::operator<=(Date other)
{
	return operator<(other) || operator=(other);
}

std::ostream& operator<<(std::ostream& os, Date date)
{
	os << date.year << '\t' << date.month << '\t' << date.day;
	return os;
}

void Solution::answer()
{
	unsigned count{};
	Date start(1901, Month::January, 1);
	Date end(2000, Month::December, 31);

	while(start <= end)
	{
		if(start.day == 1 && start.weekday == Weekday::Sunday)
		{
			++count;
		}

		start.next_day();
	}

	std::cout << "The answer is: " << count << std::endl;
}
