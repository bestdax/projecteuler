#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER18, FIND_MAX_PARENT)
{
	EXPECT_EQ(solution.find_max_parents(0,0), 0);
	EXPECT_EQ(solution.find_max_parents(2,1), 95);
	EXPECT_EQ(solution.find_max_parents(14,0), 63);
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}

