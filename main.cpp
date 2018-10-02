#include <iostream>
#include "RNG.h"


int main(int argc, char** argv)
{
	const RNG<int> cgen(0, 10, 2);
	for (int i : cgen)
	{
		std::cout << i << "\n";
	}

	
	return 0;
}