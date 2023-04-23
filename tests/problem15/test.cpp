#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER15, LARGE_NUMBER_ADDITION)
{
	EXPECT_EQ(lint(5) + 5, lint(10));
	EXPECT_EQ(lint(5) - 5, lint(0));
	EXPECT_EQ(lint(5) - 1, lint(4));
}
TEST(EULER15, LARGE_NUMBER_LESS)
{
	lint a{1};
	lint b{999};
	lint c{-1};
	lint d{-100};
	EXPECT_FALSE(a > 100);
	EXPECT_TRUE(a != b);
	EXPECT_FALSE(c < d);
	EXPECT_TRUE(d == lint(-100));
}


int main(int argc, char *argv[])
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
