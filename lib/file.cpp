#include "file.h"

std::ifstream dax::read(std::filesystem::path p)
{
	std::ifstream file(p, std::ios::in);

	if(file.is_open())
		return file;
	else
		std::cout << "Open file failed" << std::endl;
}
