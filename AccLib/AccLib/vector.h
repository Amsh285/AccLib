#pragma once

#include<stdexcept>

#include "utility.h"

namespace acclib
{
	template<typename T>
	class vector
	{
	public:
		template <class TPtr>
		class iterator
		{
		public:
			using iterator_category = std::forward_iterator_tag;
			using difference_type = std::ptrdiff_t;
			using value_type = TPtr;
			using pointer = TPtr*;
			using reference = TPtr&;

			iterator(TPtr* ptr) :
				ptr(ptr)
			{
			}

			bool operator!=(const iterator<TPtr>& other) const
			{
				return ptr != other.ptr;
			}

			bool operator==(const iterator<TPtr>& other) const
			{
				return ptr == other.ptr;
			}

			iterator<TPtr>& operator++()
			{
				++ptr;
				return *this;
			}

			iterator<TPtr> operator++(int)
			{
				iterator<TPtr> temp = *this;
				++(*this);
				return temp;
			}

			iterator<TPtr>& operator--()
			{
				--ptr;
				return *this;
			}

			iterator<TPtr> operator--(int)
			{
				iterator<TPtr> temp = *this;
				--(*this);
				return temp;
			}

			TPtr& operator*()
			{
				return *ptr;
			}
		private:
			TPtr* ptr;
		};

		using vector_reverse_iterator = acclib::reverse_iterator<iterator<T>, T>;

		size_t capacity() const { return m_capacity; };

		size_t size() const { return m_size; };

		T* buffer() const { return m_buffer; };

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

		vector(const acclib::vector<T>& other)
			: m_size(other.m_size), m_capacity(other.m_capacity)
		{
			if (other.m_size > other.m_capacity)
				throw std::invalid_argument("size cannot be larger than capacity.");

			m_buffer = new T[other.m_capacity];

			for (size_t i = 0; i < other.m_size; ++i)
				m_buffer[i] = other.m_buffer[i];
		}

		vector(acclib::vector<T>&& other) noexcept
		{
			move(other);
		}

		void resize(const size_t& capacity)
		{
			T* temp = new T[capacity];

			// Falls die kapazitaet verkleinert wird.
			size_t read_size = m_size < capacity ? m_size : capacity;

			for (std::size_t i = 0; i < read_size; ++i)
				temp[i] = m_buffer[i];

			delete[] m_buffer;

			m_buffer = temp;
			m_capacity = capacity;
			m_size = read_size;
		}

		void push_back(T value)
		{
			if (m_size >= m_capacity)
				resize(get_new_capacity());

			m_buffer[m_size] = value;
			++m_size;
		}

		T& at(const size_t& index) const
		{
			if (index >= m_size)
				throw std::invalid_argument("index must be smaller than m_size.");

			return m_buffer[index];
		}

		iterator<T> begin()
		{
			return iterator<T>(m_buffer);
		}

		vector_reverse_iterator rbegin()
		{
			return vector_reverse_iterator(end());
		}

		iterator<T> end()
		{
			return iterator<T>(m_buffer + m_size);
		}

		vector_reverse_iterator rend()
		{
			return vector_reverse_iterator(begin());
		}

		T& operator[](const size_t& index)
		{
			return m_buffer[index];
		}

		acclib::vector<T>& operator=(const acclib::vector<T>& other)
		{
			if (other.m_size > other.m_capacity)
				throw std::invalid_argument("size cannot be larger than capacity.");

			// https://en.cppreference.com/w/cpp/language/copy_assignment
			if (this != &other)
			{
				delete[] m_buffer;

				m_buffer = new T[other.capacity()];
				m_size = other.size();
				m_capacity = other.capacity();

				for (size_t i = 0; i < other.size(); ++i)
					m_buffer[i] = other.at(i);
			}

			return *this;
		}

		acclib::vector<T>& operator=(acclib::vector<T>&& other) noexcept
		{
			if (this != &other)
			{
				delete[] m_buffer;
				move(other);
			}

			return *this;
		}

		~vector()
		{
			delete[] m_buffer;
		}

	private:
		size_t get_new_capacity() const
		{
			const size_t prevent_zero = 1;

			size_t growth = static_cast<size_t>(m_capacity * 0.5f);
			size_t new_capacity = m_capacity + growth + prevent_zero;

			// overflow check
			// https://stackoverflow.com/questions/206405/overflows-in-size-t-additions
			// https://stackoverflow.com/questions/7749066/how-to-catch-out-of-memory-exception-in-c/13327733
			if (new_capacity < m_capacity)
				throw std::overflow_error("New capacity overflows maximum. Element cannot be added.");

			return new_capacity;
		}

		void move(acclib::vector<T>& other)
		{
			m_buffer = other.m_buffer;
			m_size = other.m_size;
			m_capacity = other.m_capacity;

			other.m_buffer = nullptr;
			other.m_size = 0;
			other.m_capacity = 0;
		}

		T* m_buffer;
		size_t m_capacity;
		size_t m_size;
	};
}

