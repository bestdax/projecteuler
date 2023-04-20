#include "gtest/gtest.h"
#include "problem.h"

Solution solution;
TEST(EULER47, UNIQUE)
{
	std::vector<unsigned> v{2, 3, 2, 5};
	std::vector<unsigned> v1{2, 3, 5};
	solution.unique(v);
	EXPECT_EQ(v, v1);
}
TEST(EULER47, FIRST_NUMBER)
{
  EXPECT_EQ(solution.first_number(2), 14);
  EXPECT_EQ(solution.first_number(3), 644);
}

