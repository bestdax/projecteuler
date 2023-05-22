#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER39, NUMBER_OF_RIGHT_TRIANGLES)
{
	EXPECT_EQ(solution.number_of_right_triangles(120), 3);
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
