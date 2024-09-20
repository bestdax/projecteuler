#include <gtest/gtest.h>
#include <prime.h>
#include <utils.h>

TEST(prime, is_prime)
{
	EXPECT_TRUE(dax::is_prime(2));
	EXPECT_TRUE(dax::is_prime(3));
	EXPECT_TRUE(dax::is_prime(5));
	EXPECT_TRUE(dax::is_prime(7));
	EXPECT_TRUE(dax::is_prime(11));
	EXPECT_TRUE(dax::is_prime(13));
	EXPECT_TRUE(dax::is_prime(17));
	EXPECT_TRUE(dax::is_prime(19));
	EXPECT_TRUE(dax::is_prime(23));
	EXPECT_TRUE(dax::is_prime(29));
}

TEST(prime, is_prime_improved)
{
	EXPECT_TRUE(dax::is_prime_improved(2));
	EXPECT_TRUE(dax::is_prime_improved(3));
	EXPECT_TRUE(dax::is_prime_improved(5));
	EXPECT_TRUE(dax::is_prime_improved(7));
	EXPECT_TRUE(dax::is_prime_improved(11));
	EXPECT_TRUE(dax::is_prime_improved(13));
	EXPECT_TRUE(dax::is_prime_improved(17));
	EXPECT_TRUE(dax::is_prime_improved(19));
	EXPECT_TRUE(dax::is_prime_improved(23));
	EXPECT_TRUE(dax::is_prime_improved(29));
	EXPECT_TRUE(dax::is_prime_improved(97));
	EXPECT_TRUE(dax::is_prime_improved(101));
	EXPECT_FALSE(dax::is_prime_improved(91));
}

void test_prime(unsigned long n)
{
	std::vector<bool> prime_status(n + 1, true);
	for(unsigned long i = 0; i <= n; ++i)
	{
	 prime_status[i] = dax::is_prime(i);
	}
}

void test_prime_improved(unsigned long n)
{
	std::vector<bool> prime_status(n + 1, true);
	for(unsigned long i = 1; i <= n; ++i)
	{
		prime_status[i] = dax::is_prime_improved(i);
	}
}

TEST(prime, primer_timer)
{
	measure_exe_time(test_prime, 1e6);
	measure_exe_time(test_prime_improved, 1e6);
	measure_exe_time(dax::sieve_of_eratosthenes, 1e6);
	measure_exe_time(dax::sieve_of_euler, 1e6);

	for(unsigned long i = 1; i < 1e6; ++i)
	{
		if(dax::is_prime(i) != dax::is_prime_improved(i))
			std::cout << i << std::endl;
	}

	// EXPECT_TRUE(dax::sieve_of_eratosthenes(1e6) == dax::sieve_of_euler(1e6));
}
