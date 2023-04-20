#include "gtest/gtest.h"
#include "problem.h"

Solution solution;

TEST(EULER17, SAY)
{
	EXPECT_STREQ(solution.say_number(342).c_str(), "three hundred and forty-two");
	EXPECT_STREQ(solution.say_number(42).c_str(), "forty-two");
	EXPECT_STREQ(solution.say_number(115).c_str(), "one hundred and fifteen");
	EXPECT_STREQ(solution.say_number(300).c_str(), "three hundred");
	EXPECT_STREQ(solution.say_number(1000).c_str(), "one thousand");
}

TEST(EULER17, COUNT)
{
	EXPECT_EQ(solution.count(342), 23);
	EXPECT_EQ(solution.count(115), 20);
	EXPECT_EQ(solution.count(300), 12);
}


