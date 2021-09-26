// AccLib.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "vector.h"
#include "String.h"

class foo
{
public:
	int bar;
};

class bar
{
public:
	int foo;
	int foo2;
};

class foo2
{
public:
	int bar;
	int age;
	std::string id;

	foo2()
		: foo2("")
	{};

	foo2(const char* id) 
		: id(id), age(0), bar(0)
	{};
};

template<class T>
void print_vectors(const std::vector<T>& value)
{
	std::cout << "vec: [ ";

	for (size_t i = 0; i < value.size(); ++i)
		std::cout << value[i] << " ";

	std::cout << "]" << std::endl;
}

int main()
{
	std::vector<int> vec;
	vec.at(0);

	const char* test1 = "hoi";
	
	std::vector<int> first;
	first.push_back(1);
	first.push_back(2);
	first.push_back(3);

	std::vector<int> second = first;
	second[1] = 15;

	print_vectors(first);
	print_vectors(second);

	/*acclib::vector<int> acc_vec(3);
	acc_vec.push_back(12);*/

	// https://isocpp.org/wiki/faq/freestore-mgmt#null-or-zero
	// Can I use realloc() on pointers allocated via new?  
	// No!
	// When realloc() has to copy the allocation, it uses a bitwise copy operation, 
	// which will tear many C++ objects to shreds.C++ objects should be allowed to copy themselves.They use their own copy constructor or assignment operator.
	// Besides all that, the heap that new uses may not be the same as the heap that malloc() and realloc() use!
	// Why doesn’t C++ have an equivalent to realloc() ?

	/*
	foo2* wtf= (foo2*)malloc(sizeof(foo2) * 3);
	wtf[0] = foo2("1234"); */

	// https://stackoverflow.com/questions/38807403/using-malloc-realloc-for-array-of-classes-structs-including-std-vector
	// 

	std::cout << std::numeric_limits<size_t>::max() << std::endl;
	std::cout << std::numeric_limits<size_t>::max() + 1 << std::endl;

	acclib::vector<foo2> acc_vec(3);
	acc_vec.push_back(foo2("1"));
	acc_vec.push_back(foo2("2"));
	acc_vec.push_back(foo2("3"));

	acc_vec.push_back(foo2("4"));

	// standard string legt bei der konstruktion eine copy von val an.
	const char* val = "hallo";
	std::string test5(val);
	test5 += 'a';

	acclib::String test;
	acclib::String foo;
	/*std::cout << "Test: " << test << std::endl;*/
	std::cout << "Hello World!\n";
}
