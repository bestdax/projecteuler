#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler01, sum_of_multipliers)
{
	EXPECT_EQ(solution.sum_of_multipliers(10), 23);
}
