#include "gtest/gtest.h"
#include "problem.h"

Solution solution;
TEST(EULER48, SUM)
{
	EXPECT_EQ(solution.sum_of_self_power(10), 10405071317);
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
