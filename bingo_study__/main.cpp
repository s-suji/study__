#include "bingo.h"
#include <iostream>

int setBingosize()
{
	int bingosize = 0;
	std::cout << "빙고의 사이즈를 입력하시오 : ";
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

