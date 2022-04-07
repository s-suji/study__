#include "Bingoboard.h"
#include <iostream>
#include <time.h>


Bingoboard::Bingoboard()
	:board(nullptr)
	,size(0)
	,fullsize(0)
	,idx1(0), idx2(0), iTemp(0)
{
}

Bingoboard::~Bingoboard()
{
	delete[] board;
}


int setBingosize()
{
	int bingosize = 0;
	std::cout << "������ ����� �Է��Ͻÿ� : ";
	std::cin >> bingosize;
	system("cls");

	return bingosize;
}

void Bingoboard::boardArr(int bingosize_)
{
	size = bingosize_;
	fullsize = bingosize_ * bingosize_;
	board = new int[fullsize];

	srand((unsigned int)time(0));

	for (int i = 0; i < fullsize; i++)
	{
		board[i] = i + 1;
	}
}


void Bingoboard::shuffle()
{
	for (int i = 0; i < 100; i++) // 1~�Էµ��� fullsize��ŭ�� ���� shuffle
	{
		idx1 = rand() % fullsize;
		idx2 = rand() % fullsize;

		iTemp = board[idx1];
		board[idx1] = board[idx2];
		board[idx2] = iTemp;
	}
}


void Bingoboard::createboard(int bingosize_)
{
	boardArr(bingosize_);
	shuffle();
}