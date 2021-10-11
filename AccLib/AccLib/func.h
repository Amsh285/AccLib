#pragma once

#include <assert.h>

namespace acclib
{
	template<class T_Result, class ... T_Args>
	class func
	{
	public:
		func() = delete;

		func(T_Result(*function)(T_Args...))
			: m_func(function)
		{
			assert(m_func != nullptr);
		}

		T_Result operator()(T_Args... args)
		{
			assert(m_func != nullptr);
			return m_func(args...);
		}
	private:
		T_Result(*m_func)(T_Args...);
	};
}
