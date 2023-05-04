#include "gtest/gtest.h"
#include "problem.h"

Solution solution;
TEST(EULER30, SUM_OF_4TH)
{
	EXPECT_EQ(solution.sum_of_nth_power_numbers(4), 19316);
}
TEST(EULER30, SUM_OF_5TH)
{
	EXPECT_EQ(solution.sum_of_nth_power_numbers(5), 443839);
}
int main(int argc, char *argv[])
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}

