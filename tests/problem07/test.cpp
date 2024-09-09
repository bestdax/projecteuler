#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler07, nth_prime)
{
	EXPECT_EQ(solution.nth_prime(6), 13);
}
