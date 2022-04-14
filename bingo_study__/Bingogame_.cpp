#include "Bingogame_.h"
#include "Bingoboard_.h"
#include <iostream>
#include <string>
/*
Bingogame_::Bingogame_()
	:bingocount(0)
	,input(0)
{
}

Bingogame_::~Bingogame_()
{
}

//======================================================================
void Bingogame_::Start()
{
	Bingoboard_ Bingoboard;
	Bingoboard.create(Bingoboard.inputBingoSize());
	printBoard(Bingoboard.getCompleteBoard(),Bingoboard.getSize());
	while (true)
	{
		getInput();

		if (input == 0)
			break;
		
		checkInput(Bingoboard.getCompleteBoard(), Bingoboard.getSize(), Bingoboard.getFullSize());
		compareInputwithBoard(Bingoboard.getCompleteBoard(), Bingoboard.getFullSize());
		checkBingoComplete(Bingoboard.getCompleteBoard(), Bingoboard.getSize());
		bool fiveBingo = checkBingoComplete(Bingoboard.getCompleteBoard(), Bingoboard.getSize());
		if(fiveBingo == true)
			break;
		printBoard(Bingoboard.getCompleteBoard(), Bingoboard.getSize());
		
		//checkBingoError(Bingoboard.getboard(), Bingoboard.getsize(), Bingoboard.getfullsize());
		
	}
	printEndmessage();
}
//======================================================================

void Bingogame_::getInput()
{
	std::cout << "숫자를 입력하세요 : ";
	std::cin >> input;
	system("cls");
}

void Bingogame_::checkInput(int* board, int boardsize, int boardfullsize)
{
	if (input < 0 || input > boardfullsize) // 범위 외의 수
	{
		printBoard(board, boardsize);
		printErrormessage_exception();
	}
}


void Bingogame_::compareInputwithBoard(int *board, int boardfullsize)
{

	for (int i = 0; i < boardfullsize; i++)
	{
		if (board[i] == input)
		{
			board[i] = 100;
		}
	}

}



bool Bingogame_::checkBingoComplete(int* board, int boardsize)
{
	int bingoCount_ = 0; //지역변수로의 빙고카운트
	int h_count = 0; // 가로체크
	int v_count = 0; // 세로체크
	int d1_count = 0; // 대각체크 \ //
	int d2_count = 0;  // 역대각체크 / //

	//체크완성되면 ++bingocount
	for (int i = 0; i < boardsize; ++i)
	{
		for (int j = 0; j < boardsize; ++j)
		{
			if (board[i + j * (boardsize)] == 100) // 가로체크
			{
				++h_count;
			}
		}
		if (h_count == boardsize)
			++bingoCount_;
		h_count = 0;
	}

	for (int i = 0; i < boardsize; ++i)
	{
		for (int j = 0; j < boardsize; ++j)
		{
			if (board[i * boardsize + j] == 100) // 
			{
				++v_count;
			}
		}
		if (v_count == boardsize)
			++bingoCount_;
		v_count = 0;
	}

	// 대각체크 \ //
	for (int i = 0; i < boardsize; ++i)
	{
		if (board[i * (boardsize + 1)] == 100)
			++d1_count;
		if (d1_count == boardsize)
			++bingoCount_;
	}
	d1_count = 0;

	// 역대각체크 / //
	for (int i = 1; i < (boardsize + 1); ++i)
	{
		if (board[i * (boardsize - 1)] == 100)
			++d2_count;
		if (d2_count == boardsize)
			++bingoCount_;
	}
	d2_count = 0;

	bingocount = bingoCount_;

	if (bingocount >= 5)
	{
		return true;
	}
	return false;
}

void Bingogame_::printBoard(int * board, int boardsize)
{
	for (int i = 0; i < boardsize; i++) // 숫자 출력
	{
		for (int j = 0; j < boardsize; j++)
		{
			if (board[i * boardsize + j] == 100)
				std::cout << "#\t";
			else
				std::cout << board[i * boardsize + j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << "현재 빙고 줄 수 : " << bingocount << std::endl;
	std::cout << "===================================" << "\n" << "*0을 입력하면 종료됩니다.*" << "\n" << "===================================" << std::endl;
}


//===========================================================
//void Bingogame_::checkBingoError(int* board, int boardsize, int boardfullsize)
//{
//	if (input < 0 || input > boardfullsize)
//	{
//		printErrormessage_exception();
//		printBoard(board, boardsize);
//	}
//
//	if (redupChecker == -1)
//	{
//		printErrormessage_duplication();
//		printBoard(board, boardsize);
//	}
//
//}
//===========================================================

void Bingogame_::printErrormessage_exception()
{
	std::cout << "빙고판에 없는 수 입니다. 다시 입력해주십시오" << std::endl;
	system("PAUSE");
	system("cls");
}

//void Bingogame_::printErrormessage_duplication()
//{
//	std::cout << "이미 입력한 수입니다. 다시 입력해주십시오" << std::endl;
//	system("PAUSE");
//	system("cls");
//}

void Bingogame_::printEndmessage()
{
	std::cout << "0을 입력하였거나, 5개 이상의 빙고가 되었습니다. 잠시 후 게임이 종료 됩니다.";
}

*/
