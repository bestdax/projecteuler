#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler01, sum)
{
	EXPECT_EQ(solution.sum_of_multiples_of_three_and_five(10), 23);
}
