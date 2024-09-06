#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER26, QUOTIENT)
{
	EXPECT_EQ(solution.reciprocal(2), 0);
	EXPECT_EQ(solution.reciprocal(3), 3);
}

