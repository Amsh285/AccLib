#include "MemoryAllocationFailedException.h"

acclib::MemoryAllocationFailedException::MemoryAllocationFailedException(const char* message, const size_t& requestedCapacity)
	: m_message(message), m_requestedCapacity(requestedCapacity)
{
}
