#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER21, SUM)
{
	EXPECT_EQ(solution.sum_of_proper_divisors(220), 284);
	EXPECT_EQ(solution.sum_of_proper_divisors(284), 220);
	EXPECT_EQ(solution.sum_of_proper_divisors(16), 15);
}

TEST(EULER21, AMICABLE)
{
	EXPECT_TRUE(solution.has_amicable(220));
	EXPECT_FALSE(solution.has_amicable(4));
}


