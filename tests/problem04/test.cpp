#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER04, IS_PALINDROME)
{
	EXPECT_TRUE(solution.is_palindrome(9009));
	EXPECT_TRUE(solution.is_palindrome(333));
	EXPECT_FALSE(solution.is_palindrome(56756));
}

TEST(EULER04, LARGESST_PALINDROME)
{
	EXPECT_EQ(solution.largest_palindrome(2), 9009);
}
int main(int argc, char *argv[])
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
	
