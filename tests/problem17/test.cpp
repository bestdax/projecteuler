#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(euler17, count)
{
  EXPECT_EQ(solution.count_char(solution.say_number(342)), 23);
  EXPECT_EQ(solution.count_char(solution.say_number(115)), 20);
}

