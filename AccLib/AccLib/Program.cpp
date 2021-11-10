// AccLib.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

#include "vector.h"
#include "String.h"
#include "unique_pointer.h"

int main(int argc, char** argv)
{
	acclib::func<int, int, int> add([](int left, int right) {return left + right; });
	std::cout << "add called: " << add(10, 5) << std::endl;

	{
		acclib::unique_pointer<int> ptr(new int(12));
		acclib::unique_pointer<int> ptr2(new int[3]{ 1,2,3 }, acclib::default_array_deleter<int>());
		acclib::unique_pointer<int> ptr3(new int(12), acclib::func<void, int*>([](int* target) { delete target; std::cout << "custom deleter called." << std::endl; }));
		acclib::unique_pointer<char> ptr4(new char('a'));
	}

	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	std::cout << "### reverse iterator: " << std::endl;

	for (std::vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
		std::cout << *it << std::endl;

	const char* test123 = "Seas";
	const char* second = test123 + 1;

	std::cout << "Hello World!\n";
	std::cin.get();
}
