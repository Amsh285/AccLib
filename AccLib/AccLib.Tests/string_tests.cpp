#include "pch.h"
#include "CppUnitTest.h"

#include "../AccLib/String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AccLibTests
{
	TEST_CLASS(string_tests)
	{
	public:

		TEST_METHOD(string_init)
		{
			acclib::String sut;

			Assert::AreEqual(0, (int)sut.length());
			Assert::AreEqual(1, (int)sut.size());
		}

		TEST_METHOD(string_init_with_value)
		{
			const char* expected_value = "Hallo Welt";
			acclib::String sut(expected_value);

			Assert::AreEqual((int)strlen(expected_value), (int)sut.length());
			Assert::AreEqual((int)(strlen(expected_value) + 1), (int)sut.size());

			//Equals check
			Assert::IsTrue(sut == expected_value);
		}

		TEST_METHOD(string_c_str)
		{
			acclib::String sut("i love to hate c++");
			const char* str = sut.c_str();

			Assert::IsTrue(sut == str);

			delete str;
		}
	};
}
