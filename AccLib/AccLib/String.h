#pragma once

#include <cstring>
#include <limits>
#include <utility>

#include "stringhelper.h"
#include "vector.h"

namespace acclib
{
	class String
	{
	public:
		using string_iterator = acclib::vector<char>::iterator<char>;

		using string_reverse_iterator = acclib::reverse_iterator<acclib::String::string_iterator, char>; 

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

		size_t index_of(const char& value);

		void concatenate(const acclib::String& value);
		void concatenate(const char* value);

		void push_back(char value);

		char& at(size_t index);

		acclib::String& operator=(const acclib::String& other);
		acclib::String& operator=(acclib::String&& other) noexcept;

		bool operator==(const char* value);

		acclib::String operator+(const acclib::String& other);
		acclib::String operator+(const char* other);

		//https://stackoverflow.com/questions/4581961/c-how-to-overload-operator
		acclib::String& operator+=(const acclib::String& other);
		acclib::String& operator+=(const char* other);

		operator const char*();
		const char* c_str() const;

		string_iterator begin()
		{
			return m_buffer.begin();
		}

		string_reverse_iterator rbegin()
		{
			return string_reverse_iterator(end());
		}

		string_iterator end()
		{
			return string_iterator(m_buffer.buffer() + length());
		}

		string_reverse_iterator rend()
		{
			return m_buffer.rend();
		}

		~String();
	private:
		acclib::vector<char> m_buffer;
	};
}

