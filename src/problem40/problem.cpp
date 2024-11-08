/*
Problem page link:
https://projecteuler.net/problem=40

dax 2024-09-16 15:23:10
*/
#include "problem.h"

uint Solution::get_nth_digit(ulong target_position)
{

	uint number_length = 1; // 当前数字的位数，比如1位数，2位数等
	ulong range_number_count = 9; // 当前范围内的数的个数
	ulong range_digit_count = number_length * range_number_count; // 当前范围内的数字总个数
	ulong base =  1; // 基数， 即 10^{number_length - 1}

	// 计算目标位置所在的位数区域
	while(target_position > range_digit_count)
	{
		target_position -= range_digit_count;
		++number_length;
		range_number_count *= 10;
		range_digit_count = number_length * range_number_count;
		base *= 10;
	}

	// 计算目标位置所在的数
	ulong target_number = base + (target_position - 1) / number_length;

	// 计算目标位置的索引号
	uint target_index = (target_position - 1) % number_length;

	// 将target_number进行右移操作，使得目标数字在最后一位
	for(uint i = 0; i < number_length - target_index - 1; ++i)
	{
		target_number /= 10;
	}

	// 取出对应的数字
	return target_number % 10;

}

void Solution::answer()
{
	ulong target = 1;
	uint result{1};

	for(uint i = 0; i < 7; ++i)
	{
		result *= get_nth_digit(target);
		target *= 10;
	}

	std::cout << "The answer is: " << result << std::endl;

}
