#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER51, REPLACE)
{
	EXPECT_EQ(solution.replace(12345, 4, 9), 12349);
}

TEST(EULER51, REPLACE_WITH_POSITION_LIST)
{
	EXPECT_EQ(solution.replace(12345, 4, 9), 12349);
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
