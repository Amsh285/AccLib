#pragma once

#include "func.h"

namespace acclib
{
	template<class T_Element>
	class default_deleter : public func<void, T_Element*>
	{
	public:
		default_deleter()
			: func<void, T_Element*>([](T_Element* ptr) { delete ptr; })
		{
		}
	};

	template<class T_Element>
	class default_array_deleter : public func<void, T_Element*>
	{
	public:
		default_array_deleter()
			: func<void, T_Element*>([](T_Element* ptr) { delete[] ptr; })
		{
		}
	};

	template<class TBidirectionalIterator, class TElement>
	class reverse_iterator 
	{
	public:
		reverse_iterator(TBidirectionalIterator it)
			: current(std::move(it))
		{
		}

		bool operator!=(const reverse_iterator<TBidirectionalIterator, TElement>& other)
		{
			return current != other.current;
		}

		bool operator==(const reverse_iterator<TBidirectionalIterator, TElement>& other)
		{
			return current == other.current;
		}

		reverse_iterator<TBidirectionalIterator, TElement>& operator++()
		{
			--current;
			return *this;
		}

		reverse_iterator<TBidirectionalIterator, TElement> operator++(int)
		{
			reverse_iterator<TBidirectionalIterator, TElement> temp = *this;
			++(*this);
			return temp;
		}

		reverse_iterator<TBidirectionalIterator, TElement>& operator--()
		{
			++current;
			return *this;
		}

		reverse_iterator<TBidirectionalIterator, TElement> operator--(int)
		{
			reverse_iterator<TBidirectionalIterator, TElement> temp = *this;
			--(*this);
			return temp;
		}

		TElement& operator*()
		{
			// TElement& elem = *--current;
			// ++current;
			TBidirectionalIterator temp = current;
			return *--temp;
		}

	private:
		TBidirectionalIterator current;
	};
}
