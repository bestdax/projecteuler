#pragma once
#include <filesystem>
#include <fstream>
#include <iostream>

namespace dax
{
std::ifstream read(std::filesystem::path p);
}
