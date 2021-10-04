#pragma once

#include "func.h"

namespace acclib
{
	template<class T_Element>
	class default_deleter : public func<void, T_Element*>
	{
	public:
		default_deleter()
			: func<void, T_Element*>([](T_Element* ptr) { delete ptr; })
		{
		}
	};

	template<class T_Element>
	class default_array_deleter : public func<void, T_Element*>
	{
	public:
		default_array_deleter()
			: func<void, T_Element*>([](T_Element* ptr) { delete[] ptr; })
		{
		}
	};
}