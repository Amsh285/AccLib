#include "pch.h"
#include "CppUnitTest.h"

#include "../AccLib/vector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AccLibTests
{
	TEST_CLASS(vector_tests)
	{
	public:

		TEST_METHOD(vector_works_as_intended)
		{
			acclib::vector<int> sut;
			sut.push_back(1);
			sut.push_back(2);
			sut.push_back(3);
			sut.push_back(4);

			sut[3] = 5;

			Assert::AreEqual(1, sut[0]);
			Assert::AreEqual(2, sut[1]);
			Assert::AreEqual(3, sut[2]);
			Assert::AreEqual(5, sut[3]);
		}

		TEST_METHOD(vector_copy_ctor)
		{
			acclib::vector<int> other;
			other.push_back(1);
			other.push_back(2);
			other.push_back(3);

			acclib::vector<int> sut = other;
			sut[0] = 12;

			Assert::AreEqual(1, other[0]);
			Assert::AreEqual(12, sut[0]);
		}

		TEST_METHOD(vector_move_ctor)
		{
			acclib::vector<int> pseudo_rvalue = acclib::vector<int>(12);
			acclib::vector<int> sut = std::move(pseudo_rvalue);
			sut.push_back(123);

			Assert::AreEqual(0, (int)pseudo_rvalue.capacity());
			Assert::AreEqual(0, (int)pseudo_rvalue.size());
			Assert::IsTrue(pseudo_rvalue.buffer() == nullptr);

			Assert::AreEqual(123, sut.at(0));
			Assert::AreEqual(1, (int)sut.size());
			Assert::AreEqual(12, (int)sut.capacity());
		}

		TEST_METHOD(vector_copy_assignment)
		{
			acclib::vector<int> other;
			other.push_back(1);
			other.push_back(2);
			other.push_back(3);

			acclib::vector<int> sut;
			sut = other;

			sut[0] = 100;

			Assert::AreEqual(1, other[0]);
			Assert::AreEqual(100, sut[0]);
		}

		TEST_METHOD(vector_can_grow)
		{
			test_growth(0);
			test_growth(1);
			test_growth(2);
			test_growth(3);
			test_growth(300);
		}

		TEST_METHOD(vector_can_shrink)
		{
			acclib::vector<int> sut(4);
			sut.push_back(1);
			sut.push_back(2);
			sut.push_back(3);
			sut.push_back(4);

			sut.resize(2);
			Assert::AreEqual(1, sut[0]);
			Assert::AreEqual(2, sut[1]);

			Assert::AreEqual(2, (int)sut.size());
			Assert::AreEqual(2, (int)sut.capacity());
		}

		TEST_METHOD(vector_can_write)
		{
			acclib::vector<char> sut;
			sut.push_back('a');
			sut.push_back('b');
			sut.push_back('c');

			sut[2] = 'd';

			Assert::AreEqual('d', sut[2]);
		}

	private:
		void test_growth(size_t initialcapacity)
		{
			acclib::vector<int> sut(initialcapacity);

			for (size_t i = 0; i < 200; ++i)
				sut.push_back(i);

			for (size_t i = 0; i < 200; ++i)
				Assert::AreEqual((int)i, sut[i]);

			Assert::AreEqual(200, (int)sut.size());
			Assert::IsTrue(sut.capacity() >= 200);
		}
	};
}
