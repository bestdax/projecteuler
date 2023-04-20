#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER46, IS_GOLDBACH_NUMBER)
{
	EXPECT_TRUE(solution.is_goldbach_number(9));
	EXPECT_TRUE(solution.is_goldbach_number(15));
	EXPECT_TRUE(solution.is_goldbach_number(21));
	EXPECT_TRUE(solution.is_goldbach_number(25));
	EXPECT_TRUE(solution.is_goldbach_number(27));
	EXPECT_TRUE(solution.is_goldbach_number(33));
}

