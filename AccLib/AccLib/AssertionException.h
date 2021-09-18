#pragma once

#include <stdexcept>

namespace acclib
{
	class AssertionException : public std::exception
	{
	public:
		AssertionException(const char* message);

		const char* what() const noexcept { return message; };
	private:
		const char* message;
	};
}

