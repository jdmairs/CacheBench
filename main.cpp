#include <iostream>
#include "RNG.h"


int main(int argc, char** argv)
{
	RNG<int> generator(0, 10, 2);
	auto begin = generator.begin();
	auto end = generator.end();
	for (int i : generator)
	{
		std::cout << i << "\n";
	}

	const RNG<int> cgen(0, 10, 2);
	for (int i : cgen)
	{
		std::cout << i << "\n";
	}

	for (int& i : generator)
	{
		std::cout << i << "\n";
	}

	return 0;
}