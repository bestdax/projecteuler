#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler14, collatz_length)
{
	EXPECT_EQ(solution.collatz_length(13), 10);
}
