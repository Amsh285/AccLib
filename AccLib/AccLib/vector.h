#pragma once

#include "MemoryAllocationFailedException.h"

namespace acclib
{
	template<typename T>
	class vector
	{
	public:
		size_t capacity() const { return m_capacity; };

		size_t size() const { return m_size; };

		// ich lass es mal weg weil es eher unsicher ist und nicht viel mehrwert bringt
		// weil es wahrscheinlicher ist das irgendwann mal ein Fehler bei malloc oder realloc 
		// eintritt bevor das hier erreicht wird.
		//size_t max_size() const
		//{
		//	// https://newbedev.com/c-vector-max-size
		//	// https://stackoverflow.com/questions/56208872/size-of-pointers-and-architecture
		//	return (2 ^ nativePointerBitWidth) / sizeof(T) - 1;
		//};

		vector()
			: vector(20)
		{
		}

		vector(const size_t& capacity)
		{
			m_buffer = new T[capacity];
			m_capacity = capacity;
			m_size = 0;
		}

		void resize(const size_t& capacity)
		{
			T* temp = new T[capacity];

			for (std::size_t i = 0; i < m_size; ++i)
				temp[i] = m_buffer[i];

			delete[] m_buffer;

			m_buffer = temp;
			m_capacity = capacity;
		}

		void push_back(T value)
		{
			if (m_size >= m_capacity)
			{
				size_t new_size = (m_capacity + (m_capacity * 0.5f)) + 1;

				// Todo: �berlauf checken. bzw gr��e 1 u. 0
				// https://stackoverflow.com/questions/206405/overflows-in-size-t-additions
				// https://stackoverflow.com/questions/7749066/how-to-catch-out-of-memory-exception-in-c/13327733
				if (new_size < m_capacity)
					throw std::overflow_error("New capacity overflows maximum. Element cannot be added.");

				resize(new_size);
			}

			m_buffer[m_size] = value;
			++m_size;
		}

		T& operator[](size_t index)
		{
			if (index >= m_size)
				throw std::invalid_argument("index must be smaller than m_size.");

			return m_buffer[index];
		}

		~vector()
		{
			delete[] m_buffer;
		}

	private:
		T* m_buffer;
		size_t m_capacity;
		size_t m_size;
	};
}

