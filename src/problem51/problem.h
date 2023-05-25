#pragma once
#include <iostream>
#include <vector>
typedef unsigned long ulong;
typedef std::vector<unsigned long> ulvec;
typedef std::vector<unsigned> uvec;
typedef unsigned uint;
typedef std::vector<uvec> position_lists_type;
class Solution
{
public:
	ulong replace_with_index(ulong number, uint index, uint digit);
	ulong replace_with_position(ulong number, uvec position_list, uint digit);
	position_lists_type gen_position_lists(ulong number);
	ulvec replace(ulong number);

	void answer();

};
