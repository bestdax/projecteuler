#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER12, NTH_TRIANLE_NUMBER)
{
	EXPECT_EQ(solution.digit_string_addition("13", "5"), "18");
	EXPECT_EQ(solution.digit_string_addition("16", "5"), "21");
	EXPECT_EQ(solution.digit_string_addition("16", "15"), "31");
}
