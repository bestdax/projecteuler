#include "gtest/gtest.h"
#include "problem.h"

Solution solution;
TEST(EULER06, SUM_OF_SQUARES)
{
	EXPECT_EQ(solution.sum_of_squares(10), 385);
}

TEST(EULER06, SQUARE_OF_SUM)
{
	EXPECT_EQ(solution.square_of_sum(10), 3025);
}


