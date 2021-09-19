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


int main()
{
	const char* test1 = "hoi";

#pragma region stupidstuff
	// 4611686018427387903
	// 18.446.744.073.709.551.615 auf einer 64 bit architektur
	// 4611686018427387903 * 4 = 18 446 744 073 709 551 612
	// passiert wahrscheinlich wegen aufteilung: 
	// 18.446.744.073.709.551.615 / 4 = 4 611 686 018 427 387 903,75
	// (wird wsl abgerundet)
	// 
	// 
	// 
	// 2305843009213693951
	// für x64 architektur

	// x86
	// 1 073 741 823 * 4 = 4.294.967.292 (4294967295 / 4 =  1 073 741 823,75)
	// wieder das rundungsproblem
	std::vector<int> vec;
	std::cout << vec.max_size() << std::endl;

	// 536870911 * 8 = 4.294.967.288 -> wieder rundungsfehler
	std::vector<double> vec2;
	std::cout << vec2.max_size() << std::endl;
	// unsigned int	32	0	4.294.967.295	32 Bit, 4 Byte
	// http://www.mrknowing.com/2013/10/08/datentypen-in-c-wertebereich-und-speichergroesse/
	
	// zusammenfassend kann man davon ausgehen das der std::vector also 
	// für 32 bit architekturen 2^32 elemente  und für 64 bit architekturen
	// 2^64 elemente zulässt wenn die elemente 1 byte groß wären
	// deshalb werden die 2^n elemente noch durch sizeof(_Ty) dividiert dabei kommt es
	// zu rundungsfehlern, die kann man wohl in kauf nehmen

	// https://stackoverflow.com/questions/3813124/c-vector-max-size
	// scheint so zu stimmen
	std::vector<char> vec3;
	std::cout << vec3.max_size() << std::endl;
	// 2147483647

	std::cout << "sizeof foo: " << sizeof(foo) << std::endl;
	std::cout << "sizeof bar: " << sizeof(bar) << std::endl;

	std::cout << UINT32_MAX << std::endl;
#pragma endregion stupidstuff

	char* test2 = new char[20];
	test2[0] = 'h';
	test2[1] = 'o';
	test2[2] = 'i';
	test2[3] = '\0';

	char* test3 = new char[20];
	test3[0] = 'h';
	test3[1] = 'o';
	test3[2] = 'i';
	test3[19] = '\0';
	/*hoi vs hoiÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ erstere variante dürfte die bessere sein.*/

	/*int* arr = (int*)malloc(sizeof(int) * 3);
	arr[0] = 2;
	arr[1] = 3;
	arr[2] = 4;*/
	

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
