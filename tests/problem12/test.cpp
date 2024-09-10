#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler12, count_divisors)
{
	EXPECT_EQ(solution.count_divisors(28), 6);
}
