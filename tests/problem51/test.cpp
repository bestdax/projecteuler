#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER51, REPLACE)
{
	EXPECT_EQ(solution.replace(56003, 0, 9), 56993);
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
