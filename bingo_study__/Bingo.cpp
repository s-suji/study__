#include "bingo.h"
#include <iostream>
#include <time.h>



Bingo::Bingo()
	:board(nullptr)
	, size(0), fullsize(0)
	, idx1(0), idx2(0), iTemp(0)
	, input(0)
	, bingocount(0)
{

}


Bingo::~Bingo()
{
	delete[] board;
}


void Bingo::setBingo(int bingosize_)
{
	size = bingosize_;
	fullsize = bingosize_ * bingosize_;
	board = new int[fullsize];

	srand((unsigned int)time(0));

	for (int i = 0; i < fullsize; i++)
	{
		board[i] = i + 1;
	}
	shuffle();
	printBoard();
}


void Bingo::shuffle()
{
	for (int i = 0; i < 100; i++) // 1~입력들어온 fullsize만큼의 숫자 shuffle
	{
		idx1 = rand() % fullsize;
		idx2 = rand() % fullsize;

		iTemp = board[idx1];
		board[idx1] = board[idx2];
		board[idx2] = iTemp;
	}
}


void Bingo::changeNum()
{
	while (true)
	{
		int redupCheck = -1; // 중복체크
		std::cout << "숫자를 입력하세요 : ";
		std::cin >> input;
		system("cls");

		if (input == 0)
			break;

		for (int i = 0; i < fullsize; i++)
		{
			if (board[i] == input)
			{
				board[i] = 100;
				redupCheck = input;
			}
		}
		check();
		printBoard();


		// 범위 외의 수를 입력시 "빙고판에 없는 수 입니다. 다시 입력해주십시오"
		if (input == 0 || input > fullsize)
		{
			redupCheck = input;
			std::cout << "빙고판에 없는 수 입니다. 다시 입력해주십시오" << std::endl;
			system("PAUSE");
			system("cls");
			printBoard();
		}

		// 이미 체크되서 없는 숫자 입력받은면 "이미 입력한 수입니다. 다시입력해주십시오" 떴다가 삭제
		if (redupCheck == -1)
		{
			std::cout << "이미 입력한 수입니다. 다시 입력해주십시오" << std::endl;
			system("PAUSE");
			system("cls");
			printBoard();
		}

		if (bingocount >= 5)
		{
			std::cout << "5개 이상의 빙고가 되었습니다. 잠시 후 게임이 종료 됩니다.";
			break;
		}
	}
}

void Bingo::check()
{
	int bingoCount_ = 0; //지역변수로의 빙고카운트
	int h_count = 0; // 가로체크
	int v_count = 0; // 세로체크
	int d1_count = 0; // 대각체크 \ //
	int d2_count = 0;  // 역대각체크 / //

	//체크완성되면 ++bingocount
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (board[i + j * (size)] == 100) // 가로체크
			{
				++h_count;
			}
		}
		if (h_count == size)
			++bingoCount_;
		h_count = 0;
	}

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (board[i * size + j] == 100) // 
			{
				++v_count;
			}
		}
		if (v_count == size)
			++bingoCount_;
		v_count = 0;
	}

	// 대각체크 \ //
	for (int i = 0; i < size; ++i)
	{
		if (board[i * (size + 1)] == 100)
			++d1_count;
		if (d1_count == size)
			++bingoCount_;
	}
	d1_count = 0;

	// 역대각체크 / //
	for (int i = 1; i < (size + 1); ++i)
	{
		if (board[i * (size - 1)] == 100)
			++d2_count;
		if (d2_count == size)
			++bingoCount_;
	}
	d2_count = 0;

	bingocount = bingoCount_;
}

void Bingo::printBoard()
{
	for (int i = 0; i < size; i++) // 숫자 출력
	{
		for (int j = 0; j < size; j++)
		{
			if (board[i * size + j] == 100)
				std::cout << "#\t";
			else
				std::cout << board[i * size + j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << "현재 빙고 줄 수 : " << bingocount << std::endl;
	std::cout << "===================================" << "\n" << "*0을 입력하면 종료됩니다.*" << "\n" << "===================================" << std::endl;
}

