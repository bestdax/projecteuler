#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER55, IS_LYCHREL)
{
  EXPECT_TRUE(solution.is_lychrel(lint(196)));
  EXPECT_TRUE(solution.is_lychrel(lint(4994)));
  EXPECT_FALSE(solution.is_lychrel(lint(349)));
  EXPECT_FALSE(solution.is_lychrel(lint(47)));

}

