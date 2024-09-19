#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler47, distinct_prime_factors)
{
	EXPECT_EQ(solution.count_distinct_prime_factors(644), 3);
}
