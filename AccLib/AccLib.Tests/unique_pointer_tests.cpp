#include "pch.h"
#include "CppUnitTest.h"

#include "../AccLib/unique_pointer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AccLibTests
{
	TEST_CLASS(unique_pointer_tests)
	{
	public:
		TEST_METHOD(bool_conversionfunc)
		{
			acclib::unique_pointer<int> sut(new int(12));
			Assert::IsTrue(sut);
			sut.reset();
			Assert::IsFalse(sut);
		}

		TEST_METHOD(dereference_operator)
		{
			acclib::unique_pointer<int> sut(new int(12));

			Assert::IsTrue(sut);
			Assert::AreEqual(12, *sut);
		}

		TEST_METHOD(move_constructor)
		{
			acclib::unique_pointer<int> pseudo_rvalue(new int(12));
			acclib::unique_pointer<int> sut = std::move(pseudo_rvalue);
			
			Assert::IsTrue(sut);
			Assert::AreEqual(12, *sut);

			Assert::IsFalse(pseudo_rvalue);
		}

		TEST_METHOD(move_assignment)
		{
			acclib::unique_pointer<int> pseudo_rvalue(new int(12));
			acclib::unique_pointer<int> sut;
			sut = std::move(pseudo_rvalue);

			Assert::IsTrue(sut);
			Assert::AreEqual(12, *sut);

			Assert::IsFalse(pseudo_rvalue);
		}
	};
}
