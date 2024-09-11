#pragma once
#include <iostream>
#include <chrono>
#include <vector>

template<typename Function, typename... Args>
void measure_exe_time(Function func, Args... args)
{
	auto start = std::chrono::high_resolution_clock::now();
	func(args...);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "Execution time: " << duration << std::endl;
}

template<typename Function>
void measure_exe_time(Function func)
{
	auto start = std::chrono::high_resolution_clock::now();
	func();
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "Execution time: " << duration << std::endl;
}

template<typename Container>
void print(const Container &container, const std::string& delimiter = "\t")
{
	for(auto it = container.begin(); it != container.end(); ++it)
	{
		std::cout << *it;

		if(it != container.end() - 1) std::cout << delimiter;
	}

	std::cout << std::endl;
}
