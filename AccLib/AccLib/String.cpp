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
	for (size_t i = 0; i < m_buffer.size(); ++i)
		if (m_buffer[i] == value)
			return i;

	return acclib::String::npos;
}

void acclib::String::concatenate(const char* value)
{
	if (strlen(value) > 0)
	{
		size_t terminator_position = index_of('\0');

		m_buffer[terminator_position] = value[0];

		for (size_t i = terminator_position + 1; i < strlen(value); i++)
			m_buffer.push_back(value[i]);

		m_buffer.push_back('\0');
	}
}

char& acclib::String::operator[](size_t index)
{
	return m_buffer[index];
}

bool acclib::String::operator==(const char* value)
{
	if (strlen(value) != length())
		return false;

	for (size_t i = 0; i < strlen(value); ++i)
		if (value[i] != m_buffer[i])
			return false;

	return true;
}

const char* acclib::String::c_str() const
{
	char* copy = new char[m_buffer.size()];

	for (size_t i = 0; i < m_buffer.size(); ++i)
		copy[i] = m_buffer.at(i);
	 
	return copy;
}

acclib::String::~String()
{
}
