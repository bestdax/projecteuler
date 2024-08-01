#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler10, sumofprimes)
{
	EXPECT_EQ(solution.sum_of_primes(10), 17);
}
