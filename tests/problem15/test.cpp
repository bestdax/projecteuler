#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER15, PATH_NUMBER)
{
	EXPECT_EQ(solution.path_number(2), 6);
	EXPECT_EQ(solution.path_number(3), 20);
}
int main(int argc, char *argv[])
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
