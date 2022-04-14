#pragma once
#include "BingoboardValue.h"
#include <string>

template <typename T>
class Bingoboard_
{
private:
	BingoboardValue<T> board;
	int fullsize;
	int size;

	int idx1, idx2; //>> ���ñ�ɵ� ����������� �־�������� �� ����. iTemp�� �ڷ����� �ٲ���� �ؼ�. 
	// >> �� ����Ŭ������ ���ø����� �����鼭 ���� �ٽ� ����ġ��
	T Temp;

public:
	Bingoboard_()
		: size(0)
		, fullsize(0)
		, idx1(0), idx2(0)
	{
	}
	~Bingoboard_()
	{

	}

public:
	int inputBingoSize()
	{
		int bingosize = 0;
		std::cout << "������ ����� �Է��Ͻÿ� : ";
		std::cin >> bingosize;
		system("cls");

		return bingosize;
	}

	void create(int bingosize)
	{
		size = bingosize;
		fullsize = bingosize * bingosize;
		board.create(fullsize); // BingoBoardValueŬ�������� ���� �������
	}

	void shuffle()
	{
		srand((unsigned int)time(0));

		for (int i = 0; i < 100; i++) // 1~�Էµ��� fullsize��ŭ�� ���� shuffle
		{
			idx1 = rand() % fullsize;
			idx2 = rand() % fullsize;

			Temp = board.getboard()[idx1];
			board.getboard()[idx1] = board.getboard()[idx2];
			board.getboard()[idx2] = Temp;
		}
	}
	;


	inline int getSize()
	{
		return size;
	}

	inline int getFullSize()
	{
		return fullsize;
	}

	inline T* getCompleteBoard()
	{
		return board.getboard();
	}
};


	//int getsize() const;
	//const int getsize();
	//const int getsize() const;
	
	// 1. inline
	// 2. const �Լ�