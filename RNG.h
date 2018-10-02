#pragma once
#include <boost/iterator/iterator_facade.hpp>
#include <vector>

namespace impl
{
	template <typename T>
	class RngIterator
	{
	public:
		// iterator traits
		using value_type = T;
		using difference_type = std::ptrdiff_t;
		using pointer = T*;
		using reference = T&;
		using iterator_category = std::bidirectional_iterator_tag;

		// default constructible
		RngIterator() = default;
		explicit RngIterator(T* value);

		// dereferenceable
		reference operator*() const;

		// pre and post incrementable
		RngIterator& operator++();
		RngIterator operator++(int);

		// pre and post decrementable
		RngIterator& operator--();
		RngIterator operator--(int);

		// equality and in-equality
		bool operator==(const RngIterator& rhs);
		bool operator!=(const RngIterator& rhs);


	};

}

template <typename T>
class RNG
{
public:
	RNG(int min, int max, int count)
	{
		myNumbers.resize(count);
	}

	using iterator = impl::RngIterator<int>;
	using const_iterator = impl::RngIterator<const int>;

	iterator begin() { return myNumbers.size() > 0 ? iterator{ &myNumbers[0] } : iterator{ nullptr }; }
	iterator end() { return myNumbers.size() > 0 ? iterator{ &myNumbers[myNumbers.size() - 1] } : iterator{ nullptr }; }

	const_iterator begin() const { return myNumbers.size() > 0 ? const_iterator{ &myNumbers[0] } : const_iterator{ nullptr }; }
	const_iterator end() const { return myNumbers.size() > 0 ? const_iterator{ &myNumbers[myNumbers.size() - 1] } : const_iterator{ nullptr }; }

private:
	std::vector<int> myNumbers;

};
