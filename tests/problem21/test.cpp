#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler21, sum_of_proper_divisors)
{
  EXPECT_EQ(solution.sum_of_proper_divisors(220), 284);
  EXPECT_EQ(solution.sum_of_proper_divisors(284), 220);
}

