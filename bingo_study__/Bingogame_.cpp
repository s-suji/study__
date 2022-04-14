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
	std::cout << "���ڸ� �Է��ϼ��� : ";
	std::cin >> input;
	system("cls");
}

void Bingogame_::checkInput(int* board, int boardsize, int boardfullsize)
{
	if (input < 0 || input > boardfullsize) // ���� ���� ��
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
	int bingoCount_ = 0; //������������ ����ī��Ʈ
	int h_count = 0; // ����üũ
	int v_count = 0; // ����üũ
	int d1_count = 0; // �밢üũ \ //
	int d2_count = 0;  // ���밢üũ / //

	//üũ�ϼ��Ǹ� ++bingocount
	for (int i = 0; i < boardsize; ++i)
	{
		for (int j = 0; j < boardsize; ++j)
		{
			if (board[i + j * (boardsize)] == 100) // ����üũ
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

	// �밢üũ \ //
	for (int i = 0; i < boardsize; ++i)
	{
		if (board[i * (boardsize + 1)] == 100)
			++d1_count;
		if (d1_count == boardsize)
			++bingoCount_;
	}
	d1_count = 0;

	// ���밢üũ / //
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
	for (int i = 0; i < boardsize; i++) // ���� ���
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
	std::cout << "���� ���� �� �� : " << bingocount << std::endl;
	std::cout << "===================================" << "\n" << "*0�� �Է��ϸ� ����˴ϴ�.*" << "\n" << "===================================" << std::endl;
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
	std::cout << "�����ǿ� ���� �� �Դϴ�. �ٽ� �Է����ֽʽÿ�" << std::endl;
	system("PAUSE");
	system("cls");
}

//void Bingogame_::printErrormessage_duplication()
//{
//	std::cout << "�̹� �Է��� ���Դϴ�. �ٽ� �Է����ֽʽÿ�" << std::endl;
//	system("PAUSE");
//	system("cls");
//}

void Bingogame_::printEndmessage()
{
	std::cout << "0�� �Է��Ͽ��ų�, 5�� �̻��� ���� �Ǿ����ϴ�. ��� �� ������ ���� �˴ϴ�.";
}

*/
