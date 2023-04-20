#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER14, COLLATZ_COUNT)
{
	EXPECT_EQ(solution.collatz_count(13), 10);
}
