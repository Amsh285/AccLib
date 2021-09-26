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

acclib::String::String(const acclib::String& other)
	: m_buffer(other.m_buffer)
{
}

acclib::String::String(acclib::String&& value) noexcept
	: m_buffer(std::move(value.m_buffer))
{
}

int acclib::String::index_of(const char& value)
{
	for (size_t i = 0; i < m_buffer.size(); ++i)
		if (m_buffer[i] == value)
			return i;

	return acclib::String::npos;
}

void acclib::String::concatenate(const acclib::String& value)
{
	concatenate(value.m_buffer.buffer());
}

void acclib::String::concatenate(const char* value)
{
	if (strlen(value) > 0)
	{
		size_t terminator_position = index_of('\0');

		// override \0 terminator
		m_buffer[terminator_position] = value[0];

		// override remaining chars
		for (size_t i = 1; i < strlen(value); ++i)
			m_buffer.push_back(value[i]);

		m_buffer.push_back('\0');
	}
}

char& acclib::String::at(size_t index)
{
	if (index >= size())
		throw std::invalid_argument("index must be smaller than size().");

	return m_buffer.at(index);
}

acclib::String& acclib::String::operator=(const acclib::String& other)
{
	if (this != &other)
		m_buffer = other.m_buffer;

	return *this;
}

acclib::String& acclib::String::operator=(acclib::String&& other) noexcept
{
	m_buffer = std::move(other.m_buffer);
	return *this;
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

acclib::String acclib::String::operator+(const acclib::String& other)
{
	// bin nicht ganz zufrieden damit weil man auf die buffer nicht public zugreifen können
	// sollte, aber kopieren oder redundanter code ist auch keine gute lösung.
	acclib::String result = *this + other.m_buffer.buffer();
	return result;
}

acclib::String acclib::String::operator+(const char* other)
{
	acclib::String result = *this;
	result.concatenate(other);

	return result;
}

acclib::String acclib::String::operator+=(const acclib::String& other)
{
	*this += other.m_buffer.buffer();
	return *this;
}

acclib::String acclib::String::operator+=(const char* other)
{
	concatenate(other);
	return *this;
}

acclib::String::operator const char*()
{
	return c_str();
}

const char* acclib::String::c_str() const
{
	return m_buffer.buffer();
}

acclib::String::~String()
{
}
