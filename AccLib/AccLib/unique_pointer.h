#pragma once

#include "func.h"

namespace acclib
{
	template<class T_Element>
	func<void, T_Element*> default_deleter([](T_Element* ptr) { delete ptr; });

	template<class T_Element>
	func<void, T_Element*> default_array_deleter([](T_Element* ptr) { delete[] ptr; });

	template<class T_Element, class T_Deleter = func<void, T_Element*>>
	class unique_pointer
	{
	public:
		unique_pointer(T_Element* ptr)
			: unique_pointer(ptr, default_deleter<T_Element>)
		{
		}

		unique_pointer(T_Element* ptr, T_Deleter deleter)
			: ptr(ptr), deleter(deleter)
		{
		}

		~unique_pointer()
		{
			deleter(ptr);
		}
	private:
		T_Element* ptr;
		T_Deleter deleter;
	};
}
