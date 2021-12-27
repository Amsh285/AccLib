#pragma once

#include "utility.h"

namespace acclib
{
	template<class T_Element, class T_Deleter = func<void, T_Element*>>
	class unique_pointer
	{
	public:
		unique_pointer()
			: unique_pointer(nullptr, default_deleter<T_Element>())
		{
		}

		unique_pointer(T_Element* ptr)
			: unique_pointer(ptr, default_deleter<T_Element>())
		{
		}

		unique_pointer(T_Element* ptr, T_Deleter deleter)
			: ptr(ptr), deleter(deleter)
		{
		}

		unique_pointer(const unique_pointer<T_Element, T_Deleter>& other) = delete;


		// https://stackoverflow.com/questions/39297334/why-does-a-move-constructor-require-a-default-constructor-for-its-members
		unique_pointer(unique_pointer<T_Element, T_Deleter>&& other) noexcept
			: deleter(std::move(other.deleter))
		{
			//stupid me...
			ptr = nullptr;

			T_Element* moved = other.release();
			reset(moved);
		}

		unique_pointer<T_Element, T_Deleter> operator=(const unique_pointer<T_Element, T_Deleter>& other) = delete;

		unique_pointer<T_Element, T_Deleter>& operator=(acclib::unique_pointer<T_Element, T_Deleter>&& other) noexcept
		{
			if (this != &other)
			{
				T_Element* moved = other.release();
				reset(moved);
			}

			return *this;
		}

		T_Element& operator*() const noexcept
		{
			return *ptr;
		}

		T_Element* operator->() const noexcept
		{
			return ptr;
		}

		operator bool() const noexcept
		{
			return static_cast<bool>(ptr);
		}

		T_Element* release()
		{
			T_Element* temp = ptr;
			ptr = nullptr;

			return temp;
		}

		void reset(T_Element* new_ptr = nullptr)
		{
			T_Element* old_ptr = ptr;
			ptr = new_ptr;

			if (old_ptr)
				deleter(old_ptr);
		}

		void swap(acclib::unique_pointer<T_Element, T_Deleter>& other)
		{
			T_Element* temp_ptr = ptr;
			T_Deleter temp_deleter = deleter;

			ptr = other.ptr;
			deleter = other.deleter;
			
			other.ptr = temp_ptr;
			other.deleter = temp_deleter;
		}

		~unique_pointer()
		{
			deleter(ptr);
		}

	private:
		T_Element* ptr;
		T_Deleter deleter;
	};
}
