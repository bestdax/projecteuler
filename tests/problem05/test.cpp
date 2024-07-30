#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler05, smallest)
{
	EXPECT_EQ(solution.smallest_multiple(10), 2520);
}

