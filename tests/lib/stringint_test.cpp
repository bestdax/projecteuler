#include <stringint.h>
#include <gtest/gtest.h>


TEST(sint, init)
{
	StringInt a;
	StringInt b(581501314);
	StringInt c("581098108480318043108431");

	std::cout << "a " << a << std::endl;
	std::cout << "b " << b << std::endl;
	std::cout << "c " << c << std::endl;
}
