#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER23, ISABUNDANT)
{
	EXPECT_TRUE(solution.is_abundant(12));
	EXPECT_TRUE(solution.is_abundant(24));
	EXPECT_FALSE(solution.is_abundant(28));
}

TEST(EULER23, IS_SUM_OF_TWO_ABUNDANTS)
{
	EXPECT_TRUE(solution.is_sum_of_two_abundants(24));
	EXPECT_FALSE(solution.is_sum_of_two_abundants(12));
}

