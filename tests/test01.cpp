#include "gtest/gtest.h"
#include "../src/problem01/euler01.h"

Solution Solution;
TEST(EULER01, SUM_OF_MULTIPLES)
{
	EXPECT_EQ(Solution.sum_of_multiples(10), 23);
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
