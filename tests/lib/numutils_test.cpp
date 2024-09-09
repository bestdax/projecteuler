#include <gtest/gtest.h>
#include <numutils.h>

TEST(numutils, is_palindrome)
{
	EXPECT_TRUE(dax::is_palindrome(11223432211));
	EXPECT_FALSE(dax::is_palindrome(1122344542211));
}
