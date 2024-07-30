#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler06, square_sum_diff)
{
	EXPECT_EQ(solution.square_sum_diff(10), 2640);
}
