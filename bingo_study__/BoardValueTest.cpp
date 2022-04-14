#include <iostream>
#include <string>
#include "BingoboardValue.h"

int main()
{
	BingoboardValue<std::string> test;
	test.BingoboardValue<std::string>::create(25);

	for (int i = 0; i < 25; ++i)
	{
		std::cout << test.getboard()[i] << "\t";
	}

	return 0;
}