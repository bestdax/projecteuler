#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER07, NTH_PRIME)
{
	EXPECT_EQ(solution.nth_prime(1), 2);
	EXPECT_EQ(solution.nth_prime(2), 3);
	EXPECT_EQ(solution.nth_prime(3), 5);
	EXPECT_EQ(solution.nth_prime(4), 7);
	EXPECT_EQ(solution.nth_prime(5), 11);
	EXPECT_EQ(solution.nth_prime(6), 13);
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}

