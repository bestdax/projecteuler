#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER51, REPLACE)
{
	EXPECT_EQ(solution.replace_with_index(12345, 4, 9), 12349);
}

TEST(EULER51, REPLACE_WITH_POSITION_LIST)
{
	std::vector<unsigned> p1{0, 0, 0, 1, 1};
	std::vector<unsigned> p2{0, 0, 1, 0, 1};
	std::vector<unsigned> p3{0, 0, 1, 1, 0};
	std::vector<unsigned> p4{1, 1, 0, 0, 0};
	EXPECT_EQ(solution.replace_with_position(56003, p1, 9), 56099);
	EXPECT_EQ(solution.replace_with_position(56003, p2, 9), 56909);
	EXPECT_EQ(solution.replace_with_position(56003, p3, 9), 56993);
	EXPECT_EQ(solution.replace_with_position(56003, p4, 0), 3);
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
