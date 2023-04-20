#include "gtest/gtest.h"
#include "problem.h"

Solution solution;
TEST(EULER01, SUM_OF_MULTIPLES)
{
	EXPECT_EQ(solution.sum_of_multiples(10), 23);
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
