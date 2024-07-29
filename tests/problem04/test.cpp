#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler04, is_palindrome)
{
	EXPECT_TRUE(solution.is_palindrome(1234321));
}
