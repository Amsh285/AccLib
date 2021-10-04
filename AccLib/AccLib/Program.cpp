// AccLib.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <array>
#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include <type_traits>
#include <vector>

#include "vector.h"
#include "String.h"
#include "unique_pointer.h"

class entity
{
public:
	int Id;

	entity(int id)
		: Id(id)
	{

	}

	const entity& operator()() const
	{
		std::cout << Id << std::endl;
		return *this;
	}

	~entity()
	{
		std::cout << "dtor called Id: " << Id << std::endl;
	}
};

template<class T>
void do_something(const T& func)
{
	func();
}

void print_something()
{
	std::cout << "hallo" << std::endl;
}

int main()
{
	entity ent(12);
	entity en = 12;

	/*entity* lol = new entity(12);
	entity* lol2 = nullptr;

	bool tes = static_cast<bool>(lol); true
	bool test2 = static_cast<bool>(lol2); false
	*/

	do_something(print_something);
	do_something(ent);

	//move deshalb dtor
	do_something(entity(13));


	//https://stackoverflow.com/questions/36432076/how-to-check-if-a-pointer-points-to-an-array-or-single-int-or-char

	{
		/*
		void(*func)(int*) = [](int* t) {delete t; };
		acclib::unique_pointer<int, void(int*)> ptr2(new int(13), func);
		*/
		/*void(*func)() = print_something;
		func();*/

		acclib::func<int, int, int> add([](int left, int right) {return left + right; });
		/*acclib::func<int, int, int> add = [](int left, int right) {return left + right; };*/
		std::cout << "add called: " << add(10, 5) << std::endl;

		/*std::unique_ptr<int> p(new int(12));*/
		acclib::unique_pointer<int> ptr(new int(12));
		acclib::unique_pointer<int> ptr2(new int[3]{ 1,2,3 }, acclib::default_array_deleter<int>());
		acclib::unique_pointer<int> ptr3(new int(12), acclib::func<void, int*>([](int* target) { delete target; std::cout << "custom deleter called." << std::endl; }));
		acclib::unique_pointer<char> ptr4(new char('a'));

		/*acclib::unique_pointer<int> test;
		acclib::unique_pointer<int> test2 = ptr;
		test = ptr;*/

		

		/*acclib::func<void> asdf();
		asdf();*/
	}

	std::cout << std::is_array<int*>::value << std::endl;


	std::cout << "Hello World!\n";
}
