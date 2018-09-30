#pragma once
#include <boost/iterator/iterator_facade.hpp>
#include <vector>
template <typename T>
class RNG
{
public:
	RNG(int min, int max, int count)
	{
		myNumbers.resize(count);
	}

	T* begin() { return myNumbers.size() > 0 ? &myNumbers[0] : nullptr; }
	T* end() { return myNumbers.size() > 0 ? &myNumbers[myNumbers.size() - 1] : nullptr; }

private:
	std::vector<int> myNumbers;

};
