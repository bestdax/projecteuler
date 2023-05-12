#include "gtest/gtest.h"
#include "problem.h"

Solution solution;
TEST(EULER34, IS_CURIOUS)
{
	EXPECT_TRUE(solution.is_curious(145));
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
