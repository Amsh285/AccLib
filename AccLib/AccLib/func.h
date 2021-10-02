#pragma once

namespace acclib
{
	template<class T_Result, class ... T_Args>
	class func
	{
	public:
		func(T_Result(*function)(T_Args...))
			: m_func(function)
		{
		}

		T_Result operator()(T_Args... args)
		{
			return m_func(args...);
		}
	private:
		T_Result(*m_func)(T_Args...);
	};
}
