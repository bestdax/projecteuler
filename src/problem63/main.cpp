#include "problem.h"

int main(int argc, char *argv[])
{
	Solution solution;

	measure_exe_time(&Solution::answer, &solution);
	return 0;
}
