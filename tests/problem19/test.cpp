#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler19, isleap)
{
	EXPECT_TRUE(Date::is_leap_year(2004));
	EXPECT_TRUE(Date::is_leap_year(2000));
	EXPECT_FALSE(Date::is_leap_year(2003));
	EXPECT_FALSE(Date::is_leap_year(2100));
}

TEST(euler19, nth_day_of_the_year)
{
	Date d(2024, Month::December, 31);
	EXPECT_EQ(d.nth_day_of_the_year(), 366);
	EXPECT_EQ(d.nth_day_of_the_year(), 366);
	EXPECT_EQ(Date(2024, 1, 31).nth_day_of_the_year(), 31);
	EXPECT_EQ(Date(2024, 3, 25).nth_day_of_the_year(), 85);
	EXPECT_EQ(Date(2024, 5, 31).nth_day_of_the_year(), 152);
}

TEST(euler19, days_from_19000101)
{
	Date d(1900, Month::December, 31);
	Date d2(1901, Month::December, 31);
	EXPECT_EQ(d.days_from_19000101(), 365);
	EXPECT_EQ(d2.days_from_19000101(), 730);
}

TEST(euler19, weekday)
{
	EXPECT_EQ(Date(1900, Month::January, 7).calculate_weekday(), Weekday::Sunday);
	EXPECT_EQ(Date(2024, Month::August, 4).calculate_weekday(), Weekday::Sunday);
}
