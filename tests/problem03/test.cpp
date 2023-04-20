#include "gtest/gtest.h"
#include "problem.h"
#include "number.h"

Solution solution;
using namespace dax;
TEST(EULER03, IS_PRIME)
{
	EXPECT_TRUE(is_prime(2));
	EXPECT_TRUE(is_prime(3));
	EXPECT_TRUE(is_prime(5));
	EXPECT_FALSE(is_prime(4));
	EXPECT_FALSE(is_prime(33));
}

TEST(EULER03, PRIME_FACTORS)
{
	std::vector<unsigned> pf{5, 7, 13, 29};
	EXPECT_EQ(prime_factors(13195), pf);
}

TEST(EULER03, LARGEST_PRIME_FACTOR)
{
	EXPECT_EQ(solution.largest_prime_factor(13195), 29);
}

