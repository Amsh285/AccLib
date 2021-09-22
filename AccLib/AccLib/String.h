#pragma once

// limits könnte nicht überall verfügbar sein
#include <limits.h>
#include<cstdlib>
#include<cstring>

#include "vector.h"

#define MaxLength INT_MAX - 1

namespace acclib
{
	class String
	{
	public:
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

		char& operator[](size_t index);

		acclib::String& operator=(const acclib::String& other);
		acclib::String& operator=(acclib::String&& other) noexcept;

		bool operator==(const char* value);

		acclib::String operator+(const acclib::String& other);
		acclib::String operator+(const char* other);

		acclib::String operator+=(const acclib::String& other);
		acclib::String operator+=(const char* other);

		// https://www.cplusplus.com/reference/string/string/c_str/
		// Returns a char ptr with the string content in m_buffer.
		// This string should be deleted after its usage because it will be created
		// on the heap.
		const char* c_str() const;

		~String();
	private:
		acclib::vector<char> m_buffer;
	};
}

