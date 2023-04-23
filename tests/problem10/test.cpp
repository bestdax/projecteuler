#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER10, SUMMATION_OF_PRIMES)
{
	EXPECT_EQ(solution.summation_of_primes(10), 17);
}
int main(int argc, char *argv[])
{
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
