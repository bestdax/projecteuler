#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler23, is_abundant)
{
	EXPECT_TRUE(solution.is_abundant[12]);
	EXPECT_FALSE(solution.is_abundant[13]);
}
