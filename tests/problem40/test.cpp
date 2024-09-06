#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER40, NTH_DIGIT)
{
  EXPECT_EQ(solution.nth_digit(1), 1);
  EXPECT_EQ(solution.nth_digit(2), 2);
  EXPECT_EQ(solution.nth_digit(3), 3);
  EXPECT_EQ(solution.nth_digit(4), 4);
  EXPECT_EQ(solution.nth_digit(5), 5);
  EXPECT_EQ(solution.nth_digit(6), 6);
  EXPECT_EQ(solution.nth_digit(7), 7);
  EXPECT_EQ(solution.nth_digit(8), 8);
  EXPECT_EQ(solution.nth_digit(9), 9);
  EXPECT_EQ(solution.nth_digit(10), 1);
  EXPECT_EQ(solution.nth_digit(11), 0);
  EXPECT_EQ(solution.nth_digit(12), 1);
  EXPECT_EQ(solution.nth_digit(13), 1);
  EXPECT_EQ(solution.nth_digit(14), 1);
  EXPECT_EQ(solution.nth_digit(15), 2);
  EXPECT_EQ(solution.nth_digit(16), 1);
  EXPECT_EQ(solution.nth_digit(17), 3);
  EXPECT_EQ(solution.nth_digit(18), 1);
  EXPECT_EQ(solution.nth_digit(19), 4);
  EXPECT_EQ(solution.nth_digit(20), 1);
  EXPECT_EQ(solution.nth_digit(21), 5);
}


