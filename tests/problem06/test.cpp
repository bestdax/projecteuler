#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler06, sum_square_diff)
{
	EXPECT_EQ(solution.sum_square_difference(10), 2640);
}
