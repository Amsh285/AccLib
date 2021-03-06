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

		TEST_METHOD(string_copy_ctor)
		{
			acclib::String other("hallo Welt");
			acclib::String sut = other;

			Assert::AreEqual(other[0], sut[0]);
			Assert::AreEqual(other.size(), sut.size());
			Assert::AreEqual(other.length(), sut.length());

			sut.at(0) = '$';

			char s = sut[0];

			Assert::AreEqual('h', other[0]);
			Assert::AreEqual('$', sut[0]);
		}

		TEST_METHOD(string_move_ctor)
		{
			acclib::String pseudo_rvalue("test");
			acclib::String sut = std::move(pseudo_rvalue);

			Assert::IsTrue(sut == "test");

			const acclib::vector<char>& r_buffer = pseudo_rvalue.buffer();

			Assert::AreEqual(0, (int)r_buffer.capacity());
			Assert::AreEqual(0, (int)r_buffer.size());
			Assert::IsTrue(r_buffer.buffer() == nullptr);
		}

		TEST_METHOD(string_copy_assignment)
		{
			acclib::String other = "Hoi";
			acclib::String sut;
			sut = other;

			Assert::IsTrue(other == "Hoi");
			Assert::IsTrue(sut == "Hoi");

			sut.at(0) = 'B';

			Assert::IsTrue(other == "Hoi");
			Assert::IsTrue(sut == "Boi");
		}

		TEST_METHOD(string_move_assignment)
		{
			acclib::String pseudo_rvalue("test");
			acclib::String sut;

			sut	= std::move(pseudo_rvalue);
			Assert::IsTrue(sut == "test");

			const acclib::vector<char>& r_buffer = pseudo_rvalue.buffer();

			Assert::AreEqual(0, (int)r_buffer.capacity());
			Assert::AreEqual(0, (int)r_buffer.size());
			Assert::IsTrue(r_buffer.buffer() == nullptr);
		}

		TEST_METHOD(string_plus_operator)
		{
			acclib::String sut = "Hallo ";
			sut = sut + "Welt";

			Assert::IsTrue(sut == "Hallo Welt");

			sut = "Hallo ";
			Assert::IsTrue(sut == "Hallo ");

			sut = sut + acclib::String("Welt");
			Assert::IsTrue(sut == "Hallo Welt");
		}

		TEST_METHOD(string_plus_assignment_operator)
		{
			acclib::String temp = "lt";
			acclib::String sut = "Hallo ";

			sut += "We";
			Assert::IsTrue(sut == "Hallo We");

			sut += temp;
			Assert::IsTrue(sut == "Hallo Welt");
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

		TEST_METHOD(string_iterator)
		{
			const char* expected = "Hallo";
			int i = 0;

			acclib::String sut(expected);

			for (acclib::String::string_iterator it = sut.begin(); it != sut.end(); ++it)
			{
				Assert::AreEqual(expected[i], *it);
				++i;
			}
		}

		TEST_METHOD(string_c_str)
		{
			acclib::String sut("i love to hate c++");
			const char* str = sut.c_str();

			Assert::IsTrue(sut == str);
		}
	};
}
