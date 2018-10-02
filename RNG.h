#pragma once
#include <numeric>
#include <vector>
#include <array>

namespace impl
{
	template <typename T>
	class RngIterator
	{
	public:
		// iterator traits
		using value_type = T;
		using difference_type = std::ptrdiff_t;
		using pointer = T * ;
		using reference = T & ;
		using iterator_category = std::bidirectional_iterator_tag;

		// default constructible
		RngIterator() = default;
		explicit RngIterator(T* value) :value(value) {}

		// dereferenceable
		reference operator*() const 
		{ 
			return *value; 
		}

		// pre and post incrementable
		RngIterator& operator++() 
		{ 
			value++; 
			return *this; 
		}
		
		RngIterator operator++(int) 
		{
			RngIterator tmp = *this;  
			value++; 
			return *this;
		}

		// pre and post decrementable
		RngIterator& operator--()
		{
			value--;
			return *this;
		}
		
		RngIterator operator--(int)
		{
			RngIterator tmp = *this;
			value--;
			return *this;
		}

		// equality and in-equality
		bool operator==(const RngIterator& rhs)
		{
			return *value == *rhs.value;
		}

		bool operator!=(const RngIterator& rhs)
		{
			return !(this->operator==(rhs));
		}

	private:
		T* value;

	};
}

template <typename T>
class RNG
{
public:
	RNG(int min, int max, int count)
	{
		myNumbers.resize(count);
		std::iota(std::begin(myNumbers), std::end(myNumbers), 0);
	}

	using iterator = impl::RngIterator<int>;
	using const_iterator = impl::RngIterator<const int>;

	iterator begin() { return myNumbers.size() > 0 ? iterator{ &myNumbers[0] } : iterator{ nullptr }; }
	iterator end()
	{ 
		return myNumbers.size() > 0 ? iterator{ &myNumbers[myNumbers.size() - 1] + 1} : iterator{ nullptr }; 
	}

	const_iterator begin() const { return myNumbers.size() > 0 ? const_iterator{ &myNumbers[0] } : const_iterator{ nullptr }; }
	const_iterator end() const { return myNumbers.size() > 0 ? const_iterator
	{ 
		&myNumbers[myNumbers.size() - 1] + 1 } : const_iterator{ nullptr }; 
	}

private:
	std::vector<int> myNumbers;

};

