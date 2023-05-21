#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER36, BOTH_BASE_PALINDROME)
{
	EXPECT_TRUE(solution.is_double_base_palindrome(585));
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
