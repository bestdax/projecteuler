#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler08, largest_product)
{
  EXPECT_EQ(solution.largest_product(4), 5832);
}

