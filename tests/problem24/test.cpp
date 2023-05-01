#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER24, NTH_PERMUTATION)
{
	EXPECT_STREQ(solution.nth_permutation("123", 1).c_str(), "123");
	EXPECT_STREQ(solution.nth_permutation("123", 2).c_str(), "132");
	EXPECT_STREQ(solution.nth_permutation("123", 3).c_str(), "213");
	EXPECT_STREQ(solution.nth_permutation("123", 4).c_str(), "231");
	EXPECT_STREQ(solution.nth_permutation("123", 5).c_str(), "312");
	EXPECT_STREQ(solution.nth_permutation("123", 6).c_str(), "321");
}

TEST(EULER24, NEXT_PERMUTATION)
{
	solution.set_string("24534421");
	EXPECT_TRUE(solution.next_permutation());
	EXPECT_STREQ(solution.get_colllection().c_str(), "24541234");
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
