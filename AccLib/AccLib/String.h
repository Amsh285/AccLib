#pragma once

// limits k�nnte nicht �berall verf�gbar sein
#include <limits.h>
#include<cstdlib>
#include<cstring>

#define MaxLength INT_MAX - 1

namespace acclib
{
	class String
	{
	public:
		String();
		String(const char* value);
		
		

		~String();
	private:
		String(const char* value, size_t capacity, float magnification, size_t maxCapacity);

		void concatenate(const char* target, const char* value);

		size_t m_capacity;
		float m_magnification;
		size_t m_maxCapacity;

		// Erstellung eines Strings mit const char*
		// 
		// darf man intern einen non const buffer verwenden?

		/*const char* val = "hallo";
		std::string test5(val);
		test5 += 'a';*/

		// w�rde sinn machen weil der string ver�ndert werden kann.
		// Die �nderung wirkt sich aber nicht auf val aus.
		// Alternative w�re immer neue strings zu erstellen mit new,
		// aber das wirkt sich dann auf den Performance constraint aus.
		// Mit realloc muss man den alten string nicht immer wieder kopieren,
		// weil der speicher einfach nur vergr��ert wird.
		char* m_buffer;
	};
}

