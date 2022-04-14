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

	int idx1, idx2; //>> 셔플기능도 빙고보도밸류에 넣어버려야할 것 같음. iTemp도 자료형을 바꿔줘야 해서. 
	// >> 이 보드클래스도 템플릿으로 돌리면서 셔플 다시 원위치로
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
		std::cout << "빙고의 사이즈를 입력하시오 : ";
		std::cin >> bingosize;
		system("cls");

		return bingosize;
	}

	void create(int bingosize)
	{
		size = bingosize;
		fullsize = bingosize * bingosize;
		board.create(fullsize); // BingoBoardValue클래스에서 보드 만들어줌
	}

	void shuffle()
	{
		srand((unsigned int)time(0));

		for (int i = 0; i < 100; i++) // 1~입력들어온 fullsize만큼의 숫자 shuffle
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
	// 2. const 함수