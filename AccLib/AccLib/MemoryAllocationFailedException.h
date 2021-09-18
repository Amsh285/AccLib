#pragma once
#include <stdexcept>

namespace acclib
{
	class MemoryAllocationFailedException : public std::exception
	{
	public:
		const size_t& requestedCapacity() const { return m_requestedCapacity; };

		MemoryAllocationFailedException(const char* message, const size_t& requestedCapacity);

		const char* what() const noexcept { return m_message; };
	private:
		const char* m_message;
		const size_t m_requestedCapacity;
	};
}

