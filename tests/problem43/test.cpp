#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER43, IS_DIVISIBLE)
{
	EXPECT_TRUE(solution.is_divisible());
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
