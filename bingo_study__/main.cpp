#include "bingo.h"
#include "Bingoboard.h"
#include <iostream>



int main()
{
	Bingoboard Board;
	Bingo Bingo;
	Board.createboard(Board.setBingosize());
	Bingo.changeNum();

	return 0;
}

