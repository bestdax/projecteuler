#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler21, is_amicable)
{
	EXPECT_TRUE(solution.is_amicable(220));
}

