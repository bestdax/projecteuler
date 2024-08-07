#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler23, is_sum_of_two_abundants)
{
	EXPECT_TRUE(solution.is_sum_of_two_abundants(24));
	EXPECT_FALSE(solution.is_sum_of_two_abundants(25));
}
