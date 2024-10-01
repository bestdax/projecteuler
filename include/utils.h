#pragma once
#include <iostream>
#include <chrono>
#include <vector>
#include <type_traits>
#include <iterator>
#include <functional>

template<typename Function, typename... Args>
void measure_exe_time(Function&& func, Args&&... args)
{
	auto start = std::chrono::high_resolution_clock::now();
	std::invoke(std::forward<Function>(func), std::forward<Args>(args)...);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "Execution time: " << duration << std::endl;
}

template<typename T>
struct is_container
{
	private:
		template<typename U>
		static auto test(int) -> decltype(
		    std::begin(std::declval<U>()),
		    std::end(std::declval<U>()),
		    std::true_type()
		);

		template<typename>
		static auto test(...) -> std::false_type;
	public:
		static constexpr bool value = decltype(test<T>(0))::value;
};

template<typename Container>
typename std::enable_if<is_container<Container>::value>::type
print(const Container &container, const std::string& delimiter = "\t")
{
	auto it = container.begin();

	if(it == container.end()) return;  // 如果容器为空，直接返回

	std::cout << *it; // 打印第一个元素
	++it;

	for(; it != container.end(); ++it)
	{
		std::cout << delimiter << *it; // 打印后续元素
	}

	std::cout << std::endl;
}

template<typename T>
typename std::enable_if < !is_container<T>::value >::type
print(const T& var)
{
	std::cout << var << std::endl;;
}

template<typename T, typename... Args>
typename std::enable_if < !is_container<T>::value >::type
print(const T& first, const Args... args)
{
	std::cout << first;

	if constexpr(sizeof...(args) > 0)
	{
		std::cout << "\t"; // 添加默认分隔符
		print(args...);
	}
}
