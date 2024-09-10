#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler10, sum_of_primes)
{
	EXPECT_EQ(solution.sum_of_primes(10), 17);
}
