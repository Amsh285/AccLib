#include "pch.h"
#include "CppUnitTest.h"

#include "../AccLib/unique_pointer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AccLibTests
{
	TEST_CLASS(unique_pointer_tests)
	{
	public:
		TEST_METHOD(move_constructor)
		{
			acclib::unique_pointer<int> sut = acclib::unique_pointer<int>(new int(12));
			
			Assert::AreEqual(12, *sut);
		}

		/*TEST_METHOD(default_deleters)
		{

		}*/


		//TEST_METHOD(dereference_operator)
		//{
		//	/*acclib::unique_pointer<int> sut(new int(12));*/
		//}
	};
}
