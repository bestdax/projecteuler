#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler03, prime)
{
	EXPECT_EQ(solution.get_the_greatest_prime_factor(13195), 29);
}
