#include "problem.h"
#include <timer.h>
#include "timer.h"

int main(int argc, char *argv[])
{
	Solution solution;
	auto func = [&solution]()
	{
			auto func = [&solution]()
	{
		return solution.answer();
	};

	measure_exe_time(func);
	};
	
	measure_exe_time(func);
	return 0;
}
