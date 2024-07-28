#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler03, prime)
{
	EXPECT_EQ(solution.get_prime_factors(13195), 29);
}
