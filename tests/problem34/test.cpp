#include "gtest/gtest.h"
#include "problem.h"

Solution solution;
TEST(EULER34, IS_CURIOUS)
{
    EXPECT_TRUE(solution.is_curious(145));
}

TEST(EULER34, SUM_OF_DIGIT_FACTORIAL)
{
    EXPECT_EQ(solution.sum_of_digit_factorial(34), 30);
    EXPECT_EQ(solution.sum_of_digit_factorial(100), 1);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
