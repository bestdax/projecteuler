#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER37, TRUNCATE_FROM_LEFT)
{
	EXPECT_EQ(solution.truncate_from_left(123456), 23456);
	EXPECT_EQ(solution.truncate_from_left(23456), 3456);
}

TEST(EULER37, IS_TRUNCATABLE_PRIME)
{
	EXPECT_TRUE(solution.is_truncatable_prime(3797));
}

