#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER12, NTH_TRIANLE_NUMBER)
{
	EXPECT_EQ(solution.nth_triangle_number(7), 28);
	EXPECT_EQ(solution.nth_triangle_number(10), 55);
}
TEST(EULER12, TRIANGLE_NUMBER_WITH_OVER_N_DIVISOR)
{
	EXPECT_EQ(solution.triangle_number_with_over_n_divisors(5), 28);
}
int main(int argc, char *argv[])
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
