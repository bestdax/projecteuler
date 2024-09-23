#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler53, testname)
{
  EXPECT_EQ(solution.combination(23, 10), 1144066);
}

