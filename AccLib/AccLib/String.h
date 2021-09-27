#pragma once

// limits könnte nicht überall verfügbar sein
#include <limits.h>
#include<cstdlib>
#include<cstring>

#include "vector.h"

namespace acclib
{
	class String
	{
	public:
		using string_iterator = acclib::vector<char>::iterator<char>;

		static constexpr size_t npos = std::numeric_limits<size_t>::max();

		// Gets the length of the string excluding the terminator symbol \0
		size_t length() const { return m_buffer.size() - 1; };

		// Gets the used size in m_buffer
		size_t size() const { return m_buffer.size(); };

		const acclib::vector<char>& buffer() const { return m_buffer; };

		String();
		String(const char* value);

		String(const acclib::String& other);
		String(acclib::String&& value) noexcept;

		int index_of(const char& value);

		void concatenate(const acclib::String& value);
		void concatenate(const char* value);

		char& at(size_t index);

		acclib::String& operator=(const acclib::String& other);
		acclib::String& operator=(acclib::String&& other) noexcept;

		bool operator==(const char* value);

		acclib::String operator+(const acclib::String& other);
		acclib::String operator+(const char* other);

		acclib::String operator+=(const acclib::String& other);
		acclib::String operator+=(const char* other);

		operator const char*();
		const char* c_str() const;

		string_iterator begin()
		{
			return string_iterator(m_buffer.buffer());
		}

		string_iterator end()
		{
			return string_iterator(m_buffer.buffer() + length());
		}

		~String();
	private:
		acclib::vector<char> m_buffer;
	};
}

