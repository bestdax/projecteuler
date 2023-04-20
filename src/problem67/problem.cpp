/*
Problem page link:
https://projecteuler.net/problem=67

dax 2024-09-05 10:12:12
*/
#include "problem.h"
#include "file.h"

void Solution::read_data()
{
	std::filesystem::path p = __FILE__;
	p.replace_filename("0067_triangle.txt");
	auto file = dax::read(p);
	std::string line;

	while(std::getline(file, line))
	{
		std::vector<unsigned> row;
		std::stringstream ss(line);
		std::string ns;

		while(ss >> ns)
		{
			row.push_back(std::stoi(ns));
		}

		data.push_back(row);
	}

}

void Solution::answer()
{

	read_data();

	std::vector<unsigned> floating_row{0};

	for(auto &row : data)
	{
		auto temprow(row) ;

		for(int i = 0; i < row.size(); ++i)
		{
			unsigned upperleft = i - 1 < 0 ? 0 : floating_row[i - 1];
			unsigned upperright = i == floating_row.size() ? 0 : floating_row[i];
			temprow[i] = (upperleft > upperright ? upperleft : upperright) + row[i];
		}

		floating_row = temprow;
	}


	std::cout << "The answer is: " << *std::max_element(floating_row.begin(), floating_row.end()) << std::endl;
}
