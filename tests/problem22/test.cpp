#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER22, RANK)
{
	EXPECT_EQ(solution.get_rank("COLIN"), 938);
}

TEST(EULER22, CHAR_SUM)
{
	EXPECT_EQ(solution.get_char_sum("COLIN"), 53);
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
