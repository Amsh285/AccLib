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
			acclib::vector<int> vec;
			vec.push_back(1);
			vec.push_back(2);
			vec.push_back(3);
			vec.push_back(4);

			vec[3] = 5;

			Assert::AreEqual(1, vec[0]);
			Assert::AreEqual(2, vec[1]);
			Assert::AreEqual(3, vec[2]);
			Assert::AreEqual(5, vec[3]);
		}

		TEST_METHOD(vector_can_grow)
		{
			acclib::vector<int> vec(3);

			for (size_t i = 0; i < 200; ++i)
				vec.push_back(i);

			for (size_t i = 0; i < 200; ++i)
				Assert::AreEqual((int)i, vec[i]);

			Assert::AreEqual(200, (int)vec.size());
			Assert::IsTrue(vec.capacity() >= 200);
		}

		TEST_METHOD(vector_access_with_invalid_index_throws)
		{
			auto func = [] {
				acclib::vector<int> vec(2);
				int a = vec[2];
			};

			Assert::ExpectException<std::invalid_argument>(func);
		}
	};
}
