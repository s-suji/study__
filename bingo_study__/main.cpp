#include "bingo.h"
#include <iostream>

int setBingosize()
{
	int bingosize = 0;
	std::cout << "������ ����� �Է��Ͻÿ� : ";
	std::cin >> bingosize;
	system("cls");

	return bingosize;
}


int main()
{
	Bingo Bingo;
	Bingo.setBingo(setBingosize());
	Bingo.changeNum();

	return 0;
}

