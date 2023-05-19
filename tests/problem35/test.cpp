#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER35, IS_CIRCULAR_PRIME)
{
  EXPECT_TRUE(solution.is_circular_prime(197));
  EXPECT_FALSE(solution.is_circular_prime(29));
  EXPECT_TRUE(solution.is_circular_prime(97));
}

int main(int argc, char *argv[])
{
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}

