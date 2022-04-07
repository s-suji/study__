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
	std::cout << "빙고의 사이즈를 입력하시오 : ";
	std::cin >> bingosize;
	system("cls");

	return bingosize;
}

void Bingoboard_::create(int bingosize) // 1부터 입력받은사이즈제곱으로 채운 배열 생성
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

	for (int i = 0; i < 100; i++) // 1~입력들어온 fullsize만큼의 숫자 shuffle
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

