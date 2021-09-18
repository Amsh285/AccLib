#include "String.h"

acclib::String::String()
	: String("")
{
}

acclib::String::String(const char* value)
{
	m_buffer.push_back('\0');
	concatenate(value);
}

int acclib::String::index_of(const char& value)
{
	for (size_t i = 0; i < m_buffer.size(); i++)
		if (m_buffer[i] == value)
			return i;

	return acclib::String::npos;
}

void acclib::String::concatenate(const char* value)
{
	size_t terminator_position = index_of('\0');

	for (size_t i = terminator_position; i < strlen(value); i++)
		m_buffer.push_back(value[i]);

	m_buffer.push_back('\0');
}

acclib::String::~String()
{
	m_buffer.~vector();
}
