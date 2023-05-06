#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER32, GETDIGITS)
{
  std::vector<unsigned> a{9, 8, 7, 6, 5, 4, 3, 2, 1};
  EXPECT_EQ(solution.get_digits(987654321), a);
}

TEST(EULER32, NUMBER_OF_DIGITS)
{
  std::vector<unsigned> b{123, 456, 789};
  EXPECT_EQ(solution.number_of_digits(b), 9);
}

int main(int argc, char *argv[])
{
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}

