#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler26, cycle)
{
  EXPECT_EQ(solution.unit_reciprocal_cycle(2), 0);
  EXPECT_EQ(solution.unit_reciprocal_cycle(6), 1);
  EXPECT_EQ(solution.unit_reciprocal_cycle(7), 6);
  EXPECT_EQ(solution.unit_reciprocal_cycle(9), 1);
}

