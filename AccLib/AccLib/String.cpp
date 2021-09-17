#include "String.h"

acclib::String::String()
	: String("", 100, 0.5f, MaxLength)
{
}

acclib::String::String(const char* value)
	: String(value, 100, 0.5f, MaxLength)
{
}

acclib::String::String(const char* value, size_t capacity, float magnification, size_t maxCapacity)
	: m_capacity(capacity), m_magnification(magnification), m_maxCapacity(maxCapacity)
{
	m_buffer = _strdup(value);
	/*concatenate(m_buffer, value);*/
}

void acclib::String::concatenate(const char* target, const char* value)
{
	const size_t targetCapacity = strlen(target) + strlen(value) + 1;

	//Speicherplatz immer in 0.5% schritten erhöhen bis targetcapacity überschritten wurde.
	while (m_capacity <= targetCapacity)
		m_capacity = m_capacity + m_capacity * m_magnification;

	char* temp = (char*)realloc(m_buffer, sizeof(char) * m_capacity);

	if (temp != nullptr)
		m_buffer = temp;
	else
	{
		//todo
	}

	strcat_s(m_buffer, sizeof(char) * m_capacity, value);
}

acclib::String::~String()
{
	// https://stackoverflow.com/questions/2001286/const-char-s-in-c
	if (m_buffer != nullptr)
		free(m_buffer);
}
