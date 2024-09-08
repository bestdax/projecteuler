#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler03, greatest_prime_factor)
{
	EXPECT_EQ(solution.greatest_prime_factor(13195), 29);
}
