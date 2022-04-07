#include "Bingoboard_.h"
#include <iostream>
#include <time.h>

Bingoboard_::Bingoboard_()
	:board_(nullptr)
	, size(0)
	, fullsize(0)
	, idx1(0), idx2(0), iTemp(0)
{
}

Bingoboard_::~Bingoboard_()
{
}

int Bingoboard_::inputBingoSize()
{
	int bingosize = 0;
	std::cout << "������ ����� �Է��Ͻÿ� : ";
	std::cin >> bingosize;
	system("cls");

	return bingosize;
}

void Bingoboard_::create(int bingosize) // 1���� �Է¹����������������� ä�� �迭 ����
{
	size = bingosize;
	fullsize = bingosize * bingosize;
	board_ = new int[fullsize];

	for (int i = 0; i < fullsize; i++)
	{
		board_[i] = i + 1;
	}
	
}

void Bingoboard_::shuffle()
{
	srand((unsigned int)time(0));

	for (int i = 0; i < 100; i++) // 1~�Էµ��� fullsize��ŭ�� ���� shuffle
	{
		idx1 = rand() % fullsize;
		idx2 = rand() % fullsize;

		iTemp = board_[idx1];
		board_[idx1] = board_[idx2];
		board_[idx2] = iTemp;
	}
}

//int Bingoboard_::getSize()
//{
//	return size;
//}
//
//int Bingoboard_::getFullSize()
//{
//	return fullsize;
//}
//
//int* Bingoboard_::getBoard()
//{
//	return board_;
//}

