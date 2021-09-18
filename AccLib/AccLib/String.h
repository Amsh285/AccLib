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

		String();
		String(const char* value);
		
		int index_of(const char& value);

		void concatenate(const char* value);

		~String();
	private:
		

		// Erstellung eines Strings mit const char*
		// 
		// darf man intern einen non const buffer verwenden?

		/*const char* val = "hallo";
		std::string test5(val);
		test5 += 'a';*/

		// würde sinn machen weil der string verändert werden kann.
		// Die Änderung wirkt sich aber nicht auf val aus.
		// Alternative wäre immer neue strings zu erstellen mit new,
		// aber das wirkt sich dann auf den Performance constraint aus.
		// Mit realloc muss man den alten string nicht immer wieder kopieren,
		// weil der speicher einfach nur vergrößert wird.
		acclib::vector<char> m_buffer;
	};
}

