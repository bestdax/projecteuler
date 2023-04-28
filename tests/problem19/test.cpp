#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER19, ISLEAP)
{
	EXPECT_TRUE(solution.is_leap(1996));
	EXPECT_TRUE(solution.is_leap(2004));
	EXPECT_TRUE(solution.is_leap(2000));
	EXPECT_FALSE(solution.is_leap(1997));
	EXPECT_FALSE(solution.is_leap(1900));
}

TEST(EULER19, NTH_DAY)
{
	EXPECT_EQ(solution.nth_day_of_the_year(2023, 1, 28), 28);
	EXPECT_EQ(solution.nth_day_of_the_year(2023, 12, 31), 365);
}

TEST(EULER19, WHICH_DAY)
{
	EXPECT_EQ(solution.which_day(2023, 4, 28), 5);
	EXPECT_EQ(solution.which_day(1900, 1, 8), 1);
	EXPECT_EQ(solution.which_day(2023, 3, 1), 3);
	EXPECT_EQ(solution.which_day(2023, 5, 19), 5);
}

TEST(EULER19, DAYS_FROM_1900)
{
	EXPECT_EQ(solution.how_many_days_from_19000101(1901, 12, 31), 730);
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}

