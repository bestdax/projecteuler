#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER42, COMPUTE_WORD_VALUE)
{
  EXPECT_EQ(solution.compute_word_value("SKY"), 55);
}

int main(int argc, char *argv[])
{
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}

